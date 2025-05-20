//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int height, width, colors;
    printf("Enter the height of the pixel art (max 10): ");
    scanf("%d", &height);
    printf("Enter the width of the pixel art (max 10): ");
    scanf("%d", &width);
    printf("Enter the number of colors to use (max 8): ");
    scanf("%d", &colors);

    if(height > 10 || width > 10 || colors > 8){
        printf("Invalid height/width/colors! Maximum values are 10/10/8 respectively.");
        return 1;
    }

    // Initialize the random number generator
    srand(time(NULL));

    // Allocate memory for the pixel array
    int **pixels = (int**) malloc(height * sizeof(int*));
    for(int i = 0; i < height; i++){
        pixels[i] = (int*) malloc(width * sizeof(int));
    }

    // Set the pixel values randomly
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            pixels[i][j] = rand() % colors;
        }
    }

    // Output the pixel art
    printf("\n");
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for(int i = 0; i < height; i++){
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}