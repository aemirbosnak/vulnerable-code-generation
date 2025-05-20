//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: expert-level
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned int max_color;
    unsigned char *data;
} PixelArt;

PixelArt *pixel_art_create(unsigned int width, unsigned int height, unsigned int max_color) {
    PixelArt *pixel_art = malloc(sizeof(PixelArt));
    if (!pixel_art) {
        return NULL;
    }

    pixel_art->width = width;
    pixel_art->height = height;
    pixel_art->max_color = max_color;
    pixel_art->data = malloc(width * height * sizeof(unsigned char));
    if (!pixel_art->data) {
        free(pixel_art);
        return NULL;
    }

    return pixel_art;
}

void pixel_art_destroy(PixelArt *pixel_art) {
    free(pixel_art->data);
    free(pixel_art);
}

bool pixel_art_save_ppm(PixelArt *pixel_art, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return false;
    }

    fprintf(fp, "P6\n");
    fprintf(fp, "%u %u\n", pixel_art->width, pixel_art->height);
    fprintf(fp, "%u\n", pixel_art->max_color);
    fwrite(pixel_art->data, pixel_art->width * pixel_art->height, sizeof(unsigned char), fp);
    fclose(fp);

    return true;
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s width height max_color filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int width = atoi(argv[1]);
    unsigned int height = atoi(argv[2]);
    unsigned int max_color = atoi(argv[3]);
    const char *filename = argv[4];

    PixelArt *pixel_art = pixel_art_create(width, height, max_color);
    if (!pixel_art) {
        fprintf(stderr, "Failed to create pixel art\n");
        return EXIT_FAILURE;
    }

    // Draw a circle in the center of the pixel art
    unsigned int center_x = pixel_art->width / 2;
    unsigned int center_y = pixel_art->height / 2;
    unsigned int radius = pixel_art->width / 4;
    for (unsigned int y = 0; y < pixel_art->height; y++) {
        for (unsigned int x = 0; x < pixel_art->width; x++) {
            unsigned int dx = x - center_x;
            unsigned int dy = y - center_y;
            if (dx * dx + dy * dy <= radius * radius) {
                pixel_art->data[y * pixel_art->width + x] = max_color;
            }
        }
    }

    if (!pixel_art_save_ppm(pixel_art, filename)) {
        fprintf(stderr, "Failed to save pixel art to PPM file\n");
        pixel_art_destroy(pixel_art);
        return EXIT_FAILURE;
    }

    pixel_art_destroy(pixel_art);
    return EXIT_SUCCESS;
}