//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input hexadecimal string
#define MAX_HEX_LENGTH 100

// Function to convert a hexadecimal digit to its decimal equivalent
int hex_to_dec(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else {
        return -1;
    }
}

// Function to convert a hexadecimal string to its decimal equivalent
int hex_to_dec_string(char *hex_string) {
    int decimal_value = 0;
    int length = strlen(hex_string);

    // Iterate over the hexadecimal string from right to left
    for (int i = length - 1; i >= 0; i--) {
        // Convert the current hexadecimal digit to its decimal equivalent
        int digit_value = hex_to_dec(hex_string[i]);

        // Multiply the digit value by the appropriate power of 16
        decimal_value += digit_value * pow(16, length - 1 - i);
    }

    return decimal_value;
}

// Function to convert a decimal number to its hexadecimal equivalent
char *dec_to_hex(int decimal_number) {
    // Allocate memory for the hexadecimal string
    char *hex_string = malloc(MAX_HEX_LENGTH);

    // Initialize the index of the hexadecimal string
    int index = 0;

    // While the decimal number is greater than 0
    while (decimal_number > 0) {
        // Find the remainder of the decimal number when divided by 16
        int remainder = decimal_number % 16;

        // Convert the remainder to its hexadecimal digit
        char hex_digit;
        if (remainder < 10) {
            hex_digit = '0' + remainder;
        } else {
            hex_digit = 'A' + remainder - 10;
        }

        // Append the hexadecimal digit to the hexadecimal string
        hex_string[index++] = hex_digit;

        // Divide the decimal number by 16
        decimal_number /= 16;
    }

    // Reverse the hexadecimal string
    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = hex_string[start];
        hex_string[start++] = hex_string[end];
        hex_string[end--] = temp;
    }

    // Terminate the hexadecimal string
    hex_string[index] = '\0';

    return hex_string;
}

// Function to print the hexadecimal representation of a binary number
void print_hex(unsigned int binary_number) {
    // Convert the binary number to its decimal equivalent
    int decimal_number = 0;
    int bit_index = 0;
    while (binary_number > 0) {
        if (binary_number % 10 == 1) {
            decimal_number += pow(2, bit_index);
        }
        bit_index++;
        binary_number /= 10;
    }

    // Convert the decimal number to its hexadecimal equivalent
    char *hex_string = dec_to_hex(decimal_number);

    // Print the hexadecimal string
    printf("Hexadecimal representation: %s\n", hex_string);

    // Free the memory allocated for the hexadecimal string
    free(hex_string);
}

int main() {
    // Get the input hexadecimal string from the user
    char hex_string[MAX_HEX_LENGTH];
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex_string);

    // Convert the hexadecimal string to its decimal equivalent
    int decimal_value = hex_to_dec_string(hex_string);

    // Print the decimal equivalent
    printf("Decimal equivalent: %d\n", decimal_value);

    // Convert the decimal value to its hexadecimal equivalent
    char *hex_representation = dec_to_hex(decimal_value);

    // Print the hexadecimal representation
    printf("Hexadecimal representation: %s\n", hex_representation);

    // Free the memory allocated for the hexadecimal representation
    free(hex_representation);

    // Get the input binary number from the user
    unsigned int binary_number;
    printf("Enter a binary number: ");
    scanf("%u", &binary_number);

    // Print the hexadecimal representation of the binary number
    print_hex(binary_number);

    return 0;
}