#pragma once
#include "BaseEnemy.h"

class GoblinEnemy : public BaseEnemy {
	public:
	GoblinEnemy(int health, bool isArmed) :
		BaseEnemy(health, isArmed) {
	}

public:
	std::string shout() const override {
		if (isArmed) {
			return "Armed Goblin: Grrr!";
		} else {
			return "Unarmed Goblin: Hiss!";
		}
	}
};