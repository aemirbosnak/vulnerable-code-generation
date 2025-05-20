//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_c_color_code(char **color_code)
{
    char *red_str, *green_str, *blue_str, *alpha_str;
    int red, green, blue, alpha;

    red_str = strchr(*color_code, "r");
    green_str = strchr(*color_code, "g");
    blue_str = strchr(*color_code, "b");
    alpha_str = strchr(*color_code, "a");

    if (red_str)
    {
        red = atoi(red_str + 1);
    }

    if (green_str)
    {
        green = atoi(green_str + 1);
    }

    if (blue_str)
    {
        blue = atoi(blue_str + 1);
    }

    if (alpha_str)
    {
        alpha = atoi(alpha_str + 1);
    }

    *color_code = malloc(20);
    sprintf(*color_code, "#%02x%02x%02x%02x", red, green, blue, alpha);
}

int main()
{
    char *color_code = malloc(20);
    printf("Enter a color code: ");
    scanf("%s", color_code);

    convert_c_color_code(&color_code);

    printf("Converted color code: %s\n", color_code);

    free(color_code);

    return 0;
}