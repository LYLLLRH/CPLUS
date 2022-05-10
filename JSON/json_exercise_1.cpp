#include <iostream>
#include "./nlohmann/json.hpp"
using json = nlohmann::json;
using namespace::std;

int main() {
	json t;
	t["name"] = "Micheal Zhang";
	t["age"] = 20 ;
	t["sex"] = "Male";
	t["major"] = "CS";


	cout << t["name"] << endl;
	cout << t;
}