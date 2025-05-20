//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#define COLOR_CODE_LENGTH 6
#define COLOR_CODE_HEXADECIMAL_LENGTH 7
#define COLOR_CODE_RGB_LENGTH 4

typedef struct color_rgb {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} color_rgb_t;

typedef struct color_hex {
    uint8_t hex[COLOR_CODE_LENGTH];
} color_hex_t;

bool is_hex_digit(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

bool is_valid_hex_code(const char *hex) {
    if (strlen(hex) != COLOR_CODE_HEXADECIMAL_LENGTH) {
        return false;
    }

    for (int i = 0; i < COLOR_CODE_LENGTH; i++) {
        if (!is_hex_digit(hex[i])) {
            return false;
        }
    }

    return true;
}

bool hex_to_rgb(const char *hex, color_rgb_t *rgb) {
    if (!is_valid_hex_code(hex)) {
        return false;
    }

    for (int i = 0; i < COLOR_CODE_LENGTH; i++) {
        uint8_t value = 0;

        if (hex[i] >= '0' && hex[i] <= '9') {
            value = hex[i] - '0';
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            value = hex[i] - 'a' + 10;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            value = hex[i] - 'A' + 10;
        }

        if (i % 2 == 0) {
            rgb->red |= value << 4;
        } else {
            rgb->green |= value << 4;
        }

        if (i % 4 == 0) {
            rgb->blue |= value;
        }
    }

    return true;
}

bool rgb_to_hex(const color_rgb_t *rgb, char *hex) {
    if (hex == NULL) {
        return false;
    }

    sprintf(hex, "#%02X%02X%02X", rgb->red, rgb->green, rgb->blue);

    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <hex color code>\n", argv[0]);
        return EXIT_FAILURE;
    }

    color_rgb_t rgb;

    if (!hex_to_rgb(argv[1], &rgb)) {
        printf("Invalid hex color code: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char hex[COLOR_CODE_HEXADECIMAL_LENGTH];

    if (!rgb_to_hex(&rgb, hex)) {
        printf("Failed to convert RGB to hex\n");
        return EXIT_FAILURE;
    }

    printf("Hex: %s\n", hex);

    return EXIT_SUCCESS;
}