//FormAI DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char HEXADECIMAL_DIGITS[] = "0123456789ABCDEF";

void prompt() {
    printf("Enter the RGB color code (e.g. #FF0000): ");
}

int is_valid_hex_digit(char c) {
    return strchr(HEXADECIMAL_DIGITS, c) != NULL;
}

int is_valid_hex_code(const char* hex) {
    if (strlen(hex) != 7 || hex[0] != '#') {
        return 0;
    }
    for (int i = 1; i < 7; i++) {
        if (!is_valid_hex_digit(hex[i])) {
            return 0;
        }
    }
    return 1;
}

int hex_digit_to_int(char c) {
    const char* p = strchr(HEXADECIMAL_DIGITS, c);
    return p != NULL ? p - HEXADECIMAL_DIGITS : -1;
}

void hex_to_rgb(const char* hex, int* r, int* g, int* b) {
    int value = 0;
    for (int i = 1; i < 7; i++) {
        int digit = hex_digit_to_int(hex[i]);
        value = (value << 4) + digit;
    }
    *r = (value >> 16) & 255;
    *g = (value >> 8) & 255;
    *b = value & 255;
}

char* rgb_to_hex(int r, int g, int b) {
    char* hex = (char*)malloc(8); // Allocate 8 bytes to hold #RRGGBB\0
    sprintf(hex, "#%02X%02X%02X", r, g, b);
    return hex;
}

void print_rgb(int r, int g, int b) {
    printf("RGB(%d, %d, %d)\n", r, g, b);
}

void print_hex(const char* hex) {
    printf("Hex: %s\n", hex);
}

void convert_color(const char* hex) {
    int r, g, b;
    hex_to_rgb(hex, &r, &g, &b);
    print_rgb(r, g, b);
    char* new_hex = rgb_to_hex(r+10, g-20, b+30);
    print_hex(new_hex);
    free(new_hex);
}

int main() {
    char hex[8];
    prompt();
    while (scanf("%7s", hex) == 1) {
        if (is_valid_hex_code(hex)) {
            convert_color(hex);
        } else {
            printf("Invalid hex code.\n");
        }
        prompt();
    }
    printf("Goodbye!\n");
    return 0;
}