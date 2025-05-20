//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b;
} pixel_t;

typedef struct {
    int width, height;
    pixel_t *pixels;
} image_t;

image_t *image_new(int width, int height) {
    image_t *image = malloc(sizeof(image_t));
    if (image == NULL) {
        return NULL;
    }

    image->width = width;
    image->height = height;

    image->pixels = malloc(width * height * sizeof(pixel_t));
    if (image->pixels == NULL) {
        free(image);
        return NULL;
    }

    return image;
}

void image_free(image_t *image) {
    free(image->pixels);
    free(image);
}

int image_load(image_t *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (size < 54) {
        fclose(fp);
        return -1;
    }

    unsigned char header[54];
    fread(header, 1, 54, fp);

    if (header[0] != 'B' || header[1] != 'M') {
        fclose(fp);
        return -1;
    }

    int offset = *(int *)&header[10];
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int bits_per_pixel = *(int *)&header[28];

    if (width <= 0 || height <= 0 || bits_per_pixel != 24) {
        fclose(fp);
        return -1;
    }

    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(pixel_t));
    if (image->pixels == NULL) {
        fclose(fp);
        return -1;
    }

    fseek(fp, offset, SEEK_SET);
    fread(image->pixels, 1, width * height * sizeof(pixel_t), fp);

    fclose(fp);

    return 0;
}

int image_save(image_t *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return -1;
    }

    unsigned char header[54] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    *(int *)&header[2] = 54 + image->width * image->height * 3;
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;

    fwrite(header, 1, 54, fp);
    fwrite(image->pixels, 1, image->width * image->height * sizeof(pixel_t), fp);

    fclose(fp);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <input> <output> <filter>\n", argv[0]);
        return 1;
    }

    image_t *image = image_new(MAX_WIDTH, MAX_HEIGHT);
    if (image == NULL) {
        printf("Error: Failed to allocate memory for image.\n");
        return 1;
    }

    if (image_load(image, argv[1]) != 0) {
        printf("Error: Failed to load image from disk.\n");
        image_free(image);
        return 1;
    }

    if (strcmp(argv[3], "grayscale") == 0) {
        for (int i = 0; i < image->width * image->height; i++) {
            unsigned char gray = (image->pixels[i].r + image->pixels[i].g + image->pixels[i].b) / 3;
            image->pixels[i].r = gray;
            image->pixels[i].g = gray;
            image->pixels[i].b = gray;
        }
    } else if (strcmp(argv[3], "invert") == 0) {
        for (int i = 0; i < image->width * image->height; i++) {
            image->pixels[i].r = 255 - image->pixels[i].r;
            image->pixels[i].g = 255 - image->pixels[i].g;
            image->pixels[i].b = 255 - image->pixels[i].b;
        }
    } else if (strcmp(argv[3], "edge") == 0) {
        for (int i = 1; i < image->width - 1; i++) {
            for (int j = 1; j < image->height - 1; j++) {
                int dx = image->pixels[(i + 1) + j * image->width].r - image->pixels[(i - 1) + j * image->width].r;
                int dy = image->pixels[i + (j + 1) * image->width].r - image->pixels[i + (j - 1) * image->width].r;
                int gradient = abs(dx) + abs(dy);
                image->pixels[i + j * image->width].r = gradient;
                image->pixels[i + j * image->width].g = gradient;
                image->pixels[i + j * image->width].b = gradient;
            }
        }
    } else {
        printf("Error: Unknown filter '%s'.\n", argv[3]);
        image_free(image);
        return 1;
    }

    if (image_save(image, argv[2]) != 0) {
        printf("Error: Failed to save image to disk.\n");
        image_free(image);
        return 1;
    }

    image_free(image);

    return 0;
}