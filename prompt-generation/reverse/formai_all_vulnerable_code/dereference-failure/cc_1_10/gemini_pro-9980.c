//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 768

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel image[WIDTH][HEIGHT];

int main() {
    // Read the image from a file
    FILE *file = fopen("image.bmp", "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the header
    unsigned char header[54];
    if (fread(header, sizeof(unsigned char), 54, file) != 54) {
        printf("Error reading header\n");
        return 1;
    }

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Error: not a valid BMP file\n");
        return 1;
    }

    // Get the width and height of the image
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the pixel data
    if (fread(image, sizeof(pixel), width * height, file) != width * height) {
        printf("Error reading pixel data\n");
        return 1;
    }

    // Close the file
    fclose(file);

    // Edit the image
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Convert the pixel to grayscale
            unsigned char gray = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
            image[i][j].r = gray;
            image[i][j].g = gray;
            image[i][j].b = gray;
        }
    }

    // Write the edited image to a file
    file = fopen("edited_image.bmp", "wb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Write the header
    fwrite(header, sizeof(unsigned char), 54, file);

    // Write the pixel data
    fwrite(image, sizeof(pixel), width * height, file);

    // Close the file
    fclose(file);

    return 0;
}