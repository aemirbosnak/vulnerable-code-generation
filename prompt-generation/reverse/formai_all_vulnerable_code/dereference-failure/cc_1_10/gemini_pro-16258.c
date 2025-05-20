//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Screen dimensions
#define WIDTH 800
#define HEIGHT 600

// Pixel struct
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Image struct
typedef struct {
    Pixel *pixels;
    int width, height;
} Image;

// Function to create a new image
Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));
    return image;
}

// Function to free an image
void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

// Function to set a pixel in an image
void set_pixel(Image *image, int x, int y, Pixel color) {
    image->pixels[y * image->width + x] = color;
}

// Function to get a pixel from an image
Pixel get_pixel(Image *image, int x, int y) {
    return image->pixels[y * image->width + x];
}

// Function to generate a random color
Pixel random_color() {
    Pixel color;
    color.r = rand() % 256;
    color.g = rand() % 256;
    color.b = rand() % 256;
    return color;
}

// Function to generate a surrealist image
Image *surrealist_image(int width, int height) {
    Image *image = new_image(width, height);

    // Set the background color to black
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            set_pixel(image, x, y, (Pixel){0, 0, 0});
        }
    }

    // Generate a random number of objects
    int num_objects = rand() % 100;

    // Generate the objects
    for (int i = 0; i < num_objects; i++) {
        // Get the object's position
        int x = rand() % width;
        int y = rand() % height;

        // Get the object's size
        int size = rand() % 100;

        // Get the object's color
        Pixel color = random_color();

        // Draw the object
        for (int j = -size; j < size; j++) {
            for (int k = -size; k < size; k++) {
                if (x + j >= 0 && x + j < width && y + k >= 0 && y + k < height) {
                    set_pixel(image, x + j, y + k, color);
                }
            }
        }
    }

    return image;
}

// Function to write an image to a PPM file
void write_ppm(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel color = get_pixel(image, x, y);
            fputc(color.r, file);
            fputc(color.g, file);
            fputc(color.b, file);
        }
    }
    fclose(file);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a surrealist image
    Image *image = surrealist_image(WIDTH, HEIGHT);

    // Write the image to a PPM file
    write_ppm(image, "surrealist.ppm");

    // Free the image
    free_image(image);

    return 0;
}