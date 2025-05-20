//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform image steganography
void steganography(char* image, int width, int height, char* secret) {
    int i, j;
    unsigned char* imageData = (unsigned char*)malloc(sizeof(unsigned char) * width * height);
    FILE* fp;
    fp = fopen("output.png", "wb");

    // Convert the image to grayscale
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            imageData[i * width + j] = (unsigned char)(image[(i * width + j) * 3 + 0] + image[(i * width + j) * 3 + 1] + image[(i * width + j) * 3 + 2]) / 3;
        }
    }

    // Split the image into blocks
    int blockSize = 16;
    int blockCount = width / blockSize;

    // Find the block with the least frequent color
    unsigned char leastFrequentColor = 0;
    int leastFrequentColorCount = 0;
    for (i = 0; i < blockCount; i++) {
        int blockColorCount[256];
        int blockColor = 0;
        for (j = 0; j < blockSize; j++) {
            blockColor += imageData[(i * blockSize + j) * 3 + 0];
            blockColor += imageData[(i * blockSize + j) * 3 + 1];
            blockColor += imageData[(i * blockSize + j) * 3 + 2];
            blockColor %= 256;
            blockColorCount[blockColor]++;
        }
        int minColor = 256;
        for (j = 0; j < 256; j++) {
            if (blockColorCount[j] < minColor) {
                minColor = blockColorCount[j];
                leastFrequentColor = j;
            }
        }
    }

    // Insert the secret message into the least frequent block
    int blockSizeBytes = blockSize * 3;
    int secretSizeBytes = strlen(secret) * 4;
    int messageStartIndex = blockSizeBytes - secretSizeBytes;
    int messageEndIndex = blockSizeBytes;
    for (i = 0; i < secretSizeBytes; i++) {
        imageData[messageStartIndex + i] = secret[i / 4] / 16;
        imageData[messageEndIndex - 1 - i] = secret[i / 4] % 16;
    }

    // Reconstruct the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[(i * width + j) * 3 + 0] = (unsigned char)((imageData[(i * width + j) * 3 + 0] / 16) * 16);
            image[(i * width + j) * 3 + 1] = (unsigned char)((imageData[(i * width + j) * 3 + 1] / 16) * 16);
            image[(i * width + j) * 3 + 2] = (unsigned char)((imageData[(i * width + j) * 3 + 2] / 16) * 16);
        }
    }

    // Write the steganography to output file
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fprintf(fp, "%02x", image[(i * width + j) * 3 + 0]);
            fprintf(fp, "%02x", image[(i * width + j) * 3 + 1]);
            fprintf(fp, "%02x", image[(i * width + j) * 3 + 2]);
            fprintf(fp, "\n");
        }
    }
    fclose(fp);

    // Free memory
    free(imageData);
}

int main() {
    char* image = "input.png";
    int width = 500, height = 500;
    char* secret = "This is a secret message";

    steganography(image, width, height, secret);

    return 0;
}