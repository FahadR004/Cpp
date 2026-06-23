#include <iostream>

struct student { // student is like data type
    // variables declared are called members
    std::string name;
    double gpa;
    bool enrolled = true; // default value
};

// Passing by value
// void printStruct(student student);

// Passing by reference
void printStruct(student &student);

int main() {
    // struct groups related varaibles in a data structure
    student student1;
    student1.name = "Fahad";
    student1.gpa = 3.6;
    student1.enrolled = true;

    std::cout << student1.name << "\n";

    // printStruct(student1); // Passing by value
}

// Passing by value
// void printStruct(student student) { 
//     std::cout << student.name << '\n';
// }

// Passing by reference
void printStruct(student &student) { // Passing by reference
    std::cout << student.name << '\n';
}