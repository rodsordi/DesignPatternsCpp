#pragma
#include "EnemySpawn.h"
#include "KoboldEnemy.h"
#include <memory>

class KoboldSpawn : public EnemySpawn {
public:
	KoboldSpawn(bool isArmed) :
		EnemySpawn(isArmed) {
	}

public:
	std::unique_ptr<BaseEnemy> spawnEnemy() const override {
		auto health = 15;
		return std::make_unique<KoboldEnemy>(health, isArmed);
	}
};