//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: inquisitive
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_DIGITS 16

// Function to convert a hexadecimal digit to its decimal equivalent
int hex_to_decimal(char hex_digit) {
    if (hex_digit >= '0' && hex_digit <= '9') {
        return hex_digit - '0';
    } else if (hex_digit >= 'A' && hex_digit <= 'F') {
        return hex_digit - 'A' + 10;
    } else if (hex_digit >= 'a' && hex_digit <= 'f') {
        return hex_digit - 'a' + 10;
    } else {
        // Invalid hexadecimal digit
        assert(0);
        return -1;
    }
}

// Function to convert a hexadecimal string to its decimal equivalent
int hex_to_decimal_string(const char *hex_string) {
    int decimal_value = 0;
    int i;
    int len = strlen(hex_string);
    for (i = 0; i < len; i++) {
        decimal_value *= 16;
        decimal_value += hex_to_decimal(hex_string[i]);
    }
    return decimal_value;
}

// Function to convert a decimal number to its hexadecimal equivalent
char *decimal_to_hex_string(int decimal_number) {
    char *hex_string = malloc(MAX_HEX_DIGITS + 1);
    int i = MAX_HEX_DIGITS;
    hex_string[i--] = '\0';
    do {
        int hex_digit = decimal_number % 16;
        decimal_number /= 16;
        hex_string[i--] = hex_digit < 10 ? '0' + hex_digit : 'A' + hex_digit - 10;
    } while (decimal_number != 0);
    return hex_string;
}

int main() {
    char hex_string[] = "123456789ABCDEF";
    int decimal_value = hex_to_decimal_string(hex_string);
    printf("The decimal equivalent of %s is %d\n", hex_string, decimal_value);

    int decimal_number = 123456789;
    char *hex_string2 = decimal_to_hex_string(decimal_number);
    printf("The hexadecimal equivalent of %d is %s\n", decimal_number, hex_string2);

    return 0;
}