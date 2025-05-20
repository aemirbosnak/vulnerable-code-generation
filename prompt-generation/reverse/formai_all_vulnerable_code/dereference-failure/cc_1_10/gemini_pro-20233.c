//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000

// RGB color definition
typedef struct {
    unsigned char r, g, b;
} Color;

// Pixel definition
typedef struct {
    Color color;
    double x, y;
} Pixel;

// Image definition
typedef struct {
    Pixel *pixels;
    int width, height;
} Image;

// Function to create a new image
Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Pixel) * width * height);
    return image;
}

// Function to set the color of a pixel
void set_pixel(Image *image, int x, int y, Color color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[y * image->width + x].color = color;
}

// Function to generate a gradient image
void generate_gradient_image(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Color color;
            color.r = (unsigned char) (255 * (double) x / (double) image->width);
            color.g = (unsigned char) (255 * (double) y / (double) image->height);
            color.b = (unsigned char) (255 * (double) (x + y) / ((double) image->width + (double) image->height));
            set_pixel(image, x, y, color);
        }
    }
}

// Function to generate a circle image
void generate_circle_image(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Color color;
            double distance = sqrt(pow(x - image->width / 2, 2) + pow(y - image->height / 2, 2));
            if (distance <= image->width / 2) {
                color.r = 255;
                color.g = 255;
                color.b = 255;
            } else {
                color.r = 0;
                color.g = 0;
                color.b = 0;
            }
            set_pixel(image, x, y, color);
        }
    }
}

// Function to generate a sine wave image
void generate_sine_wave_image(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Color color;
            color.r = (unsigned char) (255 * (1 + sin((double) x / (double) image->width * 2 * M_PI)));
            color.g = (unsigned char) (255 * (1 + sin((double) y / (double) image->height * 2 * M_PI)));
            color.b = (unsigned char) (255 * (1 + sin((double) (x + y) / (double) (image->width + image->height) * 2 * M_PI)));
            set_pixel(image, x, y, color);
        }
    }
}

// Function to write an image to a PPM file
void write_ppm_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fprintf(file, "%d %d %d ", image->pixels[y * image->width + x].color.r, image->pixels[y * image->width + x].color.g, image->pixels[y * image->width + x].color.b);
        }
    }
    fclose(file);
}

int main() {
    // Create a new image
    Image *image = new_image(WIDTH, HEIGHT);

    // Generate a gradient image
    generate_gradient_image(image);

    // Generate a circle image
    generate_circle_image(image);

    // Generate a sine wave image
    generate_sine_wave_image(image);

    // Write the image to a PPM file
    write_ppm_image(image, "output.ppm");

    // Free the image memory
    free(image->pixels);
    free(image);

    return 0;
}