//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: innovative
#include <stdio.h>

// define image size
#define ROWS 5
#define COLS 5

// function to flip image
int** flipImage(int** image, int rows, int cols) {
    int** flippedImage = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        flippedImage[i] = (int*)malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++) {
            flippedImage[i][j] = image[i][cols - j - 1];
        }
    }
    return flippedImage;
}

// function to adjust brightness and contrast
int** adjustBrightnessContrast(int** image, int rows, int cols, int brightness, int contrast) {
    int** adjustedImage = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        adjustedImage[i] = (int*)malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++) {
            adjustedImage[i][j] = contrast * (image[i][j] - 128) + 128 + brightness;
        }
    }
    return adjustedImage;
}

int main() {
    // initialize image
    int image[ROWS][COLS] = {
        {255, 255, 255, 255, 255},
        {255, 255, 255, 255, 255},
        {255, 255, 255, 255, 255},
        {255, 255, 255, 255, 255},
        {255, 255, 255, 255, 255}
    };
    
    // flip image horizontally
    int** flippedImage = flipImage((int**)image, ROWS, COLS);
    
    // adjust brightness and contrast
    int** adjustedImage = adjustBrightnessContrast(flippedImage, ROWS, COLS, 50, 2);
    
    // print original image
    printf("Original Image:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%3d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // print flipped image
    printf("Flipped Image:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%3d ", flippedImage[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // print adjusted image
    printf("Adjusted Image:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%3d ", adjustedImage[i][j]);
        }
        printf("\n");
    }
    
    // free memory
    for(int i = 0; i < ROWS; i++) {
        free(flippedImage[i]);
        free(adjustedImage[i]);
    }
    free(flippedImage);
    free(adjustedImage);

    return 0;
}