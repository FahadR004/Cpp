#include <iostream>

template <typename T>
T maximum (T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    std::cout << maximum(1, 2) << std::endl;
    std::cout << maximum(1.1, 2.1) << std::endl;
    return 0;
}