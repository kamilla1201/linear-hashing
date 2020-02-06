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
  void insertItem(int x);
  void deleteItem(int key);

  int hashFunction(int x);
  int hashFunction(int x, int mod);
  void displayHash();
  double getAvgBucketSize();
  void addBucket();
  void reMap(int bucketInd);
  //inline
  //size_t getCapacity () { return numBuckets * 4096; }
};

#endif
