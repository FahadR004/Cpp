#include <iostream>
#include <string>

void sort(int array[], int size);

int main() {
    int temp;
    int array[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(array)/sizeof(int);
    // int size = sizeof(array)/sizeof(array[0]);
    std::cout << "Before sorting" << std::endl;
    for (int element : array) {
        std::cout << element << " ";
    }
    sort(array, size);
    std::cout << "\nAfter sorting" << std::endl;
    for (int element : array) {
        std::cout << element << " ";

    }
}

// i is for each element in the array 
// j is the pointer to moving through all elements comparing each with the adjacent one

void sort(int array[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {// -1 because we don't need to compare the last element with anything
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }    
}
