//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define NUM_OF_DIGITS 8

// Function prototypes
void print_binary(char *binary_str);
void convert_to_binary(char *decimal_str, char *binary_str);

int main() {
    char decimal_str[MAX_LINE_LENGTH];
    char binary_str[NUM_OF_DIGITS + 1];

    // Prompt user for decimal number
    printf("Enter a decimal number: ");
    fgets(decimal_str, MAX_LINE_LENGTH, stdin);

    // Remove newline character from input
    decimal_str[strcspn(decimal_str, "\n")] = '\0';

    // Convert decimal to binary
    convert_to_binary(decimal_str, binary_str);

    // Print binary number
    printf("Binary representation: ");
    print_binary(binary_str);

    return 0;
}

// Function to print binary number
void print_binary(char *binary_str) {
    int i = 0;
    while (binary_str[i]!= '\0') {
        printf("%c", binary_str[i]);
        i++;
    }
}

// Function to convert decimal to binary
void convert_to_binary(char *decimal_str, char *binary_str) {
    int i = 0;
    int j = 0;
    int decimal_num = 0;
    int remainder = 0;

    // Convert decimal number to integer
    for (i = 0; decimal_str[i]!= '\0'; i++) {
        if (isdigit(decimal_str[i])) {
            decimal_num = decimal_num * 10 + (decimal_str[i] - '0');
        } else {
            printf("Invalid input: %c\n", decimal_str[i]);
            exit(1);
        }
    }

    // Convert integer to binary
    while (decimal_num > 0) {
        remainder = decimal_num % 2;
        binary_str[j++] = remainder + '0';
        decimal_num /= 2;
    }

    // Reverse binary string
    for (i = 0; i < j / 2; i++) {
        char temp = binary_str[i];
        binary_str[i] = binary_str[j - 1 - i];
        binary_str[j - 1 - i] = temp;
    }
}