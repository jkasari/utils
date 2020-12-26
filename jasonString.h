#ifndef JASON_STRING_H
#define JASON_STRING_H
#include <iostream>

class jasonString {

  friend std::ostream& operator<<(std::ostream& stream, const jasonString& jstr);
  friend bool operator==(const char* str, const jasonString& jstr);
  friend bool operator==(const jasonString& jstr, const char* str);

 public:
  jasonString() {}
  jasonString(const char*);
  ~jasonString();
  size_t length() const;
  void push_back(const char);
  void push_back(const char*);
  const char pop_back();
  bool remove_first(const char);
  bool remove_all(const char);

 private:
  char* data = nullptr;
  size_t slen = 0;
};


#endif  // JASON_STRING_H