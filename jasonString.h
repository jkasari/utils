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
  const char pop_back();
  bool remove_first(const char);
  const char* inner() const;

 private:
  char* data = nullptr;
  size_t slen = 0;
};

std::ostream& operator<<(std::ostream& stream, const jasonString& jstr);

bool operator==(const char* str, const jasonString& jstr);

bool operator==(const jasonString& jstr, const char* str);

#endif  // JASON_STRING_H