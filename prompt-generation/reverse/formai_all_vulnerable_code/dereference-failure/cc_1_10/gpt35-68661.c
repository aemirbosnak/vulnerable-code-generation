//FormAI DATASET v1.0 Category: Image Steganography ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define FILE_HEADER_SIZE 14
#define INFO_HEADER_SIZE 40
#define BYTE_SIZE 8

unsigned char *readBMPFile(char *filename, int *size) {
    FILE *file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    rewind(file);

    unsigned char *fileData = (unsigned char *) malloc((*size) * sizeof(unsigned char));
    fread(fileData, sizeof(unsigned char), *size, file);
    fclose(file);

    return fileData;
}

void hideMessage(unsigned char *imageData, int imageSize, char *message, int messageLength) {
    int bitIndex = 0;
    for (int i = FILE_HEADER_SIZE + INFO_HEADER_SIZE; i < imageSize && bitIndex < messageLength * BYTE_SIZE; i++) {
        for (int j = 0; j < BYTE_SIZE; j++) {
            if (bitIndex < messageLength * BYTE_SIZE) {
                int messageBit = (message[bitIndex / BYTE_SIZE] >> (BYTE_SIZE - 1 - (bitIndex % BYTE_SIZE))) & 1;
                imageData[i] = (imageData[i] & ~1) | messageBit;
                bitIndex++;
            } else {
                break;
            }
        }
    }
}

char *extractMessage(unsigned char *imageData, int imageSize, int messageLength) {
    char *message = (char *) malloc((messageLength + 1) * sizeof(char));
    int bitIndex = 0;
    for (int i = FILE_HEADER_SIZE + INFO_HEADER_SIZE; i < imageSize && bitIndex < messageLength * BYTE_SIZE; i++) {
        for (int j = 0; j < BYTE_SIZE; j++) {
            if (bitIndex < messageLength * BYTE_SIZE) {
                int messageBit = (imageData[i] >> (BYTE_SIZE - 1 - j)) & 1;
                message[bitIndex / BYTE_SIZE] |= messageBit << (BYTE_SIZE - 1 - (bitIndex % BYTE_SIZE));
                bitIndex++;
            } else {
                break;
            }
        }
    }
    message[messageLength] = '\0';
    return message;
}

int main() {
    int fileSize;
    unsigned char *imageData = readBMPFile("image.bmp", &fileSize);
    printf("Image size is %d bytes\n", fileSize);

    char message[] = "This is a secret message hidden in the image";

    int messageLength = sizeof(message) / sizeof(char) - 1;
    printf("The message to hide is \"%s\"\n", message);

    hideMessage(imageData, fileSize, message, messageLength);

    char *extractedMessage = extractMessage(imageData, fileSize, messageLength);
    printf("The extracted message is \"%s\"\n", extractedMessage);

    free(imageData);
    free(extractedMessage);

    return 0;
}