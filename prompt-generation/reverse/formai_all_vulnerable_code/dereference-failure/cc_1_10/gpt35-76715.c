//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>

// Function to determine ASCII character from pixel value
char pixelToChar(int pixelValue) {
    // Set ASCII characters from darkest to lightest
    char asciiChars[] = {'#', 'M', 'X', 'G', 'I', 'T', 'z', 'o', ':', '.', ' '};
    int charCount = sizeof(asciiChars) / sizeof(asciiChars[0]);
    int pixelCount = 255 / charCount;
    int charIndex = pixelValue / pixelCount;
    return asciiChars[charIndex];
}

// Function to convert image to ASCII art
void imageToAscii(char *filename) {
    FILE *imageFile;
    imageFile = fopen(filename, "rb");

    // Get image width and height from header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory to store pixel data
    int pixelCount = width * height;
    unsigned char *pixels = (unsigned char *) malloc(sizeof(unsigned char) * pixelCount * 3);

    // Read pixel data from image
    fread(pixels, sizeof(unsigned char), pixelCount * 3, imageFile);
    fclose(imageFile);

    // Convert pixel data to ASCII art
    for (int i = 0; i < pixelCount; i++) {
        int r = pixels[i * 3];
        int g = pixels[i * 3 + 1];
        int b = pixels[i * 3 + 2];

        int grayscale = (r * 0.3) + (g * 0.59) + (b * 0.11);
        char asciiChar = pixelToChar(grayscale);
        printf("%c", asciiChar);

        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }

    // Free allocated memory
    free(pixels);
}

int main() {
    imageToAscii("test.jpg");
    return 0;
}