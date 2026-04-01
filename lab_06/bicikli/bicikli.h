#ifndef BICIKLI_H
#define BICIKLI_H

#include <iostream>

class Kerek {
    int atmero;
public:
    Kerek(int a) : atmero(a) {
        std::cout << "\tKerek ctor\n";
    }
    virtual ~Kerek() {
        std::cout << "\tKerek dtor\n";
    }
    void kiir() {
        std::cout << "atmero=" << atmero << std::endl;
    }
    Kerek(const Kerek& k) : atmero(k.atmero) {
        std::cout << " \tKerek copy\n";
    }
};

class Jarmu {
    double vMax;
public:
    Jarmu(double v) :  vMax(v) {
        std::cout << "\tJarmu ctor vMax=" << vMax << '\n';
    }
    virtual ~Jarmu() {
        std::cout << "\tJarmu dtor vMax=" << vMax << '\n';
    }
    Jarmu(const Jarmu& j) : vMax(j.vMax) {
        std::cout << "\tJarmu copy vMax=" << vMax << '\n';
    }
};

class Szan : public Jarmu {
    int kutyakSzama;
public:
    Szan(double v = 0, int n = 0) : Jarmu(v), kutyakSzama(n) {
        std::cout << "\tSzan ctor kutyakSzama=" << kutyakSzama << '\n';
    }
    ~Szan() {
        std::cout << "\tSzan dtor kutyakSzama=" << kutyakSzama << '\n';
    }
    Szan(const Szan& s) : Jarmu(s), kutyakSzama(s.kutyakSzama) {
        std::cout << "\tSzan copy kutyakSzama=" << kutyakSzama << '\n';
    }
};

class Bicikli : public Jarmu {
    Kerek elso;
    Kerek hatso;
public:
    Bicikli(double v, int d) : Jarmu(v), elso(d), hatso(d) {
        std::cout << "\tBicikli ctor ";
        elso.kiir();
    }
    ~Bicikli() {
        std::cout << "\tBicikli dtor ";
        elso.kiir();
    }
    Bicikli(const Bicikli& b) : Jarmu(b), elso(b.elso), hatso(b.hatso) {
        std::cout << "\tBicikli copy ";
        elso.kiir();
    }

};

#endif