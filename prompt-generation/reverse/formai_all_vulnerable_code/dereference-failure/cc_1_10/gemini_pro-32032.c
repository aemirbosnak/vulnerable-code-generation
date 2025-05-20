//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    COLOR_UNKNOWN,
    COLOR_BLACK,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_CYAN,
    COLOR_RED,
    COLOR_MAGENTA,
    COLOR_BROWN,
    COLOR_LIGHTGRAY,
    COLOR_DARKGRAY,
    COLOR_LIGHTBLUE,
    COLOR_LIGHTGREEN,
    COLOR_LIGHTCYAN,
    COLOR_LIGHTRED,
    COLOR_LIGHTMAGENTA,
    COLOR_YELLOW,
    COLOR_WHITE
} color_t;

static const struct {
    const char *name;
    color_t color;
    const char *hexcode;
} colors[] = {
    { "black", COLOR_BLACK, "000000" },
    { "blue", COLOR_BLUE, "0000FF" },
    { "green", COLOR_GREEN, "00FF00" },
    { "cyan", COLOR_CYAN, "00FFFF" },
    { "red", COLOR_RED, "FF0000" },
    { "magenta", COLOR_MAGENTA, "FF00FF" },
    { "brown", COLOR_BROWN, "A52A2A" },
    { "lightgray", COLOR_LIGHTGRAY, "D3D3D3" },
    { "darkgray", COLOR_DARKGRAY, "808080" },
    { "lightblue", COLOR_LIGHTBLUE, "ADD8E6" },
    { "lightgreen", COLOR_LIGHTGREEN, "90EE90" },
    { "lightcyan", COLOR_LIGHTCYAN, "E0FFFF" },
    { "lightred", COLOR_LIGHTRED, "FFB6C1" },
    { "lightmagenta", COLOR_LIGHTMAGENTA, "FFADD8" },
    { "yellow", COLOR_YELLOW, "FFFF00" },
    { "white", COLOR_WHITE, "FFFFFF" }
};

static const unsigned int num_colors = sizeof(colors) / sizeof(colors[0]);

static color_t parse_color(const char *name)
{
    for (unsigned int i = 0; i < num_colors; i++) {
        if (!strcmp(name, colors[i].name)) {
            return colors[i].color;
        }
    }

    return COLOR_UNKNOWN;
}

static const char *parse_hexcode(const char *hexcode)
{
    if (hexcode[0] != '#' || strlen(hexcode) != 7) {
        return NULL;
    }

    for (unsigned int i = 1; i < 7; i++) {
        if (!isxdigit(hexcode[i])) {
            return NULL;
        }
    }

    return hexcode;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <color name or hexcode>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *arg = argv[1];
    color_t color;

    if (arg[0] == '#') {
        const char *hexcode = parse_hexcode(arg);
        if (!hexcode) {
            fprintf(stderr, "Invalid hexcode: %s\n", arg);
            return EXIT_FAILURE;
        }

        for (unsigned int i = 0; i < num_colors; i++) {
            if (!strcmp(hexcode, colors[i].hexcode)) {
                color = colors[i].color;
                break;
            }
        }

        if (color == COLOR_UNKNOWN) {
            fprintf(stderr, "Unknown color code: %s\n", arg);
            return EXIT_FAILURE;
        }
    } else {
        color = parse_color(arg);
        if (color == COLOR_UNKNOWN) {
            fprintf(stderr, "Unknown color name: %s\n", arg);
            return EXIT_FAILURE;
        }
    }

    printf("Color: %s, hexcode: %s\n", colors[color].name, colors[color].hexcode);

    return EXIT_SUCCESS;
}