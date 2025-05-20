//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to flip the image horizontally
void flip_horizontal(int rows, int cols, int image[rows][cols]) {
    int temp;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
}

// Function to adjust the brightness and contrast of the image
void adjust_brightness_contrast(int rows, int cols, int image[rows][cols], double brightness, double contrast) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            // Adjust brightness
            image[i][j] = (int)(image[i][j] * brightness);

            // Adjust contrast
            image[i][j] = (int)(((image[i][j] / 255.0 - 0.5) * contrast + 0.5) * 255.0);

            // Clamp pixel values to 0-255 range
            if(image[i][j] < 0) image[i][j] = 0;
            if(image[i][j] > 255) image[i][j] = 255;
        }
    }
}

int main() {
    // Initialize image array
    int rows = 5, cols = 5;
    int image[5][5] = {{255, 255, 255, 0, 0},
                      {255, 255, 255, 0, 0},
                      {255, 255, 255, 0, 0},
                      {0, 0, 0, 255, 255},
                      {0, 0, 0, 255, 255}};

    // Print original image
    printf("Original Image:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Flip image horizontally
    flip_horizontal(rows, cols, image);

    // Print flipped image
    printf("\nFlipped Image:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Adjust brightness and contrast of image
    double brightness = 1.5, contrast = 2.0;
    adjust_brightness_contrast(rows, cols, image, brightness, contrast);

    // Print adjusted image
    printf("\nAdjusted Image:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}