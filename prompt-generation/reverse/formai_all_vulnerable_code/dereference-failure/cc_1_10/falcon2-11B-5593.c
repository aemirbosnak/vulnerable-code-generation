//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// Function to flip an image
void flip_image(int** image, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int temp = image[i][j];
            image[i][j] = image[height-i-1][width-j-1];
            image[height-i-1][width-j-1] = temp;
        }
    }
}

// Function to change brightness/contrast of an image
void change_brightness_contrast(int** image, int height, int width, float contrast, float brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = image[i][j];
            int new_pixel = (int)((pixel * brightness) + (contrast * (pixel * (1.0 - brightness))));
            image[i][j] = new_pixel;
        }
    }
}

// Function to save image to a file
void save_image(const char* filename, int** image, int height, int width) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(file, "%d ", image[i][j]);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
}

int main() {
    int height = 3;
    int width = 3;
    int** image = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        image[i] = (int*)malloc(width * sizeof(int));
    }
    
    // Fill the image with random values
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = rand() % 256;
        }
    }
    
    // Flip the image
    flip_image(image, height, width);
    
    // Change brightness/contrast of the image
    float contrast = 1.0;
    float brightness = 0.5;
    change_brightness_contrast(image, height, width, contrast, brightness);
    
    // Save the image to a file
    const char* filename = "output.txt";
    save_image(filename, image, height, width);
    
    return 0;
}