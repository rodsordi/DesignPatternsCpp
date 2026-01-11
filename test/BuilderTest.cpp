#include <catch2/catch_test_macros.hpp>
#include "builder/GameMatch.h"
#include <builder/GameMatchDirector.h>

TEST_CASE("When getting the toString from GameMatch") {

	SECTION("Then should execute successfully") {

		SECTION("Given a builded GameMatch created from builder") {
			//Given
			auto gameMatch = std::make_unique<GameMatch::Builder>()
				->setType(GameMatch::Type::VERSUS)
				.setMaxPlayers(4)
				.setRanked(true)
				.addEnemy("Enemy1")
				.addEnemy("Enemy2")
				.addEnemy("Enemy3")
				.build();
			//When
			auto actual = gameMatch->toString();
			//Then
			REQUIRE(actual == "GameMatch: [type: VERSUS, maxPlayers: 4, ranked: true, enemies: Enemy1, Enemy2, Enemy3, ]");
		}

		SECTION("Given a builded GameMatch created from Director::createRankedVersusMatch") {
			//Given
			auto gameMatch = GameMatchDirector::createRankedVersusMatch();
			//When
			auto actual = gameMatch->toString();
			//Then
			REQUIRE(actual == "GameMatch: [type: VERSUS, maxPlayers: 4, ranked: true, enemies: Enemy1, Enemy2, Enemy3, ]");
		}

		SECTION("Given a builded GameMatch created from Director::createCasualCoopMatch") {
			//Given
			auto gameMatch = GameMatchDirector::createCasualCoopMatch();
			//When
			auto actual = gameMatch->toString();
			//Then
			REQUIRE(actual == "GameMatch: [type: COOP, maxPlayers: 2, ranked: false, enemies: ]");
		}
	}
}
