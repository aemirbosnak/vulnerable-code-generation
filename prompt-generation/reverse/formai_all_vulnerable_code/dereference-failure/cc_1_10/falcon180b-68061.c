//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define IMAGE_SIZE (WIDTH * HEIGHT)
#define WATERMARK_SIZE (WIDTH / 4)
#define WATERMARK_POS (HEIGHT / 2 - WATERMARK_SIZE / 2)

typedef struct {
    unsigned char luminance;
    unsigned char alpha;
} pixel_t;

typedef struct {
    pixel_t *pixels;
} image_t;

void create_image(image_t *image) {
    image->pixels = (pixel_t *) malloc(IMAGE_SIZE * sizeof(pixel_t));
    for (int i = 0; i < IMAGE_SIZE; i++) {
        image->pixels[i].luminance = rand() % 256;
        image->pixels[i].alpha = 255;
    }
}

void set_pixel(image_t *image, int x, int y, pixel_t pixel) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        image->pixels[y * WIDTH + x] = pixel;
    }
}

void draw_watermark(image_t *image) {
    pixel_t watermark = { 0, 0 };
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        for (int j = 0; j < WATERMARK_SIZE; j++) {
            int x = i + WATERMARK_POS * WIDTH;
            int y = j + WATERMARK_POS;
            set_pixel(image, x, y, watermark);
        }
    }
}

void save_image(const char *filename, image_t *image) {
    FILE *file = fopen(filename, "wb");
    if (file) {
        fwrite(image->pixels, sizeof(pixel_t), IMAGE_SIZE, file);
        fclose(file);
    }
}

int main() {
    image_t image;
    create_image(&image);
    draw_watermark(&image);
    save_image("watermarked.bmp", &image);
    return 0;
}