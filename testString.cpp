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
  section("remove_first") {
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
  section("remove_all") {
    unit_test("\"ABABA\" remove_all(A)") {
      jasonString jstr("ABABA");
      assert_eq(true, jstr.remove_all('A'));
      assert_eq("BB", jstr);
      assert_eq(2, jstr.length());

      assert_eq(false, jstr.remove_all('A'));
      assert_eq("BB", jstr);
      assert_eq(2, jstr.length());
    }
  }
  section("remove_last") {
    unit_test("\"ABABA\" remove_last(A)") {
      jasonString jstr("ABABA");
      assert_eq(true, jstr.remove_last('A'));
      assert_eq("ABAB", jstr);
      assert_eq(4, jstr.length());

      assert_eq(true, jstr.remove_last('A'));
      assert_eq("ABB", jstr);
      assert_eq(3, jstr.length());

      assert_eq(true, jstr.remove_last('A'));
      assert_eq("BB", jstr);
      assert_eq(2, jstr.length());

      assert_eq(false, jstr.remove_last('A'));
      assert_eq("BB", jstr);
      assert_eq(2, jstr.length());
    }
  }
  section("contains") {
    unit_test("null jstr does not contain anything") {
      jasonString jstr;
      assert_eq(false, jstr.contains(nullptr));
      assert_eq(false, jstr.contains(""))
      assert_eq(false, jstr.contains("A"))
    }
    unit_test("\"\" contains") {
      jasonString jstr("");
      assert_eq(false, jstr.contains(nullptr));
      assert_eq(true, jstr.contains(""));
      assert_eq(false, jstr.contains("A"));
    }
    unit_test("\"A\" contains") {
      jasonString jstr("A");
      assert_eq(false, jstr.contains(nullptr));
      assert_eq(true, jstr.contains(""));
      assert_eq(true, jstr.contains("A"));
      assert_eq(false, jstr.contains("B"));
      assert_eq(false, jstr.contains("AA"));
      assert_eq(false, jstr.contains("ABBBA"));
    }
    unit_test("\"ACATANDADOG\" contains") {
      jasonString jstr("ACATANDADOG");
      assert_eq(true, jstr.contains(""));
      assert_eq(false, jstr.contains("B"));
      assert_eq(true, jstr.contains("A"));
      assert_eq(true, jstr.contains("C"));
      assert_eq(true, jstr.contains("CAT"));
      assert_eq(true, jstr.contains("DOG"));
      assert_eq(true, jstr.contains("AND"));
      assert_eq(false, jstr.contains("ANB"));
      assert_eq(false, jstr.contains("ACATANDADOC"));
    }
    unit_test("\"WWWCCATWWW\" contains") {
      jasonString jstr = "WWWCCATWWW";
      assert_eq(true, jstr.contains("CAT"));
    }
    unit_test("\"X-REY\" contains") {
      jasonString jstr = "X-REY";
      assert_eq(false, jstr.contains("XREY"));
    }
  }
  section("reverse") {
    unit_test("\"\" reversed is \"\"") {
      jasonString jstr = "";
      jstr.reverse();
      assert_eq("", jstr);
    }
    unit_test("\"A\" reversed is \"A\"") {
      jasonString jstr = "A";
      jstr.reverse();
      assert_eq("A", jstr);
    }
    unit_test("\"BAB\" reversed is \"BAB\"") {
      jasonString jstr = "BAB";
      jstr.reverse();
      assert_eq("BAB", jstr);
    }
    unit_test("\"BA\" reversed is \"AB\"") {
      jasonString jstr = "BA";
      jstr.reverse();
      assert_eq("AB", jstr);
    }
    unit_test("\"BAA\" reversed is \"AAB\"") {
      jasonString jstr = "BAA";
      jstr.reverse();
      assert_eq("AAB", jstr);
    }
    unit_test("\"BURGER\" reversed is \"REGRUB\"") {
      jasonString jstr = "BURGER";
      jstr.reverse();
      assert_eq("REGRUB", jstr);
    }
    unit_test("\"BURGER1\" reversed is \"1REGRUB\"") {
      jasonString jstr = "BURGER1";
      jstr.reverse();
      assert_eq("1REGRUB", jstr);
    }
  }
  summary();
}


