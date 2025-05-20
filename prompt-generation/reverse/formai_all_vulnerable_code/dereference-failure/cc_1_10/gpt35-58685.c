//FormAI DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Convert non-negative integer to binary string representation
char* to_binary_string(uint64_t num, int num_bits) {
    char* binary_str = malloc((num_bits + 1) * sizeof(char));
    for (int i = 0; i < num_bits; i++) {
        binary_str[i] = (num & ((uint64_t) 1 << (num_bits - i - 1))) ? '1' : '0';
    }
    binary_str[num_bits] = '\0';
    return binary_str;
}

// Convert string of 0s and 1s to decimal integer
uint64_t to_decimal(char* binary_str, int num_bits) {
    uint64_t num = 0;
    for (int i = 0; i < num_bits; i++) {
        if (binary_str[i] == '1') num |= ((uint64_t) 1 << (num_bits - i - 1));
    }
    return num;
}

int main() {
    int num_bits = 8;  // Default number of bits
    char input[32];

    // Infinite loop to continuously prompt user for input
    while (1) {
        printf("Enter a decimal number to convert to binary (or enter 'q' to quit):\n");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input\n");
            continue;
        }

        if (input[0] == 'q') break;

        // Convert input to integer
        int decimal_num = atoi(input);
        if (decimal_num < 0) {
            printf("Input must be non-negative integer\n");
            continue;
        }

        // Convert decimal to binary string
        char* binary_str = to_binary_string(decimal_num, num_bits);
        printf("%d in binary is %s\n", decimal_num, binary_str);

        // Convert binary string back to decimal and verify result
        uint64_t decimal_check = to_decimal(binary_str, num_bits);
        if (decimal_check != (uint64_t) decimal_num) {
            printf("Error: Decimal check (%lu) does not match original input (%d)\n", decimal_check, decimal_num);
        }

        free(binary_str);
    }

    return 0;
}