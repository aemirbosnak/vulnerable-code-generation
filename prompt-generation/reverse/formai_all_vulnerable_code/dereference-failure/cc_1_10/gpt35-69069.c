//FormAI DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert character to binary string
char* charToBinary(unsigned char c) {
    char* binary = malloc(sizeof(char) * 9);
    int i;
    for (i = 0; i < 8; i++) {
        // Shift right to get the next bit, then extract LSB using bitwise AND
        binary[7-i] = (c >> i) & 1 ? '1' : '0';
    }
    binary[8] = '\0'; // Add null terminator
    return binary;
}

// Function to convert binary string back to character
char binaryToChar(char* binary) {
    int i;
    char c = 0;
    for (i = 0; i < 8; i++) {
        // Shift left to make room for next bit, then append next bit using bitwise OR
        c <<= 1;
        c |= binary[i] - '0';
    }
    return c;
}

// Function to hide a byte of data in a pixel
void hideData(unsigned char* pixel, unsigned char data) {
    // Store the LSB of each color component in the data byte
    pixel[0] = (pixel[0] & ~1) | (data & 1);
    pixel[1] = (pixel[1] & ~1) | ((data >> 1) & 1);
    pixel[2] = (pixel[2] & ~1) | ((data >> 2) & 1);
}

// Function to extract a byte of data from a pixel
unsigned char extractData(unsigned char* pixel) {
    // Extract the LSB of each color component and combine into a byte
    return (pixel[0] & 1) | ((pixel[1] & 1) << 1) | ((pixel[2] & 1) << 2);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <input image> <output image> <secret message>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        printf("Failed to open input file.\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        printf("Failed to open output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Read the BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, inputFile);
    fwrite(header, sizeof(unsigned char), 54, outputFile);

    // Read the input message
    char* inputMessage = argv[3];
    int messageLength = strlen(inputMessage);
    if (messageLength > 255) {
        printf("Message must be 255 characters or less.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    // Convert the message length to binary
    char* messageLengthBinary = charToBinary((unsigned char)messageLength);

    // Write the message length to the first pixel
    unsigned char firstPixel[3];
    fread(firstPixel, sizeof(unsigned char), 3, inputFile);
    hideData(firstPixel, (unsigned char)messageLength);
    fwrite(firstPixel, sizeof(unsigned char), 3, outputFile);

    // Write the message length to the next two pixels (for redundancy)
    unsigned char secondPixel[3], thirdPixel[3];
    fread(secondPixel, sizeof(unsigned char), 3, inputFile);
    hideData(secondPixel, (unsigned char)messageLength);
    fwrite(secondPixel, sizeof(unsigned char), 3, outputFile);
    fread(thirdPixel, sizeof(unsigned char), 3, inputFile);
    hideData(thirdPixel, (unsigned char)messageLength);
    fwrite(thirdPixel, sizeof(unsigned char), 3, outputFile);

    // Write the message itself
    int i, j;
    for (i = 0; i < messageLength; i++) {
        char* messageBinary = charToBinary((unsigned char)inputMessage[i]);
        for (j = 0; j < 8; j++) {
            // Read a pixel and hide a bit of the message in it
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, inputFile);
            hideData(pixel, messageBinary[j] - '0');
            fwrite(pixel, sizeof(unsigned char), 3, outputFile);
        }
        free(messageBinary);
    }

    // Copy any remaining image data
    unsigned char pixel[3];
    while (fread(pixel, sizeof(unsigned char), 3, inputFile)) {
        fwrite(pixel, sizeof(unsigned char), 3, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Data hidden successfully.\n");

    return 0;
}