//FormAI DATASET v1.0 Category: Image Steganography ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE unsigned char
#define IMAGE_SIZE 256*256*3

// Function to read image data from file
int readImageData(char *fileName, BYTE *imageData) {
    FILE *fp = fopen(fileName, "rb");

    if (fp == NULL) {
        printf("Error opening file");
        return -1;
    }

    fread(imageData, sizeof(BYTE), IMAGE_SIZE, fp);
    fclose(fp);

    return 0;
}

// Function to write image data to file
int writeImageData(char *fileName, BYTE *imageData) {
    FILE *fp = fopen(fileName, "wb");

    if (fp == NULL) {
        printf("Error creating file");
        return -1;
    }

    fwrite(imageData, sizeof(BYTE), IMAGE_SIZE, fp);
    fclose(fp);

    return 0;
}

// Function to hide message in image using LSB steganography
int hideMessage(BYTE *imageData, char *message) {
    int messageLength = strlen(message);
    int dataLength = IMAGE_SIZE / 8;

    if (messageLength > dataLength) {
        printf("Error: Message is too long");
        return -1;
    }

    for (int i = 0; i < messageLength; i++) {
        BYTE c = message[i];

        for (int j = 0; j < 8; j++) {
            int index = i * 8 + j;
            int bit = (c >> j) & 1;

            imageData[index] = (imageData[index] & 0xFE) | bit;
        }
    }

    return 0;
}

// Function to extract message from image using LSB steganography
char *extractMessage(BYTE *imageData) {
    char *message = (char *)malloc(IMAGE_SIZE/8 * sizeof(char));

    for (int i = 0; i < IMAGE_SIZE/8; i++) {
        BYTE c = 0;

        for (int j = 0; j < 8; j++) {
            int index = i * 8 + j;
            c = (c << 1) | (imageData[index] & 1);
        }

        message[i] = c;
    }

    return message;
}

// Main function
int main() {
    BYTE *imageData = (BYTE *)malloc(IMAGE_SIZE * sizeof(BYTE));
    char *message = "This is my secret message";

    // Read image data from file
    if (readImageData("image.bmp", imageData) != 0) {
        printf("\nExiting program...\n");
        exit(1);
    }

    // Hide message in image
    if (hideMessage(imageData, message) != 0) {
        printf("\nExiting program...\n");
        exit(1);
    }

    // Write image data to file
    if (writeImageData("stego_image.bmp", imageData) != 0) {
        printf("\nExiting program...\n");
        exit(1);
    }

    // Extract message from image
    char *extractedMessage = extractMessage(imageData);
    printf("Hidden message is: %s\n", extractedMessage);

    free(imageData);
    free(extractedMessage);

    printf("\nProgram finished...\n");

    return 0;
}