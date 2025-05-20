//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_CODE_STRING_LENGTH 12
#define COLOR_CODE_INT_LENGTH 6
#define COLOR_CODE_HEX_DIGITS "0123456789ABCDEF"
#define COLOR_CODE_RGB_MAX 255

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} ColorCodeRGB;

typedef struct {
    unsigned int hex;
} ColorCodeHex;

typedef struct {
    char string[COLOR_CODE_STRING_LENGTH];
} ColorCodeString;

void color_code_string_to_rgb(ColorCodeString *string, ColorCodeRGB *rgb) {
    char *ptr = string->string;
    char *endptr;

    rgb->red = strtol(ptr, &endptr, 16);
    ptr = endptr + 1;
    rgb->green = strtol(ptr, &endptr, 16);
    ptr = endptr + 1;
    rgb->blue = strtol(ptr, &endptr, 16);
}

void color_code_rgb_to_hex(ColorCodeRGB *rgb, ColorCodeHex *hex) {
    hex->hex = (rgb->red << 16) | (rgb->green << 8) | rgb->blue;
}

void color_code_hex_to_string(ColorCodeHex *hex, ColorCodeString *string) {
    char *ptr = string->string;
    int i;

    for (i = 0; i < COLOR_CODE_STRING_LENGTH; i++) {
        int digit = (hex->hex >> ((COLOR_CODE_STRING_LENGTH - 1 - i) * 4)) & 0xF;
        *ptr++ = COLOR_CODE_HEX_DIGITS[digit];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <color code>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ColorCodeString string;
    ColorCodeRGB rgb;
    ColorCodeHex hex;

    strcpy(string.string, argv[1]);
    color_code_string_to_rgb(&string, &rgb);
    color_code_rgb_to_hex(&rgb, &hex);
    color_code_hex_to_string(&hex, &string);

    printf("String: %s\n", string.string);
    printf("RGB: %u, %u, %u\n", rgb.red, rgb.green, rgb.blue);
    printf("Hex: %u\n", hex.hex);

    return EXIT_SUCCESS;
}