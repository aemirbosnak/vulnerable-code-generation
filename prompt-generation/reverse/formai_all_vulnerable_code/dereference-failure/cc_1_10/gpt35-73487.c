//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to flip image horizontally
void flip_image_horizontal(unsigned char **image, int width, int height) {
    int i, j;
    unsigned char temp;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

// Function to change brightness of image
void change_brightness(unsigned char **image, int width, int height, int brightness) {
    int i, j;
    float factor = (float)(brightness + 100) / 100;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int value = (int)(factor * (float)image[i][j]);
            image[i][j] = (unsigned char)(value > 255 ? 255 : value);
        }
    }
}

// Function to change contrast of image
void change_contrast(unsigned char **image, int width, int height, int contrast) {
    int i, j;
    float factor = (float)(contrast + 100) / 100;
    float value_range = 255.0;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            float value = (float)image[i][j] / value_range;
            value = (value - 0.5) * factor + 0.5;
            value = value * value_range;
            int ivalue = (int)value;
            image[i][j] = (unsigned char)(ivalue > 255 ? 255 : ivalue < 0 ? 0 : ivalue);
        }
    }
}

int main() {
    // Create and initialize image
    int width = 8;
    int height = 6;
    unsigned char **image = (unsigned char**)malloc(height * sizeof(unsigned char*));
    int i, j;
    for (i = 0; i < height; i++) {
        image[i] = (unsigned char*)malloc(width * sizeof(unsigned char));
        for (j = 0; j < width; j++) {
            image[i][j] = (unsigned char)(i * width + j);
        }
    }

    // Print original image
    printf("Original image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Flip image horizontally
    flip_image_horizontal(image, width, height);

    // Print flipped image
    printf("Flipped image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Change brightness of image
    change_brightness(image, width, height, 30);

    // Print image with changed brightness
    printf("Image with changed brightness:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Change contrast of image
    change_contrast(image, width, height, 30);

    // Print image with changed contrast
    printf("Image with changed contrast:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Free memory used by image
    for (i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}