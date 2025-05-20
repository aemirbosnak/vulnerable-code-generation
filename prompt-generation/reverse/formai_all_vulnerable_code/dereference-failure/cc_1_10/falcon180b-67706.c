//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 7
#define HEX_DIGITS "0123456789ABCDEF"

// Function to validate a given color code
int validate_color_code(char *code) {
    int length = strlen(code);
    if (length!= MAX_COLOR_CODE_LENGTH) {
        printf("Invalid color code length\n");
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (!strchr(HEX_DIGITS, code[i])) {
            printf("Invalid character in color code\n");
            return 0;
        }
    }
    return 1;
}

// Function to convert a RGB color code to hexadecimal
void rgb_to_hex(int r, int g, int b, char *hex) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

// Function to convert a hexadecimal color code to RGB
void hex_to_rgb(char *hex, int *r, int *g, int *b) {
    char *ptr = hex;
    *r = strtol(ptr, &ptr, 16);
    *g = strtol(ptr, &ptr, 16);
    *b = strtol(ptr, &ptr, 16);
}

// Function to print the usage of the program
void print_usage() {
    printf("Usage:./color_code_converter [RGB/HEX] [color_code]\n");
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        print_usage();
        return 1;
    }
    char *mode = argv[1];
    char *code = argv[2];
    if (strcmp(mode, "RGB") == 0) {
        int r, g, b;
        if (!validate_color_code(code)) {
            return 1;
        }
        hex_to_rgb(code, &r, &g, &b);
        printf("RGB color code: %d %d %d\n", r, g, b);
    } else if (strcmp(mode, "HEX") == 0) {
        int r, g, b;
        if (!validate_color_code(code)) {
            return 1;
        }
        rgb_to_hex(r, g, b, code);
        printf("HEX color code: %s\n", code);
    } else {
        print_usage();
        return 1;
    }
    return 0;
}