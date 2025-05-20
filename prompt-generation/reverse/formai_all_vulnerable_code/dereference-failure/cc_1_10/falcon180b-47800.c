//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

// Function to flip an image
void flip(int **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][width-1-j];
            image[i][width-1-j] = temp;
        }
    }
}

// Function to change brightness/contrast of an image
void adjust_brightness_contrast(int **image, int width, int height, float brightness, float contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = image[i][j];
            int new_pixel = (int) (pixel * brightness * contrast);
            if (new_pixel > 255) {
                new_pixel = 255;
            } else if (new_pixel < 0) {
                new_pixel = 0;
            }
            image[i][j] = new_pixel;
        }
    }
}

int main() {
    // Initialize image with random values
    int **image = (int **) malloc(sizeof(int *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        image[i] = (int *) malloc(sizeof(int) * WIDTH);
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = rand() % 256;
        }
    }

    // Flip image
    flip(image, WIDTH, HEIGHT);

    // Change brightness/contrast
    adjust_brightness_contrast(image, WIDTH, HEIGHT, 1.5, 1.2);

    // Print image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}