//MISTRAL-7B DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define BITS_PER_PIXEL 8
#define WATERMARK_MESSAGE "SECRET"
#define WATERMARK_MESSAGE_LENGTH 7
#define NOISE_AMPLITUDE 25
#define SALT_AND_PEPPER_PROBABILITY 0.01

typedef unsigned char pixel;

void watermark_image(pixel *image, int width, int height) {
    int x, y, message_index;
    pixel message_pixel;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            message_index = (y * width + x) % WATERMARK_MESSAGE_LENGTH;
            message_pixel = WATERMARK_MESSAGE[message_index];
            image[y * width + x] += (message_pixel >> (BITS_PER_PIXEL - (message_index + 1) % 8));
        }
    }
}

void add_noise(pixel *image, int width, int height) {
    int x, y;
    double noise;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            noise = ((double)rand() / RAND_MAX) * NOISE_AMPLITUDE;
            image[y * width + x] += (pixel)noise;
        }
    }

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if ((rand() % 10000) < SALT_AND_PEPPER_PROBABILITY * 10000) {
                image[y * width + x] = (pixel)(rand() % 256);
            }
        }
    }
}

void save_image(pixel *image, int width, int height, char *filename) {
    FILE *file;

    file = fopen(filename, "wb");
    fwrite(image, 1, width * height, file);
    fclose(file);
}

int main() {
    pixel *image;
    int i;

    image = (pixel *)calloc(WIDTH * HEIGHT, sizeof(pixel));

    // Initialize image here...

    watermark_image(image, WIDTH, HEIGHT);
    add_noise(image, WIDTH, HEIGHT);

    save_image(image, WIDTH, HEIGHT, "watermarked_image.bmp");

    free(image);

    return 0;
}