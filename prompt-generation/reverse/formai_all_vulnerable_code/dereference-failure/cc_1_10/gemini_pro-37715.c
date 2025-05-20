//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} pixel_t;

typedef struct {
    int width, height;
    pixel_t *pixels;
} image_t;

image_t *image_new(int width, int height) {
    image_t *image = malloc(sizeof(image_t));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(pixel_t));
    return image;
}

void image_free(image_t *image) {
    free(image->pixels);
    free(image);
}

void image_save(image_t *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(pixel_t), image->width * image->height, file);
    fclose(file);
}

void image_load(image_t *image, char *filename) {
    FILE *file = fopen(filename, "rb");
    char magic[3];
    fscanf(file, "%s", magic);
    if (strcmp(magic, "P6") != 0) {
        fprintf(stderr, "Error: Invalid image format\n");
        exit(1);
    }
    fscanf(file, "%d %d\n", &image->width, &image->height);
    int maxval;
    fscanf(file, "%d\n", &maxval);
    if (maxval != 255) {
        fprintf(stderr, "Error: Invalid image maxval\n");
        exit(1);
    }
    image->pixels = malloc(image->width * image->height * sizeof(pixel_t));
    fread(image->pixels, sizeof(pixel_t), image->width * image->height, file);
    fclose(file);
}

int main() {
    image_t *image = image_new(512, 512);

    // Draw a red circle in the center of the image
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int dx = x - image->width / 2;
            int dy = y - image->height / 2;
            if (dx * dx + dy * dy < 100 * 100) {
                image->pixels[y * image->width + x].r = 255;
            }
        }
    }

    // Save the image to a file
    image_save(image, "output.ppm");

    // Free the image
    image_free(image);

    return 0;
}