#include <iostream>
#include "nuttiest/nuttiest.hpp"
#include "jasonString.h"

using namespace std;
using namespace nuttiest;

int main() {
  section("constructors") {
    unit_test("empty string has a |length| of (0)") {
      jasonString jstr;
      assert_eq(0, jstr.length());
    }
    unit_test("\"ABC\" has a |length| of (3)") {
      jasonString jstr("ABC");
      assert_eq(3, jstr.length());
      assert_eq("ABC", jstr);
    }
    unit_test("\"ABCD\" has a |length| of (4)") {
      jasonString jstr("ABCD");
      assert_eq(4, jstr.length());
      assert_eq("ABCD", jstr);
    }
  }
  section("push_back") {
    unit_test("\"\" push_back \'A\' gives \"A\"") {
      jasonString jstr;
      jstr.push_back('A');
      assert_eq(1, jstr.length());
      assert_eq("A", jstr);
    }
    unit_test("\"AB\" push_back \"C\" gives \"ABC\"") {
      jasonString jstr("AB");
      jstr.push_back('C');
      assert_eq(3, jstr.length());
      assert_eq("ABC", jstr);
    }
    unit_test("\"AB\" push_back \'B\' gives you \"ABB\"") {
      jasonString jstr("AB");
      jstr.push_back('B');
      assert_eq(3, jstr.length());
      assert_eq("ABB", jstr);
    }
  }
  section("push_back") {
    unit_test("\"\" push_back \"AB\" returns \"AB\"") {
      jasonString jstr;
      jstr.push_back("AB");
      assert_eq(2, jstr.length());
      assert_eq("AB", jstr);
    }
    unit_test("\"AB\" push_back \"AB\" returns \"ABAB\"") {
      jasonString jstr("AB");
      jstr.push_back("AB");
      assert_eq(4, jstr.length());
      assert_eq("ABAB", jstr);
    }
    unit_test("\"AB\" push_back \"\" returns \"AB\"") {
      jasonString jstr("AB");
      jstr.push_back("");
      assert_eq(2, jstr.length());
      assert_eq("AB", jstr);
    }
  }
  section("pop_back") {
    unit_test("\"ABAB\" pop_back returns \'B\' and \"ABA\"") {
      jasonString jstr("ABAB");
      assert_eq('B', jstr.pop_back());
      assert_eq("ABA", jstr);
      assert_eq(3, jstr.length());
    }
    unit_test("\"\" pop_back returns \'\0\' and \"\"") {
      jasonString jstr("");
      assert_eq('\0', jstr.pop_back());
      assert_eq(0, jstr.length());
    }
  }
  section("pop_back") {
    unit_test("\"ABC\" remove_first('B') returns \'B\' and \"AC\"") {
      jasonString jstr("ABC");
      assert_eq(true, jstr.remove_first('B'));
      assert_eq("AC", jstr);
      assert_eq(2, jstr.length());

      assert_eq(false, jstr.remove_first('B'));
      assert_eq("AC", jstr);
      assert_eq(2, jstr.length());
    }
    unit_test("\"ABCD\" remove_first('B') returns true and \"ACD\"") {
      jasonString jstr("ABCD");
      assert_eq(true, jstr.remove_first('B'));
      assert_eq("ACD", jstr);
      assert_eq(3, jstr.length());

      assert_eq(false, jstr.remove_first('B'));
      assert_eq("ACD", jstr);
      assert_eq(3, jstr.length());
    }
    unit_test("\"ABABA\" remove_first('A')") {
      jasonString jstr("ABABA");
      assert_eq(true, jstr.remove_first('A'));
      assert_eq("BABA", jstr);
      assert_eq(4, jstr.length());

      assert_eq(true, jstr.remove_first('A'));
      assert_eq("BBA", jstr);
      assert_eq(3, jstr.length());

      assert_eq(true, jstr.remove_first('A'));
      assert_eq("BB", jstr);
      assert_eq(2, jstr.length());

      assert_eq(false, jstr.remove_first('A'));
      assert_eq("BB", jstr);
      assert_eq(2, jstr.length());
    }
  }
  //section("remove_all") {
  //  unit_test("\"ABABA\" remove_all(A)") {
  //    jasonString jstr("ABABA");
  //    assert_eq(true, jstr.remove_all('A'));
  //    assert_eq("BB", jstr);
  //    assert_eq(2, jstr.length());

  //    assert_eq(false, jstr.remove_all('A'));
  //    assert_eq("BB", jstr);
  //    assert_eq(2, jstr.length());

  //  }
  //}
  summary();
}
