#pragma once
#include "card_strategy.h"

class MagicCardStrategy : public CardStrategy {
public:
	MagicCardStrategy();
	std::string play() const override;
};