//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_WHITE "\x1b[37m"
#define COLOR_RESET "\x1b[0m"

typedef struct {
    char r, g, b;
    char name[10];
} Color;

Color colors[7] = {
    {255, 0, 0, "Red"},
    {0, 255, 0, "Green"},
    {0, 0, 255, "Blue"},
    {0, 255, 255, "Cyan"},
    {255, 255, 0, "Yellow"},
    {255, 0, 255, "Magenta"},
    {255, 255, 255, "White"}
};

void print_color(Color c) {
    printf(COLOR_RESET);
    printf("%s%s%s%s", COLOR_MAGENTA, "Once upon a time, in a land of code,", COLOR_RESET);
    printf(COLOR_YELLOW, "there existed a simple program that could convert colors.\n");
    printf(COLOR_CYAN, "This program, with a wave of a magical wand,\n");
    printf(COLOR_RESET);
    printf("could transform %s into:\n", c.name);
    printf(COLOR_RED, "%s: %s\n", c.name, COLOR_RED);
    printf(COLOR_GREEN, "%s: %s\n", c.name, COLOR_GREEN);
    printf(COLOR_BLUE, "%s: %s\n", c.name, COLOR_BLUE);
    printf(COLOR_MAGENTA, "%s: %s\n", c.name, COLOR_MAGENTA);
    printf(COLOR_CYAN, "%s: %s\n", c.name, COLOR_CYAN);
    printf(COLOR_YELLOW, "%s: %s\n", c.name, COLOR_YELLOW);
    printf(COLOR_WHITE, "%s: %s\n", c.name, COLOR_WHITE);
    printf(COLOR_RESET);
    printf("%s%s%s%s", COLOR_MAGENTA, "May your day be filled with colorful wonders!\n", COLOR_RESET, COLOR_RESET);

    printf(COLOR_RED, "\x1b[48;5;%dm", c.r);
    printf(COLOR_GREEN, "\x1b[48;5;%dm", c.g);
    printf(COLOR_BLUE, "\x1b[48;5;%dm\n", c.b);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color name>\n\nColors available:\nRed\nGreen\nBlue\nCyan\nYellow\nMagenta\nWhite\n", argv[0]);
        return 1;
    }

    for (int i = 0; i < 7; i++) {
        if (strcmp(argv[1], colors[i].name) == 0) {
            print_color(colors[i]);
            return 0;
        }
    }

    printf("Invalid color name.\n");
    return 1;
}