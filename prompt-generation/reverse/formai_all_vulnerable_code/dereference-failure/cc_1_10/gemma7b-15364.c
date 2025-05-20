//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 11

typedef struct ColorCode
{
    char r;
    char g;
    char b;
    char a;
} ColorCode;

ColorCode convert_color_code(char* color_code)
{
    ColorCode color_code_struct;
    char* color_code_parsed;
    int i = 0;

    color_code_parsed = malloc(MAX_COLOR_CODE_LENGTH);

    // Remove brackets from the color code
    while (color_code[i] != ')')
    {
        color_code_parsed[i] = color_code[i];
        i++;
    }

    color_code_parsed[i] = '\0';

    // Convert the parsed code into a ColorCode structure
    color_code_struct.r = atoi(color_code_parsed);
    color_code_struct.g = atoi(color_code_parsed + 2);
    color_code_struct.b = atoi(color_code_parsed + 4);
    color_code_struct.a = atoi(color_code_parsed + 6);

    free(color_code_parsed);

    return color_code_struct;
}

int main()
{
    char* color_code = "rgb(255, 255, 255)";
    ColorCode color_code_struct = convert_color_code(color_code);

    printf("Red: %d\n", color_code_struct.r);
    printf("Green: %d\n", color_code_struct.g);
    printf("Blue: %d\n", color_code_struct.b);
    printf("Alpha: %d\n", color_code_struct.a);

    return 0;
}