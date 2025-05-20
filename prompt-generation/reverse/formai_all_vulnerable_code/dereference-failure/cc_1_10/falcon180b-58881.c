//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

// Function to generate random integers
int generate_random_integer(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random array of integers
int* generate_random_array(int size) {
    int* array = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        array[i] = generate_random_integer(1, 100);
    }

    return array;
}

// Function to print an array of integers
void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to search for an integer in a sorted array using binary search
int binary_search(int* array, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    srand(time(NULL));

    int size = MAX_SIZE;
    int* array = generate_random_array(size);

    int target = generate_random_integer(1, 100);

    int result = binary_search(array, size, target);

    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    free(array);

    return 0;
}