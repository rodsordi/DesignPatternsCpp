#pragma once
#include "CardStrategy.h"

class MagicCardStrategy : public CardStrategy {
public:
	MagicCardStrategy();
	std::string play() const override;
};