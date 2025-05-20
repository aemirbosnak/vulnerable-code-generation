//FormAI DATASET v1.0 Category: Image compression ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// read a BMP image
unsigned char* readBMPImage(char* imageFileName, int* width, int* height, int* bitDepth) {
    FILE* file = fopen(imageFileName, "rb");
    if (!file) {
        printf("Error: %s could not be opened.\n", imageFileName);
        exit(1);
    }

    // BMP header is 54 bytes
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // check if the file is actually a BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Error: %s is not a BMP image.\n", imageFileName);
        exit(1);
    }

    // get image width, height, and bit depth
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];
    *bitDepth = *(int*)&header[28];

    // determine the size of the image in bytes
    int imageSize = *width * *height * (*bitDepth / 8);

    // allocate memory for the image data
    unsigned char* imageData = (unsigned char*)malloc(sizeof(unsigned char) * imageSize);

    // read in the image data
    fread(imageData, sizeof(unsigned char), imageSize, file);

    fclose(file);
    return imageData;
}

// write a BMP image
void writeBMPImage(char* imageFileName, unsigned char* imageData, int width, int height, int bitDepth) {
    FILE* file = fopen(imageFileName, "wb");
    if (!file) {
        printf("Error: %s could not be opened for writing.\n", imageFileName);
        exit(1);
    }

    // BMP header is 54 bytes
    unsigned char header[54];
    memset(header, 0, 54);
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + width * height * (bitDepth / 8);
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    *(int*)&header[26] = 1;
    *(int*)&header[28] = bitDepth;

    fwrite(header, sizeof(unsigned char), 54, file);
    fwrite(imageData, sizeof(unsigned char), width * height * (bitDepth / 8), file);

    fclose(file);
}

// compress an image using run-length encoding
unsigned char* compressImage(unsigned char* imageData, int width, int height, int bitDepth, int* compressedSize) {
    unsigned char* compressedData = (unsigned char*)malloc(sizeof(unsigned char) * width * height * (bitDepth / 8));
    int count = 1;
    int index = 0;
    unsigned char currentPixel[3];
    unsigned char nextPixel[3];

    memcpy(currentPixel, &imageData[0], bitDepth / 8); // get first pixel

    for (int i = 1; i < width * height; i++) {
        memcpy(nextPixel, &imageData[i * (bitDepth / 8)], bitDepth / 8); // get next pixel

        if (currentPixel[0] == nextPixel[0] && currentPixel[1] == nextPixel[1] && currentPixel[2] == nextPixel[2]) {
            count++; // the pixel is the same as the previous pixel, so increment the count
        } else {
            compressedData[index++] = currentPixel[0];
            compressedData[index++] = currentPixel[1];
            compressedData[index++] = currentPixel[2];
            compressedData[index++] = count;
            count = 1; // reset the count
        }

        memcpy(currentPixel, nextPixel, bitDepth / 8); // set currentPixel to nextPixel
    }

    compressedData[index++] = currentPixel[0];
    compressedData[index++] = currentPixel[1];
    compressedData[index++] = currentPixel[2];
    compressedData[index++] = count;

    *compressedSize = index;

    return compressedData;
}

// decompress an image using run-length encoding
unsigned char* decompressImage(unsigned char* compressedData, int width, int height, int bitDepth, int compressedSize) {
    unsigned char* decompressedData = (unsigned char*)malloc(sizeof(unsigned char) * width * height * (bitDepth / 8));
    int count = 0;
    int index = 0;

    for (int i = 0; i < compressedSize; i += 4) {
        int r = compressedData[i];
        int g = compressedData[i + 1];
        int b = compressedData[i + 2];
        int numPixels = compressedData[i + 3];

        for (int j = 0; j < numPixels; j++) {
            decompressedData[index++] = r;
            decompressedData[index++] = g;
            decompressedData[index++] = b;
        }
    }

    return decompressedData;
}

int main() {
    int width, height, bitDepth;
    unsigned char* imageData = readBMPImage("input.bmp", &width, &height, &bitDepth);
    int imageSize = width * height * (bitDepth / 8);
    int compressedSize;
    unsigned char* compressedData = compressImage(imageData, width, height, bitDepth, &compressedSize);
    unsigned char* decompressedData = decompressImage(compressedData, width, height, bitDepth, compressedSize);
    writeBMPImage("output.bmp", decompressedData, width, height, bitDepth);

    printf("Image size: %d bytes\n", imageSize);
    printf("Compressed size: %d bytes\n", compressedSize);
    printf("Compression ratio: %f\n", 1.0 * compressedSize / imageSize);

    free(imageData);
    free(compressedData);
    free(decompressedData);

    return 0;
}