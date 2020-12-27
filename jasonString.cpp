#include "jasonString.h"

/**
 * allocates a space on the heap for a |jasonString| to occupy
 */
jasonString::jasonString(const char* str) {
  if (!str) {
    return;
  }
  slen = strlen(str);
  allocate(slen);
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
size_t jasonString::length() const { return slen; }

/**
 * tells |ostream| how to display a |jasonString|
 */
std::ostream& operator<<(std::ostream& stream, const jasonString& jstr) {
  return stream << jstr.data;
}

bool operator==(const char* str, const jasonString& jstr) {
  if (!str || !jstr.data) {
    return false;
  }
  return !strcmp(str, jstr.data);
}

bool operator==(const jasonString& jstr, const char* str) {
  return str == jstr;
}

/**
 * finds a spot on the heap with enough room for an old |jasonString| plus one
 * additional char
 */
void jasonString::push_back(const char c) {
  const char* oldData = data;
  allocate(slen + 1);
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
  size_t strLength = strlen(str);
  const char* oldData = data;
  allocate(slen + strLength);
  if (oldData) {
    strcpy(data, oldData);
    delete[] oldData;
    oldData = nullptr;
  }
  strcat(data, str);
  slen += strLength;
}

// To Do
// Add pop_back method, takes the char at the end of the jasonString and returns
// it. The string continues on without the previous ending char. Example "ABAB"
// pop_back gives you 'B'. while the string changes to "ABA"

const char jasonString::pop_back() {
  if (slen == 0) {
    return '\0';
  }
  const char poppedBackChar = data[slen - 1];
  data[slen - 1] = '\0';
  --slen;
  return poppedBackChar;
}

/**
 * helper function that shifts all the characters in a jasonString over one from
 * a specific index
 */
void jasonString::removeAt(size_t index) {
  if (!data) {
    return;
  }
  if (index >= slen) {
    return;
  }
  for (; index < slen; ++index) {
    data[index] = data[index + 1];
  }
  --slen;
}

/**
 * removes the first instance of |toRemove| out of a jasonString
 * returns true if |toRemove| was found and removed otherwise false
 */
bool jasonString::remove_first(const char toRemove) {
  for (int i = 0; i < slen; ++i) {
    if (toRemove == data[i]) {
      removeAt(i);
      return true;
    }
  }
  return false;
}

bool jasonString::remove_last(const char toRemove) {
  for (int i = (slen - 1); i >= 0; --i) {
    if (toRemove == data[i]) {
      removeAt(i);
      return true;
    }
  }
  return false;
}

/**
 * removes all instances of |toRemove| out of a jasonString
 * returns true if |toRemove| was found and removed outherwise false
 */
bool jasonString::remove_all(const char toRemove) {
  if (!remove_last(toRemove)) {
    return false;
  }
  while (remove_last(toRemove)) {}
  return true;
}

void jasonString::allocate(size_t length) {
  data = new char[length + 1];
  data[0] = '\0';
}



/**
 * add |remove_last| this removes the last character in a jasonString
 * optimize |remove_all| to use |remove_last|
 * add a bool string search function |contains|
 * add |reverse_function|
 */