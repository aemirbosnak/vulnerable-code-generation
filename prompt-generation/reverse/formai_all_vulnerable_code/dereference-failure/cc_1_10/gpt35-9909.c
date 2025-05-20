//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flipHorizontal(int *image, int width, int height) {
    int *temp = (int*)malloc(width * sizeof(int));
    for(int i=0; i<height; i++) {
        int left = 0;
        int right = width - 1;
        while(left < right) {
            // Swap the pixels
            temp[left] = image[i*width + left];
            image[i*width + left] = image[i*width + right];
            image[i*width + right] = temp[left];
            left++;
            right--;
        }
    }
    free(temp);
}

// Function to change the brightness of an image
void changeBrightness(int *image, int width, int height, int brightness) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            // Shift the pixel value by the brightness amount
            image[i*width + j] += brightness;
            // Clamp the pixel value to [0, 255]
            if(image[i*width + j] < 0) {
                image[i*width + j] = 0;
            }
            else if(image[i*width + j] > 255) {
                image[i*width + j] = 255;
            }
        }
    }
}

// Function to change the contrast of an image
void changeContrast(int *image, int width, int height, float contrast) {
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            // Apply the contrast formula to each pixel
            int pixel = image[i*width + j];
            pixel = (int)(factor * (pixel - 128) + 128);
            // Clamp the pixel value to [0, 255]
            if(pixel < 0) {
                pixel = 0;
            }
            else if(pixel > 255) {
                pixel = 255;
            }
            image[i*width + j] = pixel;
        }
    }
}

// Main function
int main() {
    // Read the image from a file
    FILE *fp = fopen("image.raw", "rb");
    int width = 512;    // Width of the image
    int height = 512;   // Height of the image
    int *image = (int*) malloc(width * height * sizeof(int));
    fread(image, sizeof(int), width*height, fp);
    fclose(fp);

    // Flip the image horizontally
    flipHorizontal(image, width, height);

    // Change the brightness of the image
    int brightness = 50;
    changeBrightness(image, width, height, brightness);

    // Change the contrast of the image
    float contrast = 50.0f;
    changeContrast(image, width, height, contrast);

    // Write the processed image to a file
    fp = fopen("processed_image.raw", "wb");
    fwrite(image, sizeof(int), width*height, fp);
    fclose(fp);

    free(image);
    return 0;
}