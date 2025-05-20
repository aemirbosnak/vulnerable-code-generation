//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_HEX_COLOR_LEN 7
#define MAX_RGB_COLOR_LEN 15

typedef struct {
    char *hex;
    int r, g, b;
} color_t;

bool is_hex_color(const char *str) {
    if (strlen(str) != MAX_HEX_COLOR_LEN) {
        return false;
    }

    for (int i = 0; i < MAX_HEX_COLOR_LEN; i++) {
        char c = str[i];
        if (!isxdigit(c)) {
            return false;
        }
    }

    return true;
}

bool is_rgb_color(const char *str) {
    if (strlen(str) != MAX_RGB_COLOR_LEN) {
        return false;
    }

    if (str[0] != 'r' || str[1] != 'g' || str[2] != 'b' || str[3] != '(' || str[MAX_RGB_COLOR_LEN - 1] != ')') {
        return false;
    }

    for (int i = 4; i < MAX_RGB_COLOR_LEN - 1; i++) {
        char c = str[i];
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

color_t parse_hex_color(const char *str) {
    color_t color = { .hex = strdup(str) };
    sscanf(str, "%02x%02x%02x", &color.r, &color.g, &color.b);
    return color;
}

color_t parse_rgb_color(const char *str) {
    color_t color = { .hex = NULL };
    sscanf(str + 4, "%d,%d,%d", &color.r, &color.g, &color.b);
    return color;
}

void print_hex_color(const color_t *color) {
    printf("#%02x%02x%02x\n", color->r, color->g, color->b);
}

void print_rgb_color(const color_t *color) {
    printf("rgb(%d,%d,%d)\n", color->r, color->g, color->b);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <color>\n", argv[0]);
        return 1;
    }

    const char *color_str = argv[1];

    color_t color;
    if (is_hex_color(color_str)) {
        color = parse_hex_color(color_str);
    } else if (is_rgb_color(color_str)) {
        color = parse_rgb_color(color_str);
    } else {
        fprintf(stderr, "Invalid color: %s\n", color_str);
        return 1;
    }

    print_hex_color(&color);
    print_rgb_color(&color);

    free(color.hex);

    return 0;
}