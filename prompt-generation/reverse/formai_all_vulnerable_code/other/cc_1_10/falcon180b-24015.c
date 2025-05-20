//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define WIDTH 256
#define HEIGHT 256
#define SIZEOFIMAGE (WIDTH * HEIGHT)

// Function to read image data from file
void readImage(char *filename, unsigned char *image) {
    FILE *fp;
    fp = fopen(filename, "rb");
    assert(fp!= NULL);
    fread(image, SIZEOFIMAGE, 1, fp);
    fclose(fp);
}

// Function to write image data to file
void writeImage(char *filename, unsigned char *image) {
    FILE *fp;
    fp = fopen(filename, "wb");
    assert(fp!= NULL);
    fwrite(image, SIZEOFIMAGE, 1, fp);
    fclose(fp);
}

// Function to apply watermark
void applyWatermark(unsigned char *image, char *watermark) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (image[i*WIDTH+j] == 0) {
                image[i*WIDTH+j] = 1;
            }
        }
    }
}

// Function to read watermark data from file
void readWatermark(char *filename, char *watermark) {
    FILE *fp;
    fp = fopen(filename, "r");
    assert(fp!= NULL);
    fscanf(fp, "%s", watermark);
    fclose(fp);
}

// Function to write watermark data to file
void writeWatermark(char *filename, char *watermark) {
    FILE *fp;
    fp = fopen(filename, "w");
    assert(fp!= NULL);
    fprintf(fp, "%s", watermark);
    fclose(fp);
}

// Function to generate random watermark
void generateRandomWatermark(char *watermark) {
    int i;
    for (i = 0; i < strlen(watermark); i++) {
        watermark[i] = rand() % 26 + 'a';
    }
    watermark[strlen(watermark)] = '\0';
}

// Main function
int main(int argc, char **argv) {
    unsigned char image[SIZEOFIMAGE];
    char watermark[256];
    srand(time(NULL));
    readImage("image.bmp", image);
    generateRandomWatermark(watermark);
    applyWatermark(image, watermark);
    writeImage("watermarked_image.bmp", image);
    writeWatermark("watermark.txt", watermark);
    return 0;
}