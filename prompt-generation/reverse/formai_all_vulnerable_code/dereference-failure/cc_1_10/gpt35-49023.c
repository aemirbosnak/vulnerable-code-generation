//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

// Function for flipping an image
void flipImage(Image* original, Image* result) {
    for (int row = 0; row < original->height; row++) {
        for (int col = 0; col < original->width; col++) {
            // Get the origin pixel and its corresponding result pixel
            int originalPixel = (row * original->width + col) * 3;
            int resultPixel = ((original->height - row - 1) * original->width + col) * 3;

            // Copy the pixel values from the original to the result image
            result->data[resultPixel] = original->data[originalPixel];
            result->data[resultPixel + 1] = original->data[originalPixel + 1];
            result->data[resultPixel + 2] = original->data[originalPixel + 2];
        }
    }
}

// Function for changing brightness and contrast
void adjustImage(Image* original, Image* result, float brightness, float contrast) {
    for (int row = 0; row < original->height; row++) {
        for (int col = 0; col < original->width; col++) {
            // Get the original pixel and its corresponding result pixel
            int originalPixel = (row * original->width + col) * 3;
            int resultPixel = (row * original->width + col) * 3;

            // Calculate the new pixel values
            float red = (original->data[originalPixel] - 128) * contrast + 128 + brightness;
            float green = (original->data[originalPixel + 1] - 128) * contrast + 128 + brightness;
            float blue = (original->data[originalPixel + 2] - 128) * contrast + 128 + brightness;

            // Round the new pixel values to the nearest integer
            red = (int)(red + 0.5);
            green = (int)(green + 0.5);
            blue = (int)(blue + 0.5);

            // Clamp the pixel values to the range 0-255
            red = red < 0 ? 0 : red > 255 ? 255 : red;
            green = green < 0 ? 0 : green > 255 ? 255 : green;
            blue = blue < 0 ? 0 : blue > 255 ? 255 : blue;

            // Assign the new pixel values to the result image
            result->data[resultPixel] = (unsigned char)red;
            result->data[resultPixel + 1] = (unsigned char)green;
            result->data[resultPixel + 2] = (unsigned char)blue;
        }
    }
}

int main() {
    // Load the image
    FILE* file = fopen("image.bin", "rb");
    Image original = { 0 };
    original.width = 640;
    original.height = 480;
    original.data = (unsigned char*)malloc(original.width * original.height * 3);
    fread(original.data, 1, original.width * original.height * 3, file);
    fclose(file);

    // Flip the image
    Image flipped = { 0 };
    flipped.width = original.width;
    flipped.height = original.height;
    flipped.data = (unsigned char*)malloc(flipped.width * flipped.height * 3);
    flipImage(&original, &flipped);

    // Adjust the brightness and contrast of the image
    Image adjusted = { 0 };
    adjusted.width = original.width;
    adjusted.height = original.height;
    adjusted.data = (unsigned char*)malloc(adjusted.width * adjusted.height * 3);
    adjustImage(&original, &adjusted, 50, 1.5);

    // Save the images
    file = fopen("flipped.bin", "wb");
    fwrite(flipped.data, 1, flipped.width * flipped.height * 3, file);
    fclose(file);

    file = fopen("adjusted.bin", "wb");
    fwrite(adjusted.data, 1, adjusted.width * adjusted.height * 3, file);
    fclose(file);

    // Free the memory used by the images
    free(original.data);
    free(flipped.data);
    free(adjusted.data);

    return 0;
}