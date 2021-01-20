#include "jasonString.h"
#include <algorithm>

jasonString& jasonString::operator=(const jasonString& other) {
  if (this == &other) {
    return *this;
  }
  if(data) {
    delete[] data;
    data = nullptr;
  }
  if(other.data) {
    allocate(other.capacity);
    strcpy(data, other.data);
  }
  slen = other.slen;
  capacity = other.capacity;
  return *this;
}

jasonString::jasonString(const char* str) {
  if (!str) {
    return;
  }
  slen = strlen(str);
  capacity = std::max(size_t(10), slen * 2);
  allocate(capacity);
  strcpy(data, str);
}

jasonString::jasonString(const jasonString& other) {
  if (!other.data) {
    return;
  }
  capacity = other.capacity;
  slen = other.slen;
  allocate(capacity);
  strcpy(data, other.data);
}

jasonString::~jasonString() {
  if (data) {
    delete[] data;
    data = nullptr;
  }
}

size_t jasonString::length() const { return slen; }

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

void jasonString::push_back(const char c) {
  if(slen + 1 >= capacity) {
    char* oldData = data;
    capacity *= 2;
    allocate(capacity);
    if(oldData) {
      strcpy(data, oldData);
    }
  }
  data[slen] = c;
  data[slen + 1] = '\0';
  slen += 1;
}

void jasonString::push_back(const char* str) {
  if (!str) {
    return;
  }
  slen += strlen(str);
  if(slen > capacity) {
    if(capacity == 0) {
      capacity = 10;
    }
    while(capacity < slen) {
      capacity *= 2;
    }
    const char* oldData = data;
    allocate(capacity);
    if (oldData) {
      strcpy(data, oldData);
      delete[] oldData;
      oldData = nullptr;
    }
  }
  strcat(data, str);
}

const char jasonString::pop_back() {
  if (slen == 0) {
    return '\0';
  }
  const char poppedBackChar = data[slen - 1];
  data[slen - 1] = '\0';
  --slen;
  return poppedBackChar;
}

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

bool jasonString::remove_all(const char toRemove) {
  if (!remove_last(toRemove)) {
    return false;
  }
  while (remove_last(toRemove)) {
  }
  return true;
}

void jasonString::allocate(size_t capacity) {
  data = new char[capacity + 1];
  data[0] = '\0';
}

bool jasonString::contains(const char* str) {
  if (!data || !str) {
    return false;
  }

  int lenOfStr = strlen(str);
  if (lenOfStr > slen) {
    return false;
  }

  if (lenOfStr == 0) {
    return true;
  }

  for (const char* s = data; *s != '\0'; ++s) {
    if (strncmp(s, str, lenOfStr) == 0) {
      return true;
    }
  }

  return false;
}

void jasonString::reverse() {
  if (!data) {
    return;
  }
  for (int i = 0, j = (slen - 1); i < j; ++i, --j) {
    std::swap(data[i], data[j]);
  }
}