//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the characters used for the ASCII art conversion
char ascii_chars[] = " .,:;i1tfLCG08@";
int char_count = sizeof(ascii_chars) - 1;

// Define the default image dimensions and scaling factors
int IMG_WIDTH = 80;
int IMG_HEIGHT = 40;
float SCALE_FACTOR = 0.5;

// Function to read an image file and extract RGB values
void read_image(char *filename, unsigned char *image) {
    FILE *f = fopen(filename, "rb");

    if (f == NULL) {
        printf("Error opening image file.");
        exit(1);
    }

    // Read and discard header info
    char header[54];
    fread(header, sizeof(char), 54, f);

    // Read image data to buffer
    fread(image, sizeof(unsigned char), IMG_WIDTH * IMG_HEIGHT * 3, f);

    fclose(f);
}

// Function to convert RGB values to grayscale
void grayscale(unsigned char *image) {
    for (int i = 0; i < IMG_WIDTH * IMG_HEIGHT; i++) {
        unsigned char r = image[i * 3];
        unsigned char g = image[i * 3 + 1];
        unsigned char b = image[i * 3 + 2];

        image[i] = (0.3 * r) + (0.59 * g) + (0.11 * b);
    }
}

// Function to scale down the image
void scale_image(unsigned char *image) {
    int new_width = IMG_WIDTH * SCALE_FACTOR;
    int new_height = IMG_HEIGHT * SCALE_FACTOR;
    unsigned char new_image[new_width * new_height];

    for(int row = 0; row < new_height; row++) {
        for(int col = 0; col < new_width; col++) {
            int idx = ((int)(row/SCALE_FACTOR) * IMG_WIDTH + (int)(col/SCALE_FACTOR));
            new_image[row * new_width + col] = image[idx];
        }
    }

    memcpy(image, new_image, new_width * new_height);
    IMG_WIDTH = new_width;
    IMG_HEIGHT = new_height;
}

// Function to convert grayscale pixel values to ASCII chars
void ascii_convert(unsigned char *image) {
    for (int i = 0; i < IMG_WIDTH * IMG_HEIGHT; i++) {
        int grayscale_val = (int)image[i];
        int char_idx = (int)(((float)grayscale_val/255.0) * (char_count - 1));
        printf("%c", ascii_chars[char_idx]);
        if (i % IMG_WIDTH == 0) {
            printf("\n");
        }
    }
}

int main(int argc, char *argv[]) {
    // Check for image filename input
    if (argc < 2) {
        printf("Image filename missing from command line argument.");
        exit(1);
    }

    char *filename = argv[1];

    // Allocate memory for image data
    unsigned char *image = (unsigned char*) malloc(sizeof(unsigned char) * IMG_WIDTH * IMG_HEIGHT * 3);

    // Read the image from file
    read_image(filename, image);

    // Convert image to grayscale
    grayscale(image);

    // Scale the image down
    scale_image(image);

    // Convert grayscale values to ASCII chars and print result
    ascii_convert(image);

    // Free allocated memory
    free(image);

    return 0;
}