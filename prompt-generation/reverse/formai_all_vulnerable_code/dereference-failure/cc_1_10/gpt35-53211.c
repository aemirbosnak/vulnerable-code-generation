//FormAI DATASET v1.0 Category: Image compression ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// function to compress image using mathematical formulae
void compress_image(int** image, int rows, int cols) {
    // calculate average pixel value of the image
    int sum = 0;
    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++) {
            sum += image[i][j];
        }
    }
    int avg_pixel = sum/(rows*cols);

    // apply compression formula to each pixel
    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++) {
            int compressed_pixel = (image[i][j] - avg_pixel) / 2;
            image[i][j] = compressed_pixel;
        }
    }
}

int main() {
    // create a sample image
    int rows = 3;
    int cols = 3;
    int** image = (int**) malloc(rows*sizeof(int*));
    for(int i = 0; i<rows; i++) {
        image[i] = (int*) malloc(cols*sizeof(int));
        for(int j = 0; j<cols; j++) {
            image[i][j] = i+j;  // initialize each pixel with different value
        }
    }

    // print original image
    printf("Original Image:\n");
    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // compress image
    compress_image(image, rows, cols);

    // print compressed image
    printf("Compressed Image:\n");
    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}