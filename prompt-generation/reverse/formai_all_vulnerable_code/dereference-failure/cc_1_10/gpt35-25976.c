//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Declare function prototypes
void flip_image(int rows, int cols, int original_image[][cols], int flipped_image[][cols]);
void change_brightness_contrast(int rows, int cols, int original_image[][cols], int modified_image[][cols], int brightness, int contrast);

int main() {
    // Create original image array
    int original_image[4][4] = {
        {100, 200, 150, 50},
        {80, 190, 240, 30},
        {120, 220, 180, 70},
        {70, 160, 130, 90}
    };
    
    // Print original image
    printf("Original Image:\n");
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            printf("%d\t", original_image[i][j]);
        }
        printf("\n");
    }
    
    // Call flip_image function to flip the image
    int flipped_image[4][4];
    flip_image(4, 4, original_image, flipped_image);
    
    // Print flipped image
    printf("\nFlipped Image:\n");
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            printf("%d\t", flipped_image[i][j]);
        }
        printf("\n");
    }
    
    // Call change_brightness_contrast function to modify the brightness and contrast of the original image
    int modified_image[4][4];
    change_brightness_contrast(4, 4, original_image, modified_image, 30, 50);
    
    // Print modified image
    printf("\nModified Image:\n");
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            printf("%d\t", modified_image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void flip_image(int rows, int cols, int original_image[][cols], int flipped_image[][cols]) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            flipped_image[i][j] = original_image[rows-i-1][j];
        }
    }
}

void change_brightness_contrast(int rows, int cols, int original_image[][cols], int modified_image[][cols], int brightness, int contrast) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            modified_image[i][j] = ((original_image[i][j] * contrast) / 100) + brightness;
        }
    }
}