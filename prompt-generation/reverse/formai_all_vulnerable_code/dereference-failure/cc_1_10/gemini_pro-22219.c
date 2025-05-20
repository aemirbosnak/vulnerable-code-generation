//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width;
    int height;
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

pixel get_pixel(image *img, int x, int y) {
    return img->pixels[y * img->width + x];
}

void set_pixel(image *img, int x, int y, pixel color) {
    img->pixels[y * img->width + x] = color;
}

void save_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

int main() {
    image *img = new_image(512, 512);

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel color = { .r = x, .g = y, .b = 0 };
            set_pixel(img, x, y, color);
        }
    }

    save_image(img, "gradient.ppm");
    free_image(img);

    return 0;
}