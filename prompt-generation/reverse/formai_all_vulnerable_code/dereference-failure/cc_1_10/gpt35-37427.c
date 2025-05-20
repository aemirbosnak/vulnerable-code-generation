//FormAI DATASET v1.0 Category: Image compression ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define structure for pixel
typedef struct Pixel {
    unsigned char R;
    unsigned char G;
    unsigned char B;
} Pixel;

// Define structure for compressed image
typedef struct CompressedImage {
    int width;
    int height;
    Pixel* pixels;
} CompressedImage;

// Function to compress image
CompressedImage compressImage(Pixel* pixels, int width, int height) {

    // Allocate memory for compressed image
    CompressedImage compressedImage;
    compressedImage.width = width;
    compressedImage.height = height;
    compressedImage.pixels = (Pixel*) malloc(width * height / 2 * sizeof(Pixel));

    // Compress every two pixels into one
    for (int i = 0, j = 0; i < width * height; i += 2, j++) {
        compressedImage.pixels[j].R = (pixels[i].R + pixels[i+1].R) / 2;
        compressedImage.pixels[j].G = (pixels[i].G + pixels[i+1].G) / 2;
        compressedImage.pixels[j].B = (pixels[i].B + pixels[i+1].B) / 2;
    }

    return compressedImage;
}

int main() {

    // Define original image size
    int width = 4;
    int height = 4;

    // Allocate memory for original image
    Pixel* originalImage = (Pixel*) malloc(width * height * sizeof(Pixel));

    // Populate original image with random pixel values
    for (int i = 0; i < width * height; i++) {
        originalImage[i].R = rand() % 256;
        originalImage[i].G = rand() % 256;
        originalImage[i].B = rand() % 256;
    }

    // Compress image
    CompressedImage compressedImage = compressImage(originalImage, width, height);

    // Print original image
    printf("Original Image:\n");
    for (int i = 0; i < width * height; i++) {
        printf("(%d,%d,%d) ", originalImage[i].R, originalImage[i].G, originalImage[i].B);
        if ((i+1) % width == 0) {
            printf("\n");
        }
    }

    // Print compressed image
    printf("\nCompressed Image:\n");
    for (int i = 0; i < width * height / 2; i++) {
        printf("(%d,%d,%d) ", compressedImage.pixels[i].R, compressedImage.pixels[i].G, compressedImage.pixels[i].B);
        if ((i+1) % (width / 2) == 0) {
            printf("\n");
        }
    }

    // Free memory
    free(originalImage);
    free(compressedImage.pixels);

    return 0;
}