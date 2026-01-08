#pragma once
#include <string>
#include "magic_card_strategy.h"
#include <memory>

class Card {
private:
	std::unique_ptr<CardStrategy> cardStrategy_;

public:
	Card(std::unique_ptr<CardStrategy> &&cardStrategy)
	{
		cardStrategy_ = std::move(cardStrategy);
	}

	std::string play();
};