#pragma once
#include "BaseEnemy.h"

class KoboldEnemy : public BaseEnemy {
public:
	KoboldEnemy(int health, bool isArmed) :
		BaseEnemy(health, isArmed) {
	}

public:
	std::string shout() const override {
		if (isArmed) {
			return "Armed Kobold: Roar!";
		}
		else {
			return "Unarmed Kobold: Squeak!";
		}
	}
};