#include <catch2/catch_test_macros.hpp>

int Adicionar(int a, int b) {
    return a + b;
}

TEST_CASE("Verificando a funcao de soma", "[soma]") {
    REQUIRE(Adicionar(2, 2) == 4);
    REQUIRE(Adicionar(10, -2) == 8);
}