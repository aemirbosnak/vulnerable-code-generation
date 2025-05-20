//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HEX_COLOR_LENGTH 7

// Recursive function to validate a hexadecimal color code
int validate_hex(const char *hex, int index) {
    if (index >= HEX_COLOR_LENGTH) {
        return 1; // Valid hex
    }
    
    if (index == 0 && hex[index] != '#') {
        return 0; // First character must be '#'
    }

    if (index > 0 && !isxdigit(hex[index])) {
        return 0; // Valid hex digits (0-9, a-f, A-F)
    }

    return validate_hex(hex, index + 1); // Recursive call to validate next character
}

// Recursive function to convert hexadecimal to decimal
int hex_to_decimal(const char *hex, int index, int length) {
    if (index >= length) {
        return 0;
    }

    int current_value = 0;
    if (isdigit(hex[index])) {
        current_value = hex[index] - '0';
    } else if (isupper(hex[index])) {
        current_value = hex[index] - 'A' + 10;
    } else if (islower(hex[index])) {
        current_value = hex[index] - 'a' + 10;
    }

    return (current_value * (1 << ((length - index - 1) * 4))) + hex_to_decimal(hex, index + 1, length);
}

// Recursive function to convert hex color code to RGB
void hex_to_rgb(const char *hex, int index, int *rgb) {
    if (index >= 6) { // RGB has 6 characters (2 for each color)
        return;
    }

    rgb[index / 2] = hex_to_decimal(hex + index + 1, 0, 2); // Convert the two hex characters to decimal
    hex_to_rgb(hex, index + 2, rgb); // Recursive call for next color
}

int main() {
    char hex_color[HEX_COLOR_LENGTH];
    int rgb[3];

    printf("Enter a hexadecimal color code (e.g. #FF5733): ");
    scanf("%6s", hex_color);

    if (validate_hex(hex_color, 0)) {
        hex_to_rgb(hex_color, 1, rgb); // Start after '#'
        printf("RGB values: R=%d, G=%d, B=%d\n", rgb[0], rgb[1], rgb[2]);
    } else {
        printf("Invalid hexadecimal color code!\n");
    }

    return 0;
}