//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define WIDTH 20
#define HEIGHT 10

// Simple pixel structure
typedef struct {
    int r, g, b; // RGB color values
} Pixel;

// Create a canvas with specified width and height
Pixel** createCanvas(int width, int height) {
    Pixel** canvas = (Pixel**)malloc(height * sizeof(Pixel*));
    for (int i = 0; i < height; i++) {
        canvas[i] = (Pixel*)malloc(width * sizeof(Pixel));
    }
    return canvas;
}

// Free the allocated canvas
void freeCanvas(Pixel** canvas, int height) {
    for (int i = 0; i < height; i++) {
        free(canvas[i]);
    }
    free(canvas);
}

// Set a pixel at (x, y) to a specific color
void setPixel(Pixel** canvas, int x, int y, int r, int g, int b) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x].r = r;
        canvas[y][x].g = g;
        canvas[y][x].b = b;
    }
}

// Print the canvas
void printCanvas(Pixel** canvas, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = canvas[y][x].r;
            int g = canvas[y][x].g;
            int b = canvas[y][x].b;
            if (r == 0 && g == 0 && b == 0) {
                printf("  "); // Print empty space for black
            } else {
                printf("\033[48;2;%d;%d;%dm  \033[0m", r, g, b); // Print color block
            }
        }
        printf("\n");
    }
}

// Draw a simple smiley face
void drawSmiley(Pixel** canvas) {
    // Face Circle
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if ((x - WIDTH / 2) * (x - WIDTH / 2) + 
                (y - HEIGHT / 2) * (y - HEIGHT / 2) <= 36) {
                setPixel(canvas, x, y, 255, 223, 0); // Yellow face
            }
        }
    }

    // Eyes
    setPixel(canvas, 7, 4, 0, 0, 0); // Left Eye
    setPixel(canvas, 7, 5, 0, 0, 0); // Left Eye
    setPixel(canvas, 12, 4, 0, 0, 0); // Right Eye
    setPixel(canvas, 12, 5, 0, 0, 0); // Right Eye

    // Smile
    for (int x = 7; x <= 12; x++) {
        setPixel(canvas, x, 7, 0, 0, 0); // Smile line
    }
    setPixel(canvas, 8, 8, 255, 0, 0); // Smile edges
    setPixel(canvas, 11, 8, 255, 0, 0); // Smile edges
}

// Main function to demonstrate the pixel art
int main() {
    Pixel** canvas = createCanvas(WIDTH, HEIGHT);

    // Initialize the canvas to black
    memset(canvas[0], 0, WIDTH * HEIGHT * sizeof(Pixel));

    // Draw the smiley face
    drawSmiley(canvas);

    // Print the canvas to the console
    printCanvas(canvas, WIDTH, HEIGHT);

    // Cleanup
    freeCanvas(canvas, HEIGHT);

    return 0;
}