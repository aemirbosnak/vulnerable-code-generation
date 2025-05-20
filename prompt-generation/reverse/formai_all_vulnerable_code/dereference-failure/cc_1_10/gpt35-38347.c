//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PIXEL_SIZE 3 // RGB image

void flip_image(uint8_t *image, int width, int height) {
    uint8_t *temp_image = malloc(width * height * PIXEL_SIZE * sizeof(uint8_t)); // allocate temporary image
    
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp_image[((height - 1 - i) * width + j) * PIXEL_SIZE] = image[(i * width + j) * PIXEL_SIZE];
            temp_image[((height - 1 - i) * width + j) * PIXEL_SIZE + 1] = image[(i * width + j) * PIXEL_SIZE + 1];
            temp_image[((height - 1 - i) * width + j) * PIXEL_SIZE + 2] = image[(i * width + j) * PIXEL_SIZE + 2];
        }
    }
    
    // copy flipped image back to original image
    for (i = 0; i < width * height * PIXEL_SIZE; i++) {
        image[i] = temp_image[i];
    }
    
    free(temp_image); // free temporary image
}

void adjust_brightness_contrast(uint8_t *image, int width, int height, int brightness, int contrast) {
    int i, j;
    float avg_luminance = 0;
    
    // calculate average luminance of the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            float luminance = image[(i * width + j) * PIXEL_SIZE] * 0.299 
                            + image[(i * width + j) * PIXEL_SIZE + 1] * 0.587 
                            + image[(i * width + j) * PIXEL_SIZE + 2] * 0.114;
            avg_luminance += luminance;
        }
    }
    avg_luminance /= (width * height);
    
    // adjust brightness and contrast of the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            float luminance = image[(i * width + j) * PIXEL_SIZE] * 0.299 
                            + image[(i * width + j) * PIXEL_SIZE + 1] * 0.587 
                            + image[(i * width + j) * PIXEL_SIZE + 2] * 0.114;
            float delta_luminance = luminance - avg_luminance;
            int new_luminance = (int)(brightness + (contrast * delta_luminance));
            if (new_luminance < 0) {
                new_luminance = 0;
            }
            else if (new_luminance > 255) {
                new_luminance = 255;
            }
            image[(i * width + j) * PIXEL_SIZE] = new_luminance;
            image[(i * width + j) * PIXEL_SIZE + 1] = new_luminance;
            image[(i * width + j) * PIXEL_SIZE + 2] = new_luminance;
        }
    }
}

int main() {
    int width = 640;
    int height = 480;
    uint8_t *image = malloc(width * height * PIXEL_SIZE * sizeof(uint8_t)); // allocate image memory
    
    // assume image data is read from file or captured from camera
    
    flip_image(image, width, height);
    adjust_brightness_contrast(image, width, height, 50, 1.5);
    
    // assume image data is saved to file or displayed on screen
    
    free(image); // free image memory
    
    return 0;
}