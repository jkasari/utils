#include "jasonString.h"

jasonString::jasonString(const char* str) {
    if (!str) {
        return;
    }
    data = new char[strlen(str) + 1];
    strcpy(data, str);
}

jasonString::~jasonString() {
    if (data) {
      delete [] data;
      data = nullptr;
    }
}

size_t jasonString::length() const {
    if (!data) {
        return 0;
    }
    return strlen(data);
}

std::ostream& operator<<(std::ostream& stream, const jasonString& jstr) {
    return stream;
}