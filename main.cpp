#include <iostream>
#include "Student.h"

int main() {
    std::cout << "=== Student test ===\n";

    Student s1;
    s1.print();

    Student s2("Ivanov Ivan", "4141", "Software Engineering", 3, 4.5);
    s2.print();

    Student s3 = s2;
    s3.print();

    std::cout << "\n=== Exception test ===\n";
    try {
        Student bad("Test Test", "0000", "Test", 100, 10);
    }
    catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\n=== End of program ===\n";
    return 0;
}