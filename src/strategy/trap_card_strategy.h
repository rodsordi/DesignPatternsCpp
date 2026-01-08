#pragma once
#include "card_strategy.h"

class TrapCardStrategy : public CardStrategy {
public:
	TrapCardStrategy();
	std::string play() const override;
};