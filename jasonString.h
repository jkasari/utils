#ifndef JASON_STRING_H
#define JASON_STRING_H
#include <iostream>

class jasonString {
  /**
   * tells |ostream| how to display a |jasonString|
   */
  friend std::ostream& operator<<(std::ostream& stream,
                                  const jasonString& jstr);
  /**
   * Tells the == operator to read a jasonString as a char*.
   */
  friend bool operator==(const char* str, const jasonString& jstr);
  friend bool operator==(const jasonString& jstr, const char* str);

 public:
  /**
   * Lets the caller use the = operator between jasonStrings.
   */
  jasonString& operator=(const jasonString&);
  jasonString() {}
  /**
   * allocates a space on the heap for a |jasonString| to occupy
   */
  jasonString(const char*);
  /**
   * Lets the caller create a new jasonString using a previous jasonString.
   */
  jasonString(const jasonString&);
  /**
   * deletes the |jasonString| off of the heap
   */
  ~jasonString();
  /**
   * returns the length of a |jasonString|
   */
  size_t length() const;
  /**
   * finds a spot on the heap with enough room for an old |jasonString| plus one
   * additional char
   */
  void push_back(const char);
  /**
   * finds a spot on the heap with enough room for an old |jasonString| plus a
   * char array
   */
  void push_back(const char*);
  /**
   * Removes the last char in a jasonString.
   */
  const char pop_back();
  /**
   * removes the first instance of |toRemove| out of a jasonString
   * returns true if |toRemove| was found and removed otherwise false
   */
  bool remove_first(const char);
  /**
   * Removes the last instance of |toRemove| out of a jasonString
   * returns ture if |toRemove| was found an removed otherwise false.
   */
  bool remove_last(const char);
  /**
   * removes all instances of |toRemove| out of a jasonString
   * returns true if |toRemove| was found and removed outherwise false
   */
  bool remove_all(const char);
  /**
   * allocates a new spot on the heap for a jasonString
   */
  bool contains(const char*);
  /**
   * takes a jasonString and reverses it
   */
  void reverse();

 private:
  void allocate(size_t length);
  /**
   * helper function that shifts all the characters in a jasonString over one
   * from a specific index
   */
  void removeAt(size_t index);
  char* data = nullptr;
  size_t capacity = 0;
  size_t slen = 0;
};

#endif  // JASON_STRING_H