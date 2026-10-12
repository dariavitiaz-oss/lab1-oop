#include "Base.h"

Base::Base() : fio("Unknown") {
    std::cout << "[Base] Default constructor\n";
}

Base::Base(const std::string& fio) : fio(fio) {
    std::cout << "[Base] Constructor with parameters\n";
}

Base::Base(const Base& other) : fio(other.fio) {
    std::cout << "[Base] Copy constructor\n";
}

Base::~Base() {
    std::cout << "[Base] Destructor for " << fio << "\n";
}

void Base::setFio(const std::string& f) { fio = f; }
std::string Base::getFio() const { return fio; }