//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 32
#define HEIGHT 16
#define PIXEL_SIZE 4

void drawPixel(int x, int y, char* pixelGrid) {
    // calculate the starting position of the pixel
    int startIndex = (y * WIDTH * PIXEL_SIZE) + (x * PIXEL_SIZE);
    
    // set the pixel color to a random value
    char color = rand() % 2 == 0 ? '0' : '1';
    
    // set the pixel data in the grid
    for (int i = 0; i < PIXEL_SIZE; i++) {
        pixelGrid[startIndex + i] = color;
    }
}

int main() {
    srand((unsigned int) time(NULL));
    
    // allocate memory for the pixel grid
    char* pixelGrid = (char*) malloc(WIDTH * HEIGHT * PIXEL_SIZE * sizeof(char));
    
    // draw some random pixels on the grid
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            drawPixel(x, y, pixelGrid);
        }
    }
    
    // print the pixel grid
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int startIndex = (y * WIDTH * PIXEL_SIZE) + (x * PIXEL_SIZE);
            for (int i = 0; i < PIXEL_SIZE; i++) {
                printf("%c", pixelGrid[startIndex + i]);
            }
        }
        printf("\n");
    }
    
    // free the memory used by the pixel grid
    free(pixelGrid);

    return 0;
}