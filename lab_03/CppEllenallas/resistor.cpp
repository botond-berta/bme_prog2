/**
 * \file resistor.cpp
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállást modellező osztály megvalósítása
 */

/**
 * Itt kell megvalósítani a resistor.h-ban deklarált nem inline függvényeket.
 * A Jportára ezt a fájlt kell feltölteni.
 */

#include "resistor.h"

double Resistor::defR = 10;

Resistor::Resistor() {
    R = defR;
}

Resistor::Resistor(double r) {
    R = r;
}

void Resistor::setDef(double r) {
    defR = r;
}

Resistor Resistor::operator+(const Resistor& r) const {
    Resistor res(this->R + r.getR());
    return res;
}

Resistor Resistor::operator%(const Resistor& r) const {
    Resistor res(1/( (1/this->R) + (1/r.getR()) ));
    return res;
}

Resistor operator*(int n, const Resistor& r) {
    if ( n<=0 ) throw "TJ0Z3R";
    Resistor res(n * r.getR());
    return res;
}