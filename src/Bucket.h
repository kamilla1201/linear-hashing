#ifndef _INCL_BUCKET
#define _INCL_BUCKET

#include<iostream>
#include <list>
#include <vector>

using namespace std;

class Bucket {
  const int CAPACITY = 2;

  list<int> items;
  int modulus;

  public:
  Bucket();
  Bucket(int modulus);
  void setModulus(int m);
  void addItem(int i);
  size_t getSize();
  int getModulus() { return modulus; }
  list<int> getItems() {
    return items;
  }

  list<int>* getItemsRef() {
    // cout << "bucket " << (void *) &items << endl;
    return &items;
  }

};

#endif
