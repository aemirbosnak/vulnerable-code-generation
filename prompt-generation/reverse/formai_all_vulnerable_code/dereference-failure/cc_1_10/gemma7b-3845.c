//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 255

typedef struct Color
{
    char name[MAX_COLOR_NAME_LENGTH];
    int r;
    int g;
    int b;
    int a;
} Color;

Color convert_color_code(char *color_code)
{
    Color color;

    // Strip the brackets from the color code
    char *color_name = strchr(color_code, '(');
    *color_name = '\0';

    // Extract the RGB and A values
    char *r_str = strchr(color_code, ',');
    char *g_str = strchr(r_str, ',');
    char *b_str = strchr(g_str, ',');
    char *a_str = strchr(b_str, ')');

    color.r = atoi(r_str + 1);
    color.g = atoi(g_str + 1);
    color.b = atoi(b_str + 1);
    color.a = atoi(a_str + 1);

    // Copy the color name into the structure
    strncpy(color.name, color_code, MAX_COLOR_NAME_LENGTH - 1);

    return color;
}

int main()
{
    char *color_code = "RGB(255, 255, 255), rgba(0, 0, 0, 100)";

    Color color = convert_color_code(color_code);

    printf("Color name: %s\n", color.name);
    printf("Red: %d\n", color.r);
    printf("Green: %d\n", color.g);
    printf("Blue: %d\n", color.b);
    printf("Alpha: %d\n", color.a);

    return 0;
}