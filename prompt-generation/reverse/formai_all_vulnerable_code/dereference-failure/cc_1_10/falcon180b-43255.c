//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char *hex_code;
    int red;
    int green;
    int blue;
} ColorCode;

ColorCode *create_color_code(char *hex_code) {
    ColorCode *color_code = (ColorCode *)malloc(sizeof(ColorCode));
    if (color_code == NULL) {
        printf("Error: Could not allocate memory for color code.\n");
        exit(1);
    }
    strcpy(color_code->hex_code, hex_code);
    color_code->red = 0;
    color_code->green = 0;
    color_code->blue = 0;
    return color_code;
}

void set_color_code_values(ColorCode *color_code, int red, int green, int blue) {
    color_code->red = red;
    color_code->green = green;
    color_code->blue = blue;
}

int get_color_code_value(ColorCode *color_code, int index) {
    if (index == 0) {
        return color_code->red;
    } else if (index == 1) {
        return color_code->green;
    } else if (index == 2) {
        return color_code->blue;
    } else {
        printf("Error: Invalid color code value index.\n");
        exit(1);
    }
}

void print_color_code_values(ColorCode *color_code) {
    printf("Color code: %s\n", color_code->hex_code);
    printf("Red: %d\n", color_code->red);
    printf("Green: %d\n", color_code->green);
    printf("Blue: %d\n", color_code->blue);
}

int main() {
    ColorCode *color_code = NULL;
    char hex_code[MAX_COLOR_CODE_LENGTH + 1] = {0};
    int red, green, blue;
    int i;

    printf("Welcome to the Color Code Converter!\n");
    printf("Enter a hexadecimal color code (e.g. #FF0000): ");
    scanf("%s", hex_code);

    color_code = create_color_code(hex_code);

    printf("Enter the red value (0-255): ");
    scanf("%d", &red);
    set_color_code_values(color_code, red, 0, 0);

    printf("Enter the green value (0-255): ");
    scanf("%d", &green);
    set_color_code_values(color_code, 0, green, 0);

    printf("Enter the blue value (0-255): ");
    scanf("%d", &blue);
    set_color_code_values(color_code, 0, 0, blue);

    printf("RGB values: ");
    for (i = 0; i < 3; i++) {
        printf("%d ", get_color_code_value(color_code, i));
    }
    printf("\n");

    print_color_code_values(color_code);

    free(color_code);

    return 0;
}