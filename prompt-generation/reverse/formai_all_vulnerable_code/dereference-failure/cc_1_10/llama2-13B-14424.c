//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_STR_LEN 1024
#define MAX_INT 2147483647

// Structure to hold the binary representation of a number
typedef struct {
    int num_digits;
    char digits[MAX_STR_LEN];
} binary_t;

// Function to convert a number to its binary representation
binary_t *to_binary(int num) {
    binary_t *bin = malloc(sizeof(binary_t));
    int i = 0;

    // Loop until the number is 0
    while (num != 0) {
        // Get the last digit of the number
        int dig = num % 2;

        // Add the digit to the binary representation
        bin->digits[i++] = dig + '0';

        // Shift the number to the left
        num /= 2;
    }

    // Set the number of digits in the binary representation
    bin->num_digits = i;

    return bin;
}

// Function to convert a binary representation to a number
int from_binary(const binary_t *bin) {
    int num = 0;
    int i = 0;

    // Loop until the end of the binary representation
    while (i < bin->num_digits) {
        // Get the current digit
        int dig = bin->digits[i] - '0';

        // Add the digit to the number
        num *= 2;
        num += dig;

        // Shift the number to the left
        i++;
    }

    return num;
}

int main() {
    // Test cases
    int tests[] = {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
    };

    int i;
    for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        binary_t *bin = to_binary(tests[i]);
        int result = from_binary(bin);

        printf("%d = %s (%d digits)\n", tests[i], bin->digits, bin->num_digits);

        free(bin);
    }

    return 0;
}