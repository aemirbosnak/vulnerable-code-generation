//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLOR_NAME 20
#define HEX_LENGTH 7 

typedef struct {
    char name[MAX_COLOR_NAME];
    int r, g, b; // Red, Green, Blue components
} Color;

Color colors[] = {
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"White", 255, 255, 255},
    {"Black", 0, 0, 0},
    {"Yellow", 255, 255, 0},
    {"Cyan", 0, 255, 255},
    {"Magenta", 255, 0, 255},
    {"Gray", 128, 128, 128},
    {"Orange", 255, 165, 0}
};

int colorCount = sizeof(colors) / sizeof(colors[0]);

void printUsage() {
    printf("Usage:\n");
    printf("\t./color_converter <color_name>\n");
    printf("\t./color_converter <hex_color_code>\n");
    printf("\nAvailable colors:\n");

    for (int i = 0; i < colorCount; i++) {
        printf("\t- %s\n", colors[i].name);
    }

    printf("\nHex format is #RRGGBB where RR, GG, BB are hexadecimal digits.\n");
}

void convertColorNameToHex(char *colorName) {
    for (int i = 0; i < colorCount; i++) {
        if (strcasecmp(colors[i].name, colorName) == 0) {
            printf("Hex for %s is #%02X%02X%02X\n", colors[i].name, colors[i].r, colors[i].g, colors[i].b);
            return;
        }
    }
    printf("Color not found: %s\n", colorName);
}

void convertHexToColorName(char *hexColorCode) {
    if (hexColorCode[0] == '#') {
        hexColorCode++;
    }

    int r, g, b;
    if (sscanf(hexColorCode, "%02x%02x%02x", &r, &g, &b) != 3) {
        printf("Invalid hex color format: %s\n", hexColorCode);
        return;
    }

    for (int i = 0; i < colorCount; i++) {
        if (colors[i].r == r && colors[i].g == g && colors[i].b == b) {
            printf("Color name for hex #%s is %s\n", hexColorCode, colors[i].name);
            return;
        }
    }

    printf("Hex color not found: #%s\n", hexColorCode);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printUsage();
        return EXIT_FAILURE;
    }

    // Check if the input is a color name or a hex code
    if (argv[1][0] == '#') {
        convertHexToColorName(argv[1]);
    } else {
        convertColorNameToHex(argv[1]);
    }

    return EXIT_SUCCESS;
}