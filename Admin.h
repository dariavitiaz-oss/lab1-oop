#pragma once
#include "Base.h"

class Admin : public Base {
private:
    std::string position;
    std::string phone;
    std::string responsibility;

public:
    Admin();
    Admin(const std::string& fio, const std::string& position,
        const std::string& phone, const std::string& responsibility);
    Admin(const Admin& other);
    ~Admin() override;

    void setPosition(const std::string& p);
    void setPhone(const std::string& p);
    void setResponsibility(const std::string& r);

    std::string getPosition() const;
    std::string getPhone() const;
    std::string getResponsibility() const;

    void print() const override;
    std::string getType() const override { return "Admin"; }
    std::string toFile() const override;
    void fromFile(std::istream& in) override;
};