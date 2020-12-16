#ifndef JASON_STRING_H
#define JASON_STRING_H
#include <iostream>


class jasonString {

 public:
    jasonString() {}
    jasonString(const char*);
    size_t length() const;
 private:
    char* data = nullptr;

};


#endif // JASON_STRING_H