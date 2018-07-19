/* 4-0. Compile, execute, and test the programs in this chapter. */

#include "Student_info.h"
#include "grade.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main() {

  std::vector<Student_info> students;
  Student_info record;
  std::string::size_type maxlen = 0; // the length of the longest name

  // read and store all the records, and find the length of the longest name
  // read and store all the students data.
  // Invariant:
  //           students contains all the student records read so far
  //           maxlen contains the length of the longest name in students
  while (read(std::cin, record)) {
    // find length of the longest name
    maxlen = std::max(maxlen, record.name.size());
    students.push_back(record);
  }

  // alphabetize the records
  std::sort(students.begin(), students.end(), compare);

  // write names and grades
  for (std::vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
    // write the name, padded on the right to maxlen + 1 characters
    std::cout << students[i].name
              << std::string(maxlen + 1 - students[i].name.size(), ' ');

    // compute and write the grade
    try {
      double final_grade = grade(students[i]);
      std::streamsize prec = std::cout.precision();
      std::cout << std::setprecision(3) << final_grade
                << std::setprecision(prec);

    } catch (std::domain_error &e) {
      std::cout << e.what();
    }
    std::cout << std::endl;
  }
  return 0;
}
