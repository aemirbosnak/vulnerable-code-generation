//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WATERMARK_SIZE 100
#define IMAGE_SIZE 512

void readImage(FILE *fp, unsigned char *image) {
    int i;
    for (i = 0; i < IMAGE_SIZE; i++) {
        fread(&image[i], sizeof(unsigned char), 1, fp);
    }
}

void writeImage(FILE *fp, unsigned char *image) {
    int i;
    for (i = 0; i < IMAGE_SIZE; i++) {
        fwrite(&image[i], sizeof(unsigned char), 1, fp);
    }
}

void addWatermark(unsigned char *image, unsigned char *watermark) {
    int i, j;
    for (i = 0; i < IMAGE_SIZE; i++) {
        image[i] ^= watermark[i % WATERMARK_SIZE];
    }
}

void removeWatermark(unsigned char *image, unsigned char *watermark) {
    int i, j;
    for (i = 0; i < IMAGE_SIZE; i++) {
        image[i] ^= watermark[i % WATERMARK_SIZE];
    }
}

int main() {
    FILE *fpImage, *fpWatermark;
    unsigned char image[IMAGE_SIZE], watermark[WATERMARK_SIZE];

    fpImage = fopen("image.bin", "rb+");
    fpWatermark = fopen("watermark.bin", "rb+");

    if (fpImage == NULL || fpWatermark == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    readImage(fpImage, image);
    readImage(fpWatermark, watermark);

    addWatermark(image, watermark);

    writeImage(fpImage, image);

    removeWatermark(image, watermark);

    writeImage(fpImage, image);

    fclose(fpImage);
    fclose(fpWatermark);

    return 0;
}