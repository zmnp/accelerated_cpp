/* 1-4. What about this one? What if we change }} to };} in the third line from
 * the end?
 */

#include <iostream>
#include <string>

// this program compiles and works fine
int main() { // main function scope begins

  { // outer scope1 begins here

    const std::string s = "a string"; // we create variable s
    std::cout << s << std::endl;      // prints "a string" string here

    { // inner scope2 begins here
      // this scope is created inside scope1 and

      // this variable s shadows previously created varible with the same name
      // g++ compiler option -Wshadow to warn about this
      const std::string s = "another string";

      std::cout << s << std::endl; // prints "another string" string here

    }; // inner scope2 ends here. We can add semicolon here, it's just an empty
       // statement. Doesn't make any sense but there's no error adding it here

  } // outer scope1 ends here

  return 0;
} // main function scope ends
