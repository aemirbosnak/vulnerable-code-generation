//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_NAMES_SIZE    256
#define COLOR_CODES_SIZE    256
#define COLOR_CODES_MAX_LEN 8

typedef struct _color {
    char *name;
    char *code;
} color;

color colors[COLOR_NAMES_SIZE];

int main(int argc, char **argv) {
    int i;
    char *color_name;
    char *color_code;
    FILE *fp;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <color_name> <color_code>\n", argv[0]);
        return EXIT_FAILURE;
    }

    color_name = argv[1];
    color_code = argv[2];

    if (strlen(color_name) >= COLOR_NAMES_SIZE || strlen(color_code) >= COLOR_CODES_MAX_LEN) {
        fprintf(stderr, "Error: color name or code too long\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i < COLOR_NAMES_SIZE; i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            fprintf(stderr, "Error: color name already exists\n");
            return EXIT_FAILURE;
        }
    }

    fp = fopen("colors.txt", "a");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file\n");
        return EXIT_FAILURE;
    }

    fprintf(fp, "%s %s\n", color_name, color_code);
    fclose(fp);

    printf("Color code added successfully\n");

    return EXIT_SUCCESS;
}