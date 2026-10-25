#include <iostream>
#include <limits>
#include <string>
#include "Keeper.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string inputString(const std::string& prompt) {
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    return s;
}

int inputInt(const std::string& prompt) {
    int x;
    std::cout << prompt;
    while (!(std::cin >> x)) {
        std::cout << "Input error. Try again: ";
        clearInput();
    }
    clearInput();
    return x;
}

double inputDouble(const std::string& prompt) {
    double x;
    std::cout << prompt;
    while (!(std::cin >> x)) {
        std::cout << "Input error. Try again: ";
        clearInput();
    }
    clearInput();
    return x;
}

void addStudent(Keeper& k) {
    std::string fio = inputString("FIO: ");
    std::string group = inputString("Group: ");
    std::string spec = inputString("Specialty: ");
    int course = inputInt("Course (1-6): ");
    double avg = inputDouble("Average grade (0-5): ");
    k.add(new Student(fio, group, spec, course, avg));
    std::cout << "Student added.\n";
}

void addTeacher(Keeper& k) {
    std::string fio = inputString("FIO: ");
    std::string groups = inputString("Groups (comma separated): ");
    std::string subjects = inputString("Subjects (comma separated): ");
    k.add(new Teacher(fio, groups, subjects));
    std::cout << "Teacher added.\n";
}

void addAdmin(Keeper& k) {
    std::string fio = inputString("FIO: ");
    std::string pos = inputString("Position: ");
    std::string phone = inputString("Phone: ");
    std::string resp = inputString("Responsibility: ");
    k.add(new Admin(fio, pos, phone, resp));
    std::cout << "Admin added.\n";
}

void editItem(Keeper& k) {
    k.printAll();
    if (k.getCount() == 0) return;
    int idx = inputInt("Enter index to edit: ");
    try {
        Base* obj = k.getAt(idx);
        std::string type = obj->getType();
        if (type == "Student") {
            Student* s = dynamic_cast<Student*>(obj);
            s->setFio(inputString("New FIO: "));
            s->setGroup(inputString("New group: "));
            s->setSpecialty(inputString("New specialty: "));
            s->setCourse(inputInt("New course: "));
            s->setAverageGrade(inputDouble("New average grade: "));
        }
        else if (type == "Teacher") {
            Teacher* t = dynamic_cast<Teacher*>(obj);
            t->setFio(inputString("New FIO: "));
            t->setGroups(inputString("New groups: "));
            t->setSubjects(inputString("New subjects: "));
        }
        else if (type == "Admin") {
            Admin* a = dynamic_cast<Admin*>(obj);
            a->setFio(inputString("New FIO: "));
            a->setPosition(inputString("New position: "));
            a->setPhone(inputString("New phone: "));
            a->setResponsibility(inputString("New responsibility: "));
        }
        std::cout << "Edited.\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

int main() {
    Keeper keeper;
    int choice = -1;

    while (choice != 0) {
        std::cout << "\n===== MENU =====\n"
            << "1. Add student\n"
            << "2. Add teacher\n"
            << "3. Add admin\n"
            << "4. Show all\n"
            << "5. Edit record\n"
            << "6. Delete record\n"
            << "7. Save to file\n"
            << "8. Load from file\n"
            << "0. Exit\n"
            << "Choice: ";
        std::cin >> choice;
        clearInput();

        try {
            switch (choice) {
            case 1: addStudent(keeper); break;
            case 2: addTeacher(keeper); break;
            case 3: addAdmin(keeper); break;
            case 4: keeper.printAll(); break;
            case 5: editItem(keeper); break;
            case 6: {
                keeper.printAll();
                if (keeper.getCount() == 0) break;
                int idx = inputInt("Index to delete: ");
                keeper.removeAt(idx);
                std::cout << "Deleted.\n";
                break;
            }
            case 7: keeper.saveToFile("data.txt");
                std::cout << "Saved to data.txt\n"; break;
            case 8: keeper.loadFromFile("data.txt");
                std::cout << "Loaded.\n"; break;
            case 0: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid option.\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << "\n";
        }
    }
    return 0;
}