//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WATERMARK_SIZE 256
#define WATERMARK_VALUE 0.5
#define IMAGE_SIZE 512

typedef struct {
    int width;
    int height;
    char *data;
} image_t;

image_t* create_image(int width, int height) {
    image_t *image = (image_t *)malloc(sizeof(image_t));
    image->width = width;
    image->height = height;
    image->data = (char *)malloc(width * height);
    memset(image->data, 0, width * height);
    return image;
}

void destroy_image(image_t *image) {
    free(image->data);
    free(image);
}

void save_image(image_t *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fwrite(image->data, 1, image->width * image->height, fp);
    fclose(fp);
}

void load_image(const char *filename, image_t *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fread(image->data, 1, image->width * image->height, fp);
    fclose(fp);
}

void add_watermark(image_t *image, double watermark_value) {
    int i, j, k, x, y;
    double *watermark = (double *)malloc(WATERMARK_SIZE * WATERMARK_SIZE * sizeof(double));
    for (i = 0; i < WATERMARK_SIZE; i++) {
        for (j = 0; j < WATERMARK_SIZE; j++) {
            watermark[i * WATERMARK_SIZE + j] = watermark_value;
        }
    }
    for (i = 0; i < image->height; i += WATERMARK_SIZE) {
        for (j = 0; j < image->width; j += WATERMARK_SIZE) {
            for (x = 0; x < WATERMARK_SIZE; x++) {
                for (y = 0; y < WATERMARK_SIZE; y++) {
                    int index = (i + x) * image->width + j + y;
                    image->data[index] = (char)((double)image->data[index] + watermark[x * WATERMARK_SIZE + y] * WATERMARK_VALUE);
                }
            }
        }
    }
    free(watermark);
}

int main() {
    image_t *image = create_image(IMAGE_SIZE, IMAGE_SIZE);
    load_image("input.bmp", image);
    add_watermark(image, WATERMARK_VALUE);
    save_image(image, "output.bmp");
    destroy_image(image);
    return 0;
}