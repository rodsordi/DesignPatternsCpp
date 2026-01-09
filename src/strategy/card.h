#pragma once
#include <string>
#include "MagicCardStrategy.h"
#include <memory>

class Card {
private:
	std::unique_ptr<CardStrategy> cardStrategy;

public:
	Card(std::unique_ptr<CardStrategy> cardStrategy) :
		cardStrategy(std::move(cardStrategy))
	{
	}

	std::string play();
};