//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

// Define pixel structure
typedef struct {
    unsigned char r; // Red value
    unsigned char g; // Green value
    unsigned char b; // Blue value
} Pixel;

// Function to create an empty canvas
Pixel** createCanvas(int width, int height) {
    Pixel** canvas = (Pixel**)malloc(height * sizeof(Pixel*));
    for (int i = 0; i < height; i++) {
        canvas[i] = (Pixel*)malloc(width * sizeof(Pixel));
        for (int j = 0; j < width; j++) {
            canvas[i][j].r = 255; // Initialize as white
            canvas[i][j].g = 255;
            canvas[i][j].b = 255;
        }
    }
    return canvas;
}

// Function to free canvas memory
void freeCanvas(Pixel** canvas, int height) {
    for (int i = 0; i < height; i++) {
        free(canvas[i]);
    }
    free(canvas);
}

// Function to randomize a section of the canvas
void drawRandomPixels(Pixel** canvas, int width, int height, int numPixels) {
    for (int i = 0; i < numPixels; i++) {
        int x = rand() % width;
        int y = rand() % height;
        canvas[y][x].r = rand() % 256;
        canvas[y][x].g = rand() % 256;
        canvas[y][x].b = rand() % 256;
    }
}

// Function to print canvas to console
void printCanvas(Pixel** canvas, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel p = canvas[y][x];
            // Print ASCII representation of colors (using ASCII blocks)
            printf("\033[48;2;%d;%d;%dm  \033[0m", p.r, p.g, p.b);
        }
        printf("\n");
    }
}

// Main function to handle user input and painting process
int main() {
    srand(time(NULL)); // Seed for randomness
    int numPixels = 100; // Number of random pixels to draw

    Pixel** canvas = createCanvas(WIDTH, HEIGHT);
    
    // Draw random pixels on the canvas
    drawRandomPixels(canvas, WIDTH, HEIGHT, numPixels);

    // Print the canvas to the console
    printCanvas(canvas, WIDTH, HEIGHT);

    // Free allocated memory
    freeCanvas(canvas, HEIGHT);

    return 0;
}