//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_LENGTH 20
#define MAX_HEX_LENGTH 7
#define RGB_BASE 255

// Structure to hold RGB and Hex color values
typedef struct {
    int red;
    int green;
    int blue;
    char hex[MAX_HEX_LENGTH];
} Color;

// Function declarations
Color rgbToHex(int red, int green, int blue);
void printColor(Color color);
int isValidRGB(int red, int green, int blue);
void convertAndDisplayColor(const char* inputColor);
void displayHelp();

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: No color input provided.\n");
        displayHelp();
        return 1;
    }

    convertAndDisplayColor(argv[1]);

    return 0;
}

void displayHelp() {
    printf("Usage: ./color_converter R,G,B\n");
    printf("Where R, G, and B are integers between 0 and 255.\n");
    printf("Example: ./color_converter 255,0,0 for Red\n");
    printf("To convert colors, follow the format inputs.\n");
}

Color rgbToHex(int red, int green, int blue) {
    Color color;
    color.red = red;
    color.green = green;
    color.blue = blue;

    // Create hexadecimal representation
    snprintf(color.hex, MAX_HEX_LENGTH, "#%02X%02X%02X",
             color.red, color.green, color.blue);

    return color;
}

void printColor(Color color) {
    printf("RGB(%d, %d, %d) --> Hex: %s\n", color.red, color.green, color.blue, color.hex);
}

int isValidRGB(int red, int green, int blue) {
    return (red >= 0 && red <= RGB_BASE) &&
           (green >= 0 && green <= RGB_BASE) &&
           (blue >= 0 && blue <= RGB_BASE);
}

void convertAndDisplayColor(const char* inputColor) {
    int red, green, blue;
    char* token;
    char* inputCopy = strdup(inputColor); // Create a modifiable copy

    token = strtok(inputCopy, ",");
    if (token) red = atoi(token);
    else goto cleanup;

    token = strtok(NULL, ",");
    if (token) green = atoi(token);
    else goto cleanup;

    token = strtok(NULL, ",");
    if (token) blue = atoi(token);
    else goto cleanup;

    if (!isValidRGB(red, green, blue)) {
        printf("Error: RGB values must be in the range 0-255.\n");
        goto cleanup;
    }

    Color resultColor = rgbToHex(red, green, blue);
    printColor(resultColor);

cleanup:
    free(inputCopy);
}