#include<iostream>
#include <list>
#include <vector>

#include "Hash.h"
#include "Bucket.h"
#include "Employee.h"

using namespace std;

int main()
{
  // array that contains keys to be mapped
  int a[] = {15, 11, 27, 8, 12, 1};
  //int a[] = {1, 16, 20, 7, 27, 29, 18, 11, 22, 28, 9, 14};
  int n = sizeof(a)/sizeof(a[0]);

  // insert the keys into the hash table
  Hash h(2);
         // hash table
  for (int i = 0; i < n; i++)
  h.insertItem(a[i]);

  // delete 12 from hash table
  //h.deleteItem(12);

  // display the Hash table
  h.displayHash();

  return 0;
}

