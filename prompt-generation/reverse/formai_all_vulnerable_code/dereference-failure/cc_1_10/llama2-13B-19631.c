//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32
#define IMAGE_NAME "minimalist_image_editor.bmp"

// Structure to store the image data
typedef struct {
    uint32_t *pixels;
    int width;
    int height;
} image_t;

// Function to create a new image
image_t *new_image(int width, int height) {
    image_t *image = (image_t *)malloc(sizeof(image_t));
    image->width = width;
    image->height = height;
    image->pixels = (uint32_t *)malloc(width * height * BITS_PER_PIXEL / 8);
    return image;
}

// Function to draw a pixel
void draw_pixel(image_t *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[y * image->width * BITS_PER_PIXEL / 8 + x * BITS_PER_PIXEL / 8] = 0xFF000000;
}

// Function to draw a line
void draw_line(image_t *image, int x1, int y1, int x2, int y2) {
    if (x1 < 0 || x1 >= image->width || y1 < 0 || y1 >= image->height ||
            x2 < 0 || x2 >= image->width || y2 < 0 || y2 >= image->height) {
        return;
    }
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int stepx = x2 > x1 ? 1 : -1;
    int stepy = y2 > y1 ? 1 : -1;
    int x = x1, y = y1;
    while (x != x2 || y != y2) {
        draw_pixel(image, x, y);
        if (dx > dy) {
            x += stepx;
        } else {
            y += stepy;
        }
        dx -= dy;
        dy += dx;
    }
}

// Function to draw a rectangle
void draw_rectangle(image_t *image, int x, int y, int width, int height) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height ||
            width < 0 || height < 0) {
        return;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            draw_pixel(image, x + j, y + i);
        }
    }
}

// Function to save the image
void save_image(image_t *image) {
    FILE *file = fopen(IMAGE_NAME, "wb");
    if (file == NULL) {
        printf("Failed to open file %s\n", IMAGE_NAME);
        return;
    }
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            uint32_t pixel = image->pixels[i * image->width * BITS_PER_PIXEL / 8 + j * BITS_PER_PIXEL / 8];
            fwrite(&pixel, 4, 1, file);
        }
    }
    fclose(file);
}

int main() {
    srand(time(NULL));
    image_t *image = new_image(WIDTH, HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image->pixels[i] = 0xFF000000;
    }
    draw_rectangle(image, 100, 100, 200, 100);
    draw_line(image, 100, 100, 300, 200);
    draw_line(image, 300, 200, 400, 300);
    draw_line(image, 400, 300, 500, 400);
    save_image(image);
    return 0;
}