//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

int main() {
    FILE *f = fopen("input.bmp", "rb");
    if (!f) {
        printf("Couldn't open input file!\n");
        return 1;
    }

    // Read the file header
    unsigned char header[54];
    fread(header, 1, 54, f);

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    pixel *data = malloc(width * height * sizeof(pixel));
    if (!data) {
        printf("Couldn't allocate memory for image data!\n");
        return 1;
    }

    // Read the image data
    fread(data, sizeof(pixel), width * height, f);
    fclose(f);

    // Flip the image vertically
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            pixel temp = data[y * width + x];
            data[y * width + x] = data[(height - y - 1) * width + x];
            data[(height - y - 1) * width + x] = temp;
        }
    }

    // Change the brightness and contrast
    int brightness = 50;
    int contrast = 20;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            data[y * width + x].r = data[y * width + x].r + brightness;
            data[y * width + x].g = data[y * width + x].g + brightness;
            data[y * width + x].b = data[y * width + x].b + brightness;

            data[y * width + x].r = (data[y * width + x].r * contrast) / 100;
            data[y * width + x].g = (data[y * width + x].g * contrast) / 100;
            data[y * width + x].b = (data[y * width + x].b * contrast) / 100;
        }
    }

    // Write the modified image data to a new file
    f = fopen("output.bmp", "wb");
    if (!f) {
        printf("Couldn't open output file!\n");
        return 1;
    }

    // Write the file header
    fwrite(header, 1, 54, f);

    // Write the image data
    fwrite(data, sizeof(pixel), width * height, f);
    fclose(f);

    // Free the allocated memory
    free(data);

    printf("Image modified successfully!\n");
    return 0;
}