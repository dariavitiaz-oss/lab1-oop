#include "Admin.h"

Admin::Admin() : Base(), position(""), phone(""), responsibility("") {
    std::cout << "[Admin] Default constructor\n";
}

Admin::Admin(const std::string& fio, const std::string& position,
    const std::string& phone, const std::string& responsibility)
    : Base(fio), position(position), phone(phone), responsibility(responsibility) {
    std::cout << "[Admin] Constructor with parameters\n";
}

Admin::Admin(const Admin& other)
    : Base(other), position(other.position), phone(other.phone),
    responsibility(other.responsibility) {
    std::cout << "[Admin] Copy constructor\n";
}

Admin::~Admin() {
    std::cout << "[Admin] Destructor for " << fio << "\n";
}

void Admin::setPosition(const std::string& p) { position = p; }
void Admin::setPhone(const std::string& p) { phone = p; }
void Admin::setResponsibility(const std::string& r) { responsibility = r; }

std::string Admin::getPosition() const { return position; }
std::string Admin::getPhone() const { return phone; }
std::string Admin::getResponsibility() const { return responsibility; }

void Admin::print() const {
    std::cout << "=== Admin ===\n"
        << "FIO: " << fio << "\n"
        << "Position: " << position << "\n"
        << "Phone: " << phone << "\n"
        << "Responsibility: " << responsibility << "\n";
}

std::string Admin::toFile() const {
    return "Admin\n" + fio + "\n" + position + "\n" + phone + "\n"
        + responsibility + "\n";
}

void Admin::fromFile(std::istream& in) {
    std::getline(in, fio);
    std::getline(in, position);
    std::getline(in, phone);
    std::getline(in, responsibility);
}