//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    int width;
    int height;
    int depth;
    unsigned char *data;
} Image;

Image *create_image(int width, int height, int depth) {
    Image *image = malloc(sizeof(Image));
    if (!image) {
        return NULL;
    }
    image->width = width;
    image->height = height;
    image->depth = depth;
    image->data = malloc(width * height * depth);
    if (!image->data) {
        free(image);
        return NULL;
    }
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

int save_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return -1;
    }
    fprintf(fp, "P3\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int d = 0; d < image->depth; d++) {
                fprintf(fp, "%d ", image->data[y * image->width * image->depth + x * image->depth + d]);
            }
        }
    }
    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s width height depth filename\n", argv[0]);
        return 1;
    }
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int depth = atoi(argv[3]);
    if (width <= 0 || height <= 0 || depth <= 0) {
        fprintf(stderr, "Invalid dimensions\n");
        return 1;
    }
    Image *image = create_image(width, height, depth);
    if (!image) {
        fprintf(stderr, "Failed to create image\n");
        return 1;
    }
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int d = 0; d < image->depth; d++) {
                image->data[y * image->width * image->depth + x * image->depth + d] = rand() % 256;
            }
        }
    }
    if (save_image(image, argv[4]) != 0) {
        fprintf(stderr, "Failed to save image\n");
        destroy_image(image);
        return 1;
    }
    destroy_image(image);
    return 0;
}