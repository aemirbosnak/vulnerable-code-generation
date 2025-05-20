//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define global variables to hold the dimensions of the image
int width = 0;
int height = 0;

// Define a function to read the dimensions of the image from the ppm file header
void readDimensions(FILE *file) {
    char buffer[128];
    fgets(buffer, 128, file);
    while (buffer[0] == '#') {
        fgets(buffer, 128, file);
    }
    sscanf(buffer, "%d %d", &width, &height);
}

// Define a function to convert a color value to a grayscale intensity value between 0 and 255
int grayscale(int r, int g, int b) {
    return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

// Define a function to convert a grayscale intensity value to an ASCII character
char asciiFromIntensity(int intensity) {
    const char *asciiChars = " .:-=+*#%@";
    int asciiCharsLen = strlen(asciiChars);
    int intensityStep = (255 + 1) / asciiCharsLen;
    int index = (intensity / intensityStep);
    return asciiChars[index];
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check that the user has provided an image file path as an argument
    if (argc < 2) {
        printf("Error: Please provide an image file path.\n");
        return 1;
    }

    // Open the image file
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: Unable to open file: %s\n", argv[1]);
        return 1;
    }

    // Read the dimensions of the image from the header
    readDimensions(file);

    // Allocate memory for the image
    char *image = (char *) malloc(width * height * 3);

    // Read the pixel data from the image file
    fread(image, width * height * 3, 1, file);

    // Close the image file
    fclose(file);

    // Loop over each pixel in the image and convert it to an ASCII character
    char *asciiImage = (char *) malloc(width * height);
    int i, r, g, b, intensity;
    for (i = 0; i < width * height; i++) {
        r = (unsigned char) image[i * 3];
        g = (unsigned char) image[i * 3 + 1];
        b = (unsigned char) image[i * 3 + 2];
        intensity = grayscale(r, g, b);
        asciiImage[i] = asciiFromIntensity(intensity);
    }

    // Print the ASCII image to the console
    for (i = 0; i < width * height; i++) {
        printf("%c", asciiImage[i]);
        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }

    // Free the memory used for the images
    free(image);
    free(asciiImage);

    return 0;
}