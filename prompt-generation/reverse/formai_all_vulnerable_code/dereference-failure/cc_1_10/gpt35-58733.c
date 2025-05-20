//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r;
    int g;
    int b;
} Color;

int main() {
    // Define the canvas size
    int width = 20;
    int height = 10;
    
    // Allocate memory for the canvas
    Color **canvas = malloc(sizeof(Color*) * height);
    for(int i = 0; i < height; i++) {
        canvas[i] = malloc(sizeof(Color) * width);
    }
    
    // Set the background color to white
    Color white = {255, 255, 255};
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            canvas[i][j] = white;
        }
    }
    
    // Draw a blue square
    Color blue = {0, 0, 255};
    for(int i = 2; i < 8; i++) {
        for(int j = 2; j < 8; j++) {
            canvas[i][j] = blue;
        }
    }
    
    // Print the canvas
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("(%d,%d,%d)", canvas[i][j].r, canvas[i][j].g, canvas[i][j].b);
        }
        printf("\n");
    }
    
    // Free the memory
    for(int i = 0; i < height; i++) {
        free(canvas[i]);
    }
    free(canvas);
    
    return 0;
}