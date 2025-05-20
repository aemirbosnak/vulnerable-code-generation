//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: curious
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define BINARY_CONVERTER_MAX_INPUT_LENGTH 1024

// Structure to hold the binary representation of a number
typedef struct {
    uint8_t value;
    uint8_t length;
} binary_t;

// Function to convert a decimal number to binary
binary_t* decimal_to_binary(int32_t dec) {
    binary_t* bin = malloc(sizeof(binary_t));
    int i = 0;

    // Initialize the binary representation with leading 0s
    for (; i < BINARY_CONVERTER_MAX_INPUT_LENGTH; i++) {
        bin->value = 0;
        bin->length = i;
        break;
    }

    // Loop until the number is 0
    while (dec > 0) {
        // Divide the number by 2
        dec = dec / 2;

        // If the result is 0, add a 1 to the binary representation
        if (dec == 0) {
            bin->value |= (1 << i);
        }

        // Increment the position in the binary representation
        i++;
    }

    // Return the binary representation
    return bin;
}

// Function to convert a binary number to decimal
int32_t binary_to_decimal(binary_t* bin) {
    int32_t dec = 0;
    int i = 0;

    // Loop until the end of the binary representation
    for (; i < bin->length; i++) {
        // Shift the binary representation left by one bit
        dec = (dec << 1) | (bin->value & 0x01);
    }

    // Return the decimal representation
    return dec;
}

int main() {
    // Test cases
    int test_cases[] = {
        123,
        456,
        1024,
        -768,
        -32,
        255,
        -128,
        -256,
        -4096,
    };

    // Initialize the binary converter
    binary_t* bin = NULL;

    // Loop through the test cases
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        // Convert the test case to binary
        bin = decimal_to_binary(test_cases[i]);

        // Print the binary representation
        printf("Test case %d: %s\n", i, bin->value);

        // Convert the binary representation back to decimal
        int32_t dec = binary_to_decimal(bin);

        // Print the decimal representation
        printf("Decimal: %d\n", dec);

        // Free the binary representation
        free(bin);
    }

    return 0;
}