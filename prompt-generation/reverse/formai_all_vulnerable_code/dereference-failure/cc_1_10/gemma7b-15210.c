//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 11

typedef struct ColorCode
{
    int r;
    int g;
    int b;
    int a;
} ColorCode;

ColorCode* convert_color_code(char* color_code)
{
    ColorCode* color_code_ptr = malloc(sizeof(ColorCode));

    char* color_code_without_parens = strchr(color_code, ')') - color_code;

    char* r_str = strchr(color_code_without_parens, ',');
    color_code_ptr->r = atoi(r_str);

    char* g_str = strchr(r_str + 1, ',');
    color_code_ptr->g = atoi(g_str);

    char* b_str = strchr(g_str + 1, ',');
    color_code_ptr->b = atoi(b_str);

    char* a_str = strchr(b_str + 1, ')');
    color_code_ptr->a = atoi(a_str);

    return color_code_ptr;
}

int main()
{
    char* color_code = "RGB(255, 0, 0)";

    ColorCode* color_code_ptr = convert_color_code(color_code);

    printf("Red: %d\n", color_code_ptr->r);
    printf("Green: %d\n", color_code_ptr->g);
    printf("Blue: %d\n", color_code_ptr->b);
    printf("Alpha: %d\n", color_code_ptr->a);

    free(color_code_ptr);

    return 0;
}