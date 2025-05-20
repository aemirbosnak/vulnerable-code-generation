//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image
void flip(char* imgIn, char* imgOut, int width, int height) {

    // Open the image files for reading and writing
    FILE* in = fopen(imgIn, "rb");
    FILE* out = fopen(imgOut, "wb");
    
    // Calculate the size of the image
    int size = width * height;
    
    // Allocate memory for the image data
    unsigned char* imgData = (unsigned char*) malloc(size * 3);
    
    // Read the image data from the input file
    fread(imgData, sizeof(unsigned char), size * 3, in);
    
    // Loop through each row of the image data
    for (int y = 0; y < height; y++) {
        
        // Loop through each column of the image data
        for (int x = 0; x < width; x++) {
            
            // Calculate the index of the current pixel
            int index = (y * width + x) * 3;
            
            // Swap the red, green, and blue components of the current pixel
            unsigned char tmp = imgData[index];
            imgData[index] = imgData[index + 2];
            imgData[index + 2] = tmp;
        }
    }
    
    // Write the flipped image data to the output file
    fwrite(imgData, sizeof(unsigned char), size * 3, out);
    
    // Close the image files and free the memory
    fclose(in);
    fclose(out);
    free(imgData);
}

// Function to change the brightness and contrast of an image
void adjust(char* imgIn, char* imgOut, int width, int height, int brightness, int contrast) {

    // Open the image files for reading and writing
    FILE* in = fopen(imgIn, "rb");
    FILE* out = fopen(imgOut, "wb");
    
    // Calculate the size of the image
    int size = width * height;
    
    // Allocate memory for the image data
    unsigned char* imgData = (unsigned char*) malloc(size * 3);
    
    // Read the image data from the input file
    fread(imgData, sizeof(unsigned char), size * 3, in);
    
    // Loop through each pixel of the image data
    for (int i = 0; i < size * 3; i++) {
        
        // Calculate the new value of the current pixel
        int newVal = ((int) imgData[i]) * contrast / 100 + brightness;
        
        // Clamp the new value to the range [0, 255]
        if (newVal < 0) newVal = 0;
        if (newVal > 255) newVal = 255;
        
        // Update the image data with the new pixel value
        imgData[i] = (unsigned char) newVal;
    }
    
    // Write the adjusted image data to the output file
    fwrite(imgData, sizeof(unsigned char), size * 3, out);
    
    // Close the image files and free the memory
    fclose(in);
    fclose(out);
    free(imgData);
}

int main() {

    // Call the flip function to flip the image
    flip("input.jpg", "output.jpg", 800, 600);
    
    // Call the adjust function to change the brightness and contrast of the image
    adjust("input.jpg", "output.jpg", 800, 600, -50, 150);
    
    return 0;
}