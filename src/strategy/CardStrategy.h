#pragma once
#include <string>

class CardStrategy
{
public:
	virtual std::string play() const = 0;
};