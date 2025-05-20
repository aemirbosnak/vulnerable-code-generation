//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void drawTriangle(char **canvas, int row, int col, int size) {
    if (size == 1) {
        canvas[row][col] = '*';
        return;
    }
    
    int newSize = size / 2;
    // draw smaller triangles
    drawTriangle(canvas, row, col, newSize);
    drawTriangle(canvas, row + newSize, col - newSize, newSize);
    drawTriangle(canvas, row + newSize, col + newSize, newSize);
}

void printCanvas(char **canvas, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

char **createCanvas(int height, int width) {
    char **canvas = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        canvas[i] = malloc((width + 1) * sizeof(char)); // +1 for null-terminator
        memset(canvas[i], ' ', width);
        canvas[i][width] = '\0'; // null-terminate each row
    }
    return canvas;
}

void freeCanvas(char **canvas, int height) {
    for (int i = 0; i < height; i++) {
        free(canvas[i]);
    }
    free(canvas);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <size>\n", argv[0]);
        return 1;
    }
    
    int size = atoi(argv[1]);
    
    if (size <= 0 || (size & (size - 1)) != 0) {
        printf("Size must be a positive power of 2.\n");
        return 1;
    }

    int height = size;
    int width = size * 2 - 1;
    
    char **canvas = createCanvas(height, width);
    
    // Start drawing the Sierpiński triangle
    drawTriangle(canvas, 0, width / 2, size);
    
    // Print the final result
    printCanvas(canvas, height, width);
    
    // Clean up the allocated canvas
    freeCanvas(canvas, height);
    
    return 0;
}