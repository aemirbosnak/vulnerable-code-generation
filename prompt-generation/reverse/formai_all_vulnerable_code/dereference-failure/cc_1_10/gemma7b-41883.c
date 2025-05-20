//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE 255

typedef struct Color
{
    int red;
    int green;
    int blue;
    int alpha;
} Color;

Color convert_color_code(char *code)
{
    Color color;
    char *ptr = code;
    int i = 0;

    // Extract the RGB values from the code
    while (ptr[i] && ptr[i] != ';')
    {
        color.red = atoi(ptr);
        ptr++;
        color.green = atoi(ptr);
        ptr++;
        color.blue = atoi(ptr);
        ptr++;
        color.alpha = atoi(ptr);
        ptr++;
        i++;
    }

    return color;
}

int main()
{
    char *color_code = "rgb(255, 255, 255);";
    Color color = convert_color_code(color_code);

    // Print the converted color values
    printf("Red: %d\n", color.red);
    printf("Green: %d\n", color.green);
    printf("Blue: %d\n", color.blue);
    printf("Alpha: %d\n", color.alpha);

    return 0;
}