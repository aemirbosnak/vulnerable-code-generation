//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height);
    image->width = width;
    image->height = height;
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <output file>\n", argv[0]);
        return 1;
    }

    // Create a new image
    Image *image = create_image(MAX_WIDTH, MAX_HEIGHT);

    // Fill the image with white
    memset(image->data, 255, image->width * image->height);

    // Draw a black circle in the center of the image
    int radius = 100;
    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            if (x * x + y * y <= radius * radius) {
                image->data[(image->width / 2 + x) + (image->height / 2 + y) * image->width] = 0;
            }
        }
    }

    // Write the image to a file
    FILE *file = fopen(argv[1], "wb");
    fwrite(image->data, 1, image->width * image->height, file);
    fclose(file);

    // Destroy the image
    destroy_image(image);

    return 0;
}