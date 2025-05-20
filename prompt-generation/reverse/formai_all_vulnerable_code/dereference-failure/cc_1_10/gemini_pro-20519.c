//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Image dimensions
#define WIDTH  640
#define HEIGHT 480

// Image data type
typedef unsigned char pixel_t;

// Image structure
typedef struct {
    pixel_t *data;
    int width, height;
} image_t;

// Load an image from a file
image_t *load_image(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Allocate memory for the image data
    image_t *image = malloc(sizeof(image_t));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(file);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(pixel_t));
    if (!image->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        free(image);
        fclose(file);
        return NULL;
    }

    // Read the image data
    fread(image->data, sizeof(pixel_t), width * height, file);

    // Close the file
    fclose(file);

    // Return the image
    return image;
}

// Save an image to a file
void save_image(image_t *image, const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    // Write the image data
    fwrite(image->data, sizeof(pixel_t), image->width * image->height, file);

    // Close the file
    fclose(file);
}

// Flip an image vertically
void flip_vertical(image_t *image) {
    // Iterate over the rows of the image
    for (int y = 0; y < image->height / 2; y++) {
        // Swap the rows
        for (int x = 0; x < image->width; x++) {
            pixel_t temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

// Flip an image horizontally
void flip_horizontal(image_t *image) {
    // Iterate over the columns of the image
    for (int x = 0; x < image->width / 2; x++) {
        // Swap the columns
        for (int y = 0; y < image->height; y++) {
            pixel_t temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + (image->width - x - 1)];
            image->data[y * image->width + (image->width - x - 1)] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(image_t *image, int brightness) {
    // Iterate over the pixels of the image
    for (int i = 0; i < image->width * image->height; i++) {
        // Add the brightness to the pixel
        image->data[i] = image->data[i] + brightness;

        // Clamp the pixel to the range [0, 255]
        if (image->data[i] < 0) {
            image->data[i] = 0;
        } else if (image->data[i] > 255) {
            image->data[i] = 255;
        }
    }
}

// Change the contrast of an image
void change_contrast(image_t *image, float contrast) {
    // Iterate over the pixels of the image
    for (int i = 0; i < image->width * image->height; i++) {
        // Adjust the pixel based on the contrast
        image->data[i] = 128 + (image->data[i] - 128) * contrast;

        // Clamp the pixel to the range [0, 255]
        if (image->data[i] < 0) {
            image->data[i] = 0;
        } else if (image->data[i] > 255) {
            image->data[i] = 255;
        }
    }
}

// ** Example: Flip an image vertically, change the brightness,
// and save the result to a file. **

int main() {
    // Load the image
    image_t *image = load_image("input.bmp");
    if (!image) {
        return 1;
    }

    // Flip the image vertically
    flip_vertical(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Save the image to a file
    save_image(image, "output.bmp");

    // Free the image
    free(image->data);
    free(image);

    return 0;
}