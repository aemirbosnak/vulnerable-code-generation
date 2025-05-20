//FormAI DATASET v1.0 Category: Image compression ; Style: bold
//*******************************************************
//**  Image Compression Example Program               ***
//**  Written by BoldBot                               ***
//*******************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 640	// Image width
#define HEIGHT 480	// Image height
#define THRESHOLD 100	// Pixel value threshold for compression

typedef unsigned char BYTE;

// Function to compress the image
void compress_image(BYTE *orig_image, BYTE *comp_image) {
    int index = 0;

    // Iterate through each pixel of original image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int pixel = y * WIDTH + x;
            BYTE value = orig_image[pixel];

            // If the pixel value is less than the threshold, compress to 0
            if (value < THRESHOLD) {
                comp_image[index] = 0;
                index++;
            }
            // Otherwise, keep the pixel value
            else {
                comp_image[index] = value;
                index++;
            }
        }
    }
}

// Function to decompress the image
void decompress_image(BYTE *comp_image, BYTE *decomp_image) {
    int index = 0;

    // Iterate through each compressed pixel
    for (int i = 0; i < WIDTH * HEIGHT; i++) {

        // If the compressed pixel is 0, set the decompressed pixel to 0
        if (comp_image[i] == 0) {
            decomp_image[index] = 0;
        }
        // Otherwise, set the decompressed pixel to the compressed pixel value
        else {
            decomp_image[index] = comp_image[i];
        }
        index++;
    }
}

int main() {
    // Allocate memory for the images
    BYTE *orig_image = malloc(WIDTH * HEIGHT * sizeof(BYTE));
    BYTE *comp_image = malloc(WIDTH * HEIGHT * sizeof(BYTE));
    BYTE *decomp_image = malloc(WIDTH * HEIGHT * sizeof(BYTE));

    // Fill the original image with random pixel values
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        orig_image[i] = rand() % 256;
    }

    // Compress the image
    compress_image(orig_image, comp_image);

    // Decompress the image
    decompress_image(comp_image, decomp_image);

    // Check if the two images match
    if (memcmp(orig_image, decomp_image, WIDTH * HEIGHT * sizeof(BYTE)) == 0) {
        printf("Compression Successful!\n");
    }
    else {
        printf("Compression Failed!\n");
    }

    // Free the memory
    free(orig_image);
    free(comp_image);
    free(decomp_image);

    return 0;
}