//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    unsigned int width, height;
    Pixel *pixels;
} Image;

Image *create_image(unsigned int width, unsigned int height) {
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

void set_pixel(Image *image, unsigned int x, unsigned int y, Pixel color) {
    image->pixels[y * image->width + x] = color;
}

Pixel get_pixel(Image *image, unsigned int x, unsigned int y) {
    return image->pixels[y * image->width + x];
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <width> <height>\n", argv[0]);
        return 1;
    }

    unsigned int width = atoi(argv[1]);
    unsigned int height = atoi(argv[2]);

    Image *image = create_image(width, height);

    // Draw a red square
    for (unsigned int x = 0; x < width / 2; x++) {
        for (unsigned int y = 0; y < height / 2; y++) {
            set_pixel(image, x, y, (Pixel){255, 0, 0});
        }
    }

    // Draw a green circle
    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            if ((x - width / 2) * (x - width / 2) + (y - height / 2) * (y - height / 2) < width * height / 4) {
                set_pixel(image, x, y, (Pixel){0, 255, 0});
            }
        }
    }

    // Draw a blue triangle
    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            if (x + y < width + height) {
                set_pixel(image, x, y, (Pixel){0, 0, 255});
            }
        }
    }

    save_image(image, "output.ppm");
    destroy_image(image);

    return 0;
}