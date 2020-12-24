#include "jasonString.h"

/**
 * allocates a space on the heap for a |jasonString| to occupy
 */
jasonString::jasonString(const char* str) {
  if (!str) {
    return;
  }
  slen = strlen(str);
  data = new char[slen + 1];
  strcpy(data, str);
}

/**
 * deletes the |jasonString| off of the heap
 */
jasonString::~jasonString() {
  if (data) {
    delete[] data;
    data = nullptr;
  }
}

/**
 * returns the length of a |jasonString|
 */
size_t jasonString::length() const {
  return slen;
}

/**
 * returns the char array in a |jasonString| so that |nuttiest| can compare
 * results
 */
const char* jasonString::inner() const { return data; }

/**
 * tells |ostream| how to display a |jasonString|
 */
std::ostream& operator<<(std::ostream& stream, const jasonString& jstr) {
  return stream;
}

/**
 * finds a spot on the heap with enough room for an old |jasonString| plus one
 * additional char
 */
void jasonString::push_back(const char c) {
  const char* oldData = data;
  data = new char[slen + 2];
  if (oldData) {
    strcpy(data, oldData);
    delete[] oldData;
    oldData = nullptr;
  }
  data[slen] = c;
  data[slen + 1] = '\0';
  slen += 1;
}

/**
 * finds a spot on the heap with enough room for an old |jasonString| plus a
 * char array
 */
void jasonString::push_back(const char* str) {
  if (!str) {
    return;
  }
  for(int i = 0; i < strlen(str); ++i) {
    push_back(str[i]);
  }
}