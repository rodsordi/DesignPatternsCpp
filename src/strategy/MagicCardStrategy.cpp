#include "MagicCardStrategy.h"

MagicCardStrategy::MagicCardStrategy() : CardStrategy() {}

std::string MagicCardStrategy::play() const
{
	return "Playing a magic card!";
}