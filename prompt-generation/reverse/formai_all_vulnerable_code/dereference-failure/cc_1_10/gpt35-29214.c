//FormAI DATASET v1.0 Category: Image Editor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the image structure
typedef struct Image {
    int width;
    int height;
    unsigned char* data;
} Image;

// Function to read an image from a file
Image* read_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        return NULL;
    }

    // Read the header
    char magic[3];
    int width, height, maxval;
    fscanf(file, "%2s\n%d %d\n%d\n", magic, &width, &height, &maxval);
    if (strcmp(magic, "P6") != 0) {
        fprintf(stderr, "Unsupported file format\n");
        return NULL;
    }

    // Allocate memory for the image
    Image* image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = (unsigned char*) malloc(image->width * image->height * 3);

    // Read the pixel data
    fread(image->data, 3, image->width * image->height, file);

    // Clean up
    fclose(file);

    return image;
}

// Function to write an image to a file
int write_image(const char* filename, Image* image) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to open file %s for writing\n", filename);
        return 0;
    }

    // Write the header
    fprintf(file, "P6\n%d %d\n%d\n", image->width, image->height, 255);

    // Write the pixel data
    fwrite(image->data, 3, image->width * image->height, file);

    // Clean up
    fclose(file);

    return 1;
}

// Function to flip an image horizontally
void flip_image_horizontally(Image* image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            int i1 = (y * image->width + x) * 3;
            int i2 = (y * image->width + (image->width - x - 1)) * 3;

            // Swap the RGB values for the two pixels
            unsigned char r = image->data[i1];
            unsigned char g = image->data[i1 + 1];
            unsigned char b = image->data[i1 + 2];
            image->data[i1] = image->data[i2];
            image->data[i1 + 1] = image->data[i2 + 1];
            image->data[i1 + 2] = image->data[i2 + 2];
            image->data[i2] = r;
            image->data[i2 + 1] = g;
            image->data[i2 + 2] = b;
        }
    }
}

// Function to invert an image
void invert_image(Image* image) {
    for (int i = 0; i < image->width * image->height * 3; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

// Sample usage
int main(void) {
    // Read an image from file
    Image* image = read_image("input.ppm");
    if (!image) {
        return 1;
    }

    // Flip the image horizontally
    flip_image_horizontally(image);

    // Invert the image
    invert_image(image);

    // Write the modified image to file
    if (!write_image("output.ppm", image)) {
        return 1;
    }

    // Clean up
    free(image->data);
    free(image);

    return 0;
}