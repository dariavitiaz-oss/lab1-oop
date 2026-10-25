#pragma once
#include "Base.h"
#include <fstream>
#include <string>

class Keeper {
private:
    Base** items;   // динамический массив указателей
    int count;      // текущее количество
    int capacity;   // вместимость

    void resize();  // расширение массива

public:
    Keeper();
    Keeper(const Keeper& other) = delete; // запрет копирования
    ~Keeper();

    void add(Base* obj);
    void removeAt(int index);
    void printAll() const;

    int getCount() const { return count; }
    Base* getAt(int index) const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
