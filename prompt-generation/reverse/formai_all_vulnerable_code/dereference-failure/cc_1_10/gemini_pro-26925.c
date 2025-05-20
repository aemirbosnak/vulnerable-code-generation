//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_BLACK "\x1b[30m"
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_WHITE "\x1b[37m"

#define COLOR_RESET "\x1b[0m"

void print_color(const char *color_code, const char *text)
{
    printf("%s%s%s", color_code, text, COLOR_RESET);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: %s <color> <text>\n", argv[0]);
        printf("Available colors: black, red, green, yellow, blue, magenta, cyan, white\n");
        return EXIT_FAILURE;
    }

    const char *color = argv[1];
    const char *text = argv[2];

    if (strcmp(color, "black") == 0) {
        print_color(COLOR_BLACK, text);
    } else if (strcmp(color, "red") == 0) {
        print_color(COLOR_RED, text);
    } else if (strcmp(color, "green") == 0) {
        print_color(COLOR_GREEN, text);
    } else if (strcmp(color, "yellow") == 0) {
        print_color(COLOR_YELLOW, text);
    } else if (strcmp(color, "blue") == 0) {
        print_color(COLOR_BLUE, text);
    } else if (strcmp(color, "magenta") == 0) {
        print_color(COLOR_MAGENTA, text);
    } else if (strcmp(color, "cyan") == 0) {
        print_color(COLOR_CYAN, text);
    } else if (strcmp(color, "white") == 0) {
        print_color(COLOR_WHITE, text);
    } else {
        printf("Invalid color: %s\n", color);
        printf("Available colors: black, red, green, yellow, blue, magenta, cyan, white\n");
        return EXIT_FAILURE;
    }

    printf("\n");
    return EXIT_SUCCESS;
}