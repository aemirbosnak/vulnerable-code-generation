//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the color code structure
typedef struct {
    int red;
    int green;
    int blue;
} ColorCode;

// Create a new color code
ColorCode createColorCode(int red, int green, int blue) {
    ColorCode colorCode;
    colorCode.red = red;
    colorCode.green = green;
    colorCode.blue = blue;
    return colorCode;
}

// Convert a color code to a hex string
char *colorCodeToHex(ColorCode colorCode) {
    char *hexString = malloc(7);
    sprintf(hexString, "#%02x%02x%02x", colorCode.red, colorCode.green, colorCode.blue);
    return hexString;
}

// Convert a hex string to a color code
ColorCode hexToColorCode(char *hexString) {
    ColorCode colorCode;
    sscanf(hexString, "#%02x%02x%02x", &colorCode.red, &colorCode.green, &colorCode.blue);
    return colorCode;
}

// Print a color code
void printColorCode(ColorCode colorCode) {
    printf("Red: %d, Green: %d, Blue: %d\n", colorCode.red, colorCode.green, colorCode.blue);
}

// Main function
int main() {
    // Create a color code
    ColorCode colorCode = createColorCode(255, 0, 0);

    // Convert the color code to a hex string
    char *hexString = colorCodeToHex(colorCode);

    // Print the hex string
    printf("Hex string: %s\n", hexString);

    // Convert the hex string back to a color code
    colorCode = hexToColorCode(hexString);

    // Print the color code
    printColorCode(colorCode);

    return 0;
}