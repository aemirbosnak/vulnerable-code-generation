//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
};

char *colors[] = {
    "black",
    "red",
    "green",
    "yellow",
    "blue",
    "magenta",
    "cyan",
    "white",
};

unsigned int color_to_code(char *color)
{
    unsigned int i;

    for (i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
        if (!strcmp(color, colors[i])) {
            return i;
        }
    }

    return -1;
}

char *code_to_color(unsigned int code)
{
    if (code < sizeof(colors) / sizeof(colors[0])) {
        return colors[code];
    }

    return NULL;
}

int main(int argc, char **argv)
{
    char *color;
    unsigned int code;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <color>\n", argv[0]);
        return EXIT_FAILURE;
    }

    color = argv[1];

    code = color_to_code(color);
    if (code == -1) {
        fprintf(stderr, "Invalid color: %s\n", color);
        return EXIT_FAILURE;
    }

    printf("Color: %s\n", color);
    printf("Code: %u\n", code);

    return EXIT_SUCCESS;
}