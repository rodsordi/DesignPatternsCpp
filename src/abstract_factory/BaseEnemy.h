#pragma once
#include <string>

class BaseEnemy {

protected:
	int health = 0;
	bool isArmed = false;

public:
	BaseEnemy(int health,
		bool isArmed) :
		health(health),
		isArmed(isArmed){}

public:
	virtual std::string shout() const = 0;

	int getHealth() const {
		return health;
	}
};