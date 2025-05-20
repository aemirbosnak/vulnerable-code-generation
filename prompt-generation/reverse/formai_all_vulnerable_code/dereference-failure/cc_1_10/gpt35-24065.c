//FormAI DATASET v1.0 Category: Binary Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BINARY_DIGITS 64

void convert_to_binary(int dec_num, char *binary_num, int num_of_digits);

int main(void) {
    int decimal_number;
    char binary_number[MAX_BINARY_DIGITS];
    int num_of_digits;
    char input[MAX_BINARY_DIGITS];
    int invalid_input = 0;

    do {
        // Get user input
        printf("Enter a decimal number: ");
        fgets(input, MAX_BINARY_DIGITS, stdin);
        input[strcspn(input, "\n")] = 0; // remove trailing newline

        // Check if input is valid
        invalid_input = 0;
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                printf("Invalid input. Please enter a decimal number.\n");
                invalid_input = 1;
                break;
            }
        }

        if (!invalid_input) {
            // Convert input to integer and check if it's within range
            decimal_number = atoi(input);
            if (decimal_number < 0 || decimal_number > 4294967295) {
                printf("Input number out of range. Please enter a number between 0 and 4294967295.\n");
                invalid_input = 1;
            } else {
                // Convert decimal to binary and print
                num_of_digits = (int)log2(decimal_number) + 1;
                convert_to_binary(decimal_number, binary_number, num_of_digits);
                printf("The binary representation of %d is %s.\n", decimal_number, binary_number);
            }
        }
    } while (invalid_input);

    return 0;
}

void convert_to_binary(int dec_num, char *binary_num, int num_of_digits) {
    for (int i = 0; i < num_of_digits; i++) {
        binary_num[i] = (dec_num & (1 << (num_of_digits - 1 - i))) ? '1' : '0';
    }
    binary_num[num_of_digits] = '\0';
}