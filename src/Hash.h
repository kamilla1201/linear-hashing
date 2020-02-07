#ifndef _INCL_HASH
#define _INCL_HASH
#include<iostream>
#include <list>
#include <vector>
#include "Bucket.h"

using namespace std;

class Hash {
  int numBuckets;
  vector<Bucket> buckets;
  int modulus;
  int next;
  int numBucketsInRound;

public:
  Hash(int V);
  Hash(string indexFileName);
  void insertItem(Employee e);
  //void deleteItem(int key);

  int hashFunction(Employee e);
  int hashFunction(string id);
  int hashFunction(string id, int mod);
  int hashFunction(Employee e, int mod);
  void displayHash();
  void writeIndexFile();
  double getAvgBucketSize();
  void addBucket();
  void reMap(int bucketInd);
  Employee lookup(string id);
  //inline
  //size_t getCapacity () { return numBuckets * 4096; }
};

#endif
