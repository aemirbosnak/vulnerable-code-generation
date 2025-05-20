//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

// Color structure to represent 24-bit BGR colors
typedef struct {
    int r;
    int g;
    int b;
} Color;

// Function to get the brightness of a color
int getBrightness(Color c) {
    return (int)((c.r + c.g + c.b) / 3.0);
}

// Function to convert a color to a grayscale value
int getGrayscale(Color c) {
    int brightness = getBrightness(c);
    return (int)(0.2126 * (double)c.r + 0.7152 * (double)c.g + 0.0722 * (double)c.b);
}

// Function to convert an image to ASCII art
void imageToAscii(Color** image, int width, int height) {
    for (int y = 0; y < height; y += 2) {
        for (int x = 0; x < width; x++) {
            Color c1 = image[x][y];
            Color c2 = image[x][y + 1];

            int brightness1 = getBrightness(c1);
            int brightness2 = getBrightness(c2);

            int grayscale1 = getGrayscale(c1);
            int grayscale2 = getGrayscale(c2);

            char symbol1;
            char symbol2;

            // Choose the symbol based on the brightness or grayscale value
            if (brightness1 > 170) {
                symbol1 = '.';
            } else if (brightness1 > 85) {
                symbol1 = '=';
            } else {
                symbol1 = '#';
            }

            if (brightness2 > 170) {
                symbol2 = ' ';
            } else if (brightness2 > 85) {
                symbol2 = '-';
            } else {
                symbol2 = '@';
            }

            // Print the symbols
            printf("%c%c", symbol1, symbol2);
        }

        printf("\n");
    }
}

// Function to read an image file and convert it to a Color array
Color** readImage(char* path, int* width, int* height) {
    FILE* file = fopen(path, "rb");

    if (file == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    // Read the header data
    char magicNumber[2];
    fscanf(file, "%2s", magicNumber);

    if (strcmp(magicNumber, "P6") != 0) {
        printf("Error: Invalid file format\n");
        exit(1);
    }

    fscanf(file, "%d %d\n", width, height);

    int maxColor;
    fscanf(file, "%d\n", &maxColor);

    if (maxColor > 255) {
        printf("Error: Invalid color depth\n");
        exit(1);
    }

    // Allocate memory for the Color array
    Color** image = (Color**)malloc(sizeof(Color*) * (*height));

    for (int y = 0; y < (*height); y++) {
        image[y] = (Color*)malloc(sizeof(Color) * (*width));
    }

    // Read the pixel data and convert it to Color values
    for (int y = 0; y < (*height); y++) {
        for (int x = 0; x < (*width); x++) {
            unsigned char r, g, b;
            fread(&r, 1, 1, file);
            fread(&g, 1, 1, file);
            fread(&b, 1, 1, file);

            Color c;
            c.r = (int)r;
            c.g = (int)g;
            c.b = (int)b;

            image[x][y] = c;
        }
    }

    fclose(file);

    return image;
}

int main() {
    int width, height;
    Color** image = readImage("image.ppm", &width, &height);
    imageToAscii(image, width, height);

    for (int y = 0; y < height; y++) {
        free(image[y]);
    }

    free(image);

    return 0;
}