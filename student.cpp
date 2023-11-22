#include "student.h"
#include <algorithm>

STUDENT::STUDENT(std::string n, int group, const std::vector<int>& g)
    : name(std::move(n)), groupNumber(group), grades(g) {}

std::string STUDENT::getName() const {
    return name;
}

int STUDENT::getGroupNumber() const {
    return groupNumber;
}

std::vector<int> STUDENT::getGrades() const {
    return grades;
}

double STUDENT::getAverageGrade() const {
    if (grades.empty()) {
        return 0.0;
    }

    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }

    return static_cast<double>(sum) / grades.size();
}

bool STUDENT::operator<(const STUDENT& other) const {
    return getAverageGrade() < other.getAverageGrade();
}

std::ostream& operator<<(std::ostream& os, const STUDENT& student) {
    os << "Name: " << student.name << ", Group: " << student.groupNumber << ", Grades: ";
    for (int grade : student.grades) {
        os << grade << " ";
    }
    return os;
}
