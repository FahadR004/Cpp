#include <iostream>

class Animal {
    public: 
        void sound() {
            std::cout << "Animal makes sound" << std::endl;
        }
    protected: 
        void eat() {
            std::cout << "Eating food" << std::endl;
        }
};

class Dog: public Animal {
    public:
        void sound() {
            std::cout << "Dog makes sound" << std::endl;
        }
};

class German_Shepherd : public Dog {
    public:
        void sound() {
            std::cout << "Bark Bark " << std::endl;
        }
};

int main() {
    Dog dog1;
    dog1.eat();
    German_Shepherd gs1;

    gs1.sound();
    gs1.eat();
    return 0;
}

