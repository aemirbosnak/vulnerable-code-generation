//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <string.h>

#define THREADS_NUM 4
#define MAX_PIXEL_VALUE 255

typedef struct {
    uint8_t *data;
    uint32_t width;
    uint32_t height;
} Image;

typedef struct {
    Image *image;
    float value;
} BrightnessArgs;

typedef struct {
    Image *image;
    float value;
} ContrastArgs;

typedef struct {
    Image *image;
} FlipArgs;

void *flip_image(void *arg) {
    FlipArgs *args = (FlipArgs*) arg;
    Image *image = args->image;
    uint8_t *new_data = calloc(image->width * image->height, sizeof(uint8_t));
    for (uint32_t i = 0; i < image->height; i++) {
        for (uint32_t j = 0; j < image->width; j++) {
            uint32_t index = (i * image->width) + j;
            uint32_t new_index = (i * image->width) + (image->width - j - 1);
            new_data[new_index] = image->data[index];
        }
    }
    memcpy(image->data, new_data, image->width * image->height * sizeof(uint8_t));
    free(new_data);
    return NULL;
}

void *brightness_image(void *arg) {
    BrightnessArgs *args = (BrightnessArgs*) arg;
    Image *image = args->image;
    float value = args->value;
    for (uint32_t i = 0; i < image->height; i++) {
        for (uint32_t j = 0; j < image->width; j++) {
            uint32_t index = (i * image->width) + j;
            float pixel_value = image->data[index];
            pixel_value += value;
            if (pixel_value < 0) {
                pixel_value = 0;
            } else if (pixel_value > MAX_PIXEL_VALUE) {
                pixel_value = MAX_PIXEL_VALUE;
            }
            image->data[index] = (uint8_t) pixel_value;
        }
    }
    return NULL;
}

void *contrast_image(void *arg) {
    ContrastArgs *args = (ContrastArgs*) arg;
    Image *image = args->image;
    float value = args->value;
    float factor = (259 * (value + 255)) / (255 * (259 - value));
    for (uint32_t i = 0; i < image->height; i++) {
        for (uint32_t j = 0; j < image->width; j++) {
            uint32_t index = (i * image->width) + j;
            float pixel_value = image->data[index];
            pixel_value = factor * (pixel_value - 128) + 128;
            if (pixel_value < 0) {
                pixel_value = 0;
            } else if (pixel_value > MAX_PIXEL_VALUE) {
                pixel_value = MAX_PIXEL_VALUE;
            }
            image->data[index] = (uint8_t) pixel_value;
        }
    }
    return NULL;
}

int main() {
    Image image;
    image.width = 8;
    image.height = 8;
    image.data = calloc(image.width * image.height, sizeof(uint8_t));

    // Initialize image with gradient
    for (uint32_t i = 0; i < image.height; i++) {
        for (uint32_t j = 0; j < image.width; j++) {
            uint32_t index = (i * image.width) + j;
            image.data[index] = i * j * 2;
            printf("%d ", image.data[index]);
        }
        printf("\n");
    }
    printf("Before processing\n");

    // Start threads for flip, brightness and contrast
    pthread_t threads[THREADS_NUM];
    FlipArgs flip_args = {&image};
    pthread_create(&threads[0], NULL, flip_image, (void*) &flip_args);

    BrightnessArgs brightness_args = {&image, -100.0};
    pthread_create(&threads[1], NULL, brightness_image, (void*) &brightness_args);

    ContrastArgs contrast_args = {&image, 50.0};
    pthread_create(&threads[2], NULL, contrast_image, (void*) &contrast_args);

    // Wait for threads to finish
    for (int i = 0; i < THREADS_NUM; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print final image
    printf("\nAfter processing\n");
    for (uint32_t i = 0; i < image.height; i++) {
        for (uint32_t j = 0; j < image.width; j++) {
            uint32_t index = (i * image.width) + j;
            printf("%d ", image.data[index]);
        }
        printf("\n");
    }

    free(image.data);
    return 0;
}