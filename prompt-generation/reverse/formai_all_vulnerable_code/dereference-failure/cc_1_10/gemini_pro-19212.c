//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an image
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function to load an image from a file
Image *load_image(const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[10];
    fread(header, 1, 10, fp);

    // Check if the file is a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a BMP file\n", filename);
        fclose(fp);
        return NULL;
    }

    // Read the width and height of the image
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the image data
    unsigned char *data = malloc(width * height * 3);
    fread(data, 1, width * height * 3, fp);

    // Close the file
    fclose(fp);

    // Create and return the image
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Function to save an image to a file
void save_image(const Image *image, const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[10] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0
    };
    fwrite(header, 1, 10, fp);

    // Write the width and height of the image
    int width = image->width;
    int height = image->height;
    fwrite(&width, 4, 1, fp);
    fwrite(&height, 4, 1, fp);

    // Write the image data
    fwrite(image->data, 1, width * height * 3, fp);

    // Close the file
    fclose(fp);
}

// Function to flip an image vertically
void flip_vertical(Image *image) {
    // Get the width and height of the image
    int width = image->width;
    int height = image->height;

    // Create a new image to store the flipped image
    Image *flipped_image = malloc(sizeof(Image));
    flipped_image->width = width;
    flipped_image->height = height;
    flipped_image->data = malloc(width * height * 3);

    // Flip the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (i * width + j) * 3;
            int flipped_index = ((height - i - 1) * width + j) * 3;
            flipped_image->data[flipped_index] = image->data[index];
            flipped_image->data[flipped_index + 1] = image->data[index + 1];
            flipped_image->data[flipped_index + 2] = image->data[index + 2];
        }
    }

    // Free the old image
    free(image->data);

    // Assign the new image to the old image
    *image = *flipped_image;

    // Free the new image
    free(flipped_image);
}

// Function to change the brightness and contrast of an image
void adjust_brightness_contrast(Image *image, int brightness, int contrast) {
    // Get the width and height of the image
    int width = image->width;
    int height = image->height;

    // Calculate the new brightness and contrast values
    float new_brightness = brightness / 100.0f;
    float new_contrast = contrast / 100.0f;

    // Adjust the brightness and contrast of the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (i * width + j) * 3;
            image->data[index] = new_brightness * image->data[index];
            image->data[index + 1] = new_brightness * image->data[index + 1];
            image->data[index + 2] = new_brightness * image->data[index + 2];
            image->data[index] = new_contrast * (image->data[index] - 128) + 128;
            image->data[index + 1] = new_contrast * (image->data[index + 1] - 128) + 128;
            image->data[index + 2] = new_contrast * (image->data[index + 2] - 128) + 128;
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    // Load the input image
    Image *input_image = load_image(argv[1]);
    if (input_image == NULL) {
        return 1;
    }

    // Flip the image vertically
    flip_vertical(input_image);

    // Change the brightness and contrast of the image
    adjust_brightness_contrast(input_image, 20, 30);

    // Save the output image
    save_image(input_image, argv[2]);

    // Free the input image
    free(input_image->data);
    free(input_image);

    return 0;
}