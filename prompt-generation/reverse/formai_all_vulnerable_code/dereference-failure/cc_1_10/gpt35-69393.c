//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

void flipImage(int**, int, int);
void adjustBrightnessContrast(int**, int, int);

int main() {
    int rows, cols, choice;
    printf("Enter the number of rows in the image: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the image: ");
    scanf("%d", &cols);
    
    // Allocate memory for image
    int** image = malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        image[i] = malloc(cols * sizeof(int));
    }
    
    // Populate image with random values between 0 and 255
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            image[i][j] = rand() % 256;
        }
    }
    
    printf("Choose from the following image processing options:\n");
    printf("1. Flip image\n");
    printf("2. Adjust brightness and contrast\n");
    printf("Selection: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            flipImage(image, rows, cols);
            break;
        case 2:
            adjustBrightnessContrast(image, rows, cols);
            break;
        default:
            printf("Invalid option selected. Please try again.\n");
            break;
    }
    
    // Free memory
    for(int i = 0; i < rows; i++) {
        free(image[i]);
    }
    free(image);
    
    return 0;
}

// Function to flip the image horizontally
void flipImage(int** image, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][cols-1-j];
            image[i][cols-1-j] = temp;
        }
    }
    
    printf("Image flipped horizontally.\n");
}

// Function to adjust brightness and contrast of the image
void adjustBrightnessContrast(int** image, int rows, int cols) {
    int brightness, contrast;
    printf("Enter the brightness adjustment value (-255 to 255): ");
    scanf("%d", &brightness);
    printf("Enter the contrast adjustment value (-255 to 255): ");
    scanf("%d", &contrast);
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int newValue = image[i][j] + brightness;
            if(newValue < 0) {
                newValue = 0;
            } else if(newValue > 255) {
                newValue = 255;
            }
            newValue = (newValue - 127) * contrast / 127 + 127;
            if(newValue < 0) {
                newValue = 0;
            } else if(newValue > 255) {
                newValue = 255;
            }
            image[i][j] = newValue;
        }
    }
    
    printf("Image brightness and contrast adjusted.\n");
}