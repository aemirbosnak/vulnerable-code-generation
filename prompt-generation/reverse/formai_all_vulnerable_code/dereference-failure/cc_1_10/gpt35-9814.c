//FormAI DATASET v1.0 Category: Image Steganography ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define FILESIZE 8000
#define MAXMSGLEN 2000

typedef unsigned char byte;
typedef unsigned int uint;

void hideMessage(byte* image, const char* message);
char* extractMessage(byte* image, int imageSize);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <image file> <output file> <message>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Unable to open file: %s\n", argv[1]);
        return 1;
    }

    // Read the image into memory
    byte* image = (byte*)malloc(FILESIZE);
    int bytesRead = fread(image, sizeof(byte), FILESIZE, fp);
    fclose(fp);

    if (bytesRead != FILESIZE) {
        printf("Unable to read entire file into memory.\n");
        free(image);
        return 1;
    }

    // Hide the message in the image
    hideMessage(image, argv[3]);

    // Write the modified image data to the output file
    fp = fopen(argv[2], "wb");
    if (fp == NULL) {
        printf("Unable to open output file: %s\n", argv[2]);
        free(image);
        return 1;
    }
    fwrite(image, sizeof(byte), FILESIZE, fp);
    fclose(fp);

    // Extract the message from the modified image (for testing purposes)
    char* extractedMessage = extractMessage(image, FILESIZE);
    printf("Message extracted from image: %s\n", extractedMessage);
    free(extractedMessage);

    free(image);
    return 0;
}

void hideMessage(byte* image, const char* message) {
    // Calculate the maximum message length allowed (in bytes)
    int maxMessageLength = (FILESIZE / 8) - 4;
    if (maxMessageLength > MAXMSGLEN) {
        maxMessageLength = MAXMSGLEN;
    }

    // Make sure the message will be null-terminated
    char* temp = (char*)malloc(maxMessageLength + 1);
    int messageLength = snprintf(temp, maxMessageLength + 1, "%s", message);
    if (messageLength > maxMessageLength) {
        messageLength = maxMessageLength;
        temp[maxMessageLength] = '\0';
    }

    // Add the message length to the first four bytes of the image
    uint* lenPtr = (uint*)image;
    *lenPtr = (uint)messageLength;

    // Use a loop to change the least significant bit of each byte
    // in the image to the next bit of the message
    char* msgPtr = temp;
    byte* imgPtr = image + 4;
    byte imgByte = *imgPtr;
    int msgBitCount = 0;
    while (msgBitCount < (messageLength * 8)) {
        imgByte = (imgByte & 0xFE) | ((*msgPtr >> (msgBitCount % 8)) & 0x01);
        *imgPtr = imgByte;

        msgBitCount++;
        if ((msgBitCount % 8) == 0) {
            msgPtr++;
            imgPtr++;
            imgByte = *imgPtr;
        } else {
            imgByte >>= 1;
        }
    }

    free(temp);
}

char* extractMessage(byte* image, int imageSize) {
    // Get the message length from the first four bytes of the image
    uint* lenPtr = (uint*)image;
    int messageLength = (int)(*lenPtr);

    // Allocate memory for the message (plus one byte for the null terminator)
    char* message = (char*)malloc(messageLength + 1);
    char* msgPtr = message;

    // Use a loop to extract the message bits from the image
    byte* imgPtr = image + 4;
    byte imgByte = *imgPtr;
    int msgBitCount = 0;
    while (msgBitCount < (messageLength * 8)) {
        *msgPtr |= ((imgByte & 0x01) << (msgBitCount % 8));

        msgBitCount++;
        if ((msgBitCount % 8) == 0) {
            msgPtr++;
            imgPtr++;
            imgByte = *imgPtr;
        } else {
            imgByte >>= 1;
        }
    }
    *msgPtr = '\0';

    return message;
}