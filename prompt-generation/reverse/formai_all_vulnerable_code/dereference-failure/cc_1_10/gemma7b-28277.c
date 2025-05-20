//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLOR_CODE 5

typedef struct Color
{
    int red;
    int green;
    int blue;
    int alpha;
} Color;

Color convert_color(char *color_code)
{
    Color color;
    char *p, *q;
    int i = 0;

    p = color_code;
    q = strchr(p, ';');

    if (q)
    {
        color.red = atoi(p);
        p = strchr(q + 1, ',');
        color.green = atoi(p + 1);
        p = strchr(p + 1, ',');
        color.blue = atoi(p + 1);
        color.alpha = atoi(strchr(p + 1, ';') + 1);
    }
    else
    {
        color.red = atoi(p);
        color.green = atoi(p + 1);
        color.blue = atoi(p + 2);
        color.alpha = 255;
    }

    return color;
}

int main()
{
    char *color_code = "rgb 255, 255, 255; a 100";
    Color color = convert_color(color_code);

    printf("Red: %d, Green: %d, Blue: %d, Alpha: %d\n", color.red, color.green, color.blue, color.alpha);

    return 0;
}