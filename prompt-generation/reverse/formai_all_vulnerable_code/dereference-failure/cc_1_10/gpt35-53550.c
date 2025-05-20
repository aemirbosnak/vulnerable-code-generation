//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flipHorizontal(unsigned char* image, int width, int height, int channels) {
    int i, j, k;
    unsigned char temp;
    
    // Loop through each row of the image
    for (i = 0; i < height; i++) {
        
        // Loop through each pixel in the row
        for (j = 0; j < width / 2; j++) {
            
            // Loop through each color channel of the pixel
            for (k = 0; k < channels; k++) {
                
                // Swap the current pixel with its corresponding pixel on the opposite side of the row
                temp = image[i * width * channels + j * channels + k];
                image[i * width * channels + j * channels + k] = image[i * width * channels + (width - j - 1) * channels + k];
                image[i * width * channels + (width - j - 1) * channels + k] = temp;
            }
        }
    }
}

// Function to adjust the brightness of an image
void adjustBrightness(unsigned char* image, int width, int height, int channels, int adjustment) {
    int i, j, k;
    int value;
    
    // Loop through each pixel in the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (k = 0; k < channels; k++) {
                
                // Calculate the new pixel value by adding the brightness adjustment to the original pixel value
                value = (int)image[i * width * channels + j * channels + k] + adjustment;
                
                // Make sure the new pixel value is within the valid range of 0-255
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                
                // Set the new pixel value
                image[i * width * channels + j * channels + k] = (unsigned char)value;
            }
        }
    }
}

// Function to adjust the contrast of an image
void adjustContrast(unsigned char* image, int width, int height, int channels, float adjustment) {
    int i, j, k;
    float value;
    unsigned char mid = 128;
    
    // Loop through each pixel in the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (k = 0; k < channels; k++) {
                
                // Calculate the new pixel value by multiplying the contrast adjustment by the distance of the original
                // pixel value from the mid-point value of 128, and then adding the mid-point value
                value = adjustment * ((float)image[i * width * channels + j * channels + k] - mid) + mid;
                
                // Make sure the new pixel value is within the valid range of 0-255
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                
                // Set the new pixel value
                image[i * width * channels + j * channels + k] = (unsigned char)value;
            }
        }
    }
}

int main() {
    const char* filename = "image.ppm";    // Replace this with the name of your input file
    FILE* file = fopen(filename, "rb");    // Open the input file as binary read-only
    int width, height, channels;
    unsigned char* image;
    int brightness = 50;
    float contrast = 1.5;
    
    // Check that the file was successfully opened
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return 1;
    }
    
    // Read the header of the PPM file, which includes the width, height, and number of color channels
    fscanf(file, "P6 %d %d %d ", &width, &height, &channels);
    
    // Allocate memory for the image data
    image = (unsigned char*)malloc(width * height * channels * sizeof(unsigned char));
    
    // Read the image data from the file
    fread(image, sizeof(unsigned char), width * height * channels, file);
    
    // Close the input file
    fclose(file);
    
    // Perform some basic image processing operations
    flipHorizontal(image, width, height, channels);
    adjustBrightness(image, width, height, channels, brightness);
    adjustContrast(image, width, height, channels, contrast);
    
    // Write the processed image data to a new file
    const char* outputFilename = "processed_image.ppm";
    file = fopen(outputFilename, "wb");    // Open the output file as binary write-only
    
    // Write the header of the output file, which is the same as the input file header
    fprintf(file, "P6 %d %d %d\n", width, height, channels);
    
    // Write the image data to the output file
    fwrite(image, sizeof(unsigned char), width * height * channels, file);
    
    // Close the output file
    fclose(file);
    
    // Free the memory used by the image data
    free(image);
    
    return 0;
}