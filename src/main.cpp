#include <iostream>
#include "strategy.hpp"

using namespace std;

int main() {
    auto strategy = Strategy(1, "Abc123");
	cout << strategy.getId() << " " << strategy.getName() << endl;
}