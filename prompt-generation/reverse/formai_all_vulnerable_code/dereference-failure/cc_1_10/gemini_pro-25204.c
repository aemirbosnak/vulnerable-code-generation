//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WIDTH  256
#define MAX_HEIGHT 256

typedef struct {
    unsigned char *data;
    unsigned int width;
    unsigned int height;
} Image;

Image *create_image(unsigned int width, unsigned int height) {
    Image *image = malloc(sizeof(Image));
    if (!image) {
        return NULL;
    }

    image->data = malloc(width * height * sizeof(unsigned char));
    if (!image->data) {
        free(image);
        return NULL;
    }

    image->width = width;
    image->height = height;

    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

int save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return -1;
    }

    fprintf(file, "P5\n%u %u\n255\n", image->width, image->height);
    fwrite(image->data, image->width * image->height, sizeof(unsigned char), file);

    fclose(file);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <width> <height> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int width = atoi(argv[1]);
    unsigned int height = atoi(argv[2]);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Error: maximum width and height is %d\n", MAX_WIDTH);
        return EXIT_FAILURE;
    }

    Image *image = create_image(width, height);
    if (!image) {
        fprintf(stderr, "Error: failed to create image\n");
        return EXIT_FAILURE;
    }

    // Draw a circle
    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            unsigned int dx = x - width / 2;
            unsigned int dy = y - height / 2;
            if (dx * dx + dy * dy < width * width / 4) {
                image->data[x + y * width] = 255;
            }
        }
    }

    // Save the image
    if (save_image(image, argv[3]) != 0) {
        fprintf(stderr, "Error: failed to save image\n");
        destroy_image(image);
        return EXIT_FAILURE;
    }

    destroy_image(image);

    return EXIT_SUCCESS;
}