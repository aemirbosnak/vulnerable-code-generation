//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_OUTPUT_SIZE 33
#define BASE 2

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];
    int input_size = 0;
    int output_size = 0;

    if (argc == 1) {
        printf("No input provided. Please enter a binary number.\n");
        return 1;
    }

    strcpy(input, argv[1]);
    input_size = strlen(input);

    if (input_size == 0) {
        printf("Empty input provided. Please enter a binary number.\n");
        return 1;
    }

    // Check if input is a valid binary number
    for (int i = 0; i < input_size; i++) {
        if (input[i]!= '0' && input[i]!= '1') {
            printf("Invalid input provided. Please enter a binary number.\n");
            return 1;
        }
    }

    // Convert binary to decimal
    char *binary_ptr = &input[input_size - 1];
    char *decimal_ptr = &output[output_size - 1];
    *decimal_ptr = '\0';

    while (binary_ptr >= input) {
        int digit = *binary_ptr - '0';
        *decimal_ptr = (digit * BASE) + *decimal_ptr;
        binary_ptr--;
        decimal_ptr--;
    }

    // Print the result
    printf("Decimal equivalent: %s\n", output);

    return 0;
}