#include <iostream>

int main() {
    // std::string car[3][4]; // r, c
    std::string cars[][3] = {{"Mustang", "Ford", "Ferrari"},
                             {"Corvette", "Equinox", "Silverado"},
                             {"Challenger", "Durango", "Ram 1500"}};

    int rows = sizeof(cars)/sizeof(cars[0]);
    int cols = sizeof(cars[0])/sizeof(cars[0][0]);

    for (int i = 0; i < rows; i++) {
        // std::cout << cars[i] << "\n"; // This will give memory address of inner array
        for (int j = 0; i < cols; j++) {
            std::cout << cars[i][j] << " ";   
        }
        std::cout << "\n";
    }
    return 0;
}