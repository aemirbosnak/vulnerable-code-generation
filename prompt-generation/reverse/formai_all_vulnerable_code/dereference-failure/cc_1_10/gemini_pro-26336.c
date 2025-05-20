//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH  1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b, a;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));
    return image;
}

void destroy_image(Image *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, Pixel color) {
    image->pixels[y * image->width + x] = color;
}

Pixel get_pixel(Image *image, int x, int y) {
    return image->pixels[y * image->width + x];
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P3\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel color = get_pixel(image, x, y);
            fprintf(fp, "%d %d %d ", color.r, color.g, color.b);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    if (width <= 0 || width > MAX_WIDTH || height <= 0 || height > MAX_HEIGHT) {
        fprintf(stderr, "Invalid dimensions: %dx%d\n", width, height);
        return 1;
    }

    Image *image = create_image(width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel color = {rand() % 256, rand() % 256, rand() % 256, 255};
            set_pixel(image, x, y, color);
        }
    }

    save_image(image, "output.ppm");

    destroy_image(image);

    return 0;
}