#ifndef EMBER_H
#define EMBER_H

#include <iostream>
#include <cstring>

class Ember {
protected:
    char* nev;
    int szulEv;
public:
    Ember() : szulEv(2005) {
        nev = new char[7];
        strcpy(nev, "TJ0Z3R");
        nev[6] = '\0';
    }
    Ember(const char* n, int ev);
    Ember(const Ember& e);
    Ember& operator=(const Ember& e);
    const char* getNev() const;
    virtual int getKor(int ev) const;
    virtual const char* foglalkozas() const;
    virtual ~Ember();
};

#endif