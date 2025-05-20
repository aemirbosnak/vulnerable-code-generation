//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    unsigned char r, g, b;
} Color;

// Initialize the color struct with the given name and RGB values
void init_color(Color *color, char *name, unsigned char r, unsigned char g, unsigned char b) {
    color->name = strdup(name);
    color->r = r;
    color->g = g;
    color->b = b;
}

// Print the color struct in the format: name (r, g, b)
void print_color(Color *color) {
    printf("%s (%d, %d, %d)\n", color->name, color->r, color->g, color->b);
}

// Convert a hex color string to a color struct
Color *hex_to_color(char *hex) {
    if (strlen(hex) != 7 || hex[0] != '#') {
        return NULL;
    }

    Color *color = malloc(sizeof(Color));
    if (!color) {
        return NULL;
    }

    sscanf(hex, "#%02x%02x%02x", &color->r, &color->g, &color->b);
    return color;
}

// Convert a color struct to a hex color string
char *color_to_hex(Color *color) {
    char *hex = malloc(7);
    if (!hex) {
        return NULL;
    }

    sprintf(hex, "#%02x%02x%02x", color->r, color->g, color->b);
    return hex;
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <color code>\n", argv[0]);
        return 1;
    }

    // Convert the input color code to a color struct
    Color *color = hex_to_color(argv[1]);
    if (!color) {
        printf("Invalid color code: %s\n", argv[1]);
        return 1;
    }

    // Print the color struct in human-readable format
    print_color(color);

    // Convert the color struct back to a hex color string
    char *hex = color_to_hex(color);
    if (!hex) {
        printf("Failed to convert color to hex string\n");
        return 1;
    }

    // Print the hex color string
    printf("Hex: %s\n", hex);

    // Free the allocated memory
    free(color);
    free(hex);

    return 0;
}