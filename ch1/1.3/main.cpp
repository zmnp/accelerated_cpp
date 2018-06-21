/* 1-3. Is the following program valid? If so, what does it do? If not, why not?
 */

#include <iostream>
#include <string>

// this program is valid. Function main creates one scope, inside it
// there are two separate scopes each of which contains variable s
// and prints it.
int main() {
  {
    // scope 1
    const std::string s = "a string";
    std::cout << s << std::endl;
    // variable s will destroy after closing brace here
  }

  {
    // scope 2
    const std::string s = "another string";
    std::cout << s << std::endl;
    // variable s will destroy after closing brace here
  }
  return 0;
}
