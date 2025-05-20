//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to flip an image horizontally
void flipHorizontally(int rows, int cols, unsigned char *img) {
    int i, j;
    unsigned char temp;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols / 2; j++) {
            temp = img[i * cols + j];
            img[i * cols + j] = img[i * cols + cols - 1 - j];
            img[i * cols + cols - 1 - j] = temp;
        }
    }
}

// Function to adjust brightness and contrast of an image
void adjustBrightnessAndContrast(int rows, int cols, unsigned char *img, float brightness, float contrast) {
    int i, j;
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            int pixel = img[i * cols + j];
            pixel = factor * (pixel - 128) + 128 + (brightness * 255);
            if (pixel < 0) {
                pixel = 0;
            } else if (pixel > 255) {
                pixel = 255;
            }
            img[i * cols + j] = (unsigned char) pixel;
        }
    }
}

int main() {
    FILE *file;
    unsigned char *image;
    char *filename = "lena.raw"; // replace with your image file name
    int rows = 512; // replace with your image's height
    int cols = 512; // replace with your image's width
    
    // allocate memory for image data
    image = (unsigned char *) malloc(rows * cols * sizeof(unsigned char));
    
    // read image data from file
    file = fopen(filename, "rb");
    fread(image, sizeof(unsigned char), rows * cols, file);
    fclose(file);
    
    // flip image horizontally and save it to a new file
    flipHorizontally(rows, cols, image);
    file = fopen("flipped_lena.raw", "wb");
    fwrite(image, sizeof(unsigned char), rows * cols, file);
    fclose(file);
    
    // adjust brightness and contrast of the original image and save it to a new file
    adjustBrightnessAndContrast(rows, cols, image, -0.2, 1.3);
    file = fopen("brighter_contrasty_lena.raw", "wb");
    fwrite(image, sizeof(unsigned char), rows * cols, file);
    fclose(file);
    
    free(image);
    return 0;
}