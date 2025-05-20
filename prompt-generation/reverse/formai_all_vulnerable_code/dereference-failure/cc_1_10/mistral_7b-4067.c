//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a hexadecimal character to its decimal equivalent
int hex_to_decimal(char hex) {
    if (hex >= '0' && hex <= '9')
        return hex - '0';
    else if (hex >= 'A' && hex <= 'F')
        return hex - 'A' + 10;
    else
        return -1;
}

// Function to convert a string of hexadecimal characters to a decimal number
int hex_string_to_decimal(char *hex_string) {
    int base = 0, len = strlen(hex_string);

    // Iterate through each character in the hex string
    for (int i = 0; i < len; i++) {
        int digit = hex_to_decimal(hex_string[i]);

        // If the conversion fails, return an error
        if (digit == -1)
            return -1;

        // Multiply the current digit by the base and add it to the result
        base = base * 16 + digit;
    }

    // Return the decimal number
    return base;
}

// Function to convert a decimal number to an RGB color code
void decimal_to_rgb(int decimal, char rgb[11]) {
    int r, g, b;

    // Separate the RGB components of the decimal number
    r = decimal >> 16;
    g = (decimal >> 8) & 0xFF;
    b = decimal & 0xFF;

    // Convert each component to hexadecimal and append it to the output string
    sprintf(rgb, "0x%X%X%X", r, g, b);
}

// Function to convert a C color code string to its decimal equivalent
int c_color_to_decimal(char *c_color) {
    int decimal = 0;

    // Remove the leading hash symbol (#) from the color code string
    *strchr(c_color, '#') = '\0';

    // Iterate through each pair of hexadecimal characters in the color code string
    for (int i = 0; i < strlen(c_color); i += 2) {
        int digit1 = hex_to_decimal(c_color[i]);
        int digit2 = hex_to_decimal(c_color[i + 1]);

        // Combine the two digits to form a single decimal number
        decimal = decimal * 256 + digit1 * 16 + digit2;
    }

    // Return the decimal equivalent of the color code
    return decimal;
}

// Main function to convert a C color code string to its RGB equivalent
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <C color code string>\n", argv[0]);
        return 1;
    }

    char rgb[11];
    int decimal = c_color_to_decimal(argv[1]);

    // Convert the decimal number to an RGB color code and print it to the console
    decimal_to_rgb(decimal, rgb);
    printf("The RGB equivalent of %s is %s.\n", argv[1], rgb);

    return 0;
}