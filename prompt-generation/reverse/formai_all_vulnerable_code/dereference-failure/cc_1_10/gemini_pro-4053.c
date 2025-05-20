//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_DIGITS 16

// Function to convert a hexadecimal digit to its decimal equivalent
int hex_to_dec(char hex_digit) {
    if (hex_digit >= '0' && hex_digit <= '9') {
        return hex_digit - '0';
    } else if (hex_digit >= 'A' && hex_digit <= 'F') {
        return hex_digit - 'A' + 10;
    } else if (hex_digit >= 'a' && hex_digit <= 'f') {
        return hex_digit - 'a' + 10;
    } else {
        // Invalid hexadecimal digit
        return -1;
    }
}

// Function to convert a hexadecimal string to its decimal equivalent
int hex_to_dec_string(char *hex_string) {
    int dec_value = 0;
    int len = strlen(hex_string);

    for (int i = 0; i < len; i++) {
        int hex_digit = hex_string[i];
        int dec_digit = hex_to_dec(hex_digit);

        if (dec_digit == -1) {
            // Invalid hexadecimal digit
            return -1;
        }

        dec_value = dec_value * 16 + dec_digit;
    }

    return dec_value;
}

// Function to convert a decimal number to its hexadecimal equivalent
char *dec_to_hex(int dec_number) {
    char *hex_string = (char *)malloc(MAX_HEX_DIGITS + 1);
    int hex_index = 0;

    while (dec_number > 0) {
        int hex_digit = dec_number % 16;

        if (hex_digit < 10) {
            hex_string[hex_index++] = '0' + hex_digit;
        } else {
            hex_string[hex_index++] = 'A' + hex_digit - 10;
        }

        dec_number /= 16;
    }

    hex_string[hex_index] = '\0';
    return hex_string;
}

// Function to test the hexadecimal converter
void test_hex_converter() {
    char *hex_string = "ABCDEF";
    int dec_number = 0xABCDEF;

    int dec_value = hex_to_dec_string(hex_string);
    if (dec_value != dec_number) {
        printf("Error: Hexadecimal string conversion failed.\n");
    }

    char *new_hex_string = dec_to_hex(dec_number);
    if (strcmp(new_hex_string, hex_string) != 0) {
        printf("Error: Decimal number conversion failed.\n");
    }

    printf("Hexadecimal string: %s\n", hex_string);
    printf("Decimal number: %d\n", dec_number);
    printf("New hexadecimal string: %s\n", new_hex_string);
}

int main() {
    test_hex_converter();
    return 0;
}