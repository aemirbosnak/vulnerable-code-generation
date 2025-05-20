//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Load image
    FILE *fp = fopen("input.bmp", "rb");
    if (!fp) {
        printf("Error opening file");
        return 1;
    }

    // Read image size
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Allocate memory for image
    int *image = (int *)malloc(width * height * 3 * sizeof(int));
    if (!image) {
        printf("Error allocating memory");
        fclose(fp);
        return 1;
    }

    // Read image pixels
    fread(image, sizeof(int), width * height * 3, fp);
    fclose(fp);

    // Flip image
    int *flipped = (int *)malloc(width * height * 3 * sizeof(int));
    if (!flipped) {
        printf("Error allocating memory");
        free(image);
        return 1;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel = image[(y * width + x) * 3];
            flipped[(height - 1 - y) * width + x * 3] = pixel;
        }
    }

    // Save flipped image
    fp = fopen("flipped.bmp", "wb");
    if (!fp) {
        printf("Error opening file");
        free(image);
        free(flipped);
        return 1;
    }

    // Write image size
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);

    // Write image pixels
    fwrite(flipped, sizeof(int), width * height * 3, fp);
    fclose(fp);

    // Free memory
    free(image);
    free(flipped);

    return 0;
}