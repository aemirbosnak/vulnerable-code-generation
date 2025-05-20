//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

// Function to perform Image Flipping
void flipImage(BYTE *imageData, int width, int height) {
    // Calculate the number of bytes in a row
    int row_size = width * sizeof(BYTE) * 3;
    BYTE *buffer = (BYTE*)malloc(row_size);
    // Flip the rows of the image
    for(int i = 0; i < height / 2; i++) {
        memcpy(buffer, imageData + i * row_size, row_size);
        memcpy(imageData + i * row_size, imageData + (height - i - 1) * row_size, row_size);
        memcpy(imageData + (height - i - 1) * row_size, buffer, row_size);
    }
    free(buffer);
}

// Function to perform Brightness and Contrast adjustment
void brightnessContrast(BYTE *imageData, int width, int height, int brightness, int contrast) {
    // Calculate the new brightness and contrast values
    float b = brightness / 255.0f;
    float c = contrast / 255.0f;
    c = c * c;
    // Loop through each pixel in the image
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            // Get the index of the red component for the current pixel
            int idx = (y * width + x) * 3;
            BYTE r = imageData[idx];
            BYTE g = imageData[idx+1];
            BYTE b = imageData[idx+2];
            // Adjust the brightness and contrast for the current pixel
            r = (BYTE)(((r / 255.0f - 0.5f) * c + 0.5f + b) * 255.0f);
            g = (BYTE)(((g / 255.0f - 0.5f) * c + 0.5f + b) * 255.0f);
            b = (BYTE)(((b / 255.0f - 0.5f) * c + 0.5f + b) * 255.0f);
            // Set the new color values for the current pixel
            imageData[idx] = r;
            imageData[idx+1] = g;
            imageData[idx+2] = b;
        }
    }
}

int main() {
    // Read the image file
    FILE *f = fopen("input.bmp","rb");
    if(f == NULL) {
        printf("File not found.");
        return 0;
    }
    fseek(f, 54, SEEK_SET);
    BYTE *imageData = (BYTE*)malloc(3 * 512 * 512);
    fread(imageData, 1, 3 * 512 * 512, f);
    fclose(f);

    // Flip the image
    flipImage(imageData, 512, 512);

    // Adjust brightness and contrast
    brightnessContrast(imageData, 512, 512, 30, 100);

    // Save the modified image
    FILE *out = fopen("output.bmp", "wb");
    if(out == NULL) {
        printf("Could not create output file.");
        return 0;
    }
    fseek(out, 54, SEEK_SET);
    fwrite(imageData, 1, 3 * 512 * 512, out);
    fclose(out);
    free(imageData);
    return 0;
}