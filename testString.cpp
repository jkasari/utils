#include <iostream>
#include "nuttiest/nuttiest.hpp"
#include "jasonString.h"

using namespace std;
using namespace nuttiest;

int main() {
  section("test") {
    unit_test("testCase") {
      assert_eq(true, false);
    }
  }

  summary();
}

