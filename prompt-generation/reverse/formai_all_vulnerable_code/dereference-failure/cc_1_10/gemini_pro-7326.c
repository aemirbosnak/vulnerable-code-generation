//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_SIZE 7

typedef struct {
    char *name;
    unsigned char r, g, b;
} Color;

Color colors[] = {
    {"black",   0,   0,   0},
    {"white", 255, 255, 255},
    {"red",    255,   0,   0},
    {"green",   0, 255,   0},
    {"blue",    0,   0, 255},
    {"yellow", 255, 255,   0},
    {"magenta", 255,   0, 255},
    {"cyan",    0, 255, 255},
    {"gray",   128, 128, 128},
    {"maroon", 128,   0,   0},
    {"olive",  128, 128,   0},
    {"purple", 128,   0, 128},
    {"teal",    0, 128, 128},
    {"navy",    0,   0, 128},
};

Color *find_color(char *name) {
    for (int i = 0; i < sizeof(colors) / sizeof(Color); i++) {
        if (strcmp(name, colors[i].name) == 0) {
            return &colors[i];
        }
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <color name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Color *color = find_color(argv[1]);
    if (color == NULL) {
        fprintf(stderr, "Invalid color name: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("Color: %s\n", color->name);
    printf("RGB: (%d, %d, %d)\n", color->r, color->g, color->b);
    printf("Hex: #%02x%02x%02x\n", color->r, color->g, color->b);

    return EXIT_SUCCESS;
}