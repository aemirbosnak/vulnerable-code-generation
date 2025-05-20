//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WIDTH 2048
#define MAX_HEIGHT 2048
#define MAX_CHANNELS 4
#define MAX_PIXELS (MAX_WIDTH * MAX_HEIGHT)
#define MAX_COMPONENTS (MAX_PIXELS * MAX_CHANNELS)

#define RED 0
#define GREEN 1
#define BLUE 2
#define ALPHA 3

struct pixel {
    int x;
    int y;
    int channel;
    int value;
};

struct image {
    int width;
    int height;
    int channels;
    int components;
    int* pixels;
};

void init_image(struct image* img, int width, int height, int channels) {
    img->width = width;
    img->height = height;
    img->channels = channels;
    img->components = width * height * channels;
    img->pixels = malloc(img->components * sizeof(int));
    memset(img->pixels, 0, img->components * sizeof(int));
}

void set_pixel(struct image* img, int x, int y, int channel, int value) {
    int index = (y * img->width + x) * img->channels + channel;
    img->pixels[index] = value;
}

int get_pixel(struct image* img, int x, int y, int channel) {
    int index = (y * img->width + x) * img->channels + channel;
    return img->pixels[index];
}

void print_image(struct image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            for (int c = 0; c < img->channels; c++) {
                int value = get_pixel(img, x, y, c);
                printf("%d ", value);
            }
        }
        printf("\n");
    }
}

int main() {
    struct image img;
    init_image(&img, 512, 512, 3);

    // Set some pixels
    set_pixel(&img, 0, 0, RED, 255);
    set_pixel(&img, 0, 0, GREEN, 0);
    set_pixel(&img, 0, 0, BLUE, 0);
    set_pixel(&img, 0, 1, RED, 0);
    set_pixel(&img, 0, 1, GREEN, 255);
    set_pixel(&img, 0, 1, BLUE, 0);
    set_pixel(&img, 1, 0, RED, 255);
    set_pixel(&img, 1, 0, GREEN, 0);
    set_pixel(&img, 1, 0, BLUE, 0);
    set_pixel(&img, 1, 1, RED, 0);
    set_pixel(&img, 1, 1, GREEN, 255);
    set_pixel(&img, 1, 1, BLUE, 0);

    // Print the image
    print_image(&img);

    return 0;
}