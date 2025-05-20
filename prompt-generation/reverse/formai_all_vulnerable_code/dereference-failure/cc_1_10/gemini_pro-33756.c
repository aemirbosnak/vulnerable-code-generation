//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    unsigned char *data;
    unsigned int width;
    unsigned int height;
    unsigned int channels;
} Image;

void *flip_image(void *arg) {
    Image *image = (Image *)arg;
    for (unsigned int i = 0; i < image->height; i++) {
        for (unsigned int j = 0; j < image->width / 2; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - j - 1];
            image->data[i * image->width + image->width - j - 1] = temp;
        }
    }
    return NULL;
}

void *change_brightness_contrast(void *arg) {
    Image *image = (Image *)arg;
    float brightness = 0.5;
    float contrast = 1.5;
    for (unsigned int i = 0; i < image->height; i++) {
        for (unsigned int j = 0; j < image->width; j++) {
            for (unsigned int k = 0; k < image->channels; k++) {
                float pixel = image->data[i * image->width * image->channels + j * image->channels + k];
                pixel = pixel * contrast + brightness;
                if (pixel < 0) {
                    pixel = 0;
                } else if (pixel > 255) {
                    pixel = 255;
                }
                image->data[i * image->width * image->channels + j * image->channels + k] = (unsigned char) pixel;
            }
        }
    }
    return NULL;
}

int main() {
    Image image;
    FILE *file = fopen("image.bmp", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    fread(&image.width, sizeof(unsigned int), 1, file);
    fread(&image.height, sizeof(unsigned int), 1, file);
    fread(&image.channels, sizeof(unsigned int), 1, file);
    image.data = malloc(image.width * image.height * image.channels);
    fread(image.data, 1, image.width * image.height * image.channels, file);
    fclose(file);

    pthread_t flip_thread;
    pthread_create(&flip_thread, NULL, flip_image, &image);
    pthread_join(flip_thread, NULL);

    pthread_t brightness_contrast_thread;
    pthread_create(&brightness_contrast_thread, NULL, change_brightness_contrast, &image);
    pthread_join(brightness_contrast_thread, NULL);

    file = fopen("output.bmp", "wb");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    fwrite(&image.width, sizeof(unsigned int), 1, file);
    fwrite(&image.height, sizeof(unsigned int), 1, file);
    fwrite(&image.channels, sizeof(unsigned int), 1, file);
    fwrite(image.data, 1, image.width * image.height * image.channels, file);
    fclose(file);

    free(image.data);
    return EXIT_SUCCESS;
}