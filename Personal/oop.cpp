#include <iostream>

class Human {
    public:
        std::string name;
        std::string occupation;
        int age;

        void eat() {
            std::cout << "I am eating" << "\n";
        }

        void drink() {
            std::cout << "I am drinking" << "\n";
        }
    
    Human(std::string name, std::string occupation, int age) {
        this->name = name;
        this->occupation = occupation;
        this->age = age;
        // If your parameter names are different to your actual variables, you can directly assign them without using this
        // height = h;
        // Constructors can be overloaded
    }
};

class Pizza { // Class with overloaded constructors
    public:
        std::string topping1;
        std::string topping2;

    Pizza(){

    }

    Pizza(std::string topping1) {
        this->topping1 = topping1;
    }

    Pizza(std::string topping1, std::string topping2) {
        this->topping1 = topping1;
        this->topping2 = topping2;
    }
};

int main() {

    // Human human1;
    // human1.name = "Fahad";
    // human1.occupation = "Engineer";
    // human1.age = 21;

    // std::cout << human1.name << "\n";
    // human1.eat();
    // constructors are automatically called when objects are instantiated
    Human human1("Fahad", "Engineer", 21);
    Pizza pizza();
}