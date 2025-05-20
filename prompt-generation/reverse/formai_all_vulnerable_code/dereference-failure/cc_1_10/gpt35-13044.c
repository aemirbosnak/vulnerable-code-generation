//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flip_horizontally(int *image, int width, int height) {
    int i, j;
    int temp;
    for(i=0; i<height; i++) {
        for(j=0; j<width/2; j++) {
            temp = image[i*width+j];
            image[i*width+j] = image[i*width+width-j-1];
            image[i*width+width-j-1] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjust_brightness(int *image, int width, int height, int brightness) {
    int i, j;
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            image[i*width+j] += brightness;
            if(image[i*width+j] < 0) {
                image[i*width+j] = 0;
            } else if(image[i*width+j] > 255) {
                image[i*width+j] = 255;
            }
        }
    }
}

// Function to adjust the contrast of an image
void adjust_contrast(int *image, int width, int height, int contrast) {
    int i, j;
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            int pixel = image[i*width+j];
            pixel = (int)(factor * (pixel - 128) + 128);
            if(pixel < 0) {
                pixel = 0;
            } else if(pixel > 255) {
                pixel = 255;
            }
            image[i*width+j] = pixel;
        }
    }
}

int main() {
    int width = 1280; // image width
    int height = 720; // image height

    // Allocate memory for the image
    int *image = (int*)malloc(width * height * sizeof(int));

    // Read the image from file
    FILE *fp = fopen("input.bmp", "rb");
    // TODO: Add code to read BMP file format
    fclose(fp);

    // Flip the image horizontally
    flip_horizontally(image, width, height);

    // Adjust the brightness and contrast of the image
    adjust_brightness(image, width, height, -50);
    adjust_contrast(image, width, height, 50);

    // Write the output image to file
    fp = fopen("output.bmp", "wb");
    // TODO: Add code to write BMP file format
    fclose(fp);

    // Free the memory allocated for the image
    free(image);

    return 0;
}