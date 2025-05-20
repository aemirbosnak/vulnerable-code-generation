//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

//define constants for maximum and minimum brightness/contrast values
#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS -255
#define MAX_CONTRAST 100
#define MIN_CONTRAST -100

//function to flip image horizontally
void flipHorizontal(int rows, int cols, int image[][cols]) {
    int temp;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
}

//function to flip image vertically
void flipVertical(int rows, int cols, int image[][cols]) {
    int temp;
    for(int i=0; i<rows/2; i++) {
        for(int j=0; j<cols; j++) {
            temp = image[i][j];
            image[i][j] = image[rows-i-1][j];
            image[rows-i-1][j] = temp;
        }
    }
}

//function to change brightness of image
void changeBrightness(int rows, int cols, int image[][cols], int amount) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int newBrightness = image[i][j] + amount;
            if(newBrightness > MAX_BRIGHTNESS) {
                image[i][j] = MAX_BRIGHTNESS;
            } else if(newBrightness < MIN_BRIGHTNESS) {
                image[i][j] = MIN_BRIGHTNESS;
            } else {
                image[i][j] = newBrightness;
            }
        }
    }
}

//function to change contrast of image
void changeContrast(int rows, int cols, int image[][cols], int amount) {
    double factor = (259.0 * (amount + 255.0)) / (255.0 * (259.0 - amount));
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int newBrightness = factor * (image[i][j] - 128) + 128;
            if(newBrightness > MAX_BRIGHTNESS) {
                image[i][j] = MAX_BRIGHTNESS;
            } else if(newBrightness < MIN_BRIGHTNESS) {
                image[i][j] = MIN_BRIGHTNESS;
            } else {
                image[i][j] = newBrightness;
            }
        }
    }
}

//function to print image
void printImage(int rows, int cols, int image[][cols]) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    //example image
    int image[4][4] = {
        {255, 100, 150, 200},
        {50, 75, 125, 225},
        {0, 25, 175, 230},
        {100, 150, 200, 255}
    };

    printf("Original image:\n");
    printImage(4, 4, image);

    printf("\nFlipped horizontally:\n");
    flipHorizontal(4, 4, image);
    printImage(4, 4, image);

    printf("\nFlipped vertically:\n");
    flipVertical(4, 4, image);
    printImage(4, 4, image);

    printf("\nBrightness increased by 50:\n");
    changeBrightness(4, 4, image, 50);
    printImage(4, 4, image);

    printf("\nBrightness decreased by 100:\n");
    changeBrightness(4, 4, image, -100);
    printImage(4, 4, image);

    printf("\nContrast increased by 50:\n");
    changeContrast(4, 4, image, 50);
    printImage(4, 4, image);

    printf("\nContrast decreased by 100:\n");
    changeContrast(4, 4, image, -100);
    printImage(4, 4, image);

    return 0;
}