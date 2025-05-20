//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: distributed
#include<stdio.h>
#include<stdlib.h>

#define WIDTH 256
#define HEIGHT 256

// Function to flip the input image horizontally
void flip_horizontal(unsigned char** image) {
    int i,j,temp;
    for(i=0;i<HEIGHT;i++) {
        for(j=0;j<WIDTH/2;j++) {
            temp = image[i][j];
            image[i][j] = image[i][WIDTH-j-1];
            image[i][WIDTH-j-1] = temp;
        }
    }
}

// Function to change the brightness of the input image
void change_brightness(unsigned char** image, int val) {
    int i,j;
    for(i=0;i<HEIGHT;i++) {
        for(j=0;j<WIDTH;j++) {
            int new_val = image[i][j] + val;
            if(new_val < 0) new_val = 0;
            if(new_val > 255) new_val = 255;
            image[i][j] = new_val;
        }
    }
}

// Function to change the contrast of the input image
void change_contrast(unsigned char** image, int val) {
    int i,j;
    double factor = (259.0 * (val + 255.0)) / (255.0 * (259.0 - val));
    for(i=0;i<HEIGHT;i++) {
        for(j=0;j<WIDTH;j++) {
            int new_val = (int)(factor * (image[i][j] - 128) + 128);
            if(new_val < 0) new_val = 0;
            if(new_val > 255) new_val = 255;
            image[i][j] = new_val;
        }
    }
}

int main() {
    unsigned char** image = (unsigned char**) malloc(sizeof(unsigned char*) * HEIGHT);
    int i,j;

    // Allocate memory for image array
    for(i=0;i<HEIGHT;i++) {
        image[i] = (unsigned char*) malloc(sizeof(unsigned char) * WIDTH);
    }

    // Read input image from file (Here we have used a constant value of 128 to represent a gray-scale image)
    for(i=0;i<HEIGHT;i++) {
        for(j=0;j<WIDTH;j++) {
            image[i][j] = 128;
        }
    }

    // Flip the image horizontally
    flip_horizontal(image);

    // Change the brightness of the image by adding a constant value
    change_brightness(image, 50);

    // Change the contrast of the image by multiplying each pixel value with a factor
    change_contrast(image, 50);

    // Free the memory allocated for the image array
    for(i=0;i<HEIGHT;i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}