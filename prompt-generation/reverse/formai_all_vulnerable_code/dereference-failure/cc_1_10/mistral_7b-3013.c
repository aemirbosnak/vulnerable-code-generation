//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

typedef struct {
    char r;
    char g;
    char b;
} Color;

void parseColor(const char *str, Color *color) {
    int i;
    char c;

    color->r = 0;
    color->g = 0;
    color->b = 0;

    for (i = 0; i < 7 && isdigit(str[i]); i++) {
        color->r *= 10;
        color->r += (str[i] - '0');
    }

    if (str[i] == ':' && isalpha(str[i+1])) {
        i++;
        if (str[i] == 'R') {
            while (isdigit(str[i+1])) {
                color->r *= 10;
                color->r += (str[i+1] - '0');
                i++;
            }
        } else if (str[i] == 'G') {
            i++;
            while (isdigit(str[i+1])) {
                color->g *= 10;
                color->g += (str[i+1] - '0');
                i++;
            }
        } else if (str[i] == 'B') {
            i++;
            while (isdigit(str[i+1])) {
                color->b *= 10;
                color->b += (str[i+1] - '0');
                i++;
            }
        }
    }
}

void printColor(Color color) {
    if (color.r > 255 || color.g > 255 || color.b > 255) {
        printf("%sError: Color value out of range%s\n", RED, RESET);
        exit(EXIT_FAILURE);
    }

    printf("%s%d, %d, %d%s\n", YELLOW, color.r, color.g, color.b, RESET);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("%sUsage: %s <color-code>%s\n", RED, argv[0], RESET);
        exit(EXIT_FAILURE);
    }

    Color color;
    parseColor(argv[1], &color);
    printColor(color);

    return EXIT_SUCCESS;
}