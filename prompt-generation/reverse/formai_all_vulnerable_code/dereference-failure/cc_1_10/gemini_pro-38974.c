//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef uint32_t Pixel;

typedef struct Image {
    Pixel *data;
    int width;
    int height;
} Image;

Image *newImage(int width, int height) {
    Image *image = (Image *) malloc(sizeof(Image));
    image->data = (Pixel *) malloc(sizeof(Pixel) * width * height);
    image->width = width;
    image->height = height;
    return image;
}

void freeImage(Image *image) {
    free(image->data);
    free(image);
}

Pixel getPixel(Image *image, int x, int y) {
    return image->data[y * image->width + x];
}

void setPixel(Image *image, int x, int y, Pixel color) {
    image->data[y * image->width + x] = color;
}

void loadPPM(Image *image, const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Could not open file");
        exit(1);
    }
    int width, height, maxval;
    fscanf(f, "P6\n%d %d\n%d\n", &width, &height, &maxval);
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Image is too large\n");
        exit(1);
    }
    image->width = width;
    image->height = height;
    image->data = (Pixel *) malloc(sizeof(Pixel) * width * height);
    fread(image->data, sizeof(Pixel), width * height, f);
    fclose(f);
}

void savePPM(Image *image, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("Could not open file");
        exit(1);
    }
    fprintf(f, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, f);
    fclose(f);
}

void invert(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel color = getPixel(image, x, y);
            color = ~color;
            setPixel(image, x, y, color);
        }
    }
}

void blur(Image *image) {
    Image *tmp = newImage(image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int sum = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int cx = x + dx;
                    int cy = y + dy;
                    if (cx >= 0 && cx < image->width && cy >= 0 && cy < image->height) {
                        sum += getPixel(image, cx, cy);
                    }
                }
            }
            setPixel(tmp, x, y, sum / 9);
        }
    }
    freeImage(image);
    image = tmp;
}

void edge(Image *image) {
    Image *tmp = newImage(image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int gx = 0, gy = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int cx = x + dx;
                    int cy = y + dy;
                    if (cx >= 0 && cx < image->width && cy >= 0 && cy < image->height) {
                        int weight = 1 + abs(dx) + abs(dy);
                        int color = getPixel(image, cx, cy);
                        gx += weight * (color & 0xFF);
                        gy += weight * ((color >> 8) & 0xFF);
                    }
                }
            }
            setPixel(tmp, x, y, (gx * gx + gy * gy) / 13);
        }
    }
    freeImage(image);
    image = tmp;
}

void main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    Image *image = newImage(MAX_WIDTH, MAX_HEIGHT);
    loadPPM(image, argv[1]);
    // Do some magical stuff
    invert(image);
    blur(image);
    edge(image);
    savePPM(image, "output.ppm");
    freeImage(image);
}