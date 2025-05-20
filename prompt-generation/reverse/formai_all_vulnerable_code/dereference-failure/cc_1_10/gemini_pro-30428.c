//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} Image;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error loading image: %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(uint32_t), 1, file);
    fread(&image->height, sizeof(uint32_t), 1, file);
    image->data = malloc(image->width * image->height * 3);
    if (!image->data) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(file);
        free(image);
        return NULL;
    }

    fread(image->data, image->width * image->height * 3, 1, file);
    fclose(file);

    return image;
}

void save_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error saving image: %s\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(uint32_t), 1, file);
    fwrite(&image->height, sizeof(uint32_t), 1, file);
    fwrite(image->data, image->width * image->height * 3, 1, file);
    fclose(file);
}

void invert_image(Image *image) {
    for (uint32_t y = 0; y < image->height; y++) {
        for (uint32_t x = 0; x < image->width; x++) {
            uint8_t *pixel = &image->data[(y * image->width + x) * 3];
            pixel[0] = 255 - pixel[0];
            pixel[1] = 255 - pixel[1];
            pixel[2] = 255 - pixel[2];
        }
    }
}

void grayscale_image(Image *image) {
    for (uint32_t y = 0; y < image->height; y++) {
        for (uint32_t x = 0; x < image->width; x++) {
            uint8_t *pixel = &image->data[(y * image->width + x) * 3];
            uint8_t gray = (pixel[0] + pixel[1] + pixel[2]) / 3;
            pixel[0] = gray;
            pixel[1] = gray;
            pixel[2] = gray;
        }
    }
}

void blur_image(Image *image) {
    uint8_t *temp_data = malloc(image->width * image->height * 3);
    if (!temp_data) {
        fprintf(stderr, "Error allocating memory for temporary image data\n");
        return;
    }

    for (uint32_t y = 1; y < image->height - 1; y++) {
        for (uint32_t x = 1; x < image->width - 1; x++) {
            uint8_t *pixel = &image->data[(y * image->width + x) * 3];
            uint8_t *temp_pixel = &temp_data[(y * image->width + x) * 3];
            temp_pixel[0] = (pixel[0] + pixel[-3] + pixel[-2] + pixel[-1] + pixel[1] + pixel[2] + pixel[3] + pixel[image->width] + pixel[image->width - 1] + pixel[image->width + 1] + pixel[image->width + 2] + pixel[image->width + 3]) / 12;
            temp_pixel[1] = (pixel[1] + pixel[-3] + pixel[-2] + pixel[-1] + pixel[1] + pixel[2] + pixel[3] + pixel[image->width] + pixel[image->width - 1] + pixel[image->width + 1] + pixel[image->width + 2] + pixel[image->width + 3]) / 12;
            temp_pixel[2] = (pixel[2] + pixel[-3] + pixel[-2] + pixel[-1] + pixel[1] + pixel[2] + pixel[3] + pixel[image->width] + pixel[image->width - 1] + pixel[image->width + 1] + pixel[image->width + 2] + pixel[image->width + 3]) / 12;
        }
    }

    memcpy(image->data, temp_data, image->width * image->height * 3);
    free(temp_data);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        fprintf(stderr, "Error loading image: %s\n", argv[1]);
        return 1;
    }

    invert_image(image);
    grayscale_image(image);
    blur_image(image);

    save_image(image, argv[2]);

    free(image->data);
    free(image);

    return 0;
}