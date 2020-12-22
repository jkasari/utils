#include <iostream>
#include "nuttiest/nuttiest.hpp"
#include "jasonString.h"

using namespace std;
using namespace nuttiest;

int main() {
  section("stringLength") {
    unit_test("empty string has a |length| of (0)") {
      jasonString jstr;
      assert_eq(0, jstr.length());
    }
    unit_test("\"ABC\" has a |length| of (3)") {
      jasonString jstr("ABC");
      assert_eq(3, jstr.length());
    }
    unit_test("\"ABCD\" has a |length| of (4)") {
      jasonString jstr("ABCD");
      assert_eq(4, jstr.length());
    }
  }
  section("push_back") {
    unit_test("\"\" push_back \'A\' gives \"A\"") {
      jasonString jstr("");
      jstr.push_back('A');
      mem_eq("A", jstr.inner(), strlen("A"));
    }
    unit_test("\"AB\" push_back \"C\" gives \"ABC\"") {
      jasonString jstr("AB");
      jstr.push_back('C');
      mem_eq("ABC", jstr.inner(), strlen("ABC"));
    }
    unit_test("\"AB\" push_back \'B\' gives you \"ABB\"") {
      jasonString jstr("AB");
      jstr.push_back('B');
      mem_eq("ABB", jstr.inner(), strlen("ABB"));
    }
  }
  section("push_back") {
    unit_test("\"AB\" push_back \"AB\" returns \"ABAB\"") {
      jasonString jstr("AB");
      jstr.push_back("AB");
      mem_eq("ABAB", jstr.inner(), strlen("ABAB"));
    }
  }


  summary();
}

