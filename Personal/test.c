#include <stdio.h>
#include <stdlib.h>

int f();
int g();

int x = 0;

int f() {
    if (x == 0) {
        x = x + 1;
    } else {
        x = x - 1;
    }
    return x;
}

int g() {
    return x++;
}


int main() {
    int i = (f() | g()) | g();
    int j = g() | (f() | g());
    int g_val = g();
    printf("i = %d, j = %d, g = %d", i, j, g_val);
    
}