#ifndef USTRING_H
#define USTRING_H

#include "string5.h"

class UString : public String {
    static bool is_upcase;
public:
    UString(char c) : String(c) {}
    UString(const char* s = "") : String(s) {}
    UString(const String& str) : String(str) {}
    static void UCase(bool b) {
        is_upcase = b;
    }
    static bool UCase() {
        return is_upcase;
    }
};

std::ostream& operator<<(std::ostream& os, const UString& ustr);

#endif // USTRING_H
