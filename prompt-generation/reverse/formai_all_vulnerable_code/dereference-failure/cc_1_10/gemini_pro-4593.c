//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 r, g, b, a;
} pixel_t;

typedef struct {
    u16 width, height;
    pixel_t *pixels;
} image_t;

image_t *create_image(u16 width, u16 height) {
    image_t *image = malloc(sizeof(image_t));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(pixel_t));
    return image;
}

void free_image(image_t *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(image_t *image, u16 x, u16 y, pixel_t color) {
    image->pixels[y * image->width + x] = color;
}

void save_image(image_t *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    fprintf(fp, "P3\n");
    fprintf(fp, "%u %u\n", image->width, image->height);
    fprintf(fp, "255\n");

    for (u16 y = 0; y < image->height; y++) {
        for (u16 x = 0; x < image->width; x++) {
            pixel_t color = image->pixels[y * image->width + x];
            fprintf(fp, "%u %u %u ", color.r, color.g, color.b);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <width> <height> <filename>\n", argv[0]);
        return 1;
    }

    u16 width = atoi(argv[1]);
    u16 height = atoi(argv[2]);

    image_t *image = create_image(width, height);

    for (u16 y = 0; y < image->height; y++) {
        for (u16 x = 0; x < image->width; x++) {
            pixel_t color = {
                .r = (x * 255) / image->width,
                .g = (y * 255) / image->height,
                .b = 0,
            };
            set_pixel(image, x, y, color);
        }
    }

    save_image(image, argv[3]);
    free_image(image);

    return 0;
}