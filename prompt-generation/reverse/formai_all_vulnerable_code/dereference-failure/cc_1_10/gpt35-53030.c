//FormAI DATASET v1.0 Category: Image Editor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the 2D array that holds the image
int **image;

// Define a function to allocate memory for the image
void allocateMemory(int rows, int columns) {
    image = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        image[i] = (int *)malloc(columns * sizeof(int));
    }
}

// Define a function to free the memory allocated for the image
void freeMemory(int rows) {
    for(int i = 0; i < rows; i++) {
        free(image[i]);
    }
    free(image);
}

// Define a function to set all the pixels in the image to a given color
void setAllPixels(int rows, int columns, int color) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            image[i][j] = color;
        }
    }
}

// Define a function to invert the colors in the image
void invertColors(int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
}

// Define a function to rotate the image 90 degrees clockwise
void rotateClockwise(int *rowsPointer, int *columnsPointer) {
    // Swap the rows and columns
    int rows = *columnsPointer;
    int columns = *rowsPointer;
    
    // Allocate memory for the rotated image
    int **rotatedImage = (int **)malloc(columns * sizeof(int *));
    for(int i = 0; i < columns; i++) {
        rotatedImage[i] = (int *)malloc(rows * sizeof(int));
    }
    
    // Rotate the image
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            rotatedImage[j][rows - 1 - i] = image[i][j];
        }
    }
    
    // Free the memory allocated for the original image
    freeMemory(*rowsPointer);
    
    // Update the rows and columns pointers to reflect the rotated image
    *rowsPointer = columns;
    *columnsPointer = rows;
    
    // Update the image pointer to point to the rotated image
    image = rotatedImage;
}

// Define a function to print the image to the console
void printImage(int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Set up a 5x5 image
    int rows = 5;
    int columns = 5;
    allocateMemory(rows, columns);
    setAllPixels(rows, columns, 0);
    
    // Set some pixels to a different color
    image[0][0] = 255;
    image[2][2] = 128;
    image[4][4] = 64;
    
    // Print the original image
    printf("Original Image:\n");
    printImage(rows, columns);
    printf("\n");
    
    // Invert the colors in the image
    invertColors(rows, columns);
    
    // Print the inverted image
    printf("Inverted Image:\n");
    printImage(rows, columns);
    printf("\n");
    
    // Rotate the image 90 degrees clockwise
    rotateClockwise(&rows, &columns);
    
    // Print the rotated image
    printf("Rotated Image:\n");
    printImage(rows, columns);
    printf("\n");
    
    // Free the memory allocated for the image
    freeMemory(rows);
    
    return 0;
}