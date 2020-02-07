#ifndef _INCL_EMPLOYEE
#define _INCL_EMPLOYEE
#include<iostream>
#include <list>
#include <vector>

using namespace std;

class Employee {
  string bio;
  string id;
  string managerId;
  string name;

public:
  Employee(string id, string name, string bio, string managerId)
    : id(id),
      managerId(managerId),
      name(name),
      bio(bio)
  {}

  size_t getSize();
  string getId() { return id; }
  string getName() { return name; }
  string getBio() { return bio; }
  string getManagerId() { return managerId; }
};

#endif
