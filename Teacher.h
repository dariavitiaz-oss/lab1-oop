#pragma once
#include "Base.h"

class Teacher : public Base {
private:
    std::string groups;
    std::string subjects;

public:
    Teacher();
    Teacher(const std::string& fio, const std::string& groups, const std::string& subjects);
    Teacher(const Teacher& other);
    ~Teacher() override;

    void setGroups(const std::string& g);
    void setSubjects(const std::string& s);

    std::string getGroups() const;
    std::string getSubjects() const;

    void print() const override;
    std::string getType() const override { return "Teacher"; }
    std::string toFile() const override;
    void fromFile(std::istream& in) override;
};
