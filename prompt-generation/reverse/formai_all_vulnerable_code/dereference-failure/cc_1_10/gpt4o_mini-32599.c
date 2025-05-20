//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 20 // Height of the triangle (number of rows)

// Function to recursively draw the Sierpinski triangle
void drawSierpinski(char **triangle, int x, int y, int size) {
    if (size == 1) {
        triangle[x][y] = '*';
    } else {
        // Draw the top triangle
        drawSierpinski(triangle, x, y, size / 2);
        // Draw the bottom left triangle
        drawSierpinski(triangle, x + size / 2, y - size / 2, size / 2);
        // Draw the bottom right triangle
        drawSierpinski(triangle, x + size / 2, y + size / 2, size / 2);
    }
}

// Function to initialize the triangle with spaces
void initializeTriangle(char **triangle, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < 2 * height - 1; j++) {
            triangle[i][j] = ' ';
        }
        triangle[i][2 * height - 1] = '\0'; // Null terminate each row
    }
}

// Function to free the allocated memory for the triangle array
void freeTriangle(char **triangle) {
    for (int i = 0; i < HEIGHT; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

// Function to print the triangle to the console
void printTriangle(char **triangle, int height) {
    for (int i = 0; i < height; i++) {
        printf("%s\n", triangle[i]);
    }
}

int main() {
    // Allocate memory for the triangle
    char **triangle = malloc(HEIGHT * sizeof(char *));
    for (int i = 0; i < HEIGHT; i++) {
        triangle[i] = malloc((2 * HEIGHT) * sizeof(char));
    }

    // Initialize the triangle with spaces
    initializeTriangle(triangle, HEIGHT);

    // Draw the Sierpinski triangle with full size
    drawSierpinski(triangle, 0, HEIGHT - 1, HEIGHT);

    // Print the triangle to the console
    printTriangle(triangle, HEIGHT);

    // Free the allocated memory
    freeTriangle(triangle);

    return 0;
}