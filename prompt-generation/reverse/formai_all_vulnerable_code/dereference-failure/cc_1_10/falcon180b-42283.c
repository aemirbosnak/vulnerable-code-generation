//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

struct color_code {
    char hex[MAX_CODE_LENGTH + 1];
    int red, green, blue;
};

void generate_random_color_code(struct color_code *color) {
    char hex_chars[] = "0123456789ABCDEF";
    int i;

    for (i = 0; i < MAX_CODE_LENGTH; i++) {
        color->hex[i] = hex_chars[rand() % 16];
    }
    color->hex[MAX_CODE_LENGTH] = '\0';

    color->red = rand() % 256;
    color->green = rand() % 256;
    color->blue = rand() % 256;
}

void print_color_code(struct color_code *color) {
    printf("Hex code: %s\n", color->hex);
    printf("RGB values: R=%d, G=%d, B=%d\n", color->red, color->green, color->blue);
}

int main() {
    int num_colors;

    printf("Enter the number of color codes to generate: ");
    scanf("%d", &num_colors);

    struct color_code *colors = malloc(sizeof(struct color_code) * num_colors);

    srand(time(NULL));

    int i;
    for (i = 0; i < num_colors; i++) {
        generate_random_color_code(&colors[i]);
        print_color_code(&colors[i]);
    }

    free(colors);

    return 0;
}