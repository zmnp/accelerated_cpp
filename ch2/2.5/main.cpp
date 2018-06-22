/* 2-5. Write a set of "*" characters so that they form a square, a rectangle,
 * and a triangle.
 */

#include <iostream>
#include <string>

using std::cout;

int main() {
  // print a square
  const int slen = 10; // square length
  const std::string srow(slen, '*');

  cout << "Square {a = " << slen << "}" << std::endl;

  for (int i = 0; i < slen; ++i)
    cout << srow << std::endl;

  cout << std::endl;

  // print a rectangle
  const int rw = 4; // rectangle width
  const int rh = 7; // rectangle height
  const std::string rrow(rw, '*');

  cout << "Rectangle {a = " << rh << ", b = " << rw << "}" << std::endl;

  for (int i = 0; i < rh; ++i)
    cout << rrow << std::endl;

  cout << std::endl;

  // print a triangle
  const int th = 10;         // triangle height
  const int tb = th * 2 - 1; // triangle base

  cout << "Triangle {h = " << th << ", base = " << tb << "}" << std::endl;
  // we print stars in the range [from, to]
  // we print ' ' in the range [0, from) and (to, tb)
  for (int r = 0, from = tb / 2, to = tb / 2; r < th; ++r, --from, ++to) {
    for (int c = 0; c < tb; ++c) {
      if (c >= from && c <= to) {
        cout << '*';
      } else {
        cout << ' ';
      }
    }
    cout << std::endl;
  }

  return 0;
}
