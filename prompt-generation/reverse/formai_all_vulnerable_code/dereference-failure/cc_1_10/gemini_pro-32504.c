//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX_DIGIT_COUNT 16
#define HEX_DIGITS "0123456789abcdef"

// Function to convert a hexadecimal digit to its decimal equivalent
int hex_digit_to_decimal(char digit) {
    for (int i = 0; i < HEX_DIGIT_COUNT; i++) {
        if (digit == HEX_DIGITS[i]) {
            return i;
        }
    }
    return -1;
}

// Function to convert a hexadecimal string to its decimal equivalent
int hex_string_to_decimal(char *hex_string) {
    int decimal_value = 0;
    int length = strlen(hex_string);

    for (int i = 0; i < length; i++) {
        char digit = hex_string[i];
        int decimal_digit = hex_digit_to_decimal(digit);

        if (decimal_digit == -1) {
            return -1;
        }

        decimal_value = decimal_value * HEX_DIGIT_COUNT + decimal_digit;
    }

    return decimal_value;
}

// Function to convert a decimal number to its hexadecimal equivalent
char *decimal_to_hex_string(int decimal_number) {
    char *hex_string = malloc(sizeof(char) * 11);

    int quotient = decimal_number;
    int remainder;
    int index = 0;

    while (quotient != 0) {
        remainder = quotient % HEX_DIGIT_COUNT;
        hex_string[index++] = HEX_DIGITS[remainder];
        quotient /= HEX_DIGIT_COUNT;
    }

    hex_string[index] = '\0';

    return hex_string;
}

int main() {
    char *hex_string = "abcdef";
    int decimal_number = 12345;

    int decimal_value = hex_string_to_decimal(hex_string);
    if (decimal_value == -1) {
        printf("Invalid hexadecimal string: %s\n", hex_string);
        return EXIT_FAILURE;
    }

    printf("Decimal equivalent of %s: %d\n", hex_string, decimal_value);

    char *new_hex_string = decimal_to_hex_string(decimal_number);
    printf("Hexadecimal equivalent of %d: %s\n", decimal_number, new_hex_string);

    free(new_hex_string);

    return EXIT_SUCCESS;
}