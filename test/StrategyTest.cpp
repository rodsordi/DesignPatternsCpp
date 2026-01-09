#include <catch2/catch_test_macros.hpp>
#include <strategy/MagicCardStrategy.h>
#include <strategy/card.h>
#include <strategy/TrapCardStrategy.h>

TEST_CASE("When playing a card") {

    SECTION("Then should execute successfully") {

        SECTION("Given a magic card strategy") {
            //Given
            auto card = Card(std::make_unique<MagicCardStrategy>());
            //When
			auto actual = card.play();
            //Then
            REQUIRE(actual == "Playing a magic card!");
        }

        SECTION("Given a trap card strategy") {
            //Given
            auto card = Card(std::make_unique<TrapCardStrategy>());
            //When
            auto actual = card.play();
            //Then
            REQUIRE(actual == "Playing a trap card!");
        }
	}
}