#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>

class STUDENT {
private:
    std::string name;      // фамилия и инициалы
    int groupNumber;       // номер группы
    std::vector<int> grades; // успеваемость

public:
    STUDENT(std::string n, int group, const std::vector<int>& g);

    std::string getName() const;
    int getGroupNumber() const;
    std::vector<int> getGrades() const;
    double getAverageGrade() const;

    bool operator<(const STUDENT& other) const;

    friend std::ostream& operator<<(std::ostream& os, const STUDENT& student);
};

#endif // STUDENT_H
