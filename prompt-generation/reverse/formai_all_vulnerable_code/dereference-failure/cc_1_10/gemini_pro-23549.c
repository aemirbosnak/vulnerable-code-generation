//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int red;
    int green;
    int blue;
} Color;

Color colors[] = {
    { "Black", 0, 0, 0},
    { "White", 255, 255, 255},
    { "Red", 255, 0, 0},
    { "Green", 0, 128, 0},
    { "Blue", 0, 0, 255},
    { "Yellow", 255, 255, 0},
    { "Magenta", 255, 0, 255},
    { "Cyan", 0, 255, 255}
};

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s <color name>\n", argv[0]);
        return 1;
    }

    char *colorName = argv[1];

    int found = 0;
    int i;
    for (i = 0; i < sizeof(colors) / sizeof(Color); i++) {
        if (strcmp(colorName, colors[i].name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Red: %d\n", colors[i].red);
        printf("Green: %d\n", colors[i].green);
        printf("Blue: %d\n", colors[i].blue);
    } else {
        printf("Color not found.\n");
        return 1;
    }

    return 0;
}