//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define PIXEL_MAX 255

typedef struct {
    int x, y;
    int value;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

void create_image(Image *image) {
    image->width = WIDTH;
    image->height = HEIGHT;
    image->pixels = (Pixel *)malloc(WIDTH * HEIGHT * sizeof(Pixel));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image->pixels[i].x = i % WIDTH;
        image->pixels[i].y = i / WIDTH;
        image->pixels[i].value = rand() % PIXEL_MAX;
    }
}

void print_image(Image *image) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        Pixel pixel = image->pixels[i];
        printf("%d ", pixel.value);
    }
    printf("\n");
}

void add_watermark(Image *image, char *watermark) {
    int watermark_width = strlen(watermark) / 2;
    int watermark_height = strlen(watermark) / 4;
    for (int i = 0; i < watermark_height; i++) {
        for (int j = 0; j < watermark_width; j++) {
            int index = (i * WIDTH / watermark_height) * 2 + j * 2;
            char pixel_value = watermark[index];
            if (pixel_value == '1') {
                image->pixels[index / 2].value = PIXEL_MAX - 1;
            } else if (pixel_value == '0') {
                image->pixels[index / 2].value = PIXEL_MAX - 2;
            }
        }
    }
}

int main() {
    Image image;
    create_image(&image);
    add_watermark(&image, "Hello, World!");
    print_image(&image);
    return 0;
}