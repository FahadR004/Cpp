#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;
    // std::cout << "What's your name? ";
    // std::cin >> name;
    // std::cout << "What's your name? ";
    // std::getline(std::cin, name);

    // std::cout << "What's your age? ";
    // std::cin >> age;

    // If you do the following:

    // std::cout << "What's your age? ";
    // std::cin >> age;

    // std::cout << "What's your name? ";
    // std::getline(std::cin, name);

    // The \n entered with age will be passed to getline and it will not take any input

    // To prevent that:

    std::cout << "What's your age? ";
    std::cin >> age;

    std::cout << "What's your name? ";
    std::getline(std::cin >> std::ws, name); // Eliminates whitespace

    std::cout << "Hello " << name << '\n';
    std::cout << "Your age is " << age;
    return 0;
}
