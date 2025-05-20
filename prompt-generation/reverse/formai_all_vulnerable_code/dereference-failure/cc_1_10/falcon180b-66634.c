//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: artistic
/*

![Mona Lisa](https://upload.wikimedia.org/wikipedia/commons/0/05/Mona_Lisa%2C_by_Leonardo_da_Vinci%2C_from_C2RMF_retouched.jpg)

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1000 // Width of the image
#define HEIGHT 1000 // Height of the image

// Function to convert an image to ASCII art
void imageToASCII(unsigned char* image, int width, int height) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            // Get the grayscale value of the pixel
            int gray = (int) image[y * width + x];

            // Convert the grayscale value to an ASCII character
            char ascii = '@';
            if (gray > 128) {
                ascii = '.';
            } else if (gray > 64) {
                ascii = '-';
            } else if (gray > 32) {
                ascii = '=';
            } else if (gray > 16) {
                ascii = '+';
            } else if (gray > 0) {
                ascii = '*';
            }

            // Print the ASCII character
            printf("%c", ascii);
        }
        printf("\n");
    }
}

int main() {
    // Load the image file
    unsigned char* image = (unsigned char*) malloc(WIDTH * HEIGHT * 3);
    FILE* file = fopen("mona_lisa.jpg", "rb");
    if (file == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }
    fread(image, 3, WIDTH * HEIGHT, file);
    fclose(file);

    // Convert the image to grayscale
    int width = WIDTH;
    int height = HEIGHT;
    int size = width * height;
    unsigned char* grayImage = (unsigned char*) malloc(size);
    for (int i = 0; i < size; i++) {
        int index = i / 3;
        int x = i % width;
        int y = i / width;
        int r = image[index * width + x];
        int g = image[(index + 1) * width + x];
        int b = image[(index + 2) * width + x];
        int gray = (int) (0.299 * r + 0.587 * g + 0.114 * b);
        grayImage[i] = gray;
    }

    // Convert the grayscale image to ASCII art
    imageToASCII(grayImage, width, height);

    return 0;
}