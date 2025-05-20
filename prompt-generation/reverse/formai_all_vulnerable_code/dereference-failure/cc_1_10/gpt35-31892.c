//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to flip an image horizontally
void flip_horizontal(uint8_t* image, int width, int height)
{
    uint8_t* row = (uint8_t*)malloc(width);    // Allocate memory for a row
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            // Swap pixels on either side of image center
            uint8_t temp = image[y * width + x];
            image[y * width + x] = image[y * width + (width - x - 1)];
            image[y * width + (width - x - 1)] = temp;
        }
    }
    
    free(row);    // Free allocated memory
}

// Function to adjust the brightness of an image
void brightness_adjustment(uint8_t* image, int width, int height, int brightness)
{
    for (int i = 0; i < width * height; i++) {
        int pixel_value = image[i] + brightness;
        
        // Check that the pixel value is within valid range (0-255)
        if (pixel_value < 0) {
            pixel_value = 0;
        } else if (pixel_value > 255) {
            pixel_value = 255;
        }
        
        image[i] = pixel_value;
    }
}

// Function to adjust the contrast of an image
void contrast_adjustment(uint8_t* image, int width, int height, float contrast)
{
    for (int i = 0; i < width * height; i++) {
        int pixel_value = (int)((contrast * (float)(image[i] - 128)) + 128);
        
        // Check that the pixel value is within valid range (0-255)
        if (pixel_value < 0) {
            pixel_value = 0;
        } else if (pixel_value > 255) {
            pixel_value = 255;
        }
        
        image[i] = pixel_value;
    }
}

int main()
{
    // Read image data (in grayscale)
    FILE* file = fopen("image.bin", "rb");
    int width = 512;
    int height = 512;
    uint8_t* image = (uint8_t*)malloc(width * height);
    fread(&image[0], 1, width * height, file);
    fclose(file);
    
    // Flip image horizontally
    flip_horizontal(image, width, height);
    
    // Adjust brightness
    int brightness = -50;
    brightness_adjustment(image, width, height, brightness);
    
    // Adjust contrast
    float contrast = 1.5;
    contrast_adjustment(image, width, height, contrast);
    
    // Save processed image data
    file = fopen("processed_image.bin", "wb");
    fwrite(&image[0], 1, width * height, file);
    fclose(file);
    
    // Free allocated memory
    free(image);
    
    return 0;
}