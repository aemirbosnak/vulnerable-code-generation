//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// RGB to Hex Conversion Function
char* rgbToHex(int r, int g, int b) {
    char hex[3][3];
    sprintf(hex[0], "%x", r);
    sprintf(hex[1], "%x", g);
    sprintf(hex[2], "%x", b);

    char hexColor[7];
    strcpy(hexColor, "#");
    for (int i = 0; i < 3; i++) {
        if (strlen(hex[i]) < 2) {
            hexColor[6 + i] = hex[i][0];
            hexColor[7 + i] = hex[i][0];
        } else {
            hexColor[6 + i] = hex[i][0];
            hexColor[7 + i] = hex[i][1];
        }
    }

    return strdup(hexColor);
}

// Hex to RGB Conversion Function
void hexToRgb(char* hexColor, int rgb[3]) {
    char hex[3][2];
    int c;

    hex[0][0] = hexColor[1];
    hex[0][1] = hexColor[2];
    rgb[0] = strtol(hex, &hex + 2, 16);

    hex[1][0] = hexColor[3];
    hex[1][1] = hexColor[4];
    rgb[1] = strtol(hex, &hex + 2, 16);

    hex[2][0] = hexColor[5];
    hex[2][1] = hexColor[6];
    rgb[2] = strtol(hex, &hex + 2, 16);
}

// Function to print the RGB values of a given hex color
void printRgb(char* hexColor) {
    int rgb[3];
    hexToRgb(hexColor, rgb);
    printf("The RGB values for the hex color %s are: R=%d, G=%d, B=%d\n", hexColor, rgb[0], rgb[1], rgb[2]);
}

int main() {
    char* hexColor = "#FF0080";

    // Calling the function to print the RGB values of the given hex color
    printRgb(hexColor);

    // Calling the function to convert RGB values to hex color
    int rgb[3] = {255, 0, 128};
    char* rgbHex = rgbToHex(rgb[0], rgb[1], rgb[2]);
    printf("The hex color equivalent to RGB values R=%d, G=%d, B=%d is: %s\n", rgb[0], rgb[1], rgb[2], rgbHex);

    free(rgbHex);
    return 0;
}