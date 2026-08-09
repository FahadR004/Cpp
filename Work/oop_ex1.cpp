#include <iostream>

class Student{
    public:
        std::string name;   
        int age;

        void display() {
            std::cout << "My name is " << name << " and I am " << age << " years old" << std::endl; // endline
        }
};

int main() {
    Student s1;
    s1.name = "Fahad";
    s1.age = 21;
    s1.display();
    return 0;
}