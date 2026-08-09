#include <iostream>

class Teacher {
    public:
    Teacher() {
        std::cout << "Teacher created." << std::endl;
    }
};

class Department {
    private: 
        Teacher * teacher;
    public: 
        Department(Teacher* t) {
            teacher = t;
        }

};

// Passing in object in aggregation
int main() {
    Teacher t;
    Department d(&t);
}
