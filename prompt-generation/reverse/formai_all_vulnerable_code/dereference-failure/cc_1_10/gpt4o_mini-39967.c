//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void drawSierpinski(char **canvas, int x, int y, int size) {
    if (size < 1) return;

    // Draw a filled triangle
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            canvas[y + i][x + j] = '*';
            canvas[y + i][x + size - 1 - j] = '*';
        }
    }

    // Recursively draw the smaller triangles
    int newSize = size / 2;
    drawSierpinski(canvas, x + newSize / 2, y + newSize, newSize);   // Bottom middle triangle
    drawSierpinski(canvas, x, y + newSize, newSize);                // Top left triangle
    drawSierpinski(canvas, x + size, y + newSize, newSize);         // Top right triangle
}

void createCanvas(char **canvas, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            canvas[i][j] = ' ';  // Fill canvas with spaces
        }
        canvas[i][width] = '\0'; // Null terminate each row
    }
}

void printCanvas(char **canvas, int height) {
    for (int i = 0; i < height; i++) {
        printf("%s\n", canvas[i]);
    }
}

int main() {
    int size = 64; // Size of the Sierpinski triangle; must be a power of 2
    int height = size; 
    int width = size * 2; 

    // Dynamically allocate memory for the canvas
    char **canvas = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        canvas[i] = (char *)malloc((width + 1) * sizeof(char)); // +1 for null termination
    }

    createCanvas(canvas, height, width);
    drawSierpinski(canvas, 0, 0, size);
    printCanvas(canvas, height);

    // Free the allocated memory
    for (int i = 0; i < height; i++) {
        free(canvas[i]);
    }
    free(canvas);

    return 0;
}