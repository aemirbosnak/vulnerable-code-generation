//FormAI DATASET v1.0 Category: Image Steganography ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to set a bit at position 'pos' in 'num'
void setBit(char *num, int pos, int bit) {
    int byteIndex = pos / 8;
    int bitIndex = pos % 8;
    if (bit) {
        num[byteIndex] |= (1 << bitIndex);
    } else {
        num[byteIndex] &= ~(1 << bitIndex);
    }
}

// Function to get a bit at position 'pos' in 'num'
int getBit(char *num, int pos) {
    int byteIndex = pos / 8;
    int bitIndex = pos % 8;
    return ((num[byteIndex] & (1 << bitIndex)) != 0);
}

// Function to hide a message in an image
void hideMessage(char *imageData, int imageSize, char *message, int messageLength) {
    if (messageLength > imageSize / 8) {
        printf("Message is too large to be hidden in the image\n");
        return;
    }

    // Loop through each bit of the hidden message
    for (int i = 0; i < messageLength * 8; i++) {
        int messageBit = getBit(message, i);
        // Set the corresponding bit in the image data
        setBit(imageData, i, messageBit);
    }
}

// Function to extract a message from an image
void extractMessage(char *imageData, int imageSize, int messageLength) {
    char *message = malloc(messageLength);
    if (message == NULL) {
        printf("Memory allocation error\n");
        return;
    }

    // Loop through each bit of the hidden message
    for (int i = 0; i < messageLength * 8; i++) {
        int messageBit = getBit(imageData, i);
        // Set the corresponding bit in the message
        setBit(message, i, messageBit);
    }

    printf("Extracted message: %s\n", message);
    free(message);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: program <image_file> <message_file>\n");
        return 1;
    }

    char *imageFile = argv[1];
    char *messageFile = argv[2];

    FILE *image = fopen(imageFile, "rb");
    if (image == NULL) {
        printf("Error opening image file\n");
        return 1;
    }

    fseek(image, 0L, SEEK_END);
    int imageSize = ftell(image);
    rewind(image);

    char *imageData = malloc(imageSize);
    if (imageData == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    int read = fread(imageData, 1, imageSize, image);
    if (read != imageSize) {
        printf("Error reading image file\n");
        return 1;
    }

    fclose(image);

    FILE *message = fopen(messageFile, "rb");
    if (message == NULL) {
        printf("Error opening message file\n");
        return 1;
    }

    fseek(message, 0L, SEEK_END);
    int messageLength = ftell(message);
    rewind(message);

    char *messageData = malloc(messageLength);
    if (messageData == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    read = fread(messageData, 1, messageLength, message);
    if (read != messageLength) {
        printf("Error reading message file\n");
        return 1;
    }

    fclose(message);

    hideMessage(imageData, imageSize, messageData, messageLength);

    char *outputFile = malloc(strlen(imageFile) + 5);
    strcpy(outputFile, imageFile);
    strcat(outputFile, ".out");

    FILE *output = fopen(outputFile, "wb");
    if (output == NULL) {
        printf("Error writing output file\n");
        return 1;
    }

    fwrite(imageData, 1, imageSize, output);
    fclose(output);

    printf("Message hidden successfully\n");

    extractMessage(imageData, imageSize, messageLength);

    free(imageData);
    free(messageData);
    free(outputFile);

    return 0;
}