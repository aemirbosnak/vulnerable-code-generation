//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b, a;
} pixel;

typedef struct {
    int width, height;
    pixel *pixels;
} image;

image *create_image(int width, int height) {
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(width * height * sizeof(pixel));
    return img;
}

void destroy_image(image *img) {
    free(img->pixels);
    free(img);
}

void set_pixel(image *img, int x, int y, pixel color) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return;
    }
    img->pixels[y * img->width + x] = color;
}

pixel get_pixel(image *img, int x, int y) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return (pixel){0, 0, 0, 0};
    }
    return img->pixels[y * img->width + x];
}

void save_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }
    fprintf(fp, "P3\n%d %d\n255\n", img->width, img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel color = get_pixel(img, x, y);
            fprintf(fp, "%d %d %d ", color.r, color.g, color.b);
        }
    }
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    image *img = create_image(MAX_WIDTH, MAX_HEIGHT);

    // Draw a circle
    int radius = 100;
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                set_pixel(img, x + img->width / 2, y + img->height / 2, (pixel){255, 0, 0, 255});
            }
        }
    }

    // Draw a rectangle
    int width = 200;
    int height = 100;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            set_pixel(img, x + img->width / 2 - width / 2, y + img->height / 2 - height / 2, (pixel){0, 255, 0, 255});
        }
    }

    // Draw a line
    int x1 = 0;
    int y1 = 0;
    int x2 = img->width - 1;
    int y2 = img->height - 1;
    for (int t = 0; t <= 100; t++) {
        double lerp = (double)t / 100;
        int x = x1 + (x2 - x1) * lerp;
        int y = y1 + (y2 - y1) * lerp;
        set_pixel(img, x, y, (pixel){255, 255, 255, 255});
    }

    // Save the image
    save_image(img, argv[1]);

    destroy_image(img);

    return 0;
}