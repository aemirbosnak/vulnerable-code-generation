//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

typedef struct {
    unsigned char r, g, b, a;
} pixel;

typedef struct {
    int width, height;
    pixel *pixels;
} image;

image *new_image(int width, int height) {
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(width * height * sizeof(pixel));
    return img;
}

void free_image(image *img) {
    free(img->pixels);
    free(img);
}

void set_pixel(image *img, int x, int y, pixel p) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return;
    }
    img->pixels[y * img->width + x] = p;
}

pixel get_pixel(image *img, int x, int y) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return (pixel){0, 0, 0, 0};
    }
    return img->pixels[y * img->width + x];
}

void save_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P3\n%d %d\n255\n", img->width, img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel p = get_pixel(img, x, y);
            fprintf(fp, "%d %d %d ", p.r, p.g, p.b);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main() {
    image *img = new_image(MAX_WIDTH, MAX_HEIGHT);

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            // Set the pixel to a random color
            pixel p = {
                .r = rand() % 256,
                .g = rand() % 256,
                .b = rand() % 256,
                .a = 255
            };
            set_pixel(img, x, y, p);
        }
    }

    save_image(img, "output.ppm");
    free_image(img);
    return 0;
}