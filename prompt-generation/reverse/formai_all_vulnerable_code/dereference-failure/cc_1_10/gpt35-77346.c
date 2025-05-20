//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: innovative
#include <stdio.h>

// Function to flip the image horizontally
void flipImageHorizontal(int width, int height, int image[height][width]) {
    int temp;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

// Function to change the brightness of the image
void changeBrightness(int width, int height, int image[height][width], int brightnessValue) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            image[i][j] += brightnessValue;
            if(image[i][j] < 0) {
                image[i][j] = 0;
            }
            else if(image[i][j] > 255) {
                image[i][j] = 255;
            }
        }
    }
}

// Function to change the contrast of the image
void changeContrast(int width, int height, int image[height][width], float contrastValue) {
    float factor = (259.0 * (contrastValue + 255.0)) / (255.0 * (259.0 - contrastValue));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            image[i][j] = factor * (image[i][j] - 128) + 128;
            if(image[i][j] < 0) {
                image[i][j] = 0;
            }
            else if(image[i][j] > 255) {
                image[i][j] = 255;
            }
        }
    }
}

int main() {
    int width = 4;
    int height = 3;
    int image[3][4] = {{10, 20, 30, 40},
                       {50, 60, 70, 80},
                       {90, 100, 110, 120}};

    // Flipping the image horizontally
    printf("Original Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    flipImageHorizontal(width, height, image); // Applying horizontal flip
    printf("\nFlipped Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Changing the brightness of the image
    printf("\nOriginal Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    changeBrightness(width, height, image, 50); // Increasing brightness by 50
    printf("\nBrightened Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Changing the contrast of the image
    printf("\nOriginal Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    changeContrast(width, height, image, 30.0); // Increasing contrast by 30%
    printf("\nHigh Contrast Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}