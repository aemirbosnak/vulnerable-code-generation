//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void convertToAsciiArt(const char* imagePath);
unsigned char* loadImage(const char* imagePath, int* width, int* height);
void generateAsciiArt(unsigned char* imageData, int width, int height);
char getAsciiChar(int brightness);

// ASCII brightness levels
const char* asciiChars = "@%#*+=-:. "; // From dark to light

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_path>\n", argv[0]);
        return 1;
    }

    convertToAsciiArt(argv[1]);
    return 0;
}

void convertToAsciiArt(const char* imagePath) {
    int width, height;
    unsigned char* imageData = loadImage(imagePath, &width, &height);
    
    if (imageData) {
        generateAsciiArt(imageData, width, height);
        free(imageData);
    } else {
        printf("Error: Could not load image file.\n");
    }
}

unsigned char* loadImage(const char* imagePath, int* width, int* height) {
    // This is a placeholder for loading image data.
    // You would typically use a library like stb_image.h or similar to actually load an image.

    // Dummy values for simulation
    *width = 100;
    *height = 100;
    unsigned char* imageData = (unsigned char*)malloc(*width * *height * 3);
    
    // Fill with a simple gradient for demonstration
    for (int y = 0; y < *height; ++y) {
        for (int x = 0; x < *width; ++x) {
            int idx = (y * *width + x) * 3;
            imageData[idx] = (unsigned char)(x * 255 / *width);   // Red
            imageData[idx + 1] = (unsigned char)(y * 255 / *height); // Green
            imageData[idx + 2] = (unsigned char)((x + y) * 255 / (*width + *height)); // Blue
        }
    }

    return imageData;
}

void generateAsciiArt(unsigned char* imageData, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = (y * width + x) * 3;
            // Calculate brightness (grayscale value)
            int brightness = (imageData[idx] + imageData[idx + 1] + imageData[idx + 2]) / 3;
            char asciiChar = getAsciiChar(brightness);
            putchar(asciiChar);
        }
        putchar('\n');
    }
}

char getAsciiChar(int brightness) {
    int index = (brightness * (strlen(asciiChars) - 1)) / 255;
    return asciiChars[index];
}