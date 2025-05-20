//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to flip an image
void flipImage(int* image, int width, int height) {
    for(int i = 0; i < height/2; i++) {
        for(int j = 0; j < width; j++) {
            int temp = *(image + i*width + j);
            *(image + i*width + j) = *(image + (height-i-1)*width + j);
            *(image + (height-i-1)*width + j) = temp;
        }
    }
}

// Function to adjust brightness and contrast of an image
void adjustImage(int* image, int width, int height, int brightness, int contrast) {
    float alpha = (float) contrast/50;
    float beta = (float) brightness - (alpha*255/2);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int pixel = *(image + i*width + j);

            // Adjust brightness
            pixel += beta;

            // Adjust contrast
            pixel = alpha*pixel + 255/2*(1-alpha);

            // Ensure pixel value is within 0-255
            pixel = fmaxf(0, fminf(255, pixel));

            *(image + i*width + j) = pixel;
        }
    }
}

int main() {
    int width = 3;
    int height = 3;

    // Create an example image
    int* image = malloc(width * height * sizeof(int));
    *(image) = 255;
    *(image + 1) = 155;
    *(image + 2) = 55;
    *(image + 3) = 205;
    *(image + 4) = 105;
    *(image + 5) = 5;
    *(image + 6) = 100;
    *(image + 7) = 200;
    *(image + 8) = 150;

    // Flip the image
    flipImage(image, width, height);

    // Adjust the image
    adjustImage(image, width, height, 50, 75);

    // Print the modified image
    printf("Modified Image:\n");
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("%d ", *(image + i*width + j));
        }
        printf("\n");
    }

    free(image);

    return 0;
}