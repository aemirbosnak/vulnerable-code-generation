//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// Pixel struct
typedef struct {
    unsigned char r, g, b, a;
} Pixel;

// Image struct
typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

// Create a new image
Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Pixel) * width * height);
    return image;
}

// Free an image
void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

// Set a pixel in an image
void set_pixel(Image *image, int x, int y, Pixel pixel) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[y * image->width + x] = pixel;
}

// Save an image to a file
void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    // Write the header
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);

    // Write the pixels
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel = image->pixels[y * image->width + x];
            fprintf(file, "%d %d %d ", pixel.r, pixel.g, pixel.b);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Generate a random pixel
Pixel random_pixel() {
    Pixel pixel;
    pixel.r = rand() % 256;
    pixel.g = rand() % 256;
    pixel.b = rand() % 256;
    pixel.a = 255;
    return pixel;
}

// Generate a random image
Image *random_image(int width, int height) {
    Image *image = new_image(width, height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            set_pixel(image, x, y, random_pixel());
        }
    }
    return image;
}

// Generate a gradient image
Image *gradient_image(int width, int height) {
    Image *image = new_image(width, height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel;
            pixel.r = x * 255 / image->width;
            pixel.g = y * 255 / image->height;
            pixel.b = 0;
            pixel.a = 255;
            set_pixel(image, x, y, pixel);
        }
    }
    return image;
}

// Generate a circle image
Image *circle_image(int width, int height) {
    Image *image = new_image(width, height);
    int radius = width / 2;
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel;
            pixel.r = 255;
            pixel.g = 255;
            pixel.b = 255;
            pixel.a = 255;
            if (sqrt(pow(x - radius, 2) + pow(y - radius, 2)) > radius) {
                pixel.a = 0;
            }
            set_pixel(image, x, y, pixel);
        }
    }
    return image;
}

int main() {
    // Generate a random image
    Image *image = random_image(512, 512);

    // Save the image to a file
    save_image(image, "image.ppm");

    // Free the image
    free_image(image);

    return 0;
}