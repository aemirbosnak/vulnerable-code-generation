//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    int max_value;
    unsigned char *data;
} Image;

Image *image_new(int width, int height, int max_value) {
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        return NULL;
    }
    image->width = width;
    image->height = height;
    image->max_value = max_value;
    image->data = malloc(width * height * sizeof(unsigned char));
    if (image->data == NULL) {
        free(image);
        return NULL;
    }
    return image;
}

void image_free(Image *image) {
    free(image->data);
    free(image);
}

int image_get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return -1;
    }
    return image->data[y * image->width + x];
}

void image_set_pixel(Image *image, int x, int y, int value) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->data[y * image->width + x] = value;
}

void image_save_ppm(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }
    fprintf(fp, "P6\n%d %d\n%d\n", image->width, image->height, image->max_value);
    fwrite(image->data, 1, image->width * image->height * sizeof(unsigned char), fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s width height filename\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    char *filename = argv[3];

    Image *image = image_new(width, height, 255);
    if (image == NULL) {
        fprintf(stderr, "Error: could not create image\n");
        return 1;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = (x + y) % 256;
            image_set_pixel(image, x, y, value);
        }
    }

    image_save_ppm(image, filename);
    image_free(image);

    return 0;
}