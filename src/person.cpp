#include "person.h"

Person::Person(int id, std::string name)
	: id(id), name(name)
{
}

int Person::getId() {
	return id;
}

std::string Person::getName() {
	return name;
}
