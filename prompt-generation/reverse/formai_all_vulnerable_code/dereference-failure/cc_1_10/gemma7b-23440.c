//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: real-life
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

ColorCode convert_color_code(char *color_code)
{
    ColorCode color_code_struct;
    char *rgb_str, *alpha_str;
    int rgb_values[3], alpha_value;

    // Parse the color code string
    rgb_str = strtok(color_code, ",");
    alpha_str = strtok(NULL, ",");

    // Convert RGB values to integers
    rgb_values[0] = atoi(rgb_str);
    rgb_values[1] = atoi(rgb_str + 1);
    rgb_values[2] = atoi(rgb_str + 2);

    // Convert alpha value to integer
    alpha_value = atoi(alpha_str);

    // Initialize the color code structure
    color_code_struct.red = rgb_values[0];
    color_code_struct.green = rgb_values[1];
    color_code_struct.blue = rgb_values[2];
    color_code_struct.alpha = alpha_value;

    return color_code_struct;
}

int main()
{
    char *color_code = "RGB(255, 255, 255), A(255)";
    ColorCode color_code_struct = convert_color_code(color_code);

    printf("Red: %d\n", color_code_struct.red);
    printf("Green: %d\n", color_code_struct.green);
    printf("Blue: %d\n", color_code_struct.blue);
    printf("Alpha: %d\n", color_code_struct.alpha);

    return 0;
}