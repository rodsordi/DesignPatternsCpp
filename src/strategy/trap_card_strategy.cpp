#include "trap_card_strategy.h"

TrapCardStrategy::TrapCardStrategy() : CardStrategy() {}

std::string TrapCardStrategy::play() const
{
	return "Playing a trap card!";
}