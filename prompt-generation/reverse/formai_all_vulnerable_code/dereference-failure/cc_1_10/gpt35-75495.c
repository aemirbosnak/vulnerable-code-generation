//FormAI DATASET v1.0 Category: Image Steganography ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the length of binary representation of a number
int binaryLength(int num) {
    int len = 0;
    while (num > 0) {
        len++;
        num /= 2;
    }
    return len;
}

// Function to extract a particular bit from a given byte
int extractBit(unsigned char c, int pos) {
    return ((c & (1 << pos)) != 0);
}

// Function to write a bit to a particular position in a given byte
void writeBit(unsigned char *c, int bit, int pos) {
    if (bit) {
        *c |= (1 << pos);
    } else {
        *c &= ~(1 << pos);
    }
}

// Function to hide a message in an image using steganography
void embedMessage(char *message, unsigned char *image, int imageSize) {
    int messageLength = strlen(message);
    int requiredBits = binaryLength(messageLength);

    if ((requiredBits + 1) * 8 > imageSize) {
        printf("Error: Image size not sufficient to hold message.\n");
        exit(1);
    }

    // Embed message length as the first 8 bytes in the image
    for (int i = 0; i < 8; i++) {
        writeBit(&image[i], extractBit(messageLength, i), 0);
    }

    // Embed message bits in subsequent bytes of the image
    int imagePos = 8;
    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            writeBit(&image[imagePos], extractBit(message[i], j), requiredBits - j);
            imagePos++;
        }
    }
}

// Function to extract a message from an image using steganography
void extractMessage(unsigned char *image, int imageSize) {
    int messageLength = 0;

    // Extract message length from first 8 bytes of the image
    for (int i = 0; i < 8; i++) {
        messageLength |= (extractBit(image[i], 0) << i);
    }

    // Extract message bits from remaining bytes of the image
    char *message = (char *) malloc((messageLength + 1) * sizeof(char));
    int messagePos = 0;
    int imagePos = 8;
    for (int i = 0; i < messageLength; i++) {
        int currentChar = 0;
        for (int j = 0; j < 8; j++) {
            currentChar |= (extractBit(image[imagePos], j) << (7 - j));
            imagePos++;
        }
        message[messagePos] = (char) currentChar;
        messagePos++;
    }
    message[messageLength] = '\0';

    printf("Extracted message: %s\n", message);
}

int main() {
    // Open the image file and read its contents into an array
    FILE *imageFile = fopen("retroImage.bmp", "rb");
    if (!imageFile) {
        printf("Error: Image file not found.\n");
        exit(1);
    }

    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    rewind(imageFile);

    unsigned char *image = (unsigned char *) malloc(imageSize * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), imageSize, imageFile);

    // Hide a message in the image
    char *message = "Hello, world!";
    printf("Embedding message: %s\n", message);
    embedMessage(message, image, imageSize);

    // Extract the message from the image
    extractMessage(image, imageSize);

    free(image);
    fclose(imageFile);

    return 0;
}