#include "Keeper.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"
#include <iostream>
#include <stdexcept>

Keeper::Keeper() : items(nullptr), count(0), capacity(2) {
    items = new Base * [capacity];
    std::cout << "[Keeper] Default constructor\n";
}

Keeper::~Keeper() {
    for (int i = 0; i < count; ++i) delete items[i];
    delete[] items;
    std::cout << "[Keeper] Destructor\n";
}

void Keeper::resize() {
    capacity *= 2;
    Base** newItems = new Base * [capacity];
    for (int i = 0; i < count; ++i) newItems[i] = items[i];
    delete[] items;
    items = newItems;
}

void Keeper::add(Base* obj) {
    if (obj == nullptr) throw std::invalid_argument("Cannot add null object");
    if (count >= capacity) resize();
    items[count++] = obj;
}

void Keeper::removeAt(int index) {
    if (index < 0 || index >= count)
        throw std::out_of_range("Invalid index for removal");
    delete items[index];
    for (int i = index; i < count - 1; ++i) items[i] = items[i + 1];
    --count;
}

void Keeper::printAll() const {
    if (count == 0) { std::cout << "List is empty.\n"; return; }
    for (int i = 0; i < count; ++i) {
        std::cout << "\n[" << i << "] ";
        items[i]->print();
    }
}

Base* Keeper::getAt(int index) const {
    if (index < 0 || index >= count)
        throw std::out_of_range("Invalid index");
    return items[index];
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) throw std::runtime_error("Cannot open file for writing");
    out << count << "\n";
    for (int i = 0; i < count; ++i) out << items[i]->toFile();
    out.close();
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) throw std::runtime_error("Cannot open file for reading");

    // очистить текущий список
    for (int i = 0; i < count; ++i) delete items[i];
    count = 0;

    int n;
    in >> n;
    in.ignore(); // пропустить \n

    for (int i = 0; i < n; ++i) {
        std::string type;
        std::getline(in, type);

        Base* obj = nullptr;
        if (type == "Student") obj = new Student();
        else if (type == "Teacher") obj = new Teacher();
        else if (type == "Admin") obj = new Admin();
        else throw std::runtime_error("Unknown type in file: " + type);

        obj->fromFile(in);
        add(obj);
    }
    in.close();
}