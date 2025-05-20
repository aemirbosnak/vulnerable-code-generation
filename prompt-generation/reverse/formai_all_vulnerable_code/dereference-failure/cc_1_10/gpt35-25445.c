//FormAI DATASET v1.0 Category: Image Editor ; Style: complete
// A C image editor program that converts a color image to grayscale and applies a blur effect
// by averaging the color intensities of each pixel with its neighboring pixels
// Written by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

// Function to read the image file and return its content as a 2D byte array
unsigned char** read_image(const char* filename) {
    unsigned char** image = (unsigned char**) malloc(HEIGHT * sizeof(unsigned char*));
    for (int i = 0; i < HEIGHT; i++) {
        image[i] = (unsigned char*) malloc(WIDTH * 3 * sizeof(unsigned char));
    }
    FILE* fp = fopen(filename, "rb");
    fread(image[0], sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);
    return image;
}

// Function to write the 2D byte array as an image file
void write_image(const char* filename, unsigned char** image) {
    FILE* fp = fopen(filename, "wb");
    fwrite(image[0], sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);
}

// Function to convert a color pixel to grayscale
void grayscale(unsigned char* pixel) {
    unsigned char gray = (unsigned char) round((pixel[0] + pixel[1] + pixel[2]) / 3.0);
    pixel[0] = gray;
    pixel[1] = gray;
    pixel[2] = gray;
}

// Function to apply a blur effect to the image
void blur(unsigned char** image) {
    unsigned char** temp = (unsigned char**) malloc(HEIGHT * sizeof(unsigned char*));
    for (int i = 0; i < HEIGHT; i++) {
        temp[i] = (unsigned char*) malloc(WIDTH * 3 * sizeof(unsigned char));
        memcpy(temp[i], image[i], WIDTH * 3 * sizeof(unsigned char));
    }
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 3; j < WIDTH * 3 - 3; j += 3) {
            temp[i][j] = (unsigned char) round((image[i-1][j-3] + image[i-1][j] + image[i-1][j+3] +
                                                image[i][j-3] + image[i][j] + image[i][j+3] +
                                                image[i+1][j-3] + image[i+1][j] + image[i+1][j+3]) / 9.0);
            temp[i][j+1] = (unsigned char) round((image[i-1][j-2] + image[i-1][j+1] + image[i-1][j+4] +
                                                  image[i][j-2] + image[i][j+1] + image[i][j+4] +
                                                  image[i+1][j-2] + image[i+1][j+1] + image[i+1][j+4]) / 9.0);
            temp[i][j+2] = (unsigned char) round((image[i-1][j-1] + image[i-1][j+2] + image[i-1][j+5] +
                                                  image[i][j-1] + image[i][j+2] + image[i][j+5] +
                                                  image[i+1][j-1] + image[i+1][j+2] + image[i+1][j+5]) / 9.0);
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        memcpy(image[i], temp[i], WIDTH * 3 * sizeof(unsigned char));
        free(temp[i]);
    }
    free(temp);
}

int main() {
    // Read the input image file
    unsigned char** image = read_image("input.bin");

    // Convert the image to grayscale
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH * 3; j += 3) {
            grayscale(&image[i][j]);
        }
    }

    // Apply the blur effect to the image
    blur(image);

    // Write the output image file
    write_image("output.bin", image);

    // Free the memory used by the image
    for (int i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}