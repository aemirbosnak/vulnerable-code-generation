//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
    int rgb[3];
    struct Color* next;
} Color;

Color* createColor(char* name, int r, int g, int b)
{
    Color* color = (Color*)malloc(sizeof(Color));
    strcpy(color->name, name);
    color->rgb[0] = r;
    color->rgb[1] = g;
    color->rgb[2] = b;
    color->next = NULL;
    return color;
}

void convertColor(Color* color, int targetR, int targetG, int targetB)
{
    int deltaR = abs(color->rgb[0] - targetR);
    int deltaG = abs(color->rgb[1] - targetG);
    int deltaB = abs(color->rgb[2] - targetB);

    printf("The closest color to %s is:\n", color->name);
    printf("Red: %d, Green: %d, Blue: %d\n", targetR, targetG, targetB);
    printf("Delta: Red: %d, Green: %d, Blue: %d\n", deltaR, deltaG, deltaB);
    printf("Color: %s\n", color->name);
    printf("RGB: %d, %d, %d\n", color->rgb[0], color->rgb[1], color->rgb[2]);
    printf("\n");
}

int main()
{
    Color* colors = createColor("Red", 255, 0, 0);
    Color* green = createColor("Green", 0, 255, 0);
    Color* blue = createColor("Blue", 0, 0, 255);

    convertColor(colors, 128, 128, 128);
    convertColor(green, 128, 128, 128);
    convertColor(blue, 128, 128, 128);

    return 0;
}