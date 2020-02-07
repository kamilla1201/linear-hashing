// CPP program to implement hashing with chaining
#include<iostream>
#include<fstream>
#include <list>
#include <vector>
#include <numeric>
#include <boost/algorithm/string.hpp>

#include "Hash.h"

using namespace std;

Hash::Hash(int b)
{
  numBuckets = b;
  numBucketsInRound = b;
  buckets = vector<Bucket>(numBuckets);
  next = 0;
  modulus = 2;
}

Hash::Hash(string indexFileName) {
  buckets = vector<Bucket>();
 	ifstream file("EmployeeIndex");
  if (!file.good()) {
    cout << "File EmployeeIndex doesn't exist. Exiting." << endl;
    exit(1);
  }
	std::string line = "";

	while (getline(file, line)) {
		std::vector<string> vec;
		boost::algorithm::split(vec, line, boost::is_any_of(","));
    int index = stoi(vec[0]);
    if (index >= buckets.size()) {
      buckets.push_back(Bucket());
    }
    buckets[index].addItem(Employee(vec[1], vec[2], vec[3], vec[4]));
	}
  numBuckets = buckets.size();
  int maxModulus = pow(2, (int) log2(numBuckets - 1) + 1);
  modulus = maxModulus / 2;
  // cout << "modulus " << modulus << endl;
  // cout << "maxModulus " << maxModulus << endl;
  int diff = numBuckets - modulus;
  // cout << "diff " << diff << endl;
  for (Bucket& b : buckets) {
    b.setModulus(modulus);
    // cout << b.getModulus() << " ";
  }
  // cout << endl;
  int i = 0;
  while (i < diff) {
    buckets[i].setModulus(maxModulus );
    buckets[numBuckets - i - 1].setModulus(maxModulus);
    i++;
  }
  next = i;
}

int Hash::hashFunction(Employee e) {
  return hashFunction(e.getId(), modulus);
}

int Hash::hashFunction(Employee e, int mod) {
  return hashFunction(e.getId(), mod);
}

int Hash::hashFunction(string id) {
  return hashFunction(id, modulus);
}

int Hash::hashFunction(string id, int mod) {
  int ascii = std::stoi(id);
  //cout << "id = " << e.getId() << "; ascii = " << ascii <<
  //  "; mod = " << mod << endl;
  // displayHash();
  return ascii % mod;
}

void Hash::insertItem(Employee e) {
  int index = hashFunction(e);
  int bucketMod = buckets[index].getModulus();
  if (bucketMod != modulus) {
    index = hashFunction(e, bucketMod);
  }
  if (index >= numBuckets) {
    cout << "Error in Hash::insertItem:" << endl;
    cout << "Attempt to access index " << index << " that doesn't exist. Exiting" << endl;
    exit(1);
  }
  buckets[index].addItem(e);
  if (this->getAvgBucketSize() > 0.8 * 4096) {
  //if (buckets[index].getItems().size() > 2) {
    // displayHash();
    this->addBucket();
  }
}

Employee Hash::lookup(string id) {
  int index = hashFunction(id);
  int bucketMod = buckets[index].getModulus();
  if (bucketMod != modulus) {
    index = hashFunction(id, bucketMod);
  }
  if (index >= numBuckets) {
    cout << "Error in Hash::lookup:" << endl;
    cout << "Attempt to access index " << index << " that doesn't exist. Exiting" << endl;
    exit(1);
  }
  list<Employee> items = buckets[index].getItems();
  for (auto i : items) {
    if (i.getId() == id) {
      return i;
    }
  }
  cout << "id [" << id << "] was not found in the table" << endl;
  return Employee("","","","");
}

void Hash::reMap(int bucketInd) {
  list<Employee>* items = buckets[bucketInd].getItemsRef();
  int mod = buckets[bucketInd].getModulus();
  list<Employee>::iterator iter = items->begin();
  list<Employee>::iterator end  = items->end();

  while (iter != end) {
    Employee item = *iter;
    int index = hashFunction(item, mod);

    if (index == bucketInd) {
      ++iter;
    } else {
      if (index >= numBuckets) {
      cout << "Error in Hash::remap:" << endl;
      cout << "Attempt to access index " << index
          << " that doesn't exist. Exiting" << endl;
        exit(1);
      }
      iter = items->erase(iter);
      buckets[index].addItem(item);
    }
  }
}

void Hash::addBucket() {
  int bucketMod = modulus * 2;
  buckets.push_back(Bucket(bucketMod));
  numBuckets++;
  buckets[next].setModulus(bucketMod);
  reMap(next);
  if (next < numBucketsInRound - 1) {
    next++;
  } else {
    next = 0;
    numBucketsInRound = numBuckets;
    modulus = bucketMod;
  }
}

double Hash::getAvgBucketSize() {
  size_t size = 0;
  for (Bucket b : buckets) {
    size += b.getSize();
  }
  return size / numBuckets;
}

void Hash::writeIndexFile() {
  ofstream file;
  file.open("EmployeeIndex");
  // file << (numBuckets - 1) << endl;
  for (int i = 0; i < numBuckets; i++) {
    for (auto x : buckets[i].getItems()) {
      file << i << "," << x.getId() << "," << x.getName()
          << "," << x.getBio() << "," << x.getManagerId() << endl;
    }
  }
  file.close();
}

void Hash::displayHash() {
  cout << "mod: " << modulus << endl;
  for (int i = 0; i < numBuckets; i++) {
    cout << "["<< buckets[i].getModulus() << "] " << i;
    for (auto x : buckets[i].getItems()) {
      cout << " --> " << x.getId();
    }
    cout << endl;
  }
}
