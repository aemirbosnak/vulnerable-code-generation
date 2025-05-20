//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HEX_TO_DEC_TABLE_SIZE 256

// Converts a single hexadecimal digit character to its decimal value.
int hex_to_dec(char c) {
    static int hex_to_dec_table[HEX_TO_DEC_TABLE_SIZE] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, // 0-9
        10, 11, 12, 13, 14, 15,       // A-F
        10, 11, 12, 13, 14, 15        // A-F (again)
    };

    return hex_to_dec_table[(int)tolower(c)];
}

// Converts a given hexadecimal string to its decimal equivalent.
unsigned long long hex_string_to_decimal(const char *hex_string) {
    size_t length = strlen(hex_string);
    unsigned long long decimal_number = 0;

    // Loop through each character in the hexadecimal string.
    for (size_t i = 0; i < length; ++i) {
        int digit = hex_to_dec(hex_string[i]);

        // Shift the decimal number left by 4 bits (each hex digit represents 4 bits).
        decimal_number <<= 4;

        // Add the decimal equivalent of the current hex digit to the decimal number.
        decimal_number += digit;
    }

    return decimal_number;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <hexadecimal_string>\n", argv[0]);
        return 1;
    }

    // Convert the input hexadecimal string to its decimal equivalent.
    unsigned long long decimal_number = hex_string_to_decimal(argv[1]);

    printf("The decimal equivalent of the hexadecimal string \"%s\" is:\n", argv[1]);
    printf("%llu\n", decimal_number);

    return 0;
}

// Now, isn't it curious how a simple string can hold the power of a whole new number system?
// This program, with just a handful of lines, can convert any hexadecimal string to its decimal equivalent.
// Try it out! Compile it and run it with some hexadecimal strings as arguments.
// You might be surprised by what you find!