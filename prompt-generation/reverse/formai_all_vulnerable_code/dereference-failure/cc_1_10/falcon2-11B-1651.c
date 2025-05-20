//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define the size of the canvas
    int canvasWidth = 50;
    int canvasHeight = 50;

    // Create an array to hold the pixels
    int* canvas = malloc(canvasWidth * canvasHeight * sizeof(int));

    // Initialize all pixels to black
    for (int i = 0; i < canvasWidth * canvasHeight; i++) {
        canvas[i] = 0;
    }

    // Draw a red square in the center of the canvas
    int x = canvasWidth / 2;
    int y = canvasHeight / 2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int pixelIndex = y * canvasWidth + x + i + j * canvasWidth;
            canvas[pixelIndex] = 255;
        }
        x += 1;
    }

    // Draw a blue circle around the red square
    for (int i = 0; i < 6; i++) {
        int x = x - 1;
        for (int j = 0; j < 6; j++) {
            int pixelIndex = y * canvasWidth + x + i * 6 + j;
            if (pixelIndex >= canvasWidth * canvasHeight) {
                break;
            }
            if (pixelIndex < canvasWidth * canvasHeight - 1) {
                canvas[pixelIndex + 1] = canvas[pixelIndex];
            }
            canvas[pixelIndex] = 255;
        }
        x += 2;
    }

    // Display the canvas
    for (int i = 0; i < canvasWidth * canvasHeight; i++) {
        printf("%d ", canvas[i]);
    }
    printf("\n");

    // Free the memory
    free(canvas);

    return 0;
}