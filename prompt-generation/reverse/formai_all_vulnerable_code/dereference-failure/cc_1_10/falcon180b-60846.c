//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 400
#define HEIGHT 300

// Function to flip an image
void flipImage(int **img, int width, int height) {
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width/2; j++) {
            int temp = img[i][j];
            img[i][j] = img[i][width-j-1];
            img[i][width-j-1] = temp;
        }
    }
}

// Function to change brightness/contrast of an image
void changeBrightnessContrast(int **img, int width, int height, float brightness, float contrast) {
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            int value = (int)((float)img[i][j] * contrast + brightness);
            if(value < 0)
                value = 0;
            else if(value > 255)
                value = 255;
            img[i][j] = value;
        }
    }
}

// Function to display an image
void displayImage(int **img, int width, int height) {
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **img;
    int width = WIDTH, height = HEIGHT;
    img = (int **)malloc(height * sizeof(int *));
    for(int i = 0; i < height; i++) {
        img[i] = (int *)malloc(width * sizeof(int));
    }

    // Initialize the image with some values
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            img[i][j] = i*width + j;
        }
    }

    // Display the original image
    printf("Original Image:\n");
    displayImage(img, width, height);

    // Flip the image
    flipImage(img, width, height);
    printf("\nFlipped Image:\n");
    displayImage(img, width, height);

    // Change brightness and contrast of the image
    changeBrightnessContrast(img, width, height, 1.5, 2.0);
    printf("\nChanged Image:\n");
    displayImage(img, width, height);

    for(int i = 0; i < height; i++) {
        free(img[i]);
    }
    free(img);

    return 0;
}