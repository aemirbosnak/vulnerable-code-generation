//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image
void flipImage(int height, int width, int image[height][width]) {
    int temp;
    for(int i=0; i<height/2; i++) {
        for(int j=0; j<width; j++) {
            // Swap pixels from top and bottom
            temp = image[i][j];
            image[i][j] = image[height-i-1][j];
            image[height-i-1][j] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjustBrightness(int height, int width, int image[height][width], int brightness) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            // Add brightness to each pixel value
            image[i][j] += brightness;
            if(image[i][j] > 255) {
                image[i][j] = 255;
            }
            else if(image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

// Function to adjust the contrast of an image
void adjustContrast(int height, int width, int image[height][width], float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            // Multiply pixel value by contrast factor
            image[i][j] = factor * (image[i][j] - 128) + 128;
            if(image[i][j] > 255) {
                image[i][j] = 255;
            }
            else if(image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

int main() {
    // Example image
    int height = 3;
    int width = 3;
    int image[3][3] = {
        {0, 50, 100},
        {150, 200, 250},
        {255, 128, 64}
    };
    
    // Print original image
    printf("Original image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Flip image and print result
    flipImage(height, width, image);
    printf("Flipped image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Adjust brightness and print result
    adjustBrightness(height, width, image, 50);
    printf("Brightness adjusted image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Adjust contrast and print result
    adjustContrast(height, width, image, 100);
    printf("Contrast adjusted image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}