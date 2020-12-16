#include "jasonString.h"

size_t jasonString::length() const {
    return 0;
};

std::ostream& operator<<(std::ostream& stream, const jasonString& jstr) {
    return stream;
}