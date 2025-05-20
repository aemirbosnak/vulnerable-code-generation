//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 64
#define HEIGHT 48

typedef struct {
    unsigned char r, g, b;
} pixel_t;

typedef struct {
    int width, height;
    pixel_t *pixels;
} image_t;

image_t *image_load(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        return NULL;
    }

    int width, height;
    if (fscanf(file, "P6\n%d %d\n255\n", &width, &height) != 2) {
        fprintf(stderr, "Invalid PPM header\n");
        fclose(file);
        return NULL;
    }

    image_t *image = malloc(sizeof(image_t));
    if (!image) {
        perror("malloc");
        fclose(file);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(pixel_t));
    if (!image->pixels) {
        perror("malloc");
        free(image);
        fclose(file);
        return NULL;
    }

    fread(image->pixels, sizeof(pixel_t), width * height, file);
    fclose(file);

    return image;
}

void image_free(image_t *image) {
    free(image->pixels);
    free(image);
}

void image_to_ascii(const image_t *image, char *ascii) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            pixel_t pixel = image->pixels[y * image->width + x];
            double luminance = 0.2126 * pixel.r + 0.7152 * pixel.g + 0.0722 * pixel.b;
            int level = (int)round(255 * luminance / 255);
            ascii[y * image->width + x] = " .,-~;:=+*#%@";
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.txt>\n", argv[0]);
        return 1;
    }

    image_t *image = image_load(argv[1]);
    if (!image) {
        return 1;
    }

    char *ascii = malloc(image->width * image->height + 1);
    if (!ascii) {
        perror("malloc");
        image_free(image);
        return 1;
    }

    image_to_ascii(image, ascii);

    FILE *file = fopen(argv[2], "w");
    if (!file) {
        perror("fopen");
        free(ascii);
        image_free(image);
        return 1;
    }

    fprintf(file, "%s", ascii);
    fclose(file);

    free(ascii);
    image_free(image);

    return 0;
}