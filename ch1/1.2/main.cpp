/* 1-2. Are the following definitions valid? Why or why not? */

#include <string>

int main() {
  const std::string exclam = "!"; // copy initialization, this is valid

  // this is not a valid definition because "Hello" and ", world" are two string
  // literals and + operator is left-associative, so one of its operands
  // must be a string object
  const std::string message1 = "Hello" + ", world" + exclam;
  return 0;
}
