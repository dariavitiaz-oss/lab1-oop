#include "Student.h"
#include <stdexcept>

Student::Student() : Base(), group(""), specialty(""), course(1), averageGrade(0.0) {
    std::cout << "[Student] Default constructor\n";
}

Student::Student(const std::string& fio, const std::string& group,
    const std::string& specialty, int course, double avg)
    : Base(fio), group(group), specialty(specialty), course(course), averageGrade(avg) {
    if (course < 1 || course > 6)
        throw std::invalid_argument("Course must be between 1 and 6");
    if (avg < 0 || avg > 5)
        throw std::invalid_argument("Average grade must be between 0 and 5");
    std::cout << "[Student] Constructor with parameters\n";
}

Student::Student(const Student& other)
    : Base(other), group(other.group), specialty(other.specialty),
    course(other.course), averageGrade(other.averageGrade) {
    std::cout << "[Student] Copy constructor\n";
}

Student::~Student() {
    std::cout << "[Student] Destructor for " << fio << "\n";
}

void Student::setGroup(const std::string& g) { group = g; }
void Student::setSpecialty(const std::string& s) { specialty = s; }
void Student::setCourse(int c) {
    if (c < 1 || c > 6) throw std::invalid_argument("Course must be between 1 and 6");
    course = c;
}
void Student::setAverageGrade(double a) {
    if (a < 0 || a > 5) throw std::invalid_argument("Average grade must be between 0 and 5");
    averageGrade = a;
}

std::string Student::getGroup() const { return group; }
std::string Student::getSpecialty() const { return specialty; }
int Student::getCourse() const { return course; }
double Student::getAverageGrade() const { return averageGrade; }

void Student::print() const {
    std::cout << "=== Student ===\n"
        << "FIO: " << fio << "\n"
        << "Group: " << group << "\n"
        << "Specialty: " << specialty << "\n"
        << "Course: " << course << "\n"
        << "Average grade: " << averageGrade << "\n";
}

std::string Student::toFile() const {
    return "Student\n" + fio + "\n" + group + "\n" + specialty + "\n"
        + std::to_string(course) + "\n" + std::to_string(averageGrade) + "\n";
}

void Student::fromFile(std::istream& in) {
    std::getline(in, fio);
    std::getline(in, group);
    std::getline(in, specialty);
    in >> course >> averageGrade;
    in.ignore();
}