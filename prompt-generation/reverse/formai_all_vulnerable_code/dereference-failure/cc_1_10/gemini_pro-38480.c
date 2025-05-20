//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Embed the secret message into the least significant bits of the image data
void embedMessage(unsigned char *imageData, unsigned char *secretMessage, int messageLength) {
    int i, j, k;
    for (i = 0, k = 0; i < messageLength; i++, k += 8) {
        for (j = 0; j < 8; j++) {
            imageData[k + j] = (imageData[k + j] & 0xFE) | ((secretMessage[i] >> j) & 0x01);
        }
    }
}

// Extract the secret message from the least significant bits of the image data
unsigned char *extractMessage(unsigned char *imageData, int messageLength) {
    int i, j, k;
    unsigned char *secretMessage = malloc(messageLength);
    for (i = 0, k = 0; i < messageLength; i++, k += 8) {
        for (j = 0; j < 8; j++) {
            secretMessage[i] |= (imageData[k + j] & 0x01) << j;
        }
    }
    return secretMessage;
}

int main() {
    // Load the image data from a file
    FILE *imageFile = fopen("image.bmp", "rb");
    if (imageFile == NULL) {
        perror("Error opening image file");
        return 1;
    }

    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile);
    rewind(imageFile);

    unsigned char *imageData = malloc(imageSize);
    fread(imageData, 1, imageSize, imageFile);
    fclose(imageFile);

    // Load the secret message from a file
    FILE *messageFile = fopen("message.txt", "rb");
    if (messageFile == NULL) {
        perror("Error opening message file");
        return 1;
    }

    fseek(messageFile, 0, SEEK_END);
    long messageLength = ftell(messageFile);
    rewind(messageFile);

    unsigned char *secretMessage = malloc(messageLength);
    fread(secretMessage, 1, messageLength, messageFile);
    fclose(messageFile);

    // Embed the secret message into the image data
    embedMessage(imageData, secretMessage, messageLength);

    // Save the modified image data to a new file
    FILE *outFile = fopen("output.bmp", "wb");
    if (outFile == NULL) {
        perror("Error opening output file");
        return 1;
    }

    fwrite(imageData, 1, imageSize, outFile);
    fclose(outFile);

    // Extract the secret message from the modified image data
    unsigned char *extractedMessage = extractMessage(imageData, messageLength);

    // Save the extracted secret message to a file
    FILE *outFile2 = fopen("extracted_message.txt", "wb");
    if (outFile2 == NULL) {
        perror("Error opening extracted message file");
        return 1;
    }

    fwrite(extractedMessage, 1, messageLength, outFile2);
    fclose(outFile2);

    free(imageData);
    free(secretMessage);
    return 0;
}