//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_CODE_SIZE 6

typedef struct {
    char *name;
    char *hex_code;
} color_code;

static const color_code color_codes[] = {
    {"white", "#FFFFFF"},
    {"black", "#000000"},
    {"red", "#FF0000"},
    {"green", "#00FF00"},
    {"blue", "#0000FF"},
    {"yellow", "#FFFF00"},
    {"magenta", "#FF00FF"},
    {"cyan", "#00FFFF"},
    {"orange", "#FFA500"},
    {"purple", "#800080"},
    {"brown", "#A52A2A"},
    {"gray", "#808080"},
    {"pink", "#FFC0CB"},
    {"lime", "#00FF00"},
    {"teal", "#008080"},
    {"navy", "#000080"},
    {"maroon", "#800000"},
    {"olive", "#808000"},
    {"wheat", "#F5DEB3"},
    {"gold", "#FFD700"},
    {"silver", "#C0C0C0"},
    {"bronze", "#CD7F32"},
    {"lavender", "#E6E6FA"},
    {"mint", "#F5FFFA"},
    {"peach", "#FFE5B4"},
    {"coral", "#FF7F50"},
    {"salmon", "#FA8072"},
    {"plum", "#DDA0DD"},
    {"indigo", "#4B0082"},
    {"turquoise", "#40E0D0"},
    {"khaki", "#F0E68C"},
    {"beige", "#F5F5DC"},
    {"tan", "#D2B48C"},
    {"olive", "#808000"},
    {"wheat", "#F5DEB3"},
    {"gold", "#FFD700"},
    {"silver", "#C0C0C0"},
    {"bronze", "#CD7F32"},
    {"lavender", "#E6E6FA"},
    {"mint", "#F5FFFA"},
    {"peach", "#FFE5B4"},
    {"coral", "#FF7F50"},
    {"salmon", "#FA8072"},
    {"plum", "#DDA0DD"},
    {"indigo", "#4B0082"},
    {"turquoise", "#40E0D0"},
    {"khaki", "#F0E68C"},
    {"beige", "#F5F5DC"},
    {"tan", "#D2B48C"},
    {"chocolate", "#D2691E"},
    {"ivory", "#FFFFF0"},
    {"alabaster", "#F2F0E6"},
    {"eggshell", "#F0E68C"},
    {"parchment", "#F1D198"},
    {"linen", "#F5F5F5"},
    {"cream", "#FFFDD0"},
    {"beige", "#F5F5DC"},
    {"tan", "#D2B48C"},
};

static const int num_color_codes = sizeof(color_codes) / sizeof(color_code);

static void print_usage(const char *progname)
{
    fprintf(stderr, "Usage: %s <color-code>|<color-name>\n", progname);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        print_usage(argv[0]);
    }

    char *input = argv[1];
    int i;

    for (i = 0; i < num_color_codes; i++) {
        if (strcmp(input, color_codes[i].name) == 0) {
            printf("%s\n", color_codes[i].hex_code);
            return EXIT_SUCCESS;
        } else if (strncmp(input, "#", 1) == 0 && strlen(input) == COLOR_CODE_SIZE + 1) {
            if (strcmp(input, color_codes[i].hex_code) == 0) {
                printf("%s\n", color_codes[i].name);
                return EXIT_SUCCESS;
            }
        }
    }

    fprintf(stderr, "Invalid color code or color name.\n");
    return EXIT_FAILURE;
}