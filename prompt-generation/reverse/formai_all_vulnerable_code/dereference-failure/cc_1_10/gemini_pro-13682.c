//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void embedMessage(byte *image, int imageSize, byte *message, int messageSize) {
    // Check if the message can fit in the image
    if (imageSize < messageSize * 8) {
        fprintf(stderr, "Error: Message is too large for the image.\n");
        exit(1);
    }

    // Embed the message in the image
    int bitIndex = 0;
    for (int i = 0; i < messageSize; i++) {
        for (int j = 0; j < 8; j++) {
            byte bit = (message[i] >> j) & 1;
            image[bitIndex / 8] = (image[bitIndex / 8] & 0xFE) | bit;
            bitIndex++;
        }
    }
}

void extractMessage(byte *image, int imageSize, byte *message, int messageSize) {
    // Extract the message from the image
    int bitIndex = 0;
    for (int i = 0; i < messageSize; i++) {
        for (int j = 0; j < 8; j++) {
            byte bit = image[bitIndex / 8] & 1;
            message[i] |= bit << j;
            bitIndex++;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <input message> <output message>\n", argv[0]);
        exit(1);
    }

    // Load the input image
    FILE *inputImageFile = fopen(argv[1], "rb");
    if (inputImageFile == NULL) {
        fprintf(stderr, "Error: Could not open input image file.\n");
        exit(1);
    }

    fseek(inputImageFile, 0, SEEK_END);
    int inputImageSize = ftell(inputImageFile);
    rewind(inputImageFile);

    byte *inputImage = malloc(inputImageSize);
    if (inputImage == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for input image.\n");
        exit(1);
    }

    fread(inputImage, 1, inputImageSize, inputImageFile);
    fclose(inputImageFile);

    // Load the input message
    FILE *inputMessageFile = fopen(argv[3], "rb");
    if (inputMessageFile == NULL) {
        fprintf(stderr, "Error: Could not open input message file.\n");
        exit(1);
    }

    fseek(inputMessageFile, 0, SEEK_END);
    int inputMessageSize = ftell(inputMessageFile);
    rewind(inputMessageFile);

    byte *inputMessage = malloc(inputMessageSize);
    if (inputMessage == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for input message.\n");
        exit(1);
    }

    fread(inputMessage, 1, inputMessageSize, inputMessageFile);
    fclose(inputMessageFile);

    // Embed the message in the image
    embedMessage(inputImage, inputImageSize, inputMessage, inputMessageSize);

    // Save the output image
    FILE *outputImageFile = fopen(argv[2], "wb");
    if (outputImageFile == NULL) {
        fprintf(stderr, "Error: Could not open output image file.\n");
        exit(1);
    }

    fwrite(inputImage, 1, inputImageSize, outputImageFile);
    fclose(outputImageFile);

    // Extract the message from the image
    byte *outputMessage = malloc(inputMessageSize);
    if (outputMessage == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for output message.\n");
        exit(1);
    }

    extractMessage(inputImage, inputImageSize, outputMessage, inputMessageSize);

    // Save the output message
    FILE *outputMessageFile = fopen(argv[4], "wb");
    if (outputMessageFile == NULL) {
        fprintf(stderr, "Error: Could not open output message file.\n");
        exit(1);
    }

    fwrite(outputMessage, 1, inputMessageSize, outputMessageFile);
    fclose(outputMessageFile);

    // Free the allocated memory
    free(inputImage);
    free(inputMessage);
    free(outputMessage);

    return 0;
}