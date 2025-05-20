//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_CODE_LENGTH 6
#define COLOR_CODE_PREFIX "#"

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} ColorCode;

ColorCode *color_code_new(unsigned char red, unsigned char green, unsigned char blue) {
    ColorCode *color_code = malloc(sizeof(ColorCode));
    if (color_code == NULL) {
        return NULL;
    }

    color_code->red = red;
    color_code->green = green;
    color_code->blue = blue;

    return color_code;
}

void color_code_delete(ColorCode *color_code) {
    free(color_code);
}

int color_code_parse(const char *color_code_string, ColorCode *color_code) {
    if (strlen(color_code_string) != COLOR_CODE_LENGTH || strncmp(color_code_string, COLOR_CODE_PREFIX, 1) != 0) {
        return -1;
    }

    color_code->red = strtol(color_code_string + 1, NULL, 16);
    color_code->green = strtol(color_code_string + 3, NULL, 16);
    color_code->blue = strtol(color_code_string + 5, NULL, 16);

    return 0;
}

char *color_code_to_string(const ColorCode *color_code) {
    char *color_code_string = malloc(COLOR_CODE_LENGTH + 1);
    if (color_code_string == NULL) {
        return NULL;
    }

    snprintf(color_code_string, COLOR_CODE_LENGTH + 1, "%s%02X%02X%02X", COLOR_CODE_PREFIX, color_code->red, color_code->green, color_code->blue);

    return color_code_string;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <color code>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ColorCode color_code;
    if (color_code_parse(argv[1], &color_code) != 0) {
        printf("Invalid color code: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char *color_code_string = color_code_to_string(&color_code);
    if (color_code_string == NULL) {
        printf("Error converting color code to string\n");
        return EXIT_FAILURE;
    }

    printf("Color code: %s\n", color_code_string);
    free(color_code_string);

    return EXIT_SUCCESS;
}