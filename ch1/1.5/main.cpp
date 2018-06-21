/* 1-5. Is this program valid? If so, what does it do? If not, say why not,
 * and rewrite it to be valid.
 */

#include <iostream>
#include <string>

// this program won't compile. To fix it we need to delete inner scope2 opening
// and closing braces. Or we can create another variable x of
// type std::string inside scope1.
int main() { // main scope begins
  {          // outer scope1 begins

    std::string s = "a string"; // create variable s

    { // inner scope2 begins

      std::string x = s + ", really"; // create varible x
      std::cout << s << std::endl;    // print variable s from outer scope1

    } // inner scope2 ends, variable x is destroyed here

    std::cout << x << std::endl; // error is here. There's no
                                 // variable x in scope1 because
                                 // it was created and destroyed in scope2.
  }
  return 0;
} // main scope ends
