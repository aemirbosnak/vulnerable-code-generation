//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_GRAY_SCALE 255

// Function to convert pixel value to ASCII character
char pixelToAscii(int grayValue) {
    const char* asciiCharacters = "@%#*+=-:. "; // Characters from dark to light
    int index = (grayValue * (sizeof(asciiCharacters) - 2)) / MAX_GRAY_SCALE;
    return asciiCharacters[index];
}

// Function to read PGM file and convert it into a grayscale representation
unsigned char* readPGM(const char* filename, int* width, int* height) {
    FILE *file = fopen(filename, "rb");
    
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    // Read the header
    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), file)) {
        perror("Invalid PGM file");
        return NULL;
    }

    // Check for P2 or P5 PGM format
    if (buffer[1] != '2' && buffer[1] != '5') {
        perror("Not a valid PGM file");
        return NULL;
    }
    
    // Read width and height
    fscanf(file, "%d %d", width, height);
    int maxVal;
    fscanf(file, "%d", &maxVal);

    // Allocate memory for the image
    unsigned char* image = (unsigned char*)malloc((*width) * (*height));
    
    // Read pixel data based on the format
    if (buffer[1] == '5') { // Binary PGM
        fread(image, sizeof(unsigned char), (*width) * (*height), file);
    } else { // ASCII PGM
        for (int i = 0; i < (*width) * (*height); ++i) {
            int val;
            fscanf(file, "%d", &val);
            image[i] = (unsigned char)val;
        }
    }

    fclose(file);
    return image;
}

// Function to convert image to ASCII art
void convertToAsciiArt(unsigned char* image, int width, int height) {
    for (int y = 0; y < height; y += height / HEIGHT) {
        for (int x = 0; x < width; x += width / WIDTH) {
            int pixelIndex = y * width + x;
            if (pixelIndex < width * height) {
                char asciiChar = pixelToAscii(image[pixelIndex]);
                putchar(asciiChar);
            }
        }
        putchar('\n');
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    unsigned char* image = readPGM(argv[1], &width, &height);

    if (!image) {
        return EXIT_FAILURE;
    }

    convertToAsciiArt(image, width, height);
    
    // Clean up
    free(image);
    return EXIT_SUCCESS;
}