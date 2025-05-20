//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_MAX_LEN 7

typedef struct {
    char *name;
    int red;
    int green;
    int blue;
} Color;

Color colors[] = {
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"white", 255, 255, 255},
    {"black", 0, 0, 0},
    {"gray", 128, 128, 128},
    {"yellow", 255, 255, 0},
    {"magenta", 255, 0, 255},
    {"cyan", 0, 255, 255},
    {"orange", 255, 165, 0},
    {"purple", 128, 0, 128},
    {"brown", 165, 42, 42},
    {"pink", 255, 192, 203},
    {"lime", 0, 255, 0},
    {"teal", 0, 128, 128},
    {"navy", 0, 0, 128},
    {"silver", 192, 192, 192},
    {"gold", 255, 215, 0},
    {"olive", 128, 128, 0},
    {"maroon", 128, 0, 0},
    {"fuchsia", 255, 0, 255},
    {"aqua", 0, 255, 255},
};

const int COLOR_COUNT = sizeof(colors) / sizeof(Color);

Color *find_color(char *name) {
    for (int i = 0; i < COLOR_COUNT; i++) {
        if (strcmp(name, colors[i].name) == 0) {
            return &colors[i];
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];

    Color *color = find_color(color_name);

    if (color == NULL) {
        printf("Invalid color name: %s\n", color_name);
        return 1;
    }

    printf("Color %s: #%02X%02X%02X\n",
        color->name, color->red, color->green, color->blue);

    return 0;
}