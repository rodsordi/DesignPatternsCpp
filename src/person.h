#pragma once
#include <string>

class Person {
private:
	int id;
	std::string name;

public:
	Person(int id, std::string name);

	int getId();
	std::string getName();
};