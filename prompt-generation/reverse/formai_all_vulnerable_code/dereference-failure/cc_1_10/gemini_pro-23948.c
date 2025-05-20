//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_CODES_COUNT 10

typedef struct {
    char *name;
    char *code;
} ColorCode;

ColorCode color_codes[] = {
    {"black", "0"},
    {"brown", "1"},
    {"red", "2"},
    {"orange", "3"},
    {"yellow", "4"},
    {"green", "5"},
    {"blue", "6"},
    {"violet", "7"},
    {"gray", "8"},
    {"white", "9"}
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <color code> <output format>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *color_code = argv[1];
    char *output_format = argv[2];

    if (strlen(color_code) != 2) {
        fprintf(stderr, "Error: Invalid color code '%s'\n", color_code);
        return EXIT_FAILURE;
    }

    int first_digit = color_code[0] - '0';
    int second_digit = color_code[1] - '0';

    if (first_digit < 0 || first_digit >= COLOR_CODES_COUNT || second_digit < 0 || second_digit >= COLOR_CODES_COUNT) {
        fprintf(stderr, "Error: Invalid color code '%s'\n", color_code);
        return EXIT_FAILURE;
    }

    int resistance_value = first_digit * 10 + second_digit;

    if (strcmp(output_format, "resistance") == 0) {
        printf("%d ohms\n", resistance_value);
    } else if (strcmp(output_format, "color") == 0) {
        printf("%s %s\n", color_codes[first_digit].name, color_codes[second_digit].name);
    } else {
        fprintf(stderr, "Error: Invalid output format '%s'\n", output_format);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}