//FormAI DATASET v1.0 Category: Color Code Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void convertToHex(char *inputColor, char *outputColor) {
    char *hexCode = (char*) malloc(7 * sizeof(char));

    char red[3], green[3], blue[3];
    strncpy(red, &inputColor[1], 2);
    strncpy(green, &inputColor[3], 2);
    strncpy(blue, &inputColor[5], 2);

    int r = strtol(red, NULL, 16), g = strtol(green, NULL, 16), b = strtol(blue, NULL, 16);
    sprintf(hexCode, "#%02x%02x%02x", r, g, b);

    strncpy(outputColor, hexCode, 7);
    free(hexCode);
}

void convertToRGB(char *inputColor, char *outputColor) {
    char *rgbCode = (char*) malloc(12 * sizeof(char));

    uint32_t hex = strtoul(inputColor, NULL, 16);
    int r = (hex & 0xFF0000) >> 16, g = (hex & 0xFF00) >> 8, b = (hex & 0xFF);
    sprintf(rgbCode, "rgb(%d, %d, %d)", r, g, b);
  
    strncpy(outputColor, rgbCode, 12);
    free(rgbCode);
}

int main() {
    printf("Welcome to the Color Code Converter!\n");
    printf("Enter the color code you want to convert: ");

    char inputColor[8];
    scanf("%s", inputColor);

    if (inputColor[0] == '#') {
        char outputColor[12];
        convertToRGB(inputColor, outputColor);
        printf("The RGB representation of %s is %s.\n", inputColor, outputColor);
    } else {
        char outputColor[7];
        convertToHex(inputColor, outputColor);
        printf("The hex representation of %s is %s.\n", inputColor, outputColor);
    }

    return 0;
}