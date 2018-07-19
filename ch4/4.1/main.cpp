/* 4-1. We noted in 4.2.3 that it is essential that the argument types in a call
 * to max match exactly. Will the following code work? If there is a problem,
 * how would you fix it?
 * int maxlen;
 * Student_info s;
 * max(s.name.size(), maxlen);
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

struct Student_info {
  std::string name;
  double midterm;
  double final;
  std::vector<double> homework;
};

int main() {
  int maxlen = 10;
  Student_info s;
  s.name = "abc";
  // std::max(s.name.size(), maxlen);
  // mismatched types: maxlen is signed type and s.name.size() is unsigned
  // so make maxlen variable unsigned or cast it to unsigned type to fix this
  // error

  std::size_t maxlen2 = 10;
  std::max(s.name.size(), maxlen2);

  return 0;
}
