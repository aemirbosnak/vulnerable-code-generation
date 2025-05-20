//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Flip a given image in the horizontal direction
void flip_horizontal(int **image, int rows, int cols) {
    int temp;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
}

// Adjust the brightness of a given image
void adjust_brightness(int **image, int rows, int cols, int brightness) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            image[i][j] += brightness;
            if (image[i][j] > 255) {
                image[i][j] = 255;
            } else if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

// Adjust the contrast of a given image
void adjust_contrast(int **image, int rows, int cols, float contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            image[i][j] = (int) (factor * (image[i][j] - 128) + 128);
            if (image[i][j] > 255) {
                image[i][j] = 255;
            } else if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

// Main function to test the image processing functions
int main() {
    int rows = 3;
    int cols = 3;
    int **image = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        image[i] = malloc(cols * sizeof(int));
    }

    // Initialize the image with some values
    image[0][0] = 100;
    image[0][1] = 200;
    image[0][2] = 50;
    image[1][0] = 150;
    image[1][1] = 100;
    image[1][2] = 200;
    image[2][0] = 50;
    image[2][1] = 250;
    image[2][2] = 150;

    // Print the original image
    printf("Original image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Flip the image horizontally
    flip_horizontal(image, rows, cols);

    // Print the flipped image
    printf("Flipped image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Adjust the brightness of the image
    adjust_brightness(image, rows, cols, 50);

    // Print the brightness adjusted image
    printf("Brightness adjusted image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Adjust the contrast of the image
    adjust_contrast(image, rows, cols, 50.0);

    // Print the contrast adjusted image
    printf("Contrast adjusted image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Free the memory allocated for the image
    for (int i = 0; i < rows; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}