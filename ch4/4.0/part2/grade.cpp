// source file grade functions

#include "grade.h"
#include "Student_info.h"
#include "median.h"
#include <stdexcept>
#include <vector>

// compute a student's overall grade from midterm and final exam grades and
// homework grade
double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const std::vector<double> &hw) {
  if (hw.size() == 0)
    throw std::domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

// compute a student's overall grade
double grade(const Student_info &s) {
  return grade(s.midterm, s.final, s.homework);
}
