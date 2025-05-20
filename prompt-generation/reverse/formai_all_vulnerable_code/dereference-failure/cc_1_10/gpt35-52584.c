//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

void flip_image(int **image, int width, int height){
    int i,j;

    // Flip each row
    for(i=0; i<height; i++){
        for(j=0; j<width/2; j++){
            // Swap pixels
            int temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

void adjust_brightness(int **image, int width, int height, int amount){
    int i,j;

    // Adjust each pixel according to amount
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            image[i][j] += amount;
            // Make sure pixel value is within 0-255 range
            if(image[i][j] < 0) image[i][j] = 0;
            if(image[i][j] > 255) image[i][j] = 255;
        }
    }
}

void adjust_contrast(int **image, int width, int height, float amount){
    int i,j;

    float factor = (259 * (amount + 255)) / (255 * (259 - amount));

    // Adjust each pixel according to amount
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            image[i][j] = factor * (image[i][j] - 128) + 128;
            // Make sure pixel value is within 0-255 range
            if(image[i][j] < 0) image[i][j] = 0;
            if(image[i][j] > 255) image[i][j] = 255;
        }
    }
}

int main(){
    int width = 4;
    int height = 3;
    int i,j;

    // Allocate memory for image
    int **image = (int **)malloc(sizeof(int *) * height);
    for(i=0; i<height; i++){
        image[i] = (int *)malloc(sizeof(int) * width);
    }

    // Initialize pixels
    image[0][0] = 100;
    image[0][1] = 150;
    image[0][2] = 200;
    image[0][3] = 150;
    image[1][0] = 150;
    image[1][1] = 200;
    image[1][2] = 250;
    image[1][3] = 200;
    image[2][0] = 200;
    image[2][1] = 250;
    image[2][2] = 300;
    image[2][3] = 250;

    // Print original image
    printf("Original Image:\n");
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Flip image
    flip_image(image, width, height);

    // Print flipped image
    printf("\nFlipped Image:\n");
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Adjust brightness by 50
    adjust_brightness(image, width, height, 50);

    // Print image with adjusted brightness
    printf("\nBrightness Adjusted (+50):\n");
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Adjust contrast by 50%
    adjust_contrast(image, width, height, 50);

    // Print image with adjusted contrast
    printf("\nContrast Adjusted (+50%):\n");
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Free memory for image
    for(i=0; i<height; i++){
        free(image[i]);
    }
    free(image);

    return 0;
}