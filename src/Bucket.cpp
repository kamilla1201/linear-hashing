#include<iostream>
#include <list>
#include <vector>

#include "Bucket.h"

using namespace std;

Bucket::Bucket() {
  items = list<int>();
  modulus = 2;
};

Bucket::Bucket(int m) {
  items = list<int>();
  modulus = m;
};

void Bucket::setModulus(int m) {
  this->modulus = m;
}

void Bucket::addItem(int i) {
  items.push_back(i);
}

size_t Bucket::getSize() {
  size_t size = 0;
  for (int i : items) {
    size += 1;
  }
  return size;
}
