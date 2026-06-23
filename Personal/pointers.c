#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int*b);

int main() {
    int a = 10;
    int *ptrA = &a;
    int b = 20;
    int *ptrB = &b;

    swap(ptrA, ptrB);

    printf("a: %d, b: %d", a, b);

    return 0;
}

void swap(int *a, int*b) {
    int x = *a; // Gets value of a (Dereferencing)
    int y = *b; // Get value of b (Dereferencing)

    *a = y; // At the address of a or x, write the value of y
    *b = x; // At the address of b or y, write the value of x
}