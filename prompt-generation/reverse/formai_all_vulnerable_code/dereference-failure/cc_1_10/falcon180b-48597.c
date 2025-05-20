//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_PIXELS 1000
#define MAX_COLORS 256

typedef struct pixel {
    int x;
    int y;
    int color;
} pixel_t;

typedef struct image {
    pixel_t *pixels;
    int width;
    int height;
} image_t;

void init_image(image_t *image, int width, int height) {
    image->pixels = (pixel_t *) malloc(sizeof(pixel_t) * MAX_PIXELS);
    image->width = width;
    image->height = height;
    memset(image->pixels, 0, sizeof(pixel_t) * MAX_PIXELS);
}

void set_pixel(image_t *image, int x, int y, int color) {
    int index = y * image->width + x;
    if (index >= 0 && index < MAX_PIXELS) {
        image->pixels[index].x = x;
        image->pixels[index].y = y;
        image->pixels[index].color = color;
    }
}

void draw_image(image_t *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int index = i * image->width + j;
            if (index >= 0 && index < MAX_PIXELS && image->pixels[index].color!= 0) {
                printf("%d ", image->pixels[index].color);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void free_image(image_t *image) {
    free(image->pixels);
}

int main() {
    srand(time(NULL));

    image_t image;
    init_image(&image, 50, 50);

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int color = rand() % MAX_COLORS;
            set_pixel(&image, i, j, color);
        }
    }

    draw_image(&image);

    free_image(&image);

    return 0;
}