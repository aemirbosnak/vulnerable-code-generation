//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    image->data[(y * image->width + x) * 3 + 0] = r;
    image->data[(y * image->width + x) * 3 + 1] = g;
    image->data[(y * image->width + x) * 3 + 2] = b;
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, 1, image->width * image->height * 3, fp);
    fclose(fp);
}

int main() {
    Image *image = new_image(640, 480);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char r = 255 * (x / (float)image->width);
            unsigned char g = 255 * (y / (float)image->height);
            unsigned char b = 255 * (x / (float)image->width) * (y / (float)image->height);
            set_pixel(image, x, y, r, g, b);
        }
    }

    save_image(image, "gradient.ppm");
    free_image(image);

    return 0;
}