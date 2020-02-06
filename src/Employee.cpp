// CPP program to implement hashing with chaining
#include<iostream>
#include <list>
#include <vector>

#include "Employee.h"

size_t Employee::getSize() {
  return 16 + bio.length() + managerId.length();
}
