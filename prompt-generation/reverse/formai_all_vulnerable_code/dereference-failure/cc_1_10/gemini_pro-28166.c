//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int red;
    int green;
    int blue;
} color_t;

color_t colors[] = {
    { "black",   0,   0,   0 },
    { "white", 255, 255, 255 },
    { "red",   255,   0,   0 },
    { "green",   0, 255,   0 },
    { "blue",    0,   0, 255 },
    { "yellow", 255, 255,   0 },
    { "magenta", 255,   0, 255 },
    { "cyan",    0, 255, 255 }
};

const int num_colors = sizeof(colors) / sizeof(color_t);

void print_color(color_t *color) {
    printf("%s (%d, %d, %d)\n", color->name, color->red, color->green, color->blue);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <color name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *color_name = argv[1];

    color_t *color = NULL;

    for (int i = 0; i < num_colors; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        fprintf(stderr, "Invalid color name: %s\n", color_name);
        return EXIT_FAILURE;
    }

    print_color(color);

    return EXIT_SUCCESS;
}