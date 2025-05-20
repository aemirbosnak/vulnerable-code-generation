//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display binary representation of a number
void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

// Function to perform bitwise AND on an array of numbers
void bitwiseAndArray(unsigned int* arr, size_t size) {
    unsigned int result = arr[0];
    for (size_t i = 1; i < size; i++) {
        result &= arr[i];
    }
    printf("Result of AND operation on array: ");
    printBinary(result);
}

// Function to perform bitwise OR on an array of numbers
void bitwiseOrArray(unsigned int* arr, size_t size) {
    unsigned int result = arr[0];
    for (size_t i = 1; i < size; i++) {
        result |= arr[i];
    }
    printf("Result of OR operation on array: ");
    printBinary(result);
}

// Function to perform bitwise XOR on an array of numbers
void bitwiseXorArray(unsigned int* arr, size_t size) {
    unsigned int result = arr[0];
    for (size_t i = 1; i < size; i++) {
        result ^= arr[i];
    }
    printf("Result of XOR operation on array: ");
    printBinary(result);
}

// Function to left shift elements of an array
void leftShiftArray(unsigned int* arr, size_t size, int shift) {
    printf("Left shifting elements by %d:\n", shift);
    for (size_t i = 0; i < size; i++) {
        unsigned int result = arr[i] << shift;
        printf("Original: %u, Left Shifted: %u, Binary: ", arr[i], result);
        printBinary(result);
    }
}

// Function to right shift elements of an array
void rightShiftArray(unsigned int* arr, size_t size, int shift) {
    printf("Right shifting elements by %d:\n", shift);
    for (size_t i = 0; i < size; i++) {
        unsigned int result = arr[i] >> shift;
        printf("Original: %u, Right Shifted: %u, Binary: ", arr[i], result);
        printBinary(result);
    }
}

// Main function
int main() {
    size_t size;
    printf("Enter the number of elements in the array: ");
    scanf("%zu", &size);

    unsigned int* arr = (unsigned int*)malloc(size * sizeof(unsigned int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (size_t i = 0; i < size; i++) {
        printf("Element %zu: ", i + 1);
        scanf("%u", &arr[i]);
    }

    // Perform bitwise operations
    bitwiseAndArray(arr, size);
    bitwiseOrArray(arr, size);
    bitwiseXorArray(arr, size);

    int shift;
    printf("Enter the number of positions to shift (left and right): ");
    scanf("%d", &shift);
    
    leftShiftArray(arr, size, shift);
    rightShiftArray(arr, size, shift);

    // Display original array in binary
    printf("\nOriginal array in binary:\n");
    for (size_t i = 0; i < size; i++) {
        printf("Element %zu: ", i + 1);
        printBinary(arr[i]);
    }

    // Clean up
    free(arr);
    return 0;
}