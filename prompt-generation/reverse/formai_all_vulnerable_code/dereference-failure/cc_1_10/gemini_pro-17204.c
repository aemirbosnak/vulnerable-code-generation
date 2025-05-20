//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uchar;

int main() {
    // Open the image.
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening image file.\n");
        return 1;
    }

    // Read the header.
    uchar header[54];
    fread(header, 54, 1, fp);

    // Get the width and height of the image.
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Get the image data.
    int size = width * height * 3;
    uchar *data = malloc(size);
    fread(data, size, 1, fp);

    // Close the image file.
    fclose(fp);

    // Flip the image horizontally.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            int temp = data[i * width + j];
            data[i * width + j] = data[i * width + width - 1 - j];
            data[i * width + width - 1 - j] = temp;
        }
    }

    // Flip the image vertically.
    for (int i = 0; i < width / 2; i++) {
        for (int j = 0; j < height; j++) {
            int temp = data[i + j * width];
            data[i + j * width] = data[width - 1 - i + j * width];
            data[width - 1 - i + j * width] = temp;
        }
    }

    // Change the brightness.
    int brightness = 50;
    for (int i = 0; i < size; i++) {
        data[i] = data[i] + brightness;
    }

    // Change the contrast.
    int contrast = 20;
    for (int i = 0; i < size; i++) {
        data[i] = data[i] * contrast / 100;
    }

    // Write the new image to a file.
    fp = fopen("new_image.bmp", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening new image file.\n");
        return 1;
    }

    // Write the header.
    fwrite(header, 54, 1, fp);

    // Write the image data.
    fwrite(data, size, 1, fp);

    // Close the new image file.
    fclose(fp);

    // Free the memory.
    free(data);

    return 0;
}