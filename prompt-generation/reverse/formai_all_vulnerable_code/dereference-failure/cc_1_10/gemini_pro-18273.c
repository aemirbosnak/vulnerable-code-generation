//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_STR_LEN 16

typedef struct {
    char *name;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

Color colors[] = {
    { "black", 0, 0, 0 },
    { "white", 255, 255, 255 },
    { "red", 255, 0, 0 },
    { "green", 0, 255, 0 },
    { "blue", 0, 0, 255 },
    { "cyan", 0, 255, 255 },
    { "magenta", 255, 0, 255 },
    { "yellow", 255, 255, 0 }
};

int num_colors = sizeof(colors) / sizeof(Color);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <color name or hex code>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *color_str = argv[1];
    Color *color = NULL;

    // Try to find the color by name
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(color_str, colors[i].name) == 0) {
            color = &colors[i];
            break;
        }
    }

    // If the color was not found by name, try to parse it as a hex code
    if (color == NULL) {
        unsigned int hex_code;
        if (sscanf(color_str, "#%06x", &hex_code) != 1) {
            fprintf(stderr, "Invalid color name or hex code: %s\n", color_str);
            return EXIT_FAILURE;
        }
        color = malloc(sizeof(Color));
        color->name = NULL;
        color->red = (hex_code >> 16) & 0xFF;
        color->green = (hex_code >> 8) & 0xFF;
        color->blue = hex_code & 0xFF;
    }

    // Print the color in various formats
    printf("Name: %s\n", color->name);
    printf("Hex code: #%.6x\n", (color->red << 16) | (color->green << 8) | color->blue);
    printf("RGB: (%d, %d, %d)\n", color->red, color->green, color->blue);

    return EXIT_SUCCESS;
}