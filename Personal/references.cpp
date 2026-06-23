#include <iostream>

void swap(std::string &x, std::string &y);

int main() {
    // & - gives the memory address
    std::string name = "Fahad";
    int age = 21;
    bool student = true;

    std::cout << &name << std::endl;
    std::cout << &age << std::endl;
    std::cout << &student << std::endl;

    // --------------------
    std::string x = "Hello";
    std::string y = "World";
    std::string temp;

    // Works locally
    // temp = x;
    // x = y;
    // y = temp;

     // swap(x, y); // Pass by value. A copy of the variables is made and passed to the function. Changes made to the parameters inside the function do not affect the original arguments.
    std::cout << "Address of X " << &x << "\n";
    std::cout << "Address of Y " << &y << "\n";

    swap(x, y);

    std::cout << "Address of X " << &x << "\n";
    std::cout << "Address of Y " << &y << "\n";
    std::cout << "X " << x << "\n";
    std::cout << "Y " << y << "\n";
    

}

void swap(std::string &x, std::string &y) {
    std::cout << "Address of X " << &x << "\n";
    std::cout << "Address of Y " << &y << "\n";
    std::string temp;
    temp = x;
    x = y;
    y = temp;
}

// Practice
// #include <iostream>

// void swap(int &a, int &b);

// int main() {
//     int a = 10;
//     int b = 20;

//     std::cout << "Value of a before swapping: " << a << std::endl;
//     std::cout << "Value of b before swapping: " << b << std::endl;

//     swap(a, b);

//     std::cout << "Value of a after swapping: " << a << std::endl;
//     std::cout << "Value of b after swapping: " << b << std::endl;

//     return 0;
// }

// void swap(int &a, int &b) {
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }