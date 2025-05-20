//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 32
#define MAX_COLOR_CODES 16

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} color_t;

color_t color_codes[] = {
    {"black", 0x00, 0x00, 0x00},
    {"white", 0xFF, 0xFF, 0xFF},
    {"red", 0xFF, 0x00, 0x00},
    {"green", 0x00, 0xFF, 0x00},
    {"blue", 0x00, 0x00, 0xFF},
    {"yellow", 0xFF, 0xFF, 0x00},
    {"cyan", 0x00, 0xFF, 0xFF},
    {"magenta", 0xFF, 0x00, 0xFF},
    {"orange", 0xFF, 0xA5, 0x00},
    {"purple", 0x80, 0x00, 0x80},
    {"brown", 0xA5, 0x2A, 0x2A},
    {"gray", 0x80, 0x80, 0x80},
    {"light gray", 0xC0, 0xC0, 0xC0},
    {"dark gray", 0x40, 0x40, 0x40},
    {"light blue", 0xAD, 0xD8, 0xE6},
    {"dark blue", 0x00, 0x00, 0x8B},
};

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <color name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *color_name = argv[1];

    for (int i = 0; i < MAX_COLOR_CODES; i++) {
        if (strcmp(color_name, color_codes[i].name) == 0) {
            printf("Red: %d\n", color_codes[i].red);
            printf("Green: %d\n", color_codes[i].green);
            printf("Blue: %d\n", color_codes[i].blue);
            return EXIT_SUCCESS;
        }
    }

    fprintf(stderr, "Invalid color name: %s\n", color_name);
    return EXIT_FAILURE;
}