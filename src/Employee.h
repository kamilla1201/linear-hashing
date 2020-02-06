#ifndef _INCL_EMPLOYEE
#define _INCL_EMPLOYEE
#include<iostream>
#include <list>
#include <vector>

using namespace std;

class Employee {
  string id;
  string name;
  string bio;
  string managerId;

public:
  Employee(string id, string name, string bio, string managerId)
    : id(id),
      name(name),
      bio(bio),
      managerId()
  {}

  size_t getSize();
  string getId() { return id; }
  string getName() { return name; }
  string getbBio() { return bio; }
  string getManagerId() { return managerId; }
};

#endif
