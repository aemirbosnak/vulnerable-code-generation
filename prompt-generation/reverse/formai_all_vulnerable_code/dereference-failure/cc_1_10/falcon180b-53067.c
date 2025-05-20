//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 1000
#define DEBUG 0

#if DEBUG
#define DEBUG_PRINT(format,...) printf(format, ##__VA_ARGS__)
#else
#define DEBUG_PRINT(format,...)
#endif

int main(int argc, char* argv[]) {
    int size = MAX_SIZE;
    int* arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // Bitwise AND operation
    int result = 0;
    for (int i = 0; i < size; i++) {
        result |= arr[i];
    }
    DEBUG_PRINT("Bitwise AND result: %d\n", result);

    // Bitwise OR operation
    result = 0;
    for (int i = 0; i < size; i++) {
        result |= arr[i];
    }
    DEBUG_PRINT("Bitwise OR result: %d\n", result);

    // Bitwise XOR operation
    result = 0;
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    DEBUG_PRINT("Bitwise XOR result: %d\n", result);

    // Bitwise NOT operation
    result = 0;
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    result = ~result;
    DEBUG_PRINT("Bitwise NOT result: %d\n", result);

    // Bitwise left shift operation
    result = 0;
    for (int i = 0; i < size; i++) {
        result |= arr[i] << 1;
    }
    DEBUG_PRINT("Bitwise left shift result: %d\n", result);

    // Bitwise right shift operation
    result = 0;
    for (int i = 0; i < size; i++) {
        result |= arr[i] >> 1;
    }
    DEBUG_PRINT("Bitwise right shift result: %d\n", result);

    free(arr);
    return 0;
}