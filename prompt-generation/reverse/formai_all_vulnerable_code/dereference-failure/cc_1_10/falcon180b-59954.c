//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IMAGE_SIZE 1000000 // Maximum size of image in bytes

// Function to read image file and store its contents in a buffer
void readImage(char* filename, unsigned char** buffer) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    rewind(fp);

    *buffer = (unsigned char*) malloc(filesize);
    fread(*buffer, 1, filesize, fp);
    fclose(fp);
}

// Function to write image data to a file
void writeImage(char* filename, unsigned char* data, int size) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fwrite(data, 1, size, fp);
    fclose(fp);
}

// Function to hide message in image using LSB steganography
void hideMessage(unsigned char* imageData, int imageSize, char* message, int messageSize) {
    int i, j;
    for (i = 0, j = 0; i < imageSize && j < messageSize; i += 4, j++) {
        int pixelValue = *(int*) (imageData + i);
        int messageByte = message[j];
        int bitPosition = 7;

        while (bitPosition >= 0) {
            int mask = 1 << bitPosition;
            if (messageByte & mask) {
                pixelValue |= 1;
            }
            bitPosition--;
        }

        *(int*) (imageData + i) = pixelValue;
    }
}

// Function to extract hidden message from image using LSB steganography
char* extractMessage(unsigned char* imageData, int imageSize) {
    int i, j;
    char* message = (char*) malloc(imageSize / 4);
    memset(message, 0, imageSize / 4);

    for (i = 0, j = 0; i < imageSize && j < imageSize / 4; i += 4, j++) {
        int pixelValue = *(int*) (imageData + i);
        int bitPosition = 7;

        while (bitPosition >= 0) {
            int mask = 1 << bitPosition;
            if (pixelValue & mask) {
                message[j] |= 1;
            }
            bitPosition--;
        }
    }

    return message;
}

int main() {
    char inputImageFilename[100];
    char outputImageFilename[100];
    char* message = NULL;
    int messageSize = 0;

    printf("Enter name of input image file: ");
    scanf("%s", inputImageFilename);

    printf("Enter name of output image file: ");
    scanf("%s", outputImageFilename);

    readImage(inputImageFilename, &message);
    messageSize = strlen(message);

    hideMessage(message, messageSize, "Secret message", strlen("Secret message"));

    writeImage(outputImageFilename, message, messageSize);

    printf("Message hidden in image successfully!\n");

    return 0;
}