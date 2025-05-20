//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color code structure
typedef struct {
    char *name;
    int red;
    int green;
    int blue;
} ColorCode;

// Define an array of color codes
ColorCode colorCodes[] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"magenta", 255, 0, 255},
    {"cyan", 0, 255, 255},
    {"orange", 255, 165, 0},
    {"purple", 128, 0, 128},
    {"brown", 165, 42, 42},
    {"gray", 128, 128, 128},
    {"pink", 255, 192, 203},
    {"turquoise", 64, 224, 208},
    {"lime", 0, 255, 127},
    {"navy", 0, 0, 128},
    {"teal", 0, 128, 128},
    {"olive", 128, 128, 0},
    {"maroon", 128, 0, 0},
};

// Get the color code for a given name
ColorCode *getColorCode(char *name) {
    for (int i = 0; i < sizeof(colorCodes) / sizeof(ColorCode); i++) {
        if (strcmp(name, colorCodes[i].name) == 0) {
            return &colorCodes[i];
        }
    }

    return NULL;
}

// Print the color code for a given name
void printColorCode(char *name) {
    ColorCode *colorCode = getColorCode(name);

    if (colorCode != NULL) {
        printf("%s: %d, %d, %d\n", colorCode->name, colorCode->red, colorCode->green, colorCode->blue);
    } else {
        printf("%s is not a valid color name.\n", name);
    }
}

// Convert a color code to a hex string
char *colorCodeToHex(ColorCode *colorCode) {
    char *hexString = malloc(7);

    sprintf(hexString, "#%02x%02x%02x", colorCode->red, colorCode->green, colorCode->blue);

    return hexString;
}

// Print the hex string for a given color name
void printHex(char *name) {
    ColorCode *colorCode = getColorCode(name);

    if (colorCode != NULL) {
        printf("%s: %s\n", colorCode->name, colorCodeToHex(colorCode));
    } else {
        printf("%s is not a valid color name.\n", name);
    }
}

// Main function
int main() {
    // Get the color name from the user
    char *colorName = malloc(100);
    printf("Enter a color name: ");
    scanf("%s", colorName);

    // Print the color code
    printColorCode(colorName);

    // Print the hex string
    printHex(colorName);

    return 0;
}