//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to flip an image horizontally
void flipImageHorizontally(int** image, int width, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjustBrightness(int** image, int width, int height, int brightness) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int newColor = image[i][j] + brightness;
            if(newColor < 0) {
                newColor = 0;
            }
            if(newColor > 255) {
                newColor = 255;
            }
            image[i][j] = newColor;
        }
    }
}

// Function to adjust the contrast of an image
void adjustContrast(int** image, int width, int height, float contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int newColor = factor * (image[i][j] - 128) + 128;
            if(newColor < 0) {
                newColor = 0;
            }
            if(newColor > 255) {
                newColor = 255;
            }
            image[i][j] = newColor;
        }
    }
}

int main() {
    // Create a sample image with 5x4 pixels
    int width = 5;
    int height = 4;
    int** image = (int**) malloc(height * sizeof(int*));
    for(int i=0; i<height; i++) {
        image[i] = (int*) malloc(width * sizeof(int));
        for(int j=0; j<width; j++) {
            image[i][j] = rand() % 256;
        }
    }

    // Flip the image horizontally
    flipImageHorizontally(image, width, height);

    // Adjust the brightness of the image
    adjustBrightness(image, width, height, 50);

    // Adjust the contrast of the image
    adjustContrast(image, width, height, 50.0);

    // Print the modified image
    printf("Modified Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the image
    for(int i=0; i<height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}