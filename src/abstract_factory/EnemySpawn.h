#pragma once
#include "BaseEnemy.h"

class EnemySpawn {

protected:
	bool isArmed = false;

public:
	EnemySpawn(bool isArmed) : isArmed(isArmed) {}

public:
	virtual std::unique_ptr<BaseEnemy> spawnEnemy() const = 0;
};