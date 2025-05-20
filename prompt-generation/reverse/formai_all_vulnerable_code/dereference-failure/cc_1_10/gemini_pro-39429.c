//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_BLACK   0
#define COLOR_RED     1
#define COLOR_GREEN   2
#define COLOR_YELLOW  3
#define COLOR_BLUE    4
#define COLOR_MAGENTA 5
#define COLOR_CYAN    6
#define COLOR_WHITE   7

#define COLOR_COUNT  8

const char *color_names[] = {
    "black",
    "red",
    "green",
    "yellow",
    "blue",
    "magenta",
    "cyan",
    "white"
};

struct color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct color_code {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s color_code\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *color_code_str = argv[1];
    int color_code_len = strlen(color_code_str);

    if (color_code_len != 6 && color_code_len != 8) {
        fprintf(stderr, "Invalid color code: %s\n", color_code_str);
        return EXIT_FAILURE;
    }

    struct color_code color_code;
    if (color_code_len == 6) {
        sscanf(color_code_str, "%2hhx%2hhx%2hhx", &color_code.r, &color_code.g, &color_code.b);
    } else {
        sscanf(color_code_str, "%2hhx%2hhx%2hhx%2hhx", &color_code.r, &color_code.g, &color_code.b, &color_code.r);
    }

    struct color color;
    color.r = color_code.r;
    color.g = color_code.g;
    color.b = color_code.b;

    int color_index = -1;
    for (int i = 0; i < COLOR_COUNT; i++) {
        if (color.r == color_names[i][0] && color.g == color_names[i][1] && color.b == color_names[i][2]) {
            color_index = i;
            break;
        }
    }

    if (color_index == -1) {
        fprintf(stderr, "Invalid color code: %s\n", color_code_str);
        return EXIT_FAILURE;
    }

    printf("Color: %s\n", color_names[color_index]);

    return EXIT_SUCCESS;
}