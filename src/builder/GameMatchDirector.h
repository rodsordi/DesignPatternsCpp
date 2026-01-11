#pragma once
#include "GameMatch.h"
#include <memory>

class GameMatchDirector {

private:
	std::unique_ptr<GameMatch::Builder> builder;

public:
	GameMatchDirector() : builder(std::make_unique<GameMatch::Builder>()) {}

	std::unique_ptr<GameMatch::Builder> getBuilder() {
		return std::move(builder);
	}

public:
	GameMatchDirector& createRankedVersusMatch() {
		builder
			->setType(GameMatch::Type::VERSUS)
			.setMaxPlayers(4)
			.setRanked(true)
			.addEnemy("Enemy1")
			.addEnemy("Enemy2")
			.addEnemy("Enemy3")
			.build();
		return *this;
	}

	GameMatchDirector& createCasualCoopMatch() {
		builder
			->setType(GameMatch::Type::COOP)
			.setMaxPlayers(2)
			.setRanked(false)
			.addEnemy("Enemy1")
			.clearEnemies()
			.build();
		return *this;
	}
};