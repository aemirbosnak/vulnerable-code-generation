//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define HEIGHT 32
#define WIDTH 64

// Function to initialize the canvas with spaces
void initialize_canvas(char canvas[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }
}

// Function to draw a filled triangle in the canvas
void draw_triangle(char canvas[HEIGHT][WIDTH], int x, int y, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            if (y + i < HEIGHT && x + j < WIDTH) {
                canvas[y + i][x + j] = '*';
                canvas[y + i][x - j] = '*';
            }
        }
    }
}

// Recursive function to create the Sierpinski triangle
void sierpinski_triangle(char canvas[HEIGHT][WIDTH], int x, int y, int size, int depth) {
    if (depth == 0) {
        draw_triangle(canvas, x, y, size);
    } else {
        int new_size = size / 2;
        sierpinski_triangle(canvas, x, y, new_size, depth - 1);
        sierpinski_triangle(canvas, x - new_size, y + new_size, new_size, depth - 1);
        sierpinski_triangle(canvas, x + new_size, y + new_size, new_size, depth - 1);
    }
}

// Function to print the canvas
void print_canvas(char canvas[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    int depth = 5; // Set a default recursion depth
    
    // Check command-line arguments for depth input
    if (argc > 1) {
        depth = atoi(argv[1]);
        if (depth < 0 || depth > 8) {
            printf("Depth must be between 0 and 8. Using default depth 5.\n");
            depth = 5;
        }
    }

    // Allocate and initialize the canvas
    char canvas[HEIGHT][WIDTH];
    initialize_canvas(canvas);

    // Calculate starting position (centered)
    int x = WIDTH / 2;
    int y = 0;

    // Generate the Sierpinski triangle
    sierpinski_triangle(canvas, x, y, pow(2, depth), depth);

    // Print the resulting canvas
    print_canvas(canvas);

    return 0;
}