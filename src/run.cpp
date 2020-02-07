#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "Hash.h"
#include "Bucket.h"
#include "Employee.h"

using namespace std;
int lookup() {
  Hash h("EmployeeIndex");
  string id;
  while (1) {
    cout << "\nPlease enter id or type \"exit\"" << endl;
    cin >> id;
    if (id.empty()) {
      continue;
    }
    if (id == "exit") {
      exit(0);
    }
    if (!std::all_of(id.begin(), id.end(), ::isdigit)) {
      continue;
    }
    Employee e = h.lookup(id);
    if (!e.getId().empty()) {
      cout << "Found Employee" << endl;
      cout << "Id: " << e.getId() << endl;
      cout << "Name: " << e.getName() << endl;
      cout << "Bio: " << e.getBio() << endl;
      cout << "Manager-id: " << e.getManagerId() << endl;
    }
  }
  return 0;
}
int create() {
  Hash h(2);

  cout << "Reading Employee.csv file" << endl;
 	std::ifstream file("Employee.csv");
  if (!file.good()) {
    cout << "File Employee.csv doesn't exist. Exiting." << endl;
    exit(1);
  }
	std::string line = "";

	while (getline(file, line)) {
		std::vector<string> vec;
		boost::algorithm::split(vec, line, boost::is_any_of(","));
    h.insertItem(Employee(vec[0], vec[1], vec[2], vec[3]));
	}
  h.displayHash();
  cout << "Saving to EmployeeIndex" << endl;
  h.writeIndexFile();
  cout << "EmployeeIndex creation finished."<< endl;
  return 0;
}

void print_help() {
  cout << "Usage:" << endl;
  cout << "   ./main {-L|-C}" << endl;
  cout << "\nOprions:" << endl;
  cout << "   -L: Lookup mode" << endl;
  cout << "   -C: Creation mode" << endl;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    print_help();
    exit(0);
  }
  string flag = string(argv[1]);
  if (flag == "-L") {
    lookup();
  } else if (flag == "-C") {
    create();
  } else {
    print_help();
  }
  return 0;
}
