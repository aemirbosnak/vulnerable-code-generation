//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

void flip_image(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char tmp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = tmp;
        }
    }
}

void change_brightness_contrast(Image *image, double brightness, double contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            double value = image->data[y * image->width + x];
            value = (value - 127.5) * contrast + 127.5;
            value += brightness;
            if (value < 0) value = 0;
            if (value > 255) value = 255;
            image->data[y * image->width + x] = (unsigned char) value;
        }
    }
}

void *process_image(void *arg) {
    Image *image = (Image *) arg;
    flip_image(image);
    change_brightness_contrast(image, 20, 1.2);
    return NULL;
}

int main() {
    Image image;
    image.width = 640;
    image.height = 480;
    image.data = malloc(image.width * image.height);

    // Load the image from a file

    pthread_t thread;
    pthread_create(&thread, NULL, process_image, &image);
    pthread_join(thread, NULL);

    // Save the processed image to a file

    free(image.data);
    return 0;
}