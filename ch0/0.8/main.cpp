/* 0-8. ... and this one? */

// this programs compiles and works because single-line comments
// can contain multi-line comments or can be nested.
#include <iostream>
int main() {
  // this is a comment that extends over several lines
  // by using // at the beginning of each line instead of using /*
  // or */ to delimit comments.
  std::cout << "Does this work?" << std::endl;
  return 0;
}
