//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    uint8_t r, g, b;
} pixel_t;

typedef struct {
    size_t width, height;
    pixel_t *pixels;
} image_t;

image_t *read_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Error opening file");
        exit(1);
    }

    // Read the header
    uint16_t magic;
    fread(&magic, sizeof(magic), 1, f);
    if (magic != 0x4d42) {
        fprintf(stderr, "Error: Not a BMP file\n");
        exit(1);
    }

    fseek(f, 10, SEEK_SET);
    uint32_t offset;
    fread(&offset, sizeof(offset), 1, f);

    // Read the info header
    uint32_t header_size;
    fread(&header_size, sizeof(header_size), 1, f);
    fseek(f, offset, SEEK_SET);

    // Read the image dimensions
    size_t width, height;
    fread(&width, sizeof(width), 1, f);
    fread(&height, sizeof(height), 1, f);

    // Read the image pixels
    image_t *image = malloc(sizeof(image_t));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(pixel_t));
    fread(image->pixels, sizeof(pixel_t), width * height, f);

    fclose(f);

    return image;
}

void write_image(const char *filename, image_t *image) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("Error opening file");
        exit(1);
    }

    // Write the header
    uint16_t magic = 0x4d42;
    fwrite(&magic, sizeof(magic), 1, f);
    uint32_t offset = 54;
    fwrite(&offset, sizeof(offset), 1, f);

    // Write the info header
    uint32_t header_size = 40;
    fwrite(&header_size, sizeof(header_size), 1, f);
    uint32_t width = image->width;
    fwrite(&width, sizeof(width), 1, f);
    uint32_t height = image->height;
    fwrite(&height, sizeof(height), 1, f);
    uint16_t planes = 1;
    fwrite(&planes, sizeof(planes), 1, f);
    uint16_t bit_count = 24;
    fwrite(&bit_count, sizeof(bit_count), 1, f);

    // Write the image pixels
    fwrite(image->pixels, sizeof(pixel_t), width * height, f);

    fclose(f);
}

void flip_image(image_t *image) {
    for (size_t y = 0; y < image->height / 2; y++) {
        for (size_t x = 0; x < image->width; x++) {
            pixel_t temp = image->pixels[y * image->width + x];
            image->pixels[y * image->width + x] = image->pixels[(image->height - y - 1) * image->width + x];
            image->pixels[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

void change_brightness(image_t *image, float brightness) {
    for (size_t y = 0; y < image->height; y++) {
        for (size_t x = 0; x < image->width; x++) {
            pixel_t *pixel = &image->pixels[y * image->width + x];
            pixel->r = (uint8_t) round(pixel->r * brightness);
            pixel->g = (uint8_t) round(pixel->g * brightness);
            pixel->b = (uint8_t) round(pixel->b * brightness);
        }
    }
}

void change_contrast(image_t *image, float contrast) {
    for (size_t y = 0; y < image->height; y++) {
        for (size_t x = 0; x < image->width; x++) {
            pixel_t *pixel = &image->pixels[y * image->width + x];
            float r = (pixel->r - 128) * contrast + 128;
            float g = (pixel->g - 128) * contrast + 128;
            float b = (pixel->b - 128) * contrast + 128;
            pixel->r = (uint8_t) round(r);
            pixel->g = (uint8_t) round(g);
            pixel->b = (uint8_t) round(b);
        }
    }
}

int main() {
    image_t *image = read_image("image.bmp");

    // Flip the image
    flip_image(image);

    // Change the brightness
    change_brightness(image, 1.2);

    // Change the contrast
    change_contrast(image, 1.5);

    // Write the modified image
    write_image("modified_image.bmp", image);

    free(image->pixels);
    free(image);

    return 0;
}