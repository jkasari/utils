#include "jasonString.h"

/**
 * allocates a space on the heap for a |jasonString| to occupy
 */
jasonString::jasonString(const char* str) {
  if (!str) {
    return;
  }
  data = new char[strlen(str) + 1];
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
  if (!data) {
    return 0;
  }
  return strlen(data);
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
  data = new char[length() + 2];
  if (oldData) {
    strcpy(data, oldData);
    delete[] oldData;
    oldData = nullptr;
  }
  data[length()] = c;
  data[length() + 1] = '\0';
}

/**
 * finds a spot on the heap with enough room for an old |jasonString| plus a
 * char array
 */
void jasonString::push_back(const char* str) {}