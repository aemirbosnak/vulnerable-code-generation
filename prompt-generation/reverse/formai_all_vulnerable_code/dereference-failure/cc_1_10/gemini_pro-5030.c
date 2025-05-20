//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel_t;

typedef struct {
    int width;
    int height;
    pixel_t *pixels;
} image_t;

image_t *image_new(int width, int height) {
    image_t *image = malloc(sizeof(image_t));
    if (!image) {
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(pixel_t) * width * height);
    if (!image->pixels) {
        free(image);
        return NULL;
    }

    return image;
}

void image_free(image_t *image) {
    free(image->pixels);
    free(image);
}

int image_load(image_t *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return -1;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);

    size_t pixels_size = image->width * image->height * sizeof(pixel_t);
    image->pixels = malloc(pixels_size);
    if (!image->pixels) {
        fclose(file);
        return -1;
    }

    fread(image->pixels, pixels_size, 1, file);

    fclose(file);

    return 0;
}

int image_save(image_t *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return -1;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    size_t pixels_size = image->width * image->height * sizeof(pixel_t);
    fwrite(image->pixels, pixels_size, 1, file);

    fclose(file);

    return 0;
}

void image_grayscale(image_t *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            pixel_t *pixel = &image->pixels[y * image->width + x];
            uint8_t gray = (pixel->red + pixel->green + pixel->blue) / 3;
            pixel->red = gray;
            pixel->green = gray;
            pixel->blue = gray;
        }
    }
}

void image_invert(image_t *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            pixel_t *pixel = &image->pixels[y * image->width + x];
            pixel->red = 255 - pixel->red;
            pixel->green = 255 - pixel->green;
            pixel->blue = 255 - pixel->blue;
        }
    }
}

void image_brightness(image_t *image, int brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            pixel_t *pixel = &image->pixels[y * image->width + x];
            pixel->red += brightness;
            pixel->green += brightness;
            pixel->blue += brightness;

            if (pixel->red > 255) { pixel->red = 255; }
            if (pixel->green > 255) { pixel->green = 255; }
            if (pixel->blue > 255) { pixel->blue = 255; }
        }
    }
}

void image_contrast(image_t *image, int contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            pixel_t *pixel = &image->pixels[y * image->width + x];
            int r = pixel->red - 128;
            int g = pixel->green - 128;
            int b = pixel->blue - 128;

            r *= contrast;
            g *= contrast;
            b *= contrast;

            r += 128;
            g += 128;
            b += 128;

            if (r < 0) { r = 0; }
            if (g < 0) { g = 0; }
            if (b < 0) { b = 0; }
            if (r > 255) { r = 255; }
            if (g > 255) { g = 255; }
            if (b > 255) { b = 255; }

            pixel->red = r;
            pixel->green = g;
            pixel->blue = b;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    image_t *image = image_new(0, 0);
    if (!image) {
        printf("Failed to allocate memory for image\n");
        return 1;
    }

    if (image_load(image, argv[1]) != 0) {
        printf("Failed to load image %s\n", argv[1]);
        image_free(image);
        return 1;
    }

    image_grayscale(image);
    image_invert(image);
    image_brightness(image, 50);
    image_contrast(image, 150);

    if (image_save(image, argv[2]) != 0) {
        printf("Failed to save image %s\n", argv[2]);
        image_free(image);
        return 1;
    }

    image_free(image);

    return 0;
}