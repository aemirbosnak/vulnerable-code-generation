//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE 10

typedef struct ColorCode {
    char red;
    char green;
    char blue;
    char alpha;
} ColorCode;

ColorCode convert_color_code(char *color_code) {
    ColorCode color_code_obj;
    char *rgb_code = malloc(MAX_COLOR_CODE);
    char *alpha_code = malloc(MAX_COLOR_CODE);

    // Extract RGB and alpha values from the color code
    int i = 0;
    for (i = 0; color_code[i] != ';'; i++) {
        rgb_code[i] = color_code[i];
    }
    rgb_code[i] = '\0';

    for (i = i + 1; color_code[i] != '\0'; i++) {
        alpha_code[i - 1] = color_code[i];
    }
    alpha_code[i - 1] = '\0';

    color_code_obj.red = rgb_code[0];
    color_code_obj.green = rgb_code[1];
    color_code_obj.blue = rgb_code[2];
    color_code_obj.alpha = alpha_code[0];

    free(rgb_code);
    free(alpha_code);

    return color_code_obj;
}

int main() {
    char *color_code = "rgb:255,0,0;a:255";
    ColorCode color_code_obj = convert_color_code(color_code);

    printf("Red: %c\n", color_code_obj.red);
    printf("Green: %c\n", color_code_obj.green);
    printf("Blue: %c\n", color_code_obj.blue);
    printf("Alpha: %c\n", color_code_obj.alpha);

    return 0;
}