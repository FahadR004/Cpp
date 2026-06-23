#include <iostream>
#include <string>

int main() {
    std::string cars[] = {"Mustang", "Camry"};
    std::cout << cars << std::endl;

    std::string fruits[2]; // Have to declare the size of the array when declaring only
    fruits[1] = "Mango";
    double prices[] = {4.00, 2.00, 2.3, 1.435};

    std::cout << sizeof(double) << " Bytes\n";
    std::cout << sizeof(prices) << " Bytes\n";


    std::cout << fruits[0] << std::endl; // Doesn't print anything    
    std::cout << fruits[1] << std::endl;

    for (int i = 0; i < sizeof(prices)/sizeof(double); i++) {
        std::cout << prices[i] << '\n';
    }

    for (std::string fruit : fruits) { // datatype var : array
        std::cout << fruit << "\n";
    }

    const int SIZE = 100;
    std::string foods[SIZE];
    fill(foods, foods + (SIZE/2), "PIZZA");
    fill(foods + (SIZE/2), foods + SIZE, "BURGER");

    return 0;
}
