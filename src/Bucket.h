#ifndef _INCL_BUCKET
#define _INCL_BUCKET

#include<iostream>
#include <list>
#include <vector>
#include "Employee.h"

using namespace std;

class Bucket {
  list<Employee> items;
  int modulus;

  public:
  Bucket();
  Bucket(int modulus);
  void setModulus(int m);
  void addItem(Employee i);
  size_t getSize();
  int getModulus() { return modulus; }
  list<Employee> getItems() {
    return items;
  }

  list<Employee>* getItemsRef() {
    // cout << "bucket " << (void *) &items << endl;
    return &items;
  }

};

#endif
