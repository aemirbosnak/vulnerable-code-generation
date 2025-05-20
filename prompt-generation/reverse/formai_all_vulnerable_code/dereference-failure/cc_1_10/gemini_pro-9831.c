//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    unsigned char r, g, b;
} RGBPixel;

// Load an image from a file
RGBPixel** load_image(const char* filename, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    // Read the header
    unsigned char header[18];
    fread(header, 1, 18, fp);

    // Check if it's a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: '%s' is not a valid BMP file\n", filename);
        exit(1);
    }

    // Get the image dimensions
    *width = (header[18] << 8) | header[19];
    *height = (header[22] << 8) | header[23];

    // Allocate memory for the image data
    RGBPixel** image = malloc(*height * sizeof(RGBPixel*));
    for (int i = 0; i < *height; i++) {
        image[i] = malloc(*width * sizeof(RGBPixel));
    }

    // Read the image data
    fread(image[0], 1, *width * *height * sizeof(RGBPixel), fp);

    fclose(fp);

    return image;
}

// Save an image to a file
void save_image(const char* filename, RGBPixel** image, int width, int height) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    // Write the header
    unsigned char header[18] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0,
        54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    header[2] = (width * height * 3 + 14 + 40) & 0xFF;
    header[3] = ((width * height * 3 + 14 + 40) >> 8) & 0xFF;
    header[4] = ((width * height * 3 + 14 + 40) >> 16) & 0xFF;
    header[5] = ((width * height * 3 + 14 + 40) >> 24) & 0xFF;
    header[10] = ((width * height * 3 + 14 + 40) >> 32) & 0xFF;
    fwrite(header, 1, 18, fp);

    // Write the image data
    fwrite(image[0], 1, width * height * sizeof(RGBPixel), fp);

    fclose(fp);
}

// Apply a filter to an image
void filter_image(RGBPixel** image, int width, int height, double filter[3][3]) {
    RGBPixel** new_image = malloc(height * sizeof(RGBPixel*));
    for (int i = 0; i < height; i++) {
        new_image[i] = malloc(width * sizeof(RGBPixel));
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double r = 0, g = 0, b = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int x = j + k, y = i + l;
                    if (x >= 0 && x < width && y >= 0 && y < height) {
                        r += image[y][x].r * filter[k + 1][l + 1];
                        g += image[y][x].g * filter[k + 1][l + 1];
                        b += image[y][x].b * filter[k + 1][l + 1];
                    }
                }
            }
            new_image[i][j].r = r;
            new_image[i][j].g = g;
            new_image[i][j].b = b;
        }
    }

    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    image = new_image;
}

int main() {
    // Load the image
    int width, height;
    RGBPixel** image = load_image("image.bmp", &width, &height);

    // Apply a filter to the image
    double filter[3][3] = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 }
    };
    filter_image(image, width, height, filter);

    // Save the image
    save_image("new_image.bmp", image, width, height);

    // Free the image memory
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}