#include <iostream>

int main() {
    std::string name = "Fahad";
    std::string *pName = &name;

    std::string pizzas[5] = {"Pepperoni", "Mushroom", "Sausage", "Onion", "Olives"};
    std::string *pPizzas = pizzas;
    // Array variables are pointers to the first element of the array. So, pPizzas is a pointer to the first element of the pizzas array.   
    // Hence, we don't need to use the address-of operator (&) to get the address of the first element of the array. We can simply assign the array name to the pointer variable.
    std::cout << pName << std::endl;
    std::cout << *pName << std::endl;
    std::cout << pPizzas << '\n';
    std::cout << *pPizzas << '\n';

    // Null pointers
    // Don't point at anything 
    // null pointers are helpful to determine if an address was successfully assigned to a pointer

    // Good practice to assign pointers to nullptr if not assigning an address to it immediatelly
    int *pointer = nullptr;
    int x = 123;

   // pointer = &x;

    // Dereferencing a nullptr or a pointer that's not assigned a value can lead to undefined behaviour

    if (pointer == nullptr) {
        std::cout << "Address was not assigned \n";
    } else {
        std::cout << "Address was assigned \n";
    }

    return 0;
}

