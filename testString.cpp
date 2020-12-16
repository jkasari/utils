#include <iostream>
#include "nuttiest/nuttiest.hpp"
#include "jasonString.h"

using namespace std;
using namespace nuttiest;

int main() {
  section("stringLength") {
    unit_test("empty string has a length of (0)") {
      jasonString jstr;
      assert_eq(0, jstr.length());
    }
  }

  summary();
}

