//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 10

typedef struct {
    char *name;
    char *code;
} color_code;

color_code color_codes[] = {
    { "black", "#000000" },
    { "white", "#FFFFFF" },
    { "red", "#FF0000" },
    { "green", "#00FF00" },
    { "blue", "#0000FF" },
    { "yellow", "#FFFF00" },
    { "magenta", "#FF00FF" },
    { "cyan", "#00FFFF" },
    { "orange", "#FFA500" },
    { "purple", "#800080" },
    { "brown", "#A52A2A" },
    { "gray", "#808080" },
    { "pink", "#FFC0CB" },
    { "lime", "#00FF00" },
    { "navy", "#000080" },
    { "teal", "#008080" },
    { "olive", "#808000" },
    { "maroon", "#800000" },
    { "silver", "#C0C0C0" },
    { "gold", "#FFD700" },
    { "copper", "#B87333" },
    { "bronze", "#CD7F32" },
    { "brass", "#B5A642" }
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <color code>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *color_code = argv[1];

    if (strlen(color_code) != MAX_COLOR_CODE_LENGTH) {
        fprintf(stderr, "Error: Invalid color code '%s'\n", color_code);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < sizeof(color_codes) / sizeof(color_code); i++) {
        if (strcmp(color_code, color_codes[i].code) == 0) {
            printf("%s\n", color_codes[i].name);
            return EXIT_SUCCESS;
        }
    }

    fprintf(stderr, "Error: Color code '%s' not found\n", color_code);
    return EXIT_FAILURE;
}