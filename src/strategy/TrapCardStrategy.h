#pragma once
#include "CardStrategy.h"

class TrapCardStrategy : public CardStrategy {
public:
	TrapCardStrategy();
	std::string play() const override;
};