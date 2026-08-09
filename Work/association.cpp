#include <iostream>

class Teacher {
    public:
        void teach() {
            std::cout << "TEACHING" << std::endl;
        }
};

class Student {
    private:
        int *marks;
    public: 
        Student() {
            marks = new int[100];
        }
        ~Student() {
            delete[] marks;
        }
        void study(Teacher t) {
            t.teach();
        }
};

// Calling object in association
int main() {
    Teacher t;
    Student s;
    s.study(t);
}