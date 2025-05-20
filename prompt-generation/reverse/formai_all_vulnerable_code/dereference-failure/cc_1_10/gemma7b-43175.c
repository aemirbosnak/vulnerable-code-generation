//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE 10

typedef struct ColorCode
{
    int red;
    int green;
    int blue;
    int alpha;
} ColorCode;

ColorCode convertColorCode(char *colorCode)
{
    ColorCode colorCodeStruct;

    // Extract the red value
    colorCodeStruct.red = atoi(strchr(colorCode, ',') - colorCode);

    // Extract the green value
    colorCodeStruct.green = atoi(strchr(strchr(colorCode, ',') + 1, ',') - strchr(colorCode, ',') - 1);

    // Extract the blue value
    colorCodeStruct.blue = atoi(strchr(strchr(colorCode, ',') + 1, ',') + 1 - strchr(colorCode, ',') - 1);

    // Extract the alpha value
    colorCodeStruct.alpha = atoi(strchr(strchr(colorCode, ',') + 1, ')') - strchr(colorCode, ',') - 1);

    return colorCodeStruct;
}

int main()
{
    char colorCode[MAX_COLOR_CODE];
    ColorCode colorCodeStruct;

    // Get the color code from the user
    printf("Enter the color code: ");
    scanf("%s", colorCode);

    // Convert the color code to a struct
    colorCodeStruct = convertColorCode(colorCode);

    // Print the converted color code
    printf("Red: %d\n", colorCodeStruct.red);
    printf("Green: %d\n", colorCodeStruct.green);
    printf("Blue: %d\n", colorCodeStruct.blue);
    printf("Alpha: %d\n", colorCodeStruct.alpha);

    return 0;
}