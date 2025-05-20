//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_CODE_MAX_LEN 7

typedef struct {
    char *code;
    char *color;
} ColorCode;

ColorCode colorCodes[] = {
    {"#000000", "Black"},
    {"#0000FF", "Blue"},
    {"#008000", "Green"},
    {"#008080", "Teal"},
    {"#00FF00", "Lime"},
    {"#00FF80", "SpringGreen"},
    {"#00FFFF", "Cyan"},
    {"#00FFFF", "Aqua"},
    {"#00C0C0", "Turquoise"},
    {"#00C0FF", "SkyBlue"},
    {"#0080C0", "DodgerBlue"},
    {"#000080", "Navy"},
    {"#00008B", "DarkBlue"},
    {"#008080", "Teal"},
    {"#008B8B", "DarkCyan"},
    {"#008000", "Green"},
    {"#006400", "DarkGreen"},
    {"#008000", "Green"},
    {"#006400", "DarkGreen"},
    {"#000080", "Navy"},
    {"#00008B", "DarkBlue"},
    {"#008080", "Teal"},
    {"#008B8B", "DarkCyan"},
    {"#008000", "Green"},
    {"#006400", "DarkGreen"},
    {"#008000", "Green"},
    {"#006400", "DarkGreen"},
    {"#008080", "Teal"},
    {"#008B8B", "DarkCyan"},
    {"#008000", "Green"},
    {"#006400", "DarkGreen"},
    {"#008000", "Green"},
    {"#006400", "DarkGreen"},
    {"#008080", "Teal"},
    {"#008B8B", "DarkCyan"},
    {"#008000", "Green"},
    {"#006400", "DarkGreen"},
    {"#008000", "Green"},
    {"#006400", "DarkGreen"},
    {"#808080", "Gray"},
    {"#808080", "Gray"},
    {"#C0C0C0", "Silver"},
    {"#C0C0C0", "Silver"},
    {"#FFFFFF", "White"},
    {"#FFFFFF", "White"},
    {"#FF0000", "Red"},
    {"#FF0000", "Red"},
    {"#FF8000", "Orange"},
    {"#FF8000", "Orange"},
    {"#FFFF00", "Yellow"},
    {"#FFFF00", "Yellow"},
    {"#FF8000", "Orange"},
    {"#FF8000", "Orange"},
    {"#FFFF00", "Yellow"},
    {"#FFFF00", "Yellow"},
    {"#FF0000", "Red"},
    {"#FF0000", "Red"},
    {"#FF8000", "Orange"},
    {"#FF8000", "Orange"},
    {"#FFFF00", "Yellow"},
    {"#FFFF00", "Yellow"},
    {"#FF0000", "Red"},
    {"#FF0000", "Red"},
    {"#FF8000", "Orange"},
    {"#FF8000", "Orange"}
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <color code> <color name>\n", argv[0]);
        return 1;
    }

    char *colorCode = argv[1];
    char *colorName = argv[2];

    if (strlen(colorCode) > COLOR_CODE_MAX_LEN) {
        printf("Error: Color code must be %d characters or less (got %d)\n", COLOR_CODE_MAX_LEN, strlen(colorCode));
        return 1;
    }

    ColorCode *color = NULL;

    for (int i = 0; i < sizeof(colorCodes) / sizeof(ColorCode); i++) {
        if (strcmp(colorCode, colorCodes[i].code) == 0) {
            color = &colorCodes[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Error: Color code '%s' not found\n", colorCode);
        return 1;
    }

    if (strcmp(colorName, color->color) == 0) {
        printf("Yay! '%s' is a %s!\n", colorCode, color->color);
    } else {
        printf("Oops! '%s' is not a %s!\n", colorCode, color->color);
    }

    return 0;
}