//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to generate a shocked pixel art
void generate_shocked_pixel_art(int width, int height, char *filename) {
    // Create a new image
    unsigned char *image = (unsigned char *)malloc(width * height * 3);
    memset(image, 0, width * height * 3);

    // Set the background color to black
    for (int i = 0; i < width * height * 3; i += 3) {
        image[i] = 0;
        image[i + 1] = 0;
        image[i + 2] = 0;
    }

    // Draw the shocked face
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Draw the left eye
            if (i > width / 4 && i < width / 2 && j > height / 3 && j < height / 2) {
                image[(i * width + j) * 3] = 255;
                image[(i * width + j) * 3 + 1] = 255;
                image[(i * width + j) * 3 + 2] = 255;
            }

            // Draw the right eye
            if (i > width / 2 && i < width * 3 / 4 && j > height / 3 && j < height / 2) {
                image[(i * width + j) * 3] = 255;
                image[(i * width + j) * 3 + 1] = 255;
                image[(i * width + j) * 3 + 2] = 255;
            }

            // Draw the mouth
            if (i > width / 4 && i < width * 3 / 4 && j > height / 2 && j < height * 3 / 4) {
                image[(i * width + j) * 3] = 255;
                image[(i * width + j) * 3 + 1] = 0;
                image[(i * width + j) * 3 + 2] = 0;
            }
        }
    }

    // Save the image to a file
    FILE *file = fopen(filename, "wb");
    fwrite(image, 1, width * height * 3, file);
    fclose(file);

    // Free the memory allocated for the image
    free(image);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user has provided the correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <width> <height> <filename>\n", argv[0]);
        return 1;
    }

    // Get the width and height of the image
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    // Check if the width and height are valid
    if (width <= 0 || height <= 0) {
        printf("Invalid width or height\n");
        return 1;
    }

    // Get the filename
    char *filename = argv[3];

    // Generate the shocked pixel art
    generate_shocked_pixel_art(width, height, filename);

    return 0;
}