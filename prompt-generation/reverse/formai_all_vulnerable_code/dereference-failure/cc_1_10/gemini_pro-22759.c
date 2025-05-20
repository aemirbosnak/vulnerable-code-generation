//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COLOR_CODE_SIZE 7

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} color_code;

color_code *color_code_create(unsigned char red, unsigned char green, unsigned char blue) {
    color_code *color_code = malloc(sizeof(color_code));
    if (color_code == NULL) {
        return NULL;
    }
    color_code->red = red;
    color_code->green = green;
    color_code->blue = blue;
    return color_code;
}

void color_code_destroy(color_code *color_code) {
    free(color_code);
}

int color_code_compare(const color_code *color_code1, const color_code *color_code2) {
    if (color_code1->red != color_code2->red) {
        return color_code1->red - color_code2->red;
    }
    if (color_code1->green != color_code2->green) {
        return color_code1->green - color_code2->green;
    }
    return color_code1->blue - color_code2->blue;
}

char *color_code_to_string(const color_code *color_code) {
    char *color_code_string = malloc(COLOR_CODE_SIZE + 1);
    if (color_code_string == NULL) {
        return NULL;
    }
    sprintf(color_code_string, "#%02x%02x%02x", color_code->red, color_code->green, color_code->blue);
    return color_code_string;
}

color_code *color_code_from_string(const char *color_code_string) {
    if (strlen(color_code_string) != COLOR_CODE_SIZE) {
        return NULL;
    }
    if (color_code_string[0] != '#') {
        return NULL;
    }
    unsigned char red, green, blue;
    sscanf(color_code_string, "#%02x%02x%02x", &red, &green, &blue);
    return color_code_create(red, green, blue);
}

int main(void) {
    color_code *color_code1 = color_code_create(255, 0, 0);
    color_code *color_code2 = color_code_create(0, 255, 0);
    color_code *color_code3 = color_code_create(0, 0, 255);

    printf("Color Code 1: %s\n", color_code_to_string(color_code1));
    printf("Color Code 2: %s\n", color_code_to_string(color_code2));
    printf("Color Code 3: %s\n", color_code_to_string(color_code3));

    int comparison_result = color_code_compare(color_code1, color_code2);
    if (comparison_result < 0) {
        printf("Color Code 1 is less than Color Code 2.\n");
    } else if (comparison_result == 0) {
        printf("Color Code 1 is equal to Color Code 2.\n");
    } else {
        printf("Color Code 1 is greater than Color Code 2.\n");
    }

    color_code_destroy(color_code1);
    color_code_destroy(color_code2);
    color_code_destroy(color_code3);

    return 0;
}