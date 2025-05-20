//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
/*
 * Hexadecimal Converter
 *
 * This program converts a hexadecimal number to its decimal equivalent.
 *
 * Usage:
 *
 *   hexdec <hexadecimal number>
 *
 * Example:
 *
 *   hexdec 1A
 *
 * Output:
 *
 *   26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hexadecimal number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hex_string = argv[1];
    int hex_length = strlen(hex_string);

    if (hex_length == 0) {
        fprintf(stderr, "Error: Invalid hexadecimal number\n");
        return EXIT_FAILURE;
    }

    int dec_number = 0;
    int hex_digit;

    for (int i = hex_length - 1; i >= 0; i--) {
        char hex_char = hex_string[i];

        if (hex_char >= '0' && hex_char <= '9') {
            hex_digit = hex_char - '0';
        } else if (hex_char >= 'A' && hex_char <= 'F') {
            hex_digit = hex_char - 'A' + 10;
        } else if (hex_char >= 'a' && hex_char <= 'f') {
            hex_digit = hex_char - 'a' + 10;
        } else {
            fprintf(stderr, "Error: Invalid hexadecimal character '%c'\n", hex_char);
            return EXIT_FAILURE;
        }

        dec_number += hex_digit * pow(16, hex_length - 1 - i);
    }

    printf("Decimal equivalent: %d\n", dec_number);

    return EXIT_SUCCESS;
}