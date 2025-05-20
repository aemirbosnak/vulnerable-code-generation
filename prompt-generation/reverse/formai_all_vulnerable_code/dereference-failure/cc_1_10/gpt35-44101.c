//FormAI DATASET v1.0 Category: Color Code Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_LENGTH 10

typedef struct {
    char name[MAX_COLOR_LENGTH+1];
    unsigned int r, g, b;
} Color;

Color colors[] = {
    {"black", 0, 0, 0},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"magenta", 255, 0, 255},
    {"cyan", 0, 255, 255},
    {"white", 255, 255, 255},
};

int num_colors = sizeof(colors) / sizeof(colors[0]);

int color_index(const char *name) {
    for (int i = 0; i < num_colors; ++i) {
        if (strcmp(colors[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void print_rgb(unsigned int r, unsigned int g, unsigned int b) {
    printf("#%02x%02x%02x\n", r, g, b);
}

void print_color(const Color *color) {
    print_rgb(color->r, color->g, color->b);
}

void lower_case(char *str) {
    for (int i = 0; str[i]; ++i) {
        str[i] = tolower(str[i]);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <color>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    lower_case(color_name);

    int color_i = color_index(color_name);

    if (color_i == -1) {
        fprintf(stderr, "Unknown color: %s\n", argv[1]);
        return 1;
    }

    print_color(&colors[color_i]);

    return 0;
}