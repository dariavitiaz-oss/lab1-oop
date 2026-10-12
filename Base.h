#pragma once
#include <string>
#include <iostream>

class Base {
protected:
    std::string fio;

public:
    Base();
    Base(const std::string& fio);
    Base(const Base& other);
    virtual ~Base();

    void setFio(const std::string& fio);
    std::string getFio() const;

    virtual void print() const = 0;
    virtual std::string getType() const = 0;
    virtual std::string toFile() const = 0;
    virtual void fromFile(std::istream& in) = 0;
};