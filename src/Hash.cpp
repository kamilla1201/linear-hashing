// CPP program to implement hashing with chaining
#include<iostream>
#include <list>
#include <vector>

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

int Hash::hashFunction(int x) {
  return hashFunction(x, modulus);
}

int Hash::hashFunction(int x, int mod) {
  return (x % mod);
}

void Hash::insertItem(int key)
{
  int index = hashFunction(key);
  int bucketMod = buckets[index].getModulus();
  if (bucketMod != modulus) {
    index = hashFunction(key, bucketMod);
  }
  buckets[index].addItem(key);
  if (this->getAvgBucketSize() > 1.6) {
  //if (buckets[index].getItems().size() > 2) {
    displayHash();
    this->addBucket();
  }

}

void Hash::reMap(int bucketInd) {
  cout << "num b " << buckets.size() << endl;
  cout << "next " << next << endl;
  list<int>* items = buckets[bucketInd].getItemsRef();
  // cout << "items " << (void *) &items << endl;
  int mod = buckets[bucketInd].getModulus();
  list<int>::iterator iter = items->begin();
  list<int>::iterator end  = items->end();

  while (iter != end) {
    int item = *iter;
    int index = hashFunction(item, mod);

    if (index == bucketInd) {
      ++iter;
    }
    else
    {
      displayHash();
      iter = items->erase(iter);
      buckets[index].addItem(item);
    }
  }

}

void Hash::addBucket() {
  int bucketMod = modulus * 2;
  buckets.push_back(Bucket(bucketMod));
  numBuckets++;
  buckets[next].setModulus(bucketMod);//buckets[next].getModulus() * 2);
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
    cout << "[" << size << "] " << b.getSize() << endl;
  }
  cout << "size " << size << endl;
  cout << "num buckets " << numBuckets << endl;
  return size / numBuckets;
}

void Hash::displayHash() {
  cout << "mod: " << modulus << endl;
  for (int i = 0; i < numBuckets; i++) {
    cout << "["<< buckets[i].getModulus() << "] " << i;
    for (auto x : buckets[i].getItems()) {
      cout << " --> " << x;
    }
    cout << endl;
  }
}
