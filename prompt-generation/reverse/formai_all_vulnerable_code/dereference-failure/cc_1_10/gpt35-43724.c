//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the characters used to create ASCII art
static const char *chars = " .,:;ox%#@";

// Function to convert a pixel value into a character
char pixel_to_char(int pixel_val, int max_val) {
    // Scale the pixel value to the range 0-7 (7 is the maximum index for the chars string)
    int index = ((double) pixel_val / max_val) * 7;

    // Return the character corresponding to the scaled pixel value
    return chars[index];
}

int main() {
    // Allocate memory for the image data
    int **image = malloc(sizeof(int*) * MAX_HEIGHT);
    for (int i = 0; i < MAX_HEIGHT; i++) {
        image[i] = malloc(sizeof(int) * MAX_WIDTH);
    }

    // Populate the image data with random pixel values (between 0 and 255)
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            image[i][j] = rand() % 256;
        }
    }

    // Print the ASCII art
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            // Convert the pixel value at (i, j) to a character
            char c = pixel_to_char(image[i][j], 255);

            // Print the character to the console
            printf("%c", c);
        }

        // Print a newline character to start a new row
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < MAX_HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}