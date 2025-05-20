//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t *data;
    size_t width;
    size_t height;
    size_t channels;
} Image;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(file);
        return NULL;
    }

    fseek(file, 18, SEEK_SET);
    fread(&image->width, 4, 1, file);
    fread(&image->height, 4, 1, file);
    fseek(file, 28, SEEK_SET);
    fread(&image->channels, 4, 1, file);

    image->data = malloc(image->width * image->height * image->channels);
    if (!image->data) {
        free(image);
        fclose(file);
        return NULL;
    }

    fread(image->data, image->width * image->height * image->channels, 1, file);
    fclose(file);

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void flip_image(Image *image) {
    for (size_t i = 0; i < image->height / 2; i++) {
        for (size_t j = 0; j < image->width; j++) {
            for (size_t k = 0; k < image->channels; k++) {
                uint8_t temp = image->data[i * image->width * image->channels + j * image->channels + k];
                image->data[i * image->width * image->channels + j * image->channels + k] = image->data[(image->height - i - 1) * image->width * image->channels + j * image->channels + k];
                image->data[(image->height - i - 1) * image->width * image->channels + j * image->channels + k] = temp;
            }
        }
    }
}

void adjust_brightness(Image *image, int brightness) {
    for (size_t i = 0; i < image->width * image->height * image->channels; i++) {
        int new_value = (int)image->data[i] + brightness;
        if (new_value < 0) {
            new_value = 0;
        } else if (new_value > 255) {
            new_value = 255;
        }
        image->data[i] = (uint8_t)new_value;
    }
}

void adjust_contrast(Image *image, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (size_t i = 0; i < image->width * image->height * image->channels; i++) {
        int new_value = factor * (image->data[i] - 128) + 128;
        if (new_value < 0) {
            new_value = 0;
        } else if (new_value > 255) {
            new_value = 255;
        }
        image->data[i] = (uint8_t)new_value;
    }
}

int main() {
    Image *image = load_image("image.bmp");
    if (!image) {
        return 1;
    }

    flip_image(image);
    adjust_brightness(image, 50);
    adjust_contrast(image, 1.5);

    FILE *file = fopen("output.bmp", "wb");
    if (!file) {
        free_image(image);
        return 1;
    }

    fwrite("BM", 2, 1, file);
    fwrite(&image->width, 4, 1, file);
    fwrite(&image->height, 4, 1, file);
    fwrite("\0\0", 2, 1, file);
    fwrite("\0\0", 2, 1, file);
    fwrite("\0\0\0\0", 4, 1, file);
    fwrite("\0\0\0\0", 4, 1, file);
    fwrite("\0\0\0", 3, 1, file);
    fwrite("\0\0\0", 3, 1, file);
    fwrite(&image->channels, 4, 1, file);
    fwrite(&image->width, 4, 1, file);
    fwrite(&image->height, 4, 1, file);
    fwrite("\0\0", 2, 1, file);
    fwrite("\0\0\0\0", 4, 1, file);
    fwrite("\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 24, 1, file);

    fwrite(image->data, image->width * image->height * image->channels, 1, file);
    fclose(file);

    free_image(image);

    return 0;
}