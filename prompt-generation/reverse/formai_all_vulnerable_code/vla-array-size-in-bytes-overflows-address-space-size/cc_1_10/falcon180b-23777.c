//Falcon-180B DATASET v1.0 Category: Recursive ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print an array of integers
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Recursive function to generate a random permutation of an array
void rand_perm(int arr[], int size) {
    if (size == 1) {
        return;
    }
    int rand_index = rand_int(0, size - 1);
    int temp = arr[0];
    arr[0] = arr[rand_index];
    arr[rand_index] = temp;
    rand_perm(arr + 1, size - 1);
}

// Function to fill an array with random integers between min and max (inclusive)
void rand_fill(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand_int(min, max);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    rand_fill(arr, size, 1, 100);
    printf("Original array: ");
    print_array(arr, size);

    rand_perm(arr, size);
    printf("Random permutation: ");
    print_array(arr, size);

    return 0;
}