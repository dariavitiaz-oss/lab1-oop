#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"

int main() {
    std::cout << "=== Student test ===\n";
    Student s1("Ivanov Ivan", "4141", "Software Engineering", 3, 4.5);
    s1.print();

    std::cout << "\n=== Teacher test ===\n";
    Teacher t1("Petrov Petr", "4141, 4142", "Math, Physics");
    t1.print();

    std::cout << "\n=== Admin test ===\n";
    Admin a1("Sidorova Anna", "Dean", "+7-900-123-45-67", "Faculty of IT");
    a1.print();

    std::cout << "\n=== Copy constructor test ===\n";
    Teacher t2 = t1;
    t2.print();

    std::cout << "\n=== End of program ===\n";
    return 0;
}