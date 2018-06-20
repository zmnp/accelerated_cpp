/* 0-7. What about this one? */

#include <iostream>

// This one won't compile because it has an error in multi-line comment.
// Multi-line comments can't be nested.
int main() {
  /* This is a comment that extends over several lines
     because it uses /* and */ as its starting and ending delimiters */
  std::cout << "Does this work?" << std::endl;
  return 0;
}
