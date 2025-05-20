//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 512

int main(int argc, char *argv[]) {

    // Load image
    FILE *fp = fopen("input.bmp", "rb");
    if (fp == NULL) {
        printf("Error loading image.\n");
        return 1;
    }

    // Read image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Allocate memory for image
    unsigned char *image = (unsigned char *) malloc(3 * width * height);

    // Read image data
    fread(image, 3 * width * height, 1, fp);

    // Close file
    fclose(fp);

    // Apply watermark
    unsigned char *watermark = (unsigned char *) malloc(3 * SIZE * SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int x = i * SIZE / width;
            int y = j * SIZE / height;
            if (x < 0 || x >= width || y < 0 || y >= height) {
                watermark[3 * (i * SIZE + j)] = 0;
            } else {
                watermark[3 * (i * SIZE + j)] = image[3 * (y * width + x)];
            }
        }
    }

    // Save watermarked image
    FILE *fout = fopen("output.bmp", "wb");
    if (fout == NULL) {
        printf("Error saving image.\n");
        return 1;
    }

    fwrite(&width, sizeof(int), 1, fout);
    fwrite(&height, sizeof(int), 1, fout);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int x = i * SIZE / width;
            int y = j * SIZE / height;
            if (x < 0 || x >= width || y < 0 || y >= height) {
                fwrite(&watermark[3 * (i * SIZE + j)], sizeof(unsigned char), 1, fout);
            } else {
                fwrite(&image[3 * (y * width + x)], sizeof(unsigned char), 1, fout);
            }
        }
    }

    free(image);
    free(watermark);

    fclose(fout);

    return 0;
}