//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *image_new(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    return image;
}

void image_free(Image *image) {
    free(image->data);
    free(image);
}

void image_set_pixel(Image *image, int x, int y, char c) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->data[y * image->width + x] = c;
}

char image_get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return 0;
    }
    return image->data[y * image->width + x];
}

void image_save(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return;
    }
    fprintf(fp, "P1\n%d %d\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fputc(image_get_pixel(image, x, y) ? '1' : '0', fp);
        }
        fputc('\n', fp);
    }
    fclose(fp);
}

int main() {
    Image *image = image_new(64, 64);

    // Draw a line
    for (int x = 0; x < 64; x++) {
        image_set_pixel(image, x, 32, 1);
    }

    // Draw a circle
    for (int x = 0; x < 64; x++) {
        for (int y = 0; y < 64; y++) {
            if ((x - 32) * (x - 32) + (y - 32) * (y - 32) <= 32 * 32) {
                image_set_pixel(image, x, y, 1);
            }
        }
    }

    image_save(image, "output.pgm");
    image_free(image);
    return 0;
}