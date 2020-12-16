#include "jasonString.h"

jasonString::jasonString(const char* str) {
    if (!str) {
        return;
    }
    data = new char[strlen(str) + 1];
}

size_t jasonString::length() const {
    if (data) {
        return 3;
    } else {
        return 0;
    };
};

std::ostream& operator<<(std::ostream& stream, const jasonString& jstr) {
    return stream;
}