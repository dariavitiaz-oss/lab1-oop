#pragma once
#include "Base.h"

class Student : public Base {
private:
    std::string group;
    std::string specialty;
    int course;
    double averageGrade;

public:
    Student();
    Student(const std::string& fio, const std::string& group,
        const std::string& specialty, int course, double avg);
    Student(const Student& other);
    ~Student() override;

    void setGroup(const std::string& g);
    void setSpecialty(const std::string& s);
    void setCourse(int c);
    void setAverageGrade(double a);

    std::string getGroup() const;
    std::string getSpecialty() const;
    int getCourse() const;
    double getAverageGrade() const;

    void print() const override;
    std::string getType() const override { return "Student"; }
    std::string toFile() const override;
    void fromFile(std::istream& in) override;
};