//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL 255
#define MIN_PIXEL 0

void flip_image(int **image, int rows, int cols) {
    int **temp = (int**)malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++)
        temp[i] = (int*)malloc(cols * sizeof(int));

    // flip the image by copying columns to temporary array
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            temp[i][j] = image[i][cols-j-1];
        }
    }

    // copy temporary array back to original
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            image[i][j] = temp[i][j];
        }
    }

    // free the temporary memory
    for(int i=0; i<rows; i++)
        free(temp[i]);
    free(temp);
}

void adjust_brightness(int **image, int rows, int cols, int brightness) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int pixel = image[i][j] + brightness;
            if(pixel > MAX_PIXEL) pixel = MAX_PIXEL;
            else if(pixel < MIN_PIXEL) pixel = MIN_PIXEL;
            image[i][j] = pixel;
        }
    }
}

void adjust_contrast(int **image, int rows, int cols, float contrast) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            float pixel = image[i][j];
            pixel = (pixel - MIN_PIXEL) * contrast;
            pixel += MIN_PIXEL;
            if(pixel > MAX_PIXEL) pixel = MAX_PIXEL;
            else if(pixel < MIN_PIXEL) pixel = MIN_PIXEL;
            image[i][j] = (int)pixel;
        }
    }
}

void print_image(int **image, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 5;
    int cols = 5;
    int **image = (int**)malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++)
        image[i] = (int*)malloc(cols * sizeof(int));

    // initialize the image
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            image[i][j] = i*10 + j;
        }
    }

    // flip the image horizontally
    flip_image(image, rows, cols);
    printf("Flipped Image:\n");
    print_image(image, rows, cols);

    // increase brightness by 50
    adjust_brightness(image, rows, cols, 50);
    printf("Brightened Image:\n");
    print_image(image, rows, cols);

    // decrease contrast by 50%
    adjust_contrast(image, rows, cols, 0.5);
    printf("Adjusted Contrast Image:\n");
    print_image(image, rows, cols);

    // free the memory
    for(int i=0; i<rows; i++)
        free(image[i]);
    free(image);

    return 0;
}