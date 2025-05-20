//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char hex[MAX_COLOR_CODE_LENGTH];
    int r;
    int g;
    int b;
} color_code;

color_code* create_color_code(char* hex_str) {
    color_code* color = (color_code*)malloc(sizeof(color_code));
    strncpy(color->hex, hex_str, MAX_COLOR_CODE_LENGTH);
    color->r = 0;
    color->g = 0;
    color->b = 0;
    return color;
}

void set_rgb_values(color_code* color, int r, int g, int b) {
    color->r = r;
    color->g = g;
    color->b = b;
}

int get_r_value(color_code* color) {
    return color->r;
}

int get_g_value(color_code* color) {
    return color->g;
}

int get_b_value(color_code* color) {
    return color->b;
}

char* get_hex_string(color_code* color) {
    return color->hex;
}

void destroy_color_code(color_code* color) {
    free(color);
}

int main() {
    color_code* color1 = create_color_code("#ff0000");
    set_rgb_values(color1, 255, 0, 0);
    printf("Color 1: %s\n", get_hex_string(color1));
    printf("Red Value: %d\n", get_r_value(color1));
    printf("Green Value: %d\n", get_g_value(color1));
    printf("Blue Value: %d\n", get_b_value(color1));

    color_code* color2 = create_color_code("#00ff00");
    set_rgb_values(color2, 0, 255, 0);
    printf("\nColor 2: %s\n", get_hex_string(color2));
    printf("Red Value: %d\n", get_r_value(color2));
    printf("Green Value: %d\n", get_g_value(color2));
    printf("Blue Value: %d\n", get_b_value(color2));

    destroy_color_code(color1);
    destroy_color_code(color2);
    return 0;
}