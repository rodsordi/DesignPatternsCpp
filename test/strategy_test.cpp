#include <catch2/catch_test_macros.hpp>
#include <strategy/magic_card_strategy.h>
#include <strategy/card.h>
#include <strategy/trap_card_strategy.h>

TEST_CASE("When play a card") {

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