//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert hexadecimal digit to decimal
int hex_digit_to_decimal(char c) {
    if (isdigit(c))
        return c - '0';
    else if (isalpha(c))
        return c - 'A' + 10;
    else
        return -1;
}

// Function to validate hexadecimal color code
int is_valid_hex_color(const char* color) {
    int len = strlen(color);

    if (len != 7 && len != 9)
        return 0;

    for (int i = 0; i < len; ++i) {
        if (!isxdigit(color[i])) {
            if (color[i] != '#')
                return 0;
            ++i;
            if (len != 9 && (i == len || (i + 1) < len && !isxdigit(color[i + 1])))
                return 0;
            break;
        }
    }

    return 1;
}

// Function to convert hexadecimal color code to RGB values
void hex_color_to_rgb(const char* color, int* r, int* g, int* b) {
    int rgb[3] = { 0 };
    int len = strlen(color);

    if (len != 7 && len != 9)
        return;

    int red = 0, green = 0, blue = 0;

    if (len == 9) {
        red = hex_digit_to_decimal(color[1]) * 16 + hex_digit_to_decimal(color[2]);
        green = hex_digit_to_decimal(color[3]) * 16 + hex_digit_to_decimal(color[4]);
        blue = hex_digit_to_decimal(color[5]) * 16 + hex_digit_to_decimal(color[6]);
    } else {
        red = hex_digit_to_decimal(color[0]) * 16 + hex_digit_to_decimal(color[1]);
        green = hex_digit_to_decimal(color[2]) * 16 + hex_digit_to_decimal(color[3]);
        blue = hex_digit_to_decimal(color[4]) * 16 + hex_digit_to_decimal(color[5]);
    }

    rgb[0] = red;
    rgb[1] = green;
    rgb[2] = blue;

    *r = rgb[0];
    *g = rgb[1];
    *b = rgb[2];
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <hexadecimal_color_code>\n", argv[0]);
        return 1;
    }

    int r, g, b;
    if (!is_valid_hex_color(argv[1])) {
        printf("Invalid hexadecimal color code: %s\n", argv[1]);
        return 1;
    }

    hex_color_to_rgb(argv[1], &r, &g, &b);
    printf("RGB values for the given hexadecimal color code (%s): R=%d, G=%d, B=%d\n", argv[1], r, g, b);

    return 0;
}