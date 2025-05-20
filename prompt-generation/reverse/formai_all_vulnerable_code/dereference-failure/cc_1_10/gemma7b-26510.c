//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Color
{
    int red;
    int green;
    int blue;
    int alpha;
} Color;

Color convert_color(char *color_str)
{
    Color color;

    // Extract the RGB values from the color string
    char *rgb_values = strchr(color_str, '(');
    rgb_values++;
    char *red_str = strchr(rgb_values, ',');
    color.red = atoi(red_str);

    char *green_str = strchr(red_str, ',');
    color.green = atoi(green_str);

    char *blue_str = strchr(green_str, ')');
    color.blue = atoi(blue_str);

    // Extract the alpha value (optional)
    if (blue_str)
    {
        char *alpha_str = strchr(blue_str, ',');
        alpha_str++;
        color.alpha = atoi(alpha_str);
    }

    return color;
}

int main()
{
    char *color_str = "rgb(255, 255, 255)";
    Color color = convert_color(color_str);

    printf("Red: %d\n", color.red);
    printf("Green: %d\n", color.green);
    printf("Blue: %d\n", color.blue);
    printf("Alpha: %d\n", color.alpha);

    return 0;
}