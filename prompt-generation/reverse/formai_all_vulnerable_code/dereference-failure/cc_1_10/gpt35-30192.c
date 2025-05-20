//FormAI DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Constants for image size */
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

/* Constants for steganography */
#define BYTE_SIZE 8
#define MESSAGE_SIZE 32

/* Global variable to store the image data */
uint8_t pixels[MAX_HEIGHT][MAX_WIDTH][3];

/* Function declarations */
void writeMessage(uint8_t* data, uint32_t message);
uint32_t readMessage(uint8_t* data);
void encodeMessage(uint8_t* data, uint32_t message);
uint32_t decodeMessage(uint8_t* data);
void writePixelsToFile(FILE* file);
void readPixelsFromFile(FILE* file);

/* Write message to first 4 bytes of data */
void writeMessage(uint8_t* data, uint32_t message) {
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        if (((message >> i) & 1) == 1) {
            data[i / BYTE_SIZE] |= (1 << (i % BYTE_SIZE));
        } else {
            data[i / BYTE_SIZE] &= ~(1 << (i % BYTE_SIZE));
        }
    }
}

/* Read message from first 4 bytes of data */
uint32_t readMessage(uint8_t* data) {
    uint32_t message = 0;
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        if (((data[i / BYTE_SIZE] >> (i % BYTE_SIZE)) & 1) == 1) {
            message |= (1 << i);
        }
    }
    return message;
}

/* Encode message into the least significant bits of pixel data */
void encodeMessage(uint8_t* data, uint32_t message) {
    for (int i = 0; i < 3; i++) {
        if (((message >> i) & 1) == 1) {
            data[i] |= 1;
        } else {
            data[i] &= ~1;
        }
    }
}

/* Decode message from the least significant bits of pixel data */
uint32_t decodeMessage(uint8_t* data) {
    uint32_t message = 0;
    for (int i = 0; i < 3; i++) {
        if ((data[i] & 1) == 1) {
            message |= (1 << i);
        }
    }
    return message;
}

/* Write the pixel data to a file */
void writePixelsToFile(FILE* file) {
    fwrite(pixels, sizeof(uint8_t), MAX_HEIGHT * MAX_WIDTH * 3, file);
}

/* Read the pixel data from a file */
void readPixelsFromFile(FILE* file) {
    fread(pixels, sizeof(uint8_t), MAX_HEIGHT * MAX_WIDTH * 3, file);
}

int main() {
    /* Open input file */
    FILE* inputFile = fopen("input.bmp", "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    /* Read BMP header */
    uint8_t bmpHeader[54];
    if (fread(bmpHeader, sizeof(uint8_t), 54, inputFile) != 54) {
        perror("Error reading BMP header");
        exit(EXIT_FAILURE);
    }

    /* Check if BMP format is valid */
    if (bmpHeader[0] != 'B' || bmpHeader[1] != 'M') {
        perror("Invalid BMP format");
        exit(EXIT_FAILURE);
    }

    /* Read pixel data */
    readPixelsFromFile(inputFile);

    /* Get message from user */
    printf("Enter message to encode (32 bits or less):\n");
    uint32_t message;
    scanf("%u", &message);

    /* Encode message into pixel data */
    uint8_t* pixelData = pixels[0][0];
    writeMessage(pixelData, message);
    encodeMessage(pixelData + 3, message);
    encodeMessage(pixelData + 6, message);

    /* Open output file */
    FILE* outputFile = fopen("output.bmp", "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    /* Write BMP header */
    if (fwrite(bmpHeader, sizeof(uint8_t), 54, outputFile) != 54) {
        perror("Error writing BMP header");
        exit(EXIT_FAILURE);
    }

    /* Write pixel data */
    writePixelsToFile(outputFile);

    /* Close files */
    fclose(inputFile);
    fclose(outputFile);

    /* Open output file */
    outputFile = fopen("output.bmp", "rb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    /* Read BMP header */
    if (fread(bmpHeader, sizeof(uint8_t), 54, outputFile) != 54) {
        perror("Error reading BMP header");
        exit(EXIT_FAILURE);
    }

    /* Check if BMP format is valid */
    if (bmpHeader[0] != 'B' || bmpHeader[1] != 'M') {
        perror("Invalid BMP format");
        exit(EXIT_FAILURE);
    }

    /* Read pixel data */
    readPixelsFromFile(outputFile);

    /* Decode message from pixel data */
    pixelData = pixels[0][0];
    uint32_t decodedMessage = readMessage(pixelData);
    uint32_t decodedMessage2 = decodeMessage(pixelData + 3);
    uint32_t decodedMessage3 = decodeMessage(pixelData + 6);

    /* Print decoded message */
    printf("Decoded message: %u %u %u\n", decodedMessage, decodedMessage2, decodedMessage3);

    /* Close files */
    fclose(outputFile);

    return 0;
}