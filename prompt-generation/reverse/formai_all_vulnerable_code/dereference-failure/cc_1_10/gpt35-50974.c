//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image
void flipImage(int *image, int width, int height) {
    int temp, i, j;

    // Flip horizontally
    for(i=0; i<height; i++) {
        for(j=0; j<width/2; j++) {
            temp = *(image + i*width + j);
            *(image + i*width + j) = *(image + i*width + (width-1-j));
            *(image + i*width + (width-1-j)) = temp;
        }
    }

    // Flip vertically
    for(j=0; j<width; j++) {
        for(i=0; i<height/2; i++) {
            temp = *(image + i*width + j);
            *(image + i*width + j) = *(image + (height-1-i)*width + j);
            *(image + (height-1-i)*width + j) = temp;
        }
    }
}

// Function to change brightness and contrast of an image
void changeBrightnessContrast(int *image, int width, int height, int brightness, int contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for(int i=0; i<width*height; i++) {
        int pixel = *(image + i);
        pixel = factor * (pixel - 128) + 128 + brightness;
        *(image + i) = (pixel < 0) ? 0 : (pixel > 255) ? 255 : pixel;
    }
}

int main() {
    int width = 4, height = 4;
    int brightness = 50, contrast = 50;

    // Allocate memory for image
    int *image = (int*) malloc(sizeof(int) * width * height);

    // Initialize image
    int count = 0;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            *(image + i*width + j) = count++;
        }
    }

    // Print original image
    printf("Original Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", *(image + i*width + j));
        }
        printf("\n");
    }

    // Flip image
    flipImage(image, width, height);

    // Print flipped image
    printf("\nFlipped Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", *(image + i*width + j));
        }
        printf("\n");
    }

    // Change brightness and contrast of image
    changeBrightnessContrast(image, width, height, brightness, contrast);

    // Print modified image
    printf("\nModified Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", *(image + i*width + j));
        }
        printf("\n");
    }

    // Free memory
    free(image);

    return 0;
}