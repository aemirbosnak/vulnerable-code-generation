//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pixel {
    unsigned char r, g, b;
} pixel;

typedef struct image {
    int width, height;
    pixel *data;
} image;

image *new_image(int width, int height) {
    image *im = malloc(sizeof(image));
    im->width = width;
    im->height = height;
    im->data = malloc(width * height * sizeof(pixel));
    return im;
}

void free_image(image *im) {
    free(im->data);
    free(im);
}

void set_pixel(image *im, int x, int y, pixel p) {
    im->data[y * im->width + x] = p;
}

pixel get_pixel(image *im, int x, int y) {
    return im->data[y * im->width + x];
}

void save_ppm(image *im, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", im->width, im->height);
    fwrite(im->data, im->width * im->height * sizeof(pixel), 1, fp);
    fclose(fp);
}

int main() {
    image *im = new_image(100, 100);

    for (int y = 0; y < im->height; y++) {
        for (int x = 0; x < im->width; x++) {
            pixel p = {x % 255, y % 255, (x + y) % 255};
            set_pixel(im, x, y, p);
        }
    }

    save_ppm(im, "test.ppm");
    free_image(im);
    return 0;
}