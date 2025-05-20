//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image
void flip_image(int rows, int cols, int image[rows][cols]) {
    // Create a temporary array to store the flipped image
    int temp[rows][cols];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            // Copy the pixel at (i,j) to (j,i) in the temporary array
            temp[j][i] = image[i][j];
        }
    }

    // Copy the flipped image from the temporary array to the original array
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            image[i][j] = temp[i][j];
        }
    }
}

// Function to adjust the brightness of an image
void adjust_brightness(int rows, int cols, int image[rows][cols], int brightness) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            // Add the brightness value to the pixel at (i,j)
            image[i][j] += brightness;

            // Make sure the pixel value is within the range 0-255
            if(image[i][j] < 0) {
                image[i][j] = 0;
            } else if(image[i][j] > 255) {
                image[i][j] = 255;
            }
        }
    }
}

// Function to adjust the contrast of an image
void adjust_contrast(int rows, int cols, int image[rows][cols], int contrast) {
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            // Apply the contrast function to the pixel at (i,j)
            image[i][j] = (int)(factor * (image[i][j] - 128) + 128);

            // Make sure the pixel value is within the range 0-255
            if(image[i][j] < 0) {
                image[i][j] = 0;
            } else if(image[i][j] > 255) {
                image[i][j] = 255;
            }
        }
    }
}

int main() {
    int rows = 5;
    int cols = 5;
    int image[5][5] = {{100, 150, 200, 150, 100},
                       {100, 150, 200, 150, 100},
                       {100, 150, 200, 150, 100},
                       {100, 150, 200, 150, 100},
                       {100, 150, 200, 150, 100}};

    // Flip the image horizontally
    flip_image(rows, cols, image);

    // Adjust the brightness by adding 50 to each pixel
    adjust_brightness(rows, cols, image, 50);

    // Adjust the contrast by multiplying each pixel by 2
    adjust_contrast(rows, cols, image, 100);

    // Print the resulting image
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}