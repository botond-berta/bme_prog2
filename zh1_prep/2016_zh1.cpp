/* a) Definiáljon C++ osztályt, melynek a konstruktora a
szabványos kimenetre kiírja a paraméterként kapott
karaktersorozatot, a másoló konstruktora, hogy „Copy”, az
értékadó operátora hogy „Assign”, a destruktora pedig, hogy
„ByeBye”! (2p) */

#include <iostream>

struct C {
    C(const char* p) {
        std::cout << p;
    }
    C(const C& c) {
        std::cout << "Copy";
    }
    C& operator=(const C& c) {
        std::cout << "Assign";
        return *this;
    }
    ~C() {
        std::cout << "ByeBye";
    }
};