//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE 10

typedef struct ColorCode
{
    char r;
    char g;
    char b;
    char a;
} ColorCode;

ColorCode convertColorCode(char *colorCode)
{
    ColorCode colorCodeStruct;
    char *rgbArray = malloc(MAX_COLOR_CODE);
    char *rgbaArray = malloc(MAX_COLOR_CODE);

    rgbArray = strstr(colorCode, "rgb");
    rgbaArray = strstr(colorCode, "rgba");

    if (rgbArray)
    {
        colorCodeStruct.r = atoi(rgbArray + 4);
        colorCodeStruct.g = atoi(rgbArray + 6);
        colorCodeStruct.b = atoi(rgbArray + 8);
        colorCodeStruct.a = 255;
    }

    else if (rgbaArray)
    {
        colorCodeStruct.r = atoi(rgbaArray + 4);
        colorCodeStruct.g = atoi(rgbaArray + 6);
        colorCodeStruct.b = atoi(rgbaArray + 8);
        colorCodeStruct.a = atoi(rgbaArray + 10);
    }

    else
    {
        printf("Error converting color code.\n");
        exit(1);
    }

    free(rgbArray);
    free(rgbaArray);

    return colorCodeStruct;
}

int main()
{
    char *colorCode = "rgb 255, 255, 255";
    ColorCode colorCodeStruct = convertColorCode(colorCode);

    printf("Red: %d\n", colorCodeStruct.r);
    printf("Green: %d\n", colorCodeStruct.g);
    printf("Blue: %d\n", colorCodeStruct.b);
    printf("Alpha: %d\n", colorCodeStruct.a);

    return 0;
}