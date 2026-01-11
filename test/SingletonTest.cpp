#include <catch2/catch_test_macros.hpp>
#include "singleton/GameImmutableInfo.h"

TEST_CASE("When getting the toString info from GameImmutableInfo") {

    SECTION("Then should execute successfully") {

        SECTION("Given a GameImmutableInfo instance") {
            //Given
            auto& gameImmutableInfo = GameImmutableInfo::getInstance();
            //When
            auto actual = gameImmutableInfo.toString();
            //Then
            REQUIRE(actual == "GameImmutableInfo: [name: MyGame, version: 1, launched: true, studio: StudioInfo: [name: GameStudio, class: A, adresses: Address: [street: Street 123, city: São Paulo] Address: [street: Square 2, city: Rio de Janeiro] ]]");
            //And
			auto& actualStudio = gameImmutableInfo.getStudio();
            REQUIRE(actualStudio.toString() == "StudioInfo: [name: GameStudio, class: A, adresses: Address: [street: Street 123, city: São Paulo] Address: [street: Square 2, city: Rio de Janeiro] ]");
            //And
			auto& actualAddresses = actualStudio.getAddresses();
			REQUIRE(actualAddresses[0].toString() == "Address: [street: Street 123, city: São Paulo]");
        }

        SECTION("Given two GameImmutableInfo instances") {
            //Given
            auto& gameImmutableInfo1 = GameImmutableInfo::getInstance();
            auto& gameImmutableInfo2 = GameImmutableInfo::getInstance();
            //When
            auto actual1 = gameImmutableInfo1.toString();
            auto actual2 = gameImmutableInfo2.toString();
            //Then
            REQUIRE(actual1 == actual2);
            REQUIRE(&gameImmutableInfo1 == &gameImmutableInfo2);
            //And
			auto& actualStudio1 = gameImmutableInfo1.getStudio();
            auto& actualStudio2 = gameImmutableInfo2.getStudio();
			REQUIRE(&actualStudio1 == &actualStudio2);
			REQUIRE(actualStudio1.toString() == actualStudio2.toString());
            //And
            auto& actualAddresses1 = actualStudio1.getAddresses();
            auto& actualAddresses2 = actualStudio1.getAddresses();
            REQUIRE(&actualAddresses1 == &actualAddresses2);
            //And
			auto& actualAddress11 = actualAddresses1[0];
			auto& actualAddress21 = actualAddresses2[0];
            REQUIRE(&actualAddress11 == &actualAddress21);
			REQUIRE(actualAddress11.toString() == actualAddress21.toString());
            //And
            auto& actualAddress12 = actualAddresses1[1];
            auto& actualAddress22 = actualAddresses2[1];
            REQUIRE(&actualAddress12 == &actualAddress22);
            REQUIRE(actualAddress12.toString() == actualAddress22.toString());
        }
    }
}

TEST_CASE("When try changing state of immutable singleton") {

    SECTION("Then should not compile") {

        SECTION("Given a GameImmutableInfo instance") {
            //Example
            std::vector<std::string> newPhones = { "000-000-0000" };
            REQUIRE(newPhones.size() == 1);
            REQUIRE(newPhones[0] == "000-000-0000");
            newPhones.erase(newPhones.begin());
            REQUIRE(newPhones.size() == 0);

            //Given
            auto& gameImmutableInfo = GameImmutableInfo::getInstance();
            auto& studio = gameImmutableInfo.getStudio();
            auto& addresses = studio.getAddresses();
            //When
			//studio.getPhones().erase(studio.getPhones().begin()); // DOES NOT COMPILE
			//addresses.erase(addresses.begin()); // DOES NOT COMPILE
        }
    }
}