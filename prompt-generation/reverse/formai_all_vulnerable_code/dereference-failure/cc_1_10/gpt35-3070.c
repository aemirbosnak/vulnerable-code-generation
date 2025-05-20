//FormAI DATASET v1.0 Category: Image Editor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h> // for malloc and free
#include <string.h> // for memcpy

// Define the image struct
typedef struct {
    int width;
    int height;
    unsigned char* pixels;
} Image;

// Define a function to create a new image
Image* create_image(int width, int height) {
    // Allocate memory for the image struct
    Image* image = (Image*)malloc(sizeof(Image));
    // Set the width and height
    image->width = width;
    image->height = height;
    // Allocate memory for the pixels
    image->pixels = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    // Set all pixels to white (255)
    memset(image->pixels, 255, width * height);
    // Return the new image
    return image;
}

// Define a function to set a pixel's color
void set_pixel(Image* image, int x, int y, unsigned char color) {
    image->pixels[y * image->width + x] = color;
}

// Define a function to get a pixel's color
unsigned char get_pixel(Image* image, int x, int y) {
    return image->pixels[y * image->width + x];
}

// Define a function to copy an image
Image* copy_image(Image* image) {
    // Allocate memory for the new image
    Image* new_image = (Image*)malloc(sizeof(Image));
    // Copy the width and height
    new_image->width = image->width;
    new_image->height = image->height;
    // Allocate memory for the pixels
    new_image->pixels = (unsigned char*)malloc(image->width * image->height * sizeof(unsigned char));
    // Copy the pixels
    memcpy(new_image->pixels, image->pixels, image->width * image->height * sizeof(unsigned char));
    // Return the new image
    return new_image;
}

int main() {
    // Create a new 100x100 image
    Image* image = create_image(100, 100);
    // Set a pixel to black at (50, 50)
    set_pixel(image, 50, 50, 0);
    // Copy the image
    Image* copy = copy_image(image);
    // Set a pixel to red in the copy at (25, 25)
    set_pixel(copy, 25, 25, 255);
    // Print the original image and the copy
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%d ", get_pixel(image, x, y));
        }
        printf("\n");
    }
    printf("\n");
    for (int y = 0; y < copy->height; y++) {
        for (int x = 0; x < copy->width; x++) {
            printf("%d ", get_pixel(copy, x, y));
        }
        printf("\n");
    }
    // Free the memory for the images
    free(image->pixels);
    free(image);
    free(copy->pixels);
    free(copy);
    return 0;
}