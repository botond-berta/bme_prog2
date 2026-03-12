#include "memtrace.h"
#include "vektor.h"
#include "gtest_lite.h"

// itt implementálja az osztály konstruktorait és tagmetódusait!

size_t Vektor::defSize = 5;
double Vektor::defValue = 35;

Vektor::Vektor(const Vektor& vektor) {
    pVec = new double[vektor.nElements];
    nElements = vektor.nElements;
    for (size_t i = 0; i < nElements; i++) {
        pVec[i] = vektor.pVec[i];
    }
}

Vektor::~Vektor() {
    delete[] pVec;
}

Vektor& Vektor::operator=(const Vektor& vektor) {
    if (this->pVec == vektor.pVec) {
        return *this;
    }
    delete[] pVec;
    this->pVec = new double[vektor.nElements];
    this->nElements = vektor.nElements;
    for (size_t i = 0; i < nElements; i++) {
        this->pVec[i] = vektor.pVec[i];
    }
    return *this;
}

double& Vektor::operator[](size_t idx) {
    if (idx < 0 || idx >= this->nElements) throw "TJ0Z3R";
    return this->pVec[idx];
}

const double& Vektor::operator[](size_t idx) const {
    if (idx < 0 || idx >= this->nElements) throw "TJ0Z3R";
    return this->pVec[idx];
}

Vektor operator*(double val, const Vektor& vek) {
    Vektor res(vek);
    for (size_t i = 0; i < res.size(); i++) {
        res[i] = val * vek[i];
    }
    return res;
}