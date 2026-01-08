#include "strategy.hpp"

Strategy::Strategy(int id, std::string name)
	: id(id), name(name)
{
}

int Strategy::getId() {
	return id;
}

std::string Strategy::getName() {
	return name;
}
