//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the pixel art
#define WIDTH 10
#define HEIGHT 10

// Define the number of colors in the palette
#define NUM_COLORS 5

// Define the ASCII characters to represent the colors
char colors[NUM_COLORS] = { '.', ':', 'o', 'O', 'B' };

/* Generate a random pixel art */
char** generatePixelArt() {

    // Allocate memory for the pixel array
    char** pixels = (char**) malloc(HEIGHT * sizeof(char*));
    for (int i = 0; i < HEIGHT; i++) {
        pixels[i] = (char*) malloc(WIDTH * sizeof(char));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Fill the array with random colors
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int colorIndex = rand() % NUM_COLORS;
            pixels[i][j] = colors[colorIndex];
        }
    }

    return pixels;
}

/* Print the pixel art to the console */
void printPixelArt(char** pixels) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {

    // Generate and print a pixel art
    char** pixels = generatePixelArt();
    printPixelArt(pixels);

    // Free memory
    for (int i = 0; i < HEIGHT; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}