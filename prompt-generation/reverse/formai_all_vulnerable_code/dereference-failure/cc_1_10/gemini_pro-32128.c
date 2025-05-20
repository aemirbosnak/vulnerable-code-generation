//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define COLOR_MAX_LEN 20

typedef struct {
    char *name;
    int r, g, b;
} Color;

Color *color_create(char *name, int r, int g, int b) {
    Color *color = malloc(sizeof(Color));
    if (!color) {
        return NULL;
    }

    color->name = strdup(name);
    if (!color->name) {
        free(color);
        return NULL;
    }

    color->r = r;
    color->g = g;
    color->b = b;

    return color;
}

void color_destroy(Color *color) {
    free(color->name);
    free(color);
}

int color_compare(const void *a, const void *b) {
    const Color *color1 = *(const Color **)a;
    const Color *color2 = *(const Color **)b;

    return strcmp(color1->name, color2->name);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <color code>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *color_code = argv[1];

    if (strlen(color_code) != 6) {
        fprintf(stderr, "Invalid color code: %s\n", color_code);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 6; i++) {
        if (!isxdigit(color_code[i])) {
            fprintf(stderr, "Invalid color code: %s\n", color_code);
            return EXIT_FAILURE;
        }
    }

    int r, g, b;
    sscanf(color_code, "%2x%2x%2x", &r, &g, &b);

    Color *color = color_create("Custom", r, g, b);
    if (!color) {
        fprintf(stderr, "Error creating color\n");
        return EXIT_FAILURE;
    }

    Color *colors[] = {
        color_create("Red", 255, 0, 0),
        color_create("Green", 0, 255, 0),
        color_create("Blue", 0, 0, 255),
        color_create("Yellow", 255, 255, 0),
        color_create("Magenta", 255, 0, 255),
        color_create("Cyan", 0, 255, 255),
        color_create("White", 255, 255, 255),
        color_create("Black", 0, 0, 0),
        color_create("Gray", 128, 128, 128),
        color,
    };

    qsort(colors, sizeof(colors) / sizeof(colors[0]), sizeof(colors[0]), color_compare);

    for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
        printf("%s: #%02x%02x%02x\n", colors[i]->name, colors[i]->r, colors[i]->g, colors[i]->b);
        color_destroy(colors[i]);
    }

    return EXIT_SUCCESS;
}