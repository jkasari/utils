#ifndef JASON_STRING_H
#define JASON_STRING_H
#include <iostream>


class jasonString {

 public:
    jasonString() {}
    jasonString(const char*);
    ~jasonString();
    size_t length() const;
    void push_back(const char);
    void push_back(const char*);
    char pop_back();
    const char* inner() const;
 private:
    char* data = nullptr;
    size_t slen = 0;

};


#endif // JASON_STRING_H