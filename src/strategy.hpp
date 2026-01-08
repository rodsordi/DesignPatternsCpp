#pragma once
#include <string>

class Strategy {
private:
	int id;
	std::string name;

public:
	Strategy(int id, std::string name);

	int getId();
	std::string getName();
};