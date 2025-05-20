//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_PIXEL 3      // Assuming 24bpp

// Function to flip the image horizontally
void flipHorizontally(unsigned char* image, int width, int height) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width / 2; col++) {
            int index = (row * width + col) * BYTES_PER_PIXEL;
            int flipIndex = (row * width + width - col - 1) * BYTES_PER_PIXEL;
            for (int color = 0; color < BYTES_PER_PIXEL; color++) { 
                // Swap pixel values
                unsigned char temp = image[index + color];
                image[index + color] = image[flipIndex + color];
                image[flipIndex + color] = temp;
            }
        }
    }
}

int main() {
    // Declare variables
    FILE* imageFile = fopen("example.bmp", "rb");
    unsigned char* imageData;
    int imageSize;
    int width, height, colorDepth;

    // Read image data
    fseek(imageFile, 0, SEEK_END);
    imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);
    imageData = (unsigned char*)malloc(imageSize * sizeof(unsigned char));
    fread(imageData, imageSize, 1, imageFile);

    // Extract image metadata
    width = *(int*)&imageData[18];
    height = *(int*)&imageData[22];
    colorDepth = *(int*)&imageData[28];

    // Flip the image horizontally
    flipHorizontally(imageData + 54, width, height);

    // Write image data to file
    FILE* flippedImageFile = fopen("example_flipped.bmp", "wb");
    fwrite(imageData, imageSize, 1, flippedImageFile);

    // Free memory
    free(imageData);
    fclose(imageFile);
    fclose(flippedImageFile);

    return 0;
}