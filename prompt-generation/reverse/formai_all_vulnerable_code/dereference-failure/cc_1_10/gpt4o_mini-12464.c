//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME 20
#define MAX_HEX_LENGTH 8

typedef struct {
    char name[MAX_COLOR_NAME];
    char hex[MAX_HEX_LENGTH];
} Color;

Color colorPalette[] = {
    {"Black", "#000000"},
    {"White", "#FFFFFF"},
    {"Red", "#FF0000"},
    {"Green", "#00FF00"},
    {"Blue", "#0000FF"},
    {"Cyan", "#00FFFF"},
    {"Magenta", "#FF00FF"},
    {"Yellow", "#FFFF00"},
    {"Gray", "#808080"},
    {"Maroon", "#800000"},
    {"Olive", "#808000"},
    {"DarkGreen", "#006400"},
    {"Purple", "#800080"},
    {"Teal", "#008080"},
    {"Navy", "#000080"},
    {"Silver", "#C0C0C0"}
};

int colorCount = sizeof(colorPalette) / sizeof(colorPalette[0]);

void printUsage() {
    printf("Color Code Converter\n");
    printf("Usage:\n");
    printf("  To convert color name to hex: ./color_converter name <ColorName>\n");
    printf("  To convert hex code to color name: ./color_converter hex <HexCode>\n");
    printf("Example:\n");
    printf("  ./color_converter name Red\n");
    printf("  ./color_converter hex #00FF00\n");
}

void convertColorNameToHex(char *colorName) {
    for (int i = 0; i < colorCount; i++) {
        if (strcasecmp(colorName, colorPalette[i].name) == 0) {
            printf("Hex code for %s: %s\n", colorPalette[i].name, colorPalette[i].hex);
            return;
        }
    }
    printf("Color '%s' not found in the palette.\n", colorName);
}

void convertHexToColorName(char *hexCode) {
    for (int i = 0; i < colorCount; i++) {
        if (strcasecmp(hexCode, colorPalette[i].hex) == 0) {
            printf("Color name for %s: %s\n", hexCode, colorPalette[i].name);
            return;
        }
    }
    printf("Hex code '%s' not found in the palette.\n", hexCode);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "name") == 0) {
        convertColorNameToHex(argv[2]);
    } else if (strcmp(argv[1], "hex") == 0) {
        convertHexToColorName(argv[2]);
    } else {
        printUsage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}