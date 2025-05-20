//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_COLOR_VALUE 255

// Define our pixel struct
typedef struct {
    int x;
    int y;
    int r;
    int g;
    int b;
} Pixel;

// Function to generate a random pixel
Pixel generateRandomPixel() {
    Pixel pixel;
    pixel.x = rand() % WIDTH;
    pixel.y = rand() % HEIGHT;
    pixel.r = rand() % MAX_COLOR_VALUE;
    pixel.g = rand() % MAX_COLOR_VALUE;
    pixel.b = rand() % MAX_COLOR_VALUE;
    return pixel;
}

// Function to print the pixel art
void printPixelArt(Pixel *pixels, int numPixels) {
    for (int i = 0; i < numPixels; i++) {
        printf("%d,%d,%d\n", pixels[i].x, pixels[i].y, pixels[i].r);
    }
}

// Function to generate the pixel art
void generatePixelArt(Pixel *pixels, int numPixels) {
    srand(time(NULL)); // Seed the random number generator with the current time
    for (int i = 0; i < numPixels; i++) {
        pixels[i] = generateRandomPixel();
    }
}

// Main function
int main() {
    Pixel *pixels = malloc(sizeof(Pixel) * WIDTH * HEIGHT); // Allocate memory for our pixels
    int numPixels = WIDTH * HEIGHT; // Calculate the number of pixels
    generatePixelArt(pixels, numPixels); // Generate the pixel art
    printPixelArt(pixels, numPixels); // Print the pixel art
    free(pixels); // Free the memory we allocated
    return 0;
}