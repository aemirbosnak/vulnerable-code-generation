//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flipHorizontally(unsigned char* image, int width, int height, int bytesPerPixel) {
    unsigned char* temp = (unsigned char*) malloc(bytesPerPixel);
    int row, col;
    for (row = 0; row < height; row++) {
        for (col = 0; col < width / 2; col++) {
            int offset1 = (row * width + col) * bytesPerPixel;
            int offset2 = (row * width + (width - col - 1)) * bytesPerPixel;
            int i;
            for (i = 0; i < bytesPerPixel; i++) {
                temp[i] = image[offset1 + i];
                image[offset1 + i] = image[offset2 + i];
                image[offset2 + i] = temp[i];
            }
        }
    }
    free(temp);
}

// Function to adjust brightness and contrast of an image
void adjustBrightnessContrast(unsigned char* image, int width, int height, int bytesPerPixel, int brightness, int contrast) {
    int row, col;
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            int offset = (row * width + col) * bytesPerPixel;
            int i;
            for (i = 0; i < bytesPerPixel; i++) {
                int value = image[offset + i];
                value += brightness;
                value = value * contrast / 100;
                if (value > 255) value = 255;
                if (value < 0) value = 0;
                image[offset + i] = (unsigned char) value;
            }
        }
    }
}

// Main function
int main() {
    // Read image file
    FILE* file = fopen("image.rgb", "rb");
    if (!file) {
        printf("Failed to open image file\n");
        return 1;
    }
    int width = 640;
    int height = 480;
    int bytesPerPixel = 3;
    unsigned char* imageData = (unsigned char*) malloc(width * height * bytesPerPixel);
    fread(imageData, 1, width * height * bytesPerPixel, file);
    fclose(file);
    
    // Flip image horizontally
    flipHorizontally(imageData, width, height, bytesPerPixel);
    
    // Adjust brightness and contrast
    adjustBrightnessContrast(imageData, width, height, bytesPerPixel, 50, 150);
    
    // Write image file
    FILE* file2 = fopen("output.rgb", "wb");
    if (!file2) {
        printf("Failed to create output file\n");
        return 1;
    }
    fwrite(imageData, 1, width * height * bytesPerPixel, file2);
    fclose(file2);
    
    free(imageData);
    return 0;
}