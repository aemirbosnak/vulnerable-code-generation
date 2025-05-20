//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE 256

typedef struct ColorCode
{
    int red;
    int green;
    int blue;
    int alpha;
} ColorCode;

ColorCode convert_color_code(char *color_code)
{
    ColorCode color_code_obj;
    char *rgb_values = NULL;
    int i = 0;

    rgb_values = strchr(color_code, ',');
    if (rgb_values)
    {
        color_code_obj.red = atoi(rgb_values + 1);
        rgb_values = strchr(rgb_values + 1, ',');
        if (rgb_values)
        {
            color_code_obj.green = atoi(rgb_values + 1);
            rgb_values = strchr(rgb_values + 1, ',');
            if (rgb_values)
            {
                color_code_obj.blue = atoi(rgb_values + 1);
                color_code_obj.alpha = atoi(color_code + MAX_COLOR_CODE);
            }
        }
    }

    return color_code_obj;
}

int main()
{
    char *color_code = "rgb(255, 255, 255), a(255)";
    ColorCode color_code_obj = convert_color_code(color_code);

    printf("Red: %d\n", color_code_obj.red);
    printf("Green: %d\n", color_code_obj.green);
    printf("Blue: %d\n", color_code_obj.blue);
    printf("Alpha: %d\n", color_code_obj.alpha);

    return 0;
}