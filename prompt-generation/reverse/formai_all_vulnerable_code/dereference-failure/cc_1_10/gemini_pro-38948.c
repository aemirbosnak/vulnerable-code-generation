//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct {
    uint8_t *data;
    size_t size;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    image->data = malloc(MAX_SIZE);
    if (image->data == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        free(image);
        return NULL;
    }

    size_t size = fread(image->data, 1, MAX_SIZE, fp);
    if (size == 0) {
        perror("Error reading file");
        fclose(fp);
        free(image->data);
        free(image);
        return NULL;
    }

    image->size = size;

    fclose(fp);

    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    size_t size = fwrite(image->data, 1, image->size, fp);
    if (size != image->size) {
        perror("Error writing file");
    }

    fclose(fp);
}

void watermark_image(Image *image, const char *watermark) {
    size_t watermark_size = strlen(watermark);
    if (watermark_size > image->size) {
        printf("Watermark is too large\n");
        return;
    }

    for (size_t i = 0; i < watermark_size; i++) {
        image->data[i] ^= watermark[i];
    }
}

void unwatermark_image(Image *image, const char *watermark) {
    size_t watermark_size = strlen(watermark);
    if (watermark_size > image->size) {
        printf("Watermark is too large\n");
        return;
    }

    for (size_t i = 0; i < watermark_size; i++) {
        image->data[i] ^= watermark[i];
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <image> <watermark> <output>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    watermark_image(image, argv[2]);

    write_image(argv[3], image);

    free(image->data);
    free(image);

    return 0;
}