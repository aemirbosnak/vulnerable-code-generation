//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Function prototypes
void flip_image(int height, int width, int **image);
void change_brightness(int height, int width, int **image, int delta);
void change_contrast(int height, int width, int **image, int delta);

int main() {
    int height, width, delta;

    // Read image dimensions and delta values from user input
    printf("Enter image height: ");
    scanf("%d", &height);
    printf("Enter image width: ");
    scanf("%d", &width);
    printf("Enter delta for brightness/contrast: ");
    scanf("%d", &delta);

    // Allocate memory for the image
    int **image = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        image[i] = (int *)malloc(width * sizeof(int));
    }

    // Read image data from user input
    printf("Enter image data:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    // Flip the image
    flip_image(height, width, image);

    // Change brightness and contrast
    change_brightness(height, width, image, delta);
    change_contrast(height, width, image, delta);

    // Print the modified image
    printf("Modified image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}

void flip_image(int height, int width, int **image) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

void change_brightness(int height, int width, int **image, int delta) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int value = image[i][j] + delta;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image[i][j] = value;
        }
    }
}

void change_contrast(int height, int width, int **image, int delta) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int value = image[i][j] + delta;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image[i][j] = value;
        }
    }
}