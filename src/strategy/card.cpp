#include "card.h"

std::string Card::play()
{
	return cardStrategy_->play();
}