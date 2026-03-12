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
    Pr("ctor0");
    R = defR;
}

Resistor::Resistor(double r) {
    Pr("ctor1");
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

Resistor::Resistor(const Resistor& rhs) : R(rhs.R) {
    Pr("copy");
}

Resistor::~Resistor() {
    Pr("dtor");
}

Resistor& Resistor::operator=(const Resistor& rhs) {
    this->R = rhs.R;
    Pr("assign");
    return *this;
}

double Resistor::getI(double u) const{
    return u / this->R;
}

double Resistor::getU(double i) const {
    return i * this->R;
}