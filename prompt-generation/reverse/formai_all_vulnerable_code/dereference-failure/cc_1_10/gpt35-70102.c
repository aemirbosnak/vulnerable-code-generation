//FormAI DATASET v1.0 Category: Image Steganography ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_PIXEL 3

int getBit(unsigned char byte, int bitPosition) {
    return (byte & (1 << bitPosition)) != 0;
}

unsigned char setBit(unsigned char byte, int bitPosition, int value) {
    if(value == 0)
        return byte & ~(1 << bitPosition);
    else
        return byte | (1 << bitPosition);
}

void encodeImage(char* imageFileName, char* secretMessage, char* outputFileName) {
    FILE* imageFile = fopen(imageFileName, "rb");
    FILE* outputFile = fopen(outputFileName, "wb");

    if(imageFile == NULL) {
        printf("Error: Unable to open image file.\n");
        exit(0);
    }

    if(outputFile == NULL) {
        printf("Error: Unable to open output file.\n");
        exit(0);
    }

    unsigned char* imageData;
    unsigned char* messageData;
    unsigned long imageSize;
    unsigned long messageSize;

    // Get image data
    fseek(imageFile, 0, SEEK_END);
    imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);
    imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, imageSize, 1, imageFile);

    // Get message data
    messageSize = strlen(secretMessage) + 1;
    messageData = (unsigned char*)malloc(messageSize);
    strcpy((char*)messageData, secretMessage);

    // Check if secret message can fit in image
    if(imageSize < messageSize * BYTES_PER_PIXEL) {
        printf("Error: Secret message cannot fit in image.\n");
        exit(0);
    }

    // Encode message in image data
    int messageIndex = 0;
    for(int i = 0; i < imageSize; i += BYTES_PER_PIXEL) {
        for(int bitOffset = 0; bitOffset < 8; bitOffset++) {
            if(messageIndex >= messageSize)
                break;

            int bit = getBit(messageData[messageIndex], bitOffset);
            imageData[i] = setBit(imageData[i], bitOffset, bit);
            messageIndex++;
        }

        if(messageIndex >= messageSize)
            break;
    }

    // Write output file
    fwrite(imageData, imageSize, 1, outputFile);

    // Clean up
    fclose(imageFile);
    fclose(outputFile);
    free(imageData);
    free(messageData);

    printf("Message encoded successfully.\n");
}

void decodeImage(char* imageFileName, char* outputFileName) {
    FILE* imageFile = fopen(imageFileName, "rb");
    FILE* outputFile = fopen(outputFileName, "w");

    if(imageFile == NULL) {
        printf("Error: Unable to open image file.\n");
        exit(0);
    }

    if(outputFile == NULL) {
        printf("Error: Unable to open output file.\n");
        exit(0);
    }

    unsigned char* imageData;
    unsigned long imageSize;
    unsigned long messageSize = 0;

    // Get image data
    fseek(imageFile, 0, SEEK_END);
    imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);
    imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, imageSize, 1, imageFile);

    // Decode message from image data
    for(int i = 0; i < imageSize; i += BYTES_PER_PIXEL) {
        unsigned char messageByte = 0;
        for(int bitOffset = 0; bitOffset < 8; bitOffset++) {
            int bit = getBit(imageData[i], bitOffset);
            messageByte = setBit(messageByte, bitOffset, bit);
        }

        if(messageByte == '\0')
            break;

        messageSize++;
        fputc(messageByte, outputFile);
    }

    // Clean up
    fclose(imageFile);
    fclose(outputFile);
    free(imageData);

    if(messageSize == 0)
        printf("No message found in image.\n");
    else
        printf("Message decoded successfully.\n");
}

int main() {
    char imageFileName[] = "image.bmp";
    char secretMessage[] = "This is a secret message!";

    // Encode secret message in image
    char encodedFileName[] = "encoded.bmp";
    encodeImage(imageFileName, secretMessage, encodedFileName);

    // Decode secret message from image
    char decodedFileName[] = "decoded.txt";
    decodeImage(encodedFileName, decodedFileName);

    return 0;
}