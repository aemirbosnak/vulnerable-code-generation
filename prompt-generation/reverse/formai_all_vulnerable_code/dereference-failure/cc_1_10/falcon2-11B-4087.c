//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BLOCK_SIZE 256

int main() {
    // Read the input image file
    FILE *imgFile;
    char imgName[] = "input.jpg";
    imgFile = fopen(imgName, "rb");
    if (imgFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read image data
    unsigned char *imgData = (unsigned char*)malloc(BLOCK_SIZE);
    int imgSize = fread(imgData, 1, BLOCK_SIZE, imgFile);
    if (imgSize!= BLOCK_SIZE) {
        printf("Error reading image data\n");
        return 1;
    }
    fclose(imgFile);

    // Initialize watermark image
    unsigned char *watermarkData = (unsigned char*)malloc(BLOCK_SIZE);
    // Load watermark image data here

    // Watermarking algorithm
    int watermarkX = 0;
    int watermarkY = 0;
    for (int i = 0; i < imgSize; i++) {
        for (int j = 0; j < imgSize; j++) {
            // Calculate watermark position
            watermarkX = (int)((double)watermarkX + ((double)i / imgSize) * (double)BLOCK_SIZE);
            watermarkY = (int)((double)watermarkY + ((double)j / imgSize) * (double)BLOCK_SIZE);

            // Check if watermark overlaps with image pixels
            if (watermarkX >= 0 && watermarkX < BLOCK_SIZE && watermarkY >= 0 && watermarkY < BLOCK_SIZE) {
                // Overlap detected, modify pixel
                imgData[i * imgSize + j] = imgData[i * imgSize + j] + watermarkData[watermarkX * imgSize + watermarkY];
            }
        }
    }

    // Save the watermarked image
    FILE *outFile;
    char outName[] = "watermarked.jpg";
    outFile = fopen(outName, "wb");
    if (outFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fwrite(imgData, 1, imgSize, outFile);
    fclose(outFile);

    free(imgData);
    free(watermarkData);

    return 0;
}