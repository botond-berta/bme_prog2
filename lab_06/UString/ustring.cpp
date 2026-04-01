#include "ustring.h"

#include <iostream>
#include <cctype>

bool UString::is_upcase = false;

std::ostream& operator<<(std::ostream& os, const UString& ustr) {
    if (ustr.UCase()) {
        for (size_t i = 0; i < ustr.size(); i++) {
            char c = ustr[i];
            if (c >= 'a' && c <= 'z') {
                os << (char)(c - ('a' - 'A'));
            } else {
                os << c;
            }
        }
    } else {
        os << ustr.c_str();
    }
    return os;
}