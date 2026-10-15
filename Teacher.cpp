#include "Teacher.h"

Teacher::Teacher() : Base(), groups(""), subjects("") {
    std::cout << "[Teacher] Default constructor\n";
}

Teacher::Teacher(const std::string& fio, const std::string& groups, const std::string& subjects)
    : Base(fio), groups(groups), subjects(subjects) {
    std::cout << "[Teacher] Constructor with parameters\n";
}

Teacher::Teacher(const Teacher& other)
    : Base(other), groups(other.groups), subjects(other.subjects) {
    std::cout << "[Teacher] Copy constructor\n";
}

Teacher::~Teacher() {
    std::cout << "[Teacher] Destructor for " << fio << "\n";
}

void Teacher::setGroups(const std::string& g) { groups = g; }
void Teacher::setSubjects(const std::string& s) { subjects = s; }
std::string Teacher::getGroups() const { return groups; }
std::string Teacher::getSubjects() const { return subjects; }

void Teacher::print() const {
    std::cout << "=== Teacher ===\n"
        << "FIO: " << fio << "\n"
        << "Groups: " << groups << "\n"
        << "Subjects: " << subjects << "\n";
}

std::string Teacher::toFile() const {
    return "Teacher\n" + fio + "\n" + groups + "\n" + subjects + "\n";
}

void Teacher::fromFile(std::istream& in) {
    std::getline(in, fio);
    std::getline(in, groups);
    std::getline(in, subjects);
}