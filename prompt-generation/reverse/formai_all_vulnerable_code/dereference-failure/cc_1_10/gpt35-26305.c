//FormAI DATASET v1.0 Category: Image Steganography ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 100000
#define MAX_SECRET_SIZE 10000

// Helper function to read image file
int readImage(char* fileName, char image[MAX_IMAGE_SIZE], int maxSize) {
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        return -1;
    }
    int size = fread(image, sizeof(char), maxSize, file);
    fclose(file);
    return size;
}

// Helper function to write image file
int writeImage(char* fileName, char image[MAX_IMAGE_SIZE], int size) {
    FILE* file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        return -1;
    }
    fwrite(image, sizeof(char), size, file);
    fclose(file);
    return 0;
}

// Function to hide secret message in the LSBs of image pixels
int embedMessage(char image[MAX_IMAGE_SIZE], int imageSize, char* secretMessage, int messageSize) {
    if (imageSize < messageSize * 8) {
        printf("Error: Image size is too small to embed the secret message.\n");
        return -1;
    }
    int messageIndex = 0;
    int bitIndex = 0;
    for (int i = 0; i < imageSize; i++) {
        if (messageIndex == messageSize) {
            break;
        }
        if (bitIndex == 8) {
            messageIndex++;
            bitIndex = 0;
        }
        image[i] = (image[i] & 0xFE) | ((secretMessage[messageIndex] >> bitIndex) & 0x01);
        bitIndex++;
    }
    return 0;
}

// Function to extract secret message from the LSBs of image pixels
int extractMessage(char image[MAX_IMAGE_SIZE], int imageSize, char* secretMessage, int messageSize) {
    int messageIndex = 0;
    int bitIndex = 0;
    for (int i = 0; i < imageSize; i++) {
        if (messageIndex == messageSize) {
            break;
        }
        if (bitIndex == 8) {
            messageIndex++;
            bitIndex = 0;
        }
        secretMessage[messageIndex] = (secretMessage[messageIndex] & ~(0x01 << bitIndex)) | ((image[i] & 0x01) << bitIndex);
        bitIndex++;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    char* imageFile = "image.ppm";
    char* secretMessageFile = "secret.txt";
    char image[MAX_IMAGE_SIZE];
    char secretMessage[MAX_SECRET_SIZE];
    int imageSize = readImage(imageFile, image, MAX_IMAGE_SIZE);
    if (imageSize < 0) {
        return -1;
    }
    int secretSize = readImage(secretMessageFile, secretMessage, MAX_SECRET_SIZE);
    if (secretSize < 0) {
        return -1;
    }
    int messageSize = strlen(secretMessage);
    if (messageSize > MAX_SECRET_SIZE) {
        printf("Error: Secret message is too large.\n");
        return -1;
    }
    if (strcmp(argv[1], "hide") == 0) {
        printf("Embedding secret message into the image...\n");
        if (embedMessage(image, imageSize, secretMessage, messageSize) < 0) {
            return -1;
        }
        printf("Done!\n");
        if (writeImage("encoded.ppm", image, imageSize) < 0) {
            return -1;
        }
    } else if (strcmp(argv[1], "reveal") == 0) {
        printf("Extracting secret message from the image...\n");
        if (extractMessage(image, imageSize, secretMessage, messageSize) < 0) {
            return -1;
        }
        printf("Done! The secret message is:\n%s\n", secretMessage);
    } else {
        printf("Usage: %s [hide | reveal]\n", argv[0]);
    }
    return 0;
}