//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4

typedef struct pixel {
    int x;
    int y;
    int color;
} pixel_t;

pixel_t* create_pixel_array(int size) {
    pixel_t* pixels = (pixel_t*)malloc(size * sizeof(pixel_t));
    for (int i = 0; i < size; i++) {
        pixels[i].x = i;
        pixels[i].y = i;
        pixels[i].color = BLACK;
    }
    return pixels;
}

void draw_pixel(pixel_t* pixels, int size, int x, int y, int color) {
    if (x >= 0 && y >= 0 && x < size && y < size) {
        pixels[y * size + x].color = color;
    }
}

void fill_pixels(pixel_t* pixels, int size, int x, int y, int color) {
    draw_pixel(pixels, size, x, y, color);
    for (int i = 1; i < size; i++) {
        fill_pixels(pixels, size, x + i, y, color);
        fill_pixels(pixels, size, x, y + i, color);
    }
}

void print_pixels(pixel_t* pixels, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", pixels[i].color);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 1;
    pixel_t* pixels = create_pixel_array(size);
    fill_pixels(pixels, size, rand() % size, rand() % size, WHITE);
    print_pixels(pixels, size);
    free(pixels);
    return 0;
}