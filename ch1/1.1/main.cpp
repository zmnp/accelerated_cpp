/* 1-1. Are the following definitions valid? Why or why not? */

#include <string>

int main() {
  // copy initialization with a string literal
  const std::string hello = "Hello";

  // copy initialization with a concatenation of variable hello
  // and two string literals
  const std::string message = hello + ", world" + "!";

  return 0;
}
