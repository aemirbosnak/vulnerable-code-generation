//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLOR_CODE_LENGTH 20

typedef struct ColorCode {
    char red[MAX_COLOR_CODE_LENGTH];
    char green[MAX_COLOR_CODE_LENGTH];
    char blue[MAX_COLOR_CODE_LENGTH];
    char alpha[MAX_COLOR_CODE_LENGTH];
} ColorCode;

ColorCode convert_color_code(char *color_code) {
    ColorCode color_code_obj;
    char *red_ptr, *green_ptr, *blue_ptr, *alpha_ptr;

    red_ptr = color_code_obj.red;
    green_ptr = color_code_obj.green;
    blue_ptr = color_code_obj.blue;
    alpha_ptr = color_code_obj.alpha;

    // Extract red value
    red_ptr = strchr(color_code, ',') + 1;
    strncpy(red_ptr, strchr(red_ptr, ',') - red_ptr, MAX_COLOR_CODE_LENGTH - 1);

    // Extract green value
    green_ptr = strchr(red_ptr, ',') + 1;
    strncpy(green_ptr, strchr(green_ptr, ',') - green_ptr, MAX_COLOR_CODE_LENGTH - 1);

    // Extract blue value
    blue_ptr = strchr(green_ptr, ',') + 1;
    strncpy(blue_ptr, strchr(blue_ptr, ')') - blue_ptr, MAX_COLOR_CODE_LENGTH - 1);

    // Extract alpha value
    alpha_ptr = strchr(blue_ptr, ')') + 1;
    strncpy(alpha_ptr, strchr(alpha_ptr, '}') - alpha_ptr, MAX_COLOR_CODE_LENGTH - 1);

    return color_code_obj;
}

int main() {
    char color_code[] = "rgb(255, 255, 255), rgba(255, 255, 255, 100)";
    ColorCode color_code_obj = convert_color_code(color_code);

    printf("Red: %s\n", color_code_obj.red);
    printf("Green: %s\n", color_code_obj.green);
    printf("Blue: %s\n", color_code_obj.blue);
    printf("Alpha: %s\n", color_code_obj.alpha);

    return 0;
}