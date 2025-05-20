//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel_t;

typedef struct {
    pixel_t *pixels;
    size_t width;
    size_t height;
} bitmap_t;

bitmap_t *bmp;
bitmap_t *bmp_flipped;
bitmap_t *bmp_brightness;
bitmap_t *bmp_contrast;

// Flips an image horizontally
void flip_image() {
    for (size_t y = 0; y < bmp->height; y++) {
        for (size_t x = 0; x < bmp->width / 2; x++) {
            pixel_t temp = bmp->pixels[y * bmp->width + x];
            bmp->pixels[y * bmp->width + x] = bmp->pixels[(y + 1) * bmp->width - x - 1];
            bmp->pixels[(y + 1) * bmp->width - x - 1] = temp;
        }
    }

    bmp_flipped = bmp;
}

// Increases the brightness of an image by a factor of n
void increase_brightness(int n) {
    bmp_brightness = malloc(sizeof(bitmap_t));
    bmp_brightness->width = bmp->width;
    bmp_brightness->height = bmp->height;
    bmp_brightness->pixels = malloc(bmp->width * bmp->height * sizeof(pixel_t));

    for (size_t y = 0; y < bmp->height; y++) {
        for (size_t x = 0; x < bmp->width; x++) {
            pixel_t pixel = bmp->pixels[y * bmp->width + x];
            pixel.r /= (255 / n);
            pixel.g /= (255 / n);
            pixel.b /= (255 / n);
            bmp_brightness->pixels[y * bmp->width + x] = pixel;
        }
    }
}

// Increases the contrast of an image by a factor of n
void increase_contrast(int n) {
    bmp_contrast = malloc(sizeof(bitmap_t));
    bmp_contrast->width = bmp->width;
    bmp_contrast->height = bmp->height;
    bmp_contrast->pixels = malloc(bmp->width * bmp->height * sizeof(pixel_t));

    for (size_t y = 0; y < bmp->height; y++) {
        for (size_t x = 0; x < bmp->width; x++) {
            pixel_t pixel = bmp->pixels[y * bmp->width + x];
            pixel.r = ((pixel.r - 128) * n) + 128;
            pixel.g = ((pixel.g - 128) * n) + 128;
            pixel.b = ((pixel.b - 128) * n) + 128;
            bmp_contrast->pixels[y * bmp->width + x] = pixel;
        }
    }
}

// Thread for flipping the image
void *flip_thread() {
    flip_image();
    return NULL;
}

// Thread for increasing brightness
void *brightness_thread(void *n_ptr) {
    int n = *(int *) n_ptr;
    increase_brightness(n);
    return NULL;
}

// Thread for increasing contrast
void *contrast_thread(void *n_ptr) {
    int n = *(int *) n_ptr;
    increase_contrast(n);
    return NULL;
}

int main(void) {
    bmp = malloc(sizeof(bitmap_t));
    bmp->width = WIDTH;
    bmp->height = HEIGHT;
    bmp->pixels = malloc(WIDTH * HEIGHT * sizeof(pixel_t));

    // Read image into bmp->pixels here...


    // Flip the image asynchronously
    pthread_t flip_tid;
    pthread_create(&flip_tid, NULL, flip_thread, NULL);

    // Increase brightness and contrast asynchronously
    int n = 2;
    pthread_t brightness_tid;
    pthread_create(&brightness_tid, NULL, brightness_thread, (void *) &n);

    pthread_t contrast_tid;
    pthread_create(&contrast_tid, NULL, contrast_thread, (void *) &n);

    // Wait for all threads to complete
    pthread_join(flip_tid, NULL);
    pthread_join(brightness_tid, NULL);
    pthread_join(contrast_tid, NULL);

    // Write the processed images to disk here...

    // Free memory
    free(bmp->pixels);
    free(bmp);
    free(bmp_flipped->pixels);
    free(bmp_flipped);
    free(bmp_brightness->pixels);
    free(bmp_brightness);
    free(bmp_contrast->pixels);
    free(bmp_contrast);

    return 0;
}