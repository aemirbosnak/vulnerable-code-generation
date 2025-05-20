//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    char color;
} Pixel;

Pixel* create_pixel(int x, int y, char color) {
    Pixel* pixel = (Pixel*) malloc(sizeof(Pixel));
    pixel->x = x;
    pixel->y = y;
    pixel->color = color;
    return pixel;
}

void destroy_pixel(Pixel* pixel) {
    free(pixel);
}

void print_pixel(Pixel* pixel) {
    printf("%c", pixel->color);
}

void main() {
    Pixel* pixel1 = create_pixel(0, 0, 'O');
    Pixel* pixel2 = create_pixel(0, 1, '#');
    Pixel* pixel3 = create_pixel(1, 0, 'O');
    Pixel* pixel4 = create_pixel(1, 1, '#');
    Pixel* pixel5 = create_pixel(2, 0, 'O');
    Pixel* pixel6 = create_pixel(2, 1, '#');
    Pixel* pixel7 = create_pixel(3, 0, 'O');
    Pixel* pixel8 = create_pixel(3, 1, '#');

    printf("Pixel Art Generator\n");
    printf("---------\n");

    printf("|");
    print_pixel(pixel1);
    print_pixel(pixel2);
    printf("|\n");
    printf("|");
    print_pixel(pixel3);
    print_pixel(pixel4);
    printf("|\n");
    printf("|");
    print_pixel(pixel5);
    print_pixel(pixel6);
    printf("|\n");
    printf("|");
    print_pixel(pixel7);
    print_pixel(pixel8);
    printf("|\n");
    printf("---------\n");

    destroy_pixel(pixel1);
    destroy_pixel(pixel2);
    destroy_pixel(pixel3);
    destroy_pixel(pixel4);
    destroy_pixel(pixel5);
    destroy_pixel(pixel6);
    destroy_pixel(pixel7);
    destroy_pixel(pixel8);
}