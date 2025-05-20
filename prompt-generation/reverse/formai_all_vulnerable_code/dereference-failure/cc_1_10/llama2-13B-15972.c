//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define BITS_PER_PIXEL 32
#define MAX_IMAGE_SIZE (WIDTH * HEIGHT * BITS_PER_PIXEL / 8)

// Structure to represent a pixel
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

// Function to create a new image
pixel *create_image(int width, int height) {
    pixel *image = (pixel *)malloc(width * height * sizeof(pixel));
    for (int i = 0; i < width * height; i++) {
        image[i].r = (i % 2) ? 255 : 0;
        image[i].g = (i % 3) ? 255 : 0;
        image[i].b = (i % 4) ? 255 : 0;
    }
    return image;
}

// Function to draw a line on the image
void draw_line(pixel *image, int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        image[y1 * WIDTH * BITS_PER_PIXEL / 8 + i * BITS_PER_PIXEL / 8].r = 255;
        image[y1 * WIDTH * BITS_PER_PIXEL / 8 + i * BITS_PER_PIXEL / 8].g = 0;
        image[y1 * WIDTH * BITS_PER_PIXEL / 8 + i * BITS_PER_PIXEL / 8].b = 0;
    }
    for (int i = y1; i <= y2; i++) {
        image[i * WIDTH * BITS_PER_PIXEL / 8 + x1 * BITS_PER_PIXEL / 8].r = 255;
        image[i * WIDTH * BITS_PER_PIXEL / 8 + x1 * BITS_PER_PIXEL / 8].g = 0;
        image[i * WIDTH * BITS_PER_PIXEL / 8 + x1 * BITS_PER_PIXEL / 8].b = 0;
    }
}

// Function to draw a rectangle on the image
void draw_rectangle(pixel *image, int x, int y, int width, int height) {
    for (int i = x; i < x + width; i++) {
        for (int j = y; j < y + height; j++) {
            image[j * WIDTH * BITS_PER_PIXEL / 8 + i * BITS_PER_PIXEL / 8].r = 255;
            image[j * WIDTH * BITS_PER_PIXEL / 8 + i * BITS_PER_PIXEL / 8].g = 0;
            image[j * WIDTH * BITS_PER_PIXEL / 8 + i * BITS_PER_PIXEL / 8].b = 0;
        }
    }
}

// Function to display the image
void display_image(pixel *image) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%02x%02x%02x", image[i].r, image[i].g, image[i].b);
    }
    printf("\n");
}

int main() {
    pixel *image = create_image(WIDTH, HEIGHT);
    draw_line(image, 0, 0, WIDTH, HEIGHT);
    draw_rectangle(image, 100, 100, 200, 100);
    display_image(image);
    free(image);
    return 0;
}