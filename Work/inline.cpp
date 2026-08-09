#include <iostream>

int cube (int x) {
    return x * x * x;
}

int main () {
    std::cout << cube(3) << std::endl;
    return 0;
}