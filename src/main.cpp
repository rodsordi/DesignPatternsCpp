#include <iostream>
#include "person.h"

using namespace std;

int main() {
    auto person = Person(1, "Abc123");
	cout << person.getId() << " " << person.getName() << endl;
}