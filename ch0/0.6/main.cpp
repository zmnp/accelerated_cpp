/* 0-6. Is this a valid program? Why or why not? */

// This program is valid because outermost opening and closing
// braces define body of main function and all other pairs of braces
// just create new scope. So the innermost pair of braces which contains
// std::cout << .... ; statement executes in this last created scope.
#include <iostream>
int main() {{{{{{ std::cout << "Hello, world!" << std::endl; }}}}}}
