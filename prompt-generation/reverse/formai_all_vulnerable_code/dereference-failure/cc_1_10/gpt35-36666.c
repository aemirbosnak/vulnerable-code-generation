//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to flip the image horizontally
void flipHorizontal(int rows, int cols, int image[][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][cols-1-j];
            image[i][cols-1-j] = temp;
        }
    }
}

// Function to adjust the brightness of the image
void adjustBrightness(int rows, int cols, int image[][cols], int brightness) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int newPixel = image[i][j] + brightness;
            if(newPixel > 255) {    // Maximum brightness is 255
                newPixel = 255;
            } else if(newPixel < 0) {   // Minimum brightness is 0
                newPixel = 0;
            }
            image[i][j] = newPixel;
        }
    }
}

// Function to adjust the contrast of the image
void adjustContrast(int rows, int cols, int image[][cols], int contrast) {
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int newPixel = factor * (image[i][j] - 128) + 128;
            if(newPixel > 255) {    // Maximum brightness is 255
                newPixel = 255;
            } else if(newPixel < 0) {   // Minimum brightness is 0
                newPixel = 0;
            }
            image[i][j] = newPixel;
        }
    }
}

// Function to print the image
void printImage(int rows, int cols, int image[][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%4d", image[i][j]);
        }
        printf("\n");
     }
}

int main() {
    int rows = 3;
    int cols = 3;
    int image[3][3] = {{10, 20, 30},
                       {40, 50, 60},
                       {70, 80, 90}};
    int brightness = 30;
    int contrast = -50;
    
    printf("Original Image:\n");
    printImage(rows, cols, image);
    
    flipHorizontal(rows, cols, image);
    
    printf("\nImage after flipping horizontally:\n");
    printImage(rows, cols, image);
    
    adjustBrightness(rows, cols, image, brightness);
    
    printf("\nImage after adjusting brightness by %d:\n", brightness);
    printImage(rows, cols, image);
    
    adjustContrast(rows, cols, image, contrast);
    
    printf("\nImage after adjusting contrast by %d:\n", contrast);
    printImage(rows, cols, image);
    
    return 0;
}