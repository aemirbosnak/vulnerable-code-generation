//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    unsigned short width, height;
    Color **pixels;
} Image;

Image *create_image(unsigned short width, unsigned short height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Color *) * height);
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(Color) * width);
    }
    return image;
}

void destroy_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < image->height; i++) {
        fwrite(image->pixels[i], sizeof(Color), image->width, file);
    }
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <width> <height>\n", argv[0]);
        return 1;
    }

    unsigned short width = atoi(argv[1]);
    unsigned short height = atoi(argv[2]);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: image dimensions too large.\n");
        return 1;
    }

    Image *image = create_image(width, height);

    // Draw a gradient from red to blue
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image->pixels[i][j].r = (j * 255) / width;
            image->pixels[i][j].g = 0;
            image->pixels[i][j].b = (255 - (i * 255) / height);
        }
    }

    save_image(image, "gradient.ppm");
    destroy_image(image);

    return 0;
}