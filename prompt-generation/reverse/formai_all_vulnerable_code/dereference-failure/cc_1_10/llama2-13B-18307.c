//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the number of bits to convert
#define BITS 32

// Define the number of bases to use for the conversion
#define BASES 2

// Define a structure to hold the binary and base representations
typedef struct {
    unsigned int binary;
    int base;
} binary_t;

// Function to convert a binary number to a base
binary_t* binary_to_base(unsigned int binary, int base) {
    binary_t* result = malloc(sizeof(binary_t));
    result->binary = binary;
    result->base = base;
    return result;
}

// Function to convert a base to a binary
binary_t* base_to_binary(int base) {
    binary_t* result = malloc(sizeof(binary_t));
    result->base = base;
    result->binary = 0;
    for (int i = 0; i < BITS; i++) {
        result->binary = (result->binary << 1) + (base % 2);
        base /= 2;
    }
    return result;
}

int main() {
    // Test cases
    unsigned int binaries[3] = {0x01010101, 0x10101010, 0x11111111};
    int bases[3] = {2, 10, 16};

    // Convert binary to base
    for (int i = 0; i < 3; i++) {
        binary_t* binary = binary_to_base(binaries[i], bases[i]);
        printf("%s (%d) in base %d is %s (%d)\n",
               binary->binary > 0 ? "positive" : "negative",
               binary->binary,
               binary->base,
               binary->base > 0 ? "positive" : "negative",
               binary->base);
        free(binary);
    }

    // Convert base to binary
    for (int i = 0; i < 3; i++) {
        binary_t* binary = base_to_binary(bases[i]);
        printf("%s (%d) in base %d is %s (%d)\n",
               binary->binary > 0 ? "positive" : "negative",
               binary->binary,
               binary->base,
               binary->base > 0 ? "positive" : "negative",
               binary->base);
        free(binary);
    }

    return 0;
}