#include <iostream>

// template <typename T>

// T max (T x, T y) {
//      return (x > y) ? x : y;
// }

template <typename T, typename U>

auto max (T x, U y) {
     return (x > y) ? x : y;
}

// int max (int x, int y) {
//     return (x > y) ? x : y;
// }

// double max (double x, double y) {
//     return (x > y) ? x : y;
// }

// char max (char x, char y) {
//     return (x > y) ? x : y;
// }

int main() {
    // std::cout << max(1,2) << '\n'; 

    // If I want to use the same function just with different data types, I will have to create multiple overloaded functions.
    // This can be resolved by using function templates 
    // Replace the data types with T (common naming convention)
    // Our compiler doesn't know T, so we need to add a template compiler declaration

    std::cout << max(1,2) << '\n'; 
    std::cout << max(1.1,2.2) << '\n'; 
    std::cout << max('1','2') << '\n'; 

    // But, a mix of data types won't work like 1 and 1.2
    // So, we use U. But, currently, it would return truncated value for
    // std::cout << max(1 ,2.2) << '\n';
    // whereas it should return float
    // Hence, we should use auto so then the compiler can automatically infer the return on it's own 
}

