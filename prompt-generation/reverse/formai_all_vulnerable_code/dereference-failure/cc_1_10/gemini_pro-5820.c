//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TBL_SIZE 16

typedef struct {
    char *name;
    unsigned char r, g, b;
} color_t;

color_t tbl[TBL_SIZE] = {
    {"black",   0,   0,   0},
    {"white", 255, 255, 255},
    {"red",   255,   0,   0},
    {"green",   0, 255,   0},
    {"blue",    0,   0, 255},
    {"yellow", 255, 255,   0},
    {"magenta", 255,   0, 255},
    {"cyan",    0, 255, 255},
    {"gray",  128, 128, 128},
    {"light gray",  192, 192, 192},
    {"dark gray",   64,  64,  64},
    {"brown",  165,  42,  42},
    {"orange", 255, 165,   0},
    {"purple", 128,   0, 128},
    {"pink",   255, 192, 203},
    {"lime",    0, 255,   0}
};

int main(int argc, char *argv[])
{
    char *color_name;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s color_name\n", argv[0]);
        return EXIT_FAILURE;
    }

    color_name = argv[1];

    for (i = 0; i < TBL_SIZE; i++) {
        if (!strcmp(color_name, tbl[i].name)) {
            printf("R: %d, G: %d, B: %d\n", tbl[i].r, tbl[i].g, tbl[i].b);
            return EXIT_SUCCESS;
        }
    }

    fprintf(stderr, "Color '%s' not found\n", color_name);
    return EXIT_FAILURE;
}