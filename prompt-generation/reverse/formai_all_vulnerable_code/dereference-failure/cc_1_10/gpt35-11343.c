//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complete
#include <stdio.h>

// function prototypes
void flipImage(int width, int height, int originalImage[width][height], int flippedImage[width][height]);
void changeBrightnessContrast(int width, int height, int originalImage[width][height], int modifiedImage[width][height], int brightness, int contrast);

int main() {
    // initialize width and height
    int width = 5;
    int height = 5;
    
    // initialize original image
    int originalImage[5][5] = { {50, 100, 150, 200, 250},
                                {60, 110, 160, 210, 255},
                                {70, 120, 170, 220, 255},
                                {80, 130, 180, 225, 255},
                                {90, 140, 190, 230, 255} };
    
    // declare and initialize flipped and modified images
    int flippedImage[5][5] = {0};
    int modifiedImage[5][5] = {0};
    
    // display original image
    printf("Original Image:\n");
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("%d ", originalImage[j][i]);
        }
        printf("\n");
    }
    
    // flip the original image
    flipImage(width, height, originalImage, flippedImage);
    
    // display flipped image
    printf("\nFlipped Image:\n");
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("%d ", flippedImage[j][i]);
        }
        printf("\n");
    }
    
    // modify the original image brightness and contrast
    changeBrightnessContrast(width, height, originalImage, modifiedImage, 50, 20);
    
    // display modified image
    printf("\nModified Image:\n");
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("%d ", modifiedImage[j][i]);
        }
        printf("\n");
    }
    
    return 0;
}

// function to flip the image
void flipImage(int width, int height, int originalImage[width][height], int flippedImage[width][height]) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            flippedImage[j][i] = originalImage[width-j-1][i];
        }
    }
}

// function to change image brightness and contrast
void changeBrightnessContrast(int width, int height, int originalImage[width][height], int modifiedImage[width][height], int brightness, int contrast) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            modifiedImage[j][i] = (originalImage[j][i] + brightness) * contrast;
            if(modifiedImage[j][i] > 255) modifiedImage[j][i] = 255; // cap values over 255
            if(modifiedImage[j][i] < 0) modifiedImage[j][i] = 0; // cap values below 0
        }
    }
}