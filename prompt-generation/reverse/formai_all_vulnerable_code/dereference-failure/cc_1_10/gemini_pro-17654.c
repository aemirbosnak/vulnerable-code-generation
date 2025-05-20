//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 10

typedef struct {
    char *name;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} ColorCode;

ColorCode colorCodes[] = {
    { "black",   0x00, 0x00, 0x00 },
    { "white",   0xFF, 0xFF, 0xFF },
    { "red",     0xFF, 0x00, 0x00 },
    { "green",   0x00, 0xFF, 0x00 },
    { "blue",    0x00, 0x00, 0xFF },
    { "yellow",  0xFF, 0xFF, 0x00 },
    { "magenta", 0xFF, 0x00, 0xFF },
    { "cyan",    0x00, 0xFF, 0xFF },
    { "orange",  0xFF, 0x80, 0x00 },
    { "purple",  0x80, 0x00, 0xFF },
    { "brown",   0x80, 0x80, 0x00 },
    { "gray",    0x80, 0x80, 0x80 },
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color code>\n", argv[0]);
        return 1;
    }

    char *colorCode = argv[1];

    if (strlen(colorCode) > MAX_COLOR_CODE_LENGTH) {
        printf("Error: color code length must be less than or equal to %d\n", MAX_COLOR_CODE_LENGTH);
        return 1;
    }

    ColorCode *colorCodePtr = NULL;

    for (int i = 0; i < sizeof(colorCodes) / sizeof(ColorCode); i++) {
        if (strcmp(colorCode, colorCodes[i].name) == 0) {
            colorCodePtr = &colorCodes[i];
            break;
        }
    }

    if (colorCodePtr == NULL) {
        printf("Error: invalid color code: %s\n", colorCode);
        return 1;
    }

    printf("Color code: %s\n", colorCode);
    printf("Red: %d\n", colorCodePtr->red);
    printf("Green: %d\n", colorCodePtr->green);
    printf("Blue: %d\n", colorCodePtr->blue);

    return 0;
}