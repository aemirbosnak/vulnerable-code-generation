//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Width and Height of ASCII Image
#define WIDTH 80
#define HEIGHT 60

// Define Function to Convert RGB Values to Grayscale Value
int grayscale(int r, int g, int b) {
    return (0.3 * r + 0.59 * g + 0.11 * b);
}

int main(int argc, char **argv) {
    // Check if File Name was Provided as Command Line Argument
    if (argc < 2) {
        printf("Please provide a file name as argument!\n");
        return 1;
    }

    // Open Image File
    FILE *image_file = fopen(argv[1], "rb");
    if (!image_file) {
        printf("Could not open image file!\n");
        return 1;
    }

    // Read Image Header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);

    // Extract Image Width and Height from Header
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Verify if Image is Valid for Conversion
    if (width > WIDTH || height > HEIGHT) {
        printf("Conversion of this image is not supported! Please use an image with a resolution of %dx%d or less.\n", WIDTH, HEIGHT);
        return 1;
    }

    // Read Image Data
    unsigned char image[height][width][3];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(image[i][j], sizeof(unsigned char), 3, image_file);
        }
    }

    // Close Image File
    fclose(image_file);

    // Convert Image to Grayscale and Print ASCII Art
    char ascii_art[height][width + 1];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int gray_value = grayscale(image[i][j][0], image[i][j][1], image[i][j][2]);
            int ascii_index = gray_value / 25;
            ascii_art[i][j] = ".-:=+*#%@"[ascii_index];
        }
        ascii_art[i][width] = '\0';
    }

    // Print ASCII Art
    printf("ASCII Art of Image '%s':\n", argv[1]);
    for (int i = 0; i < height; i++) {
        printf("%s\n", ascii_art[i]);
    }

    return 0;
}