/* 3-5. Write a program that will keep track of grades for several students at
 * once. The program could keep two vectors in sync. The first should hold the
 * student’s names, and the second the final grades that can be computed
 * as input is read. For now, you should assume a fixed number of homework
 * grades. We’ll see in 4.1.3/56 how to handle a variable number of grades
 * intermixed with student names.
 */

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

int main() {

  std::vector<std::string> names;   // students' names
  std::vector<double> final_grades; // students' final grades

  std::cout << "Please enter your first name: ";
  std::string name;

  while (std::cin >> name) {

    names.push_back(name);

    std::cout << "Please enter your midterm and final exam grades: ";
    double midterm_grade, final_grade;
    std::cin >> midterm_grade >> final_grade;

    std::cout << "Enter the number of homework grades: ";
    int hw_grades_num;
    std::cin >> hw_grades_num;

    // check that the student entered some homework grades
    if (hw_grades_num == 0) {
      std::cout << std::endl
                << "You must enter your grades. "
                   "Please try again."
                << std::endl;
      return 1;
    }
    std::cout << "Enter your homework grades: ";

    std::vector<double> homework;
    double x;

    for (int i = 0; i < hw_grades_num; ++i) {
      std::cin >> x;
      homework.push_back(x);
    }

    std::sort(homework.begin(), homework.end());

    // compute the median homework grade
    std::size_t size = homework.size();
    std::size_t mid = size / 2;
    double median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2.0
                                  : homework[mid];

    // compute and save the final grade
    final_grades.push_back(0.2 * midterm_grade + 0.4 * final_grade +
                           0.4 * median);

    std::cout << "Please enter your first name: ";
  }
  std::cout << std::endl;
  for (std::size_t i = 0; i < names.size(); ++i) {
    std::streamsize prec = std::cout.precision();
    std::cout << names[i] << ", final grade: " << std::setprecision(3)
              << final_grades[i] << std::setprecision(prec) << std::endl;
  }
  return 0;
}
