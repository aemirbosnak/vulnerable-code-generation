//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void print_help();
void hex_to_rgb(const char *hex);
void rgb_to_hex(int r, int g, int b);

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    if (argv[1][0] == '#') {
        // Convert hex to RGB
        hex_to_rgb(argv[1]);
    } else {
        // Assume it's in RGB format
        int r, g, b;
        if (sscanf(argv[1], "%d,%d,%d", &r, &g, &b) == 3) {
            // Convert RGB to hex
            rgb_to_hex(r, g, b);
        } else {
            print_help();
            return 1;
        }
    }
    return 0;
}

// Print the usage instructions
void print_help() {
    printf("Color Code Converter\n");
    printf("Usage:\n");
    printf("  Convert HEX to RGB: ./color_converter #RRGGBB\n");
    printf("  Convert RGB to HEX: ./color_converter R,G,B\n");
    printf("Examples:\n");
    printf("  ./color_converter #ff5733\n");
    printf("  ./color_converter 255,87,51\n");
}

// Convert Hexadecimal color code to RGB
void hex_to_rgb(const char *hex) {
    int r, g, b;
    if (sscanf(hex, "#%2x%2x%2x", &r, &g, &b) == 3) {
        printf("RGB: %d, %d, %d\n", r, g, b);
    } else {
        printf("Invalid HEX code format.\n");
    }
}

// Convert RGB to Hexadecimal color code
void rgb_to_hex(int r, int g, int b) {
    if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255)) {
        printf("RGB values must be in the range 0-255.\n");
    } else {
        printf("HEX: #%02x%02x%02x\n", r, g, b);
    }
}