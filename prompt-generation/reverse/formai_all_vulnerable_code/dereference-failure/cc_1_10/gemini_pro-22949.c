//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

Color colors[] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"magenta", 255, 0, 255},
    {"cyan", 0, 255, 255},
    {"orange", 255, 128, 0},
    {"purple", 128, 0, 128},
    {"brown", 165, 42, 42},
    {"gray", 128, 128, 128},
    {"light gray", 192, 192, 192},
    {"dark gray", 64, 64, 64},
    {"pink", 255, 192, 203},
    {"light blue", 173, 216, 230},
    {"light green", 144, 238, 144},
    {"light yellow", 255, 255, 224},
    {"light orange", 255, 165, 0},
    {"light purple", 238, 130, 238},
    {"light brown", 189, 183, 107},
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s color_name\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];

    for (int i = 0; i < sizeof(colors) / sizeof(Color); i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            printf("The color code for %s is: #%02X%02X%02X\n", color_name, colors[i].red, colors[i].green, colors[i].blue);
            return 0;
        }
    }

    printf("The color %s is not recognized.\n", color_name);
    return 1;
}