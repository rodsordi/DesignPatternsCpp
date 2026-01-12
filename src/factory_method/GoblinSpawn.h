#pragma once
#include "EnemySpawn.h"
#include "GoblinEnemy.h"
#include <memory>

class GoblinSpawn : public EnemySpawn {
public:
	GoblinSpawn(bool isArmed) :
		EnemySpawn(isArmed) {
	}

public:
	std::unique_ptr<BaseEnemy> spawnEnemy() const override {
		auto health = 10;
		return std::make_unique<GoblinEnemy>(health, isArmed);
	}
};