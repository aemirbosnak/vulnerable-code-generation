//FormAI DATASET v1.0 Category: Image Editor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the struct for holding RGB values
struct RGB {
    unsigned char R;
    unsigned char G;
    unsigned char B;
};

// Define the recursive function to flip the input image horizontally
void flipHorizontal(struct RGB** image, int height, int width, int row, int col) {
    
    // Base case: exhausted all rows in the image
    if (row == height) {
        return;
    }
    
    // Recursively call for the next row
    flipHorizontal(image, height, width, row + 1, 0);
    
    // Base case: exhausted all columns in the row
    if (col == width / 2) {
        return;
    }
    
    // Swap the pixel values on either side of the image center
    struct RGB temp = image[row][col];
    image[row][col] = image[row][width - 1 - col];
    image[row][width - 1 - col] = temp;
    
    // Recursively call for the next column
    flipHorizontal(image, height, width, row, col + 1);
}

int main() {
    
    // Generate a dummy image with dimensions 4x6
    struct RGB** image = (struct RGB**)malloc(4 * sizeof(struct RGB*));
    for (int i = 0; i < 4; i++) {
        image[i] = (struct RGB*)malloc(6 * sizeof(struct RGB));
    }
    image[0][0] = (struct RGB){255, 0, 0};
    image[0][1] = (struct RGB){0, 255, 0};
    image[0][2] = (struct RGB){0, 0, 255};
    image[0][3] = (struct RGB){255, 255, 0};
    image[0][4] = (struct RGB){255, 0, 255};
    image[0][5] = (struct RGB){0, 255, 255};
    image[1][0] = (struct RGB){150, 200, 50};
    image[1][1] = (struct RGB){50, 150, 200};
    image[1][2] = (struct RGB){200, 50, 150};
    image[1][3] = (struct RGB){150, 150, 50};
    image[1][4] = (struct RGB){50, 150, 150};
    image[1][5] = (struct RGB){150, 50, 150};
    image[2][0] = (struct RGB){100, 100, 100};
    image[2][1] = (struct RGB){150, 150, 150};
    image[2][2] = (struct RGB){200, 200, 200};
    image[2][3] = (struct RGB){50, 50, 50};
    image[2][4] = (struct RGB){100, 100, 100};
    image[2][5] = (struct RGB){150, 150, 150};
    image[3][0] = (struct RGB){255, 255, 255};
    image[3][1] = (struct RGB){0, 0, 0};
    image[3][2] = (struct RGB){255, 255, 255};
    image[3][3] = (struct RGB){0, 0, 0};
    image[3][4] = (struct RGB){255, 255, 255};
    image[3][5] = (struct RGB){0, 0, 0};
    
    // Display the original image in the console
    printf("Original Image:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            printf("(%d, %d, %d)\t", image[i][j].R, image[i][j].G, image[i][j].B);
        }
        printf("\n");
    }
    
    // Flip the image horizontally using recursion
    flipHorizontal(image, 4, 6, 0, 0);
    
    // Display the flipped image in the console
    printf("\nFlipped Image:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            printf("(%d, %d, %d)\t", image[i][j].R, image[i][j].G, image[i][j].B);
        }
        printf("\n");
    }
    
    // Free the dynamically allocated memory
    for (int i = 0; i < 4; i++) {
        free(image[i]);
    }
    free(image);
    
    return 0;
}