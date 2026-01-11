#pragma once
#include "GameMatch.h"
#include <memory>

class GameMatchDirector {

public:
	static std::unique_ptr<GameMatch> createRankedVersusMatch() {
		return std::make_unique<GameMatch::Builder>()
			->setType(GameMatch::Type::VERSUS)
			.setMaxPlayers(4)
			.setRanked(true)
			.addEnemy("Enemy1")
			.addEnemy("Enemy2")
			.addEnemy("Enemy3")
			.build();
	}

	static std::unique_ptr<GameMatch> createCasualCoopMatch() {
		return std::make_unique<GameMatch::Builder>()
			->setType(GameMatch::Type::COOP)
			.setMaxPlayers(2)
			.setRanked(false)
			.addEnemy("Enemy1")
			.clearEnemies()
			.build();
	}
};