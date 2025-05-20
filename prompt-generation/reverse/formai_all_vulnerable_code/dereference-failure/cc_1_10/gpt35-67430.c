//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 80

// Function to convert RGB values to grayscale
int convertToGrayScale(unsigned char red, unsigned char green, unsigned char blue) {
    int gray = (0.2126 * red) + (0.7152 * green) + (0.0722 * blue);
    return gray;
}

int main() {

    // Open the image file
    FILE* fp = fopen("image.bmp", "rb");
    if (!fp) {
        printf("Error opening image file.\n");
        return 1;
    }

    // Read in the bitmap header data
    unsigned int width, height;
    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(width), 1, fp);
    fread(&height, sizeof(height), 1, fp);

    // Allocate memory for the bitmap data
    unsigned char* data = (unsigned char*) malloc(width * height * 3);
    if (!data) {
        printf("Error allocating memory for image data.\n");
        return 1;
    }

    // Read in the bitmap data
    fseek(fp, 54, SEEK_SET);
    fread(data, 1, width * height * 3, fp);

    // Close the file
    fclose(fp);

    // Output the ASCII art
    for (int y = 0; y < height; y += HEIGHT) {
        for (int x = 0; x < width; x += WIDTH) {
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    int index = ((y+i) * width + (x+j)) * 3;
                    unsigned char red = data[index];
                    unsigned char green = data[index+1];
                    unsigned char blue = data[index+2];
                    int gray = convertToGrayScale(red, green, blue);
                    char asciiChar;
                    if (gray < 30) {
                        asciiChar = '@';
                    } else if (gray < 60) {
                        asciiChar = '#';
                    } else if (gray < 90) {
                        asciiChar = '*';
                    } else if (gray < 120) {
                        asciiChar = '+';
                    } else if (gray < 150) {
                        asciiChar = '=';
                    } else if (gray < 180) {
                        asciiChar = '-';
                    } else if (gray < 210) {
                        asciiChar = ':';
                    } else if (gray < 240) {
                        asciiChar = '.';
                    } else {
                        asciiChar = ' ';
                    }
                    putchar(asciiChar);
                }
                putchar('\n');
            }
        }
    }

    // Free the memory used for the bitmap data
    free(data);

    return 0;
}