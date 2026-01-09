#include <catch2/catch_test_macros.hpp>
#include "singleton/GameInfo.h"

TEST_CASE("When getting the toString info of GameInfo") {

    SECTION("Then should execute successfully") {

        SECTION("Given a GameInfo instance") {
            //Given
            auto& gameInfo = GameInfo::getInstance();
            //When
            auto actual = gameInfo.toString();
            //Then
            REQUIRE(actual == "GameInfo: [name: MyGame, version: 1, studio: StudioInfo: [name: GameStudio, site: https://gamestudio.example.com]]");
            //And
			auto actualStudio = gameInfo.getStudioInfo();
            REQUIRE(actualStudio.toString() == "StudioInfo: [name: GameStudio, site: https://gamestudio.example.com]");
        }

        SECTION("Given two GameInfo instances") {
            //Given
            auto& gameInfo1 = GameInfo::getInstance();
            auto& gameInfo2 = GameInfo::getInstance();

            //When
            auto actual1 = gameInfo1.toString();
            auto actual2 = gameInfo2.toString();
            //Then
            REQUIRE(actual1 == actual2);
            REQUIRE(&gameInfo1 == &gameInfo2);
            //And
			auto& actualStudio1 = gameInfo1.getStudioInfo();
            auto& actualStudio2 = gameInfo2.getStudioInfo();
			REQUIRE(&actualStudio1 == &actualStudio2);
			REQUIRE(actualStudio1.toString() == actualStudio2.toString());
        }
    }
}