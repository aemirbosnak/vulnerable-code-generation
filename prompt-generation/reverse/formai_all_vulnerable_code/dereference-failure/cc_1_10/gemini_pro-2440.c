//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Paranoia level: MAXIMUM!
#define PARANOIA 10

// Function to check if a number is within a range
int in_range(int n, int min, int max) {
    return n >= min && n <= max;
}

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            // Swap the pixels at (x, y) and (width - x - 1, y)
            unsigned char temp = image[y * width + x];
            image[y * width + x] = image[y * width + (width - x - 1)];
            image[y * width + (width - x - 1)] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertical(unsigned char *image, int width, int height) {
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            // Swap the pixels at (x, y) and (x, height - y - 1)
            unsigned char temp = image[y * width + x];
            image[y * width + x] = image[(height - y - 1) * width + x];
            image[(height - y - 1) * width + x] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
    // Clamp the brightness value to the range [-255, 255]
    brightness = in_range(brightness, -255, 255) ? brightness : 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Add the brightness value to each pixel
            image[y * width + x] = image[y * width + x] + brightness;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, float contrast) {
    // Clamp the contrast value to the range [0.0, 5.0]
    contrast = in_range(contrast, 0.0, 5.0) ? contrast : 1.0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Adjust the pixel value using the following formula:
            // new_value = (old_value - 127.5) * contrast + 127.5
            image[y * width + x] = (image[y * width + x] - 127.5) * contrast + 127.5;
        }
    }
}

// Main function
int main() {
    // Load the image from a file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error opening the image file.\n");
        return 1;
    }

    // Read the image header
    unsigned int file_size;
    unsigned int offset;
    unsigned int width;
    unsigned int height;
    fread(&file_size, 4, 1, fp);
    fread(&offset, 4, 1, fp);
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);

    // Check if the image is a valid BMP file
    if (file_size != offset + width * height * 3) {
        printf("Error: Invalid BMP file.\n");
        fclose(fp);
        return 1;
    }

    // Allocate memory for the image data
    unsigned char *image = malloc(width * height * 3);
    if (image == NULL) {
        printf("Error allocating memory for the image data.\n");
        fclose(fp);
        return 1;
    }

    // Read the image data into the buffer
    fread(image, width * height * 3, 1, fp);

    // Close the image file
    fclose(fp);

    // Flip the image horizontally (for paranoia)
    flip_horizontal(image, width, height);

    // Change the brightness of the image (for even more paranoia)
    change_brightness(image, width, height, -50);

    // Change the contrast of the image (for maximum paranoia)
    change_contrast(image, width, height, 2.0);

    // Save the modified image to a file
    fp = fopen("paranoia.bmp", "wb");
    if (fp == NULL) {
        printf("Error opening the output image file.\n");
        free(image);
        return 1;
    }

    // Write the image header to the output file
    fwrite(&file_size, 4, 1, fp);
    fwrite(&offset, 4, 1, fp);
    fwrite(&width, 4, 1, fp);
    fwrite(&height, 4, 1, fp);

    // Write the image data to the output file
    fwrite(image, width * height * 3, 1, fp);

    // Close the output image file
    fclose(fp);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}