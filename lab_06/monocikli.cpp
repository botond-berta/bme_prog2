#include <iostream>
/// Utasítást kiíró és végrehajtó makró
#define _(x)  std::cout << #x << std::endl; x

class Kerek {
    int atmero;
public:
    Kerek(int a) : atmero(a) {
        std::cout << "\tKerek ctor\n";
    }
    ~Kerek() {
        std::cout << "\tKerek dtor\n";
    }
    void kiir() {
        std::cout << "atmero=" << atmero << std::endl;
    }
    Kerek(const Kerek& k) : atmero(k.atmero) {
        std::cout << " \tKerek copy\n";
    }
};

class Monocikli {
    Kerek k;
public:
    Monocikli() : k(16) {
        std::cout << "\tMonocikli ctor\n";
    }
    /*~Monocikli() {
        std::cout << "\tMonocikli dtor\n";
    }*/
    void kiir() {
        std::cout << "\tk."; k.kiir();
    }
    Monocikli(const Monocikli& m) : k(m.k) {
        std::cout << "\tMonocikli copy\n";
    }
};
 
int main() {
_(    Monocikli m1_obj;          )
_(    m1_obj.kiir();             )
_(    Monocikli m2_obj = m1_obj; )
_(    m2_obj.kiir();             )
_(    return 0;                  )
}