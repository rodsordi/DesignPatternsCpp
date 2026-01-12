#include <catch2/catch_test_macros.hpp>
#include "factory_method/EnemySpawn.h"
#include <factory_method/GoblinSpawn.h>
#include <factory_method/KoboldSpawn.h>

TEST_CASE("When enemy do shout") {

	SECTION("Then should execute successfully") {

		SECTION("Given a GoblinSpawn and an armed setup") {
			//Given
			auto armed = true;
			auto enemySpawn = std::make_unique<GoblinSpawn>(armed);
			auto enemy = enemySpawn->spawnEnemy();
			//When
			auto actual = enemy->shout();
			//Then
			REQUIRE(actual == "Armed Goblin: Grrr!");
			REQUIRE(enemy->getHealth() == 10);
		}

		SECTION("Given a KoboldSpawn and an unarmed setup") {
			//Given
			auto armed = false;
			auto enemySpawn = std::make_unique<KoboldSpawn>(armed);
			auto enemy = enemySpawn->spawnEnemy();
			//When
			auto actual = enemy->shout();
			//Then
			REQUIRE(actual == "Unarmed Kobold: Squeak!");
			REQUIRE(enemy->getHealth() == 15);
		}
	}
}