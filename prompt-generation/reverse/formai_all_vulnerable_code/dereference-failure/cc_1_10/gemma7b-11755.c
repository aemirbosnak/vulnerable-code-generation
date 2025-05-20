//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 20

typedef struct ColorCode
{
    char r, g, b, a;
    int intensity;
} ColorCode;

ColorCode convert_color_code(char *color_code)
{
    ColorCode color_code_struct;

    // Extract the RGB values from the color code
    char *r_str = strchr(color_code, ',');
    char *g_str = strchr(r_str + 1, ',');
    char *b_str = strchr(g_str + 1, ',');

    color_code_struct.r = atoi(r_str + 1);
    color_code_struct.g = atoi(g_str + 1);
    color_code_struct.b = atoi(b_str + 1);

    // Extract the alpha value (optional)
    if (strchr(b_str + 1, ';') != NULL)
    {
        color_code_struct.a = atoi(strchr(b_str + 1, ';') + 1);
    }

    // Extract the intensity value (optional)
    if (strchr(b_str + 1, '#') != NULL)
    {
        color_code_struct.intensity = atoi(strchr(b_str + 1, '#') + 1);
    }

    return color_code_struct;
}

int main()
{
    char *color_code = "rgb(255, 255, 255)";

    ColorCode color_code_struct = convert_color_code(color_code);

    printf("Red: %d\n", color_code_struct.r);
    printf("Green: %d\n", color_code_struct.g);
    printf("Blue: %d\n", color_code_struct.b);
    printf("Alpha: %d\n", color_code_struct.a);
    printf("Intensity: %d\n", color_code_struct.intensity);

    return 0;
}