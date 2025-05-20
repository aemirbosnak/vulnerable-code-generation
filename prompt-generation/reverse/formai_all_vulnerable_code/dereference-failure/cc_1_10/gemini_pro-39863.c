//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_NAMES 16
#define MAX_COLOR_LEN 10


struct color {
    char *name;
    int red;
    int green;
    int blue;
};

struct color color_names[] = {
    {"black",    0,   0,   0},
    {"white", 255, 255, 255},
    {"red",    255,   0,   0},
    {"green",   0, 255,   0},
    {"blue",    0,   0, 255},
    {"yellow", 255, 255,   0},
    {"magenta", 255,   0, 255},
    {"cyan",    0, 255, 255},
    {"orange", 255, 165,   0},
    {"purple", 128,   0, 128},
    {"brown",  165,  42,  42},
    {"gray",   128, 128, 128},
    {"silver", 192, 192, 192},
    {"gold",   255, 215,   0},
    {"lime",    0, 255,   0},
    {"navy",    0,   0, 128},
};

int main(int argc, char *argv[]) {
    char *color_name;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s color_name\n", argv[0]);
        return EXIT_FAILURE;
    }

    color_name = argv[1];

    for (i = 0; i < COLOR_NAMES; i++) {
        if (strcmp(color_name, color_names[i].name) == 0) {
            printf("Color %s: %d %d %d\n", color_name, color_names[i].red, color_names[i].green, color_names[i].blue);
            return EXIT_SUCCESS;
        }
    }

    fprintf(stderr, "Color %s not found\n", color_name);
    return EXIT_FAILURE;
}