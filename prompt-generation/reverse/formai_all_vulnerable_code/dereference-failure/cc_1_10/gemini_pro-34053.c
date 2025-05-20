//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} image_t;

void *flip_image(void *arg) {
    image_t *img = (image_t *)arg;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            unsigned char temp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[i * img->width + img->width - 1 - j];
            img->data[i * img->width + img->width - 1 - j] = temp;
        }
    }
    return NULL;
}

void *change_brightness(void *arg) {
    image_t *img = (image_t *)arg;
    int brightness = 50;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int new_value = img->data[i * img->width + j] + brightness;
            if (new_value > 255) {
                new_value = 255;
            } else if (new_value < 0) {
                new_value = 0;
            }
            img->data[i * img->width + j] = new_value;
        }
    }
    return NULL;
}

void *change_contrast(void *arg) {
    image_t *img = (image_t *)arg;
    float contrast = 1.5;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int new_value = (img->data[i * img->width + j] - 128) * contrast + 128;
            if (new_value > 255) {
                new_value = 255;
            } else if (new_value < 0) {
                new_value = 0;
            }
            img->data[i * img->width + j] = new_value;
        }
    }
    return NULL;
}

int main() {
    image_t img;
    img.width = 512;
    img.height = 512;
    img.data = (unsigned char *)malloc(img.width * img.height * sizeof(unsigned char));

    // Load image data from file

    pthread_t flip_thread, brightness_thread, contrast_thread;
    pthread_create(&flip_thread, NULL, flip_image, &img);
    pthread_create(&brightness_thread, NULL, change_brightness, &img);
    pthread_create(&contrast_thread, NULL, change_contrast, &img);

    pthread_join(flip_thread, NULL);
    pthread_join(brightness_thread, NULL);
    pthread_join(contrast_thread, NULL);

    // Save image data to file

    return 0;
}