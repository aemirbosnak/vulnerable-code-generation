//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE 256

typedef struct ColorCode {
    int red;
    int green;
    int blue;
    int alpha;
} ColorCode;

ColorCode convertColorCode(char *colorCode) {
    ColorCode colorCodeStruct = { 0, 0, 0, 0 };

    // Strip the # character and normalize the color code
    char normalizedColorCode[MAX_COLOR_CODE] = "";
    int i = 0;
    for (i = 1; colorCode[i] != '\0'; i++) {
        normalizedColorCode[i - 1] = colorCode[i];
    }

    // Convert the normalized color code to integers
    char *redStr = strchr(normalizedColorCode, ',');
    colorCodeStruct.red = atoi(redStr);

    char *greenStr = strchr(redStr + 1, ',');
    colorCodeStruct.green = atoi(greenStr);

    char *blueStr = strchr(greenStr + 1, ',');
    colorCodeStruct.blue = atoi(blueStr);

    // Convert the alpha value if it is present
    if (blueStr + 1) {
        char *alphaStr = strchr(blueStr + 1, ')');
        colorCodeStruct.alpha = atoi(alphaStr);
    }

    return colorCodeStruct;
}

int main() {
    char *colorCode = "#FF0000";
    ColorCode colorCodeStruct = convertColorCode(colorCode);

    printf("Red: %d\n", colorCodeStruct.red);
    printf("Green: %d\n", colorCodeStruct.green);
    printf("Blue: %d\n", colorCodeStruct.blue);
    printf("Alpha: %d\n", colorCodeStruct.alpha);

    return 0;
}