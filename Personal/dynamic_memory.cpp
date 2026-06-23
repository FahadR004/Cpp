#include <iostream>

int main () {
    int *pNum = NULL;
    pNum = new int; // new operator + data type
    // Use up enough space for an integer
    *pNum = 21;

    std::cout << "Address: " << pNum << '\n';
    std::cout << "Value: " << *pNum << '\n';

    // Good practice to free up the memory
    delete pNum;

    char *pGrades = NULL;
    int size;

    std::cout << "How many grades to enter?: " << std::endl;
    std::cin >> size;

    pGrades = new char[size];

    for (int i = 0; i < size; i++) {
        std::cout << "Enter grade #:" << i + 1 << ": ";
        std::cin >> pGrades[i];
    }

    for (int i = 0; i < size; i++) {
        std::cout << pGrades[i] << " ";
    }

    delete[] pGrades;


    return 0;
}