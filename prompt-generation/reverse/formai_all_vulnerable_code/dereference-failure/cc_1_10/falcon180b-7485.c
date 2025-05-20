//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define BITS_PER_PIXEL 8
#define MAX_VALUE 255
#define THRESHOLD 10

// Function to read image file and store pixel values in 2D array
void readImage(char* filename, unsigned char** image) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    *image = (unsigned char*) malloc(filesize);
    if (*image == NULL) {
        printf("Error: could not allocate memory for image\n");
        exit(1);
    }

    fread(*image, filesize, 1, fp);
    fclose(fp);
}

// Function to apply watermark to image
void applyWatermark(unsigned char* image, unsigned char* watermark, int alpha) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;
            int value = image[index];

            if (value > THRESHOLD) {
                int w = watermark[y % 16 * 16 + x % 16];
                value += w * alpha / 256;
            }

            if (value > MAX_VALUE)
                value = MAX_VALUE;
            else if (value < 0)
                value = 0;

            image[index] = value;
        }
    }
}

// Function to save modified image to file
void saveImage(char* filename, unsigned char* image) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fwrite(image, WIDTH * HEIGHT, 1, fp);
    fclose(fp);
}

// Main function
int main() {
    unsigned char* image = NULL;
    unsigned char* watermark = NULL;

    readImage("romeo.bmp", &image);
    readImage("juliet.bmp", &watermark);

    applyWatermark(image, watermark, 128);

    saveImage("watermarked.bmp", image);

    free(image);
    free(watermark);

    return 0;
}