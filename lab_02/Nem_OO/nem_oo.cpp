#include <cstring>
#include <cctype>
#include "nem_oo.h"

/**
 * \file nem_oo_teszt.cpp
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * FELADATOK:
 *  1. Ebben a fájlban valósítsa meg a nem_oo.h állományban deklarált függvényeket!
 *
 * Ügyeljen a helyes névtér használatra!
 *   Tipp: Használja a scope operátort, vagy nyisson névteret!
 */

int sajat::atoi(const char *p, int base) {
    int res = 0;
    int szamjegy = 0;
    for (int i = 0; p[i] != ' ' && p[i] != '\0' && p[i] != '\t' && p[i] != '\n'; i++) {
        if (!(p[i] >= '0' && p[i] <= '9') && !(p[i] >= 'A' && p[i] <= 'F')) {
            throw "TJ0Z3R";
        }
        if (p[i] >= '0' && p[i] <= '9') {
            szamjegy = p[i] - '0';
        } else {
            szamjegy = p[i] - '7';
        }
        if (szamjegy >= base) {
            throw "TJ0Z3R";
        }
        res = res * base + szamjegy;
    }
    return res;
}

char *sajat::strcat(const char *p1, const char *p2) {
    char *res = new char[strlen(p1) + strlen(p2) + 1];
    for (size_t i = 0; i < strlen(p1); i++) {
        res[i] = p1[i];
    }
    for (size_t i = 0; i < strlen(p2); i++) {
        res[i+strlen(p1)] = p2[i];
    }
    res[strlen(p1) + strlen(p2)] = '\0';
    return res;
}

char *sajat::unique(char *first, char *last) {
    char *olv;
    char *iro = first;
    for (olv = first; olv != last; olv++) {
        if (olv == first || *olv != *(olv-1)) {
            *iro = *olv;
            iro++;
        }
    }
    return iro;
}