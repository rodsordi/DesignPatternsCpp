#include <catch2/catch_test_macros.hpp>
#include "singleton/GameInfo.h"

TEST_CASE("When printing GameInfo") {

    SECTION("Then should execute successfully") {

        SECTION("Given a GameInfo instance") {
            //Given
            auto gameInfo = GameInfo::getInstance();
            //When
            auto actual = gameInfo->toString();
            //Then
            REQUIRE(actual == "GameInfo: [name: MyGame, version: 1, studio: StudioInfo: [name: GameStudio, site: https://gamestudio.example.com]]");
        }
    }
}