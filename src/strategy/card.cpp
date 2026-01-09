#include "card.h"

std::string Card::play()
{
	return cardStrategy->play();
}