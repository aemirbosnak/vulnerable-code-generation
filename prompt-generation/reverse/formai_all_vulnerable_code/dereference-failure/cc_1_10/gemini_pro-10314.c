//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} Image;

Image *create_image(uint32_t width, uint32_t height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%u %u\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(uint8_t), image->width * image->height * 3, file);
    fclose(file);
}

void load_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "rb");
    char header[100];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        printf("Error: Not a PPM image.\n");
        return;
    }
    fscanf(file, "%u %u", &image->width, &image->height);
    fscanf(file, "%*s");
    image->data = malloc(image->width * image->height * 3);
    fread(image->data, sizeof(uint8_t), image->width * image->height * 3, file);
    fclose(file);
}

void invert_image(Image *image) {
    for (uint32_t i = 0; i < image->width * image->height * 3; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void grayscale_image(Image *image) {
    for (uint32_t i = 0; i < image->width * image->height * 3; i += 3) {
        uint8_t gray = (image->data[i] + image->data[i + 1] + image->data[i + 2]) / 3;
        image->data[i] = gray;
        image->data[i + 1] = gray;
        image->data[i + 2] = gray;
    }
}

void blur_image(Image *image, uint32_t radius) {
    uint32_t *sum = malloc(image->width * image->height * 3 * sizeof(uint32_t));
    uint32_t *count = malloc(image->width * image->height * 3 * sizeof(uint32_t));
    for (uint32_t i = 0; i < image->width * image->height * 3; i++) {
        sum[i] = 0;
        count[i] = 0;
    }
    for (uint32_t y = 0; y < image->height; y++) {
        for (uint32_t x = 0; x < image->width; x++) {
            for (int32_t dy = -radius; dy <= radius; dy++) {
                for (int32_t dx = -radius; dx <= radius; dx++) {
                    if (y + dy >= 0 && y + dy < image->height && x + dx >= 0 && x + dx < image->width) {
                        for (uint32_t i = 0; i < 3; i++) {
                            sum[(y + dy) * image->width * 3 + (x + dx) * 3 + i] += image->data[y * image->width * 3 + x * 3 + i];
                            count[(y + dy) * image->width * 3 + (x + dx) * 3 + i] += 1;
                        }
                    }
                }
            }
        }
    }
    for (uint32_t i = 0; i < image->width * image->height * 3; i++) {
        image->data[i] = sum[i] / count[i];
    }
    free(sum);
    free(count);
}

void main() {
    Image *image = create_image(512, 512);
    for (uint32_t i = 0; i < image->width * image->height * 3; i += 3) {
        image->data[i] = 255;
        image->data[i + 1] = 0;
        image->data[i + 2] = 0;
    }
    save_image(image, "red.ppm");
    destroy_image(image);
}