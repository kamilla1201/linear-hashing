#include<iostream>
#include <list>
#include <vector>

#include "Bucket.h"

using namespace std;

Bucket::Bucket() {
  items = list<Employee>();
  modulus = 2;
};

Bucket::Bucket(int m) {
  items = list<Employee>();
  modulus = m;
};

void Bucket::setModulus(int m) {
  modulus = m;
}

void Bucket::addItem(Employee i) {
  items.push_back(i);
}

size_t Bucket::getSize() {
  size_t size = 0;
  for (Employee i : items) {
    size += i.getSize();
  }
  return size;
}
