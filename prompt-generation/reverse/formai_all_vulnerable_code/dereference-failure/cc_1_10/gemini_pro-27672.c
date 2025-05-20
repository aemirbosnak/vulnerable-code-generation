//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the pixel struct
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Define the image struct
typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

// Create a new image
Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));
    return image;
}

// Free an image
void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

// Set a pixel in an image
void set_pixel(Image *image, int x, int y, Pixel pixel) {
    image->pixels[y * image->width + x] = pixel;
}

// Get a pixel from an image
Pixel get_pixel(Image *image, int x, int y) {
    return image->pixels[y * image->width + x];
}

// Save an image to a file
void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

// Generate a random pixel
Pixel random_pixel() {
    Pixel pixel;
    pixel.r = rand() % 256;
    pixel.g = rand() % 256;
    pixel.b = rand() % 256;
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
            pixel.r = (unsigned char)(x * 255 / image->width);
            pixel.g = (unsigned char)(y * 255 / image->height);
            pixel.b = (unsigned char)(x * y / (image->width * image->height));
            set_pixel(image, x, y, pixel);
        }
    }
    return image;
}

// Generate a circle image
Image *circle_image(int width, int height) {
    Image *image = new_image(width, height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel;
            double dx = x - image->width / 2;
            double dy = y - image->height / 2;
            double r = sqrt(dx * dx + dy * dy);
            if (r < image->width / 2) {
                pixel.r = 255;
                pixel.g = 255;
                pixel.b = 255;
            } else {
                pixel.r = 0;
                pixel.g = 0;
                pixel.b = 0;
            }
            set_pixel(image, x, y, pixel);
        }
    }
    return image;
}

int main() {
    int width = 512;
    int height = 512;

    // Generate a random image
    Image *image = random_image(width, height);

    // Save the image to a file
    save_image(image, "random.ppm");

    // Free the image
    free_image(image);

    return 0;
}