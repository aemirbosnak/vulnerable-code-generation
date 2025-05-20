//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARANOID 1

typedef struct {
    char *name;
    char *hex;
} color_t;

color_t colors[] = {
    {"black", "#000000"},
    {"white", "#ffffff"},
    {"red", "#ff0000"},
    {"green", "#00ff00"},
    {"blue", "#0000ff"},
    {"yellow", "#ffff00"},
    {"magenta", "#ff00ff"},
    {"cyan", "#00ffff"},
    {"orange", "#ffa500"},
    {"purple", "#800080"},
    {"brown", "#a52a2a"},
    {"gray", "#808080"},
    {"pink", "#ffc0cb"},
    {"gold", "#ffd700"},
    {"silver", "#c0c0c0"},
    {NULL, NULL}
};

int main(int argc, char *argv[])
{
    char *color_name;
    char *color_hex;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <color name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    color_name = argv[1];

    if (!PARANOID) {
        for (i = 0; colors[i].name != NULL; i++) {
            if (strcmp(color_name, colors[i].name) == 0) {
                color_hex = colors[i].hex;
                break;
            }
        }
    } else {
        for (i = 0; colors[i].name != NULL; i++) {
            if (strcmp(color_name, colors[i].name) == 0) {
                color_hex = colors[i].hex;
                break;
            }
            if (strcmp(color_name, colors[i].hex) == 0) {
                color_name = colors[i].name;
                break;
            }
        }
    }

    if (color_hex == NULL) {
        fprintf(stderr, "Invalid color name: %s\n", color_name);
        return EXIT_FAILURE;
    }

    printf("%s\n", color_hex);

    return EXIT_SUCCESS;
}