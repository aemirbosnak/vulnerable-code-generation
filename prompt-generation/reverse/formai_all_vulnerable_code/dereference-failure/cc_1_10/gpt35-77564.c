//FormAI DATASET v1.0 Category: Image Editor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Struct for holding RGB values
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// Image struct containing width, height, and pixel data
typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

// Function to allocate memory for an Image struct with given width and height
Image *create_image(int width, int height) {
    Image *image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (Pixel*) malloc(width * height * sizeof(Pixel));
    return image;
}

// Function to free memory allocated for an Image struct
void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

// Function to set the color of a pixel at the specified x and y coordinates in the given Image struct
void set_pixel(Image *image, int x, int y, unsigned char red, unsigned char green, unsigned char blue) {
    Pixel *pixel = image->pixels + (y * image->width + x);
    pixel->red = red;
    pixel->green = green;
    pixel->blue = blue;
}

// Function to read an image from a file
Image *read_image_from_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read in file header
    int width, height;
    fscanf(file, "P6\n%d %d\n255\n", &width, &height);

    // Allocate memory for Image struct
    Image *image = create_image(width, height);

    // Read in pixel data
    fread(image->pixels, sizeof(Pixel), width * height, file);

    fclose(file);
    return image;
}

// Function to write an image to a file
void write_image_to_file(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    // Write out file header
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);

    // Write out pixel data
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);

    fclose(file);
}

int main() {
    // Test image
    Image *image = create_image(400, 300);

    // Draw diagonal line of red pixels
    for (int i = 0; i < 300; i++) {
        set_pixel(image, i, i, 255, 0, 0);
    }

    // Write image to file
    write_image_to_file(image, "test.ppm");

    printf("Surprise!!! Image has been created.\n");

    // Free memory
    free_image(image);

    return 0;
}