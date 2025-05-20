//FormAI DATASET v1.0 Category: Image Steganography ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MSG_SIZE 100
#define MAX_FILENAME_SIZE 50

void readImage(char*, unsigned char*, int*);
void writeImage(char*, unsigned char*, int);
void hideMessage(unsigned char*, char*, unsigned char*);
void extractMessage(unsigned char*, char*);

int main()
{
    char sourceFilename[MAX_FILENAME_SIZE];
    char hiddenMsg[MAX_MSG_SIZE];
    char outputFilename[MAX_FILENAME_SIZE];

    printf("Enter the name of the source image file: ");
    fgets(sourceFilename, MAX_FILENAME_SIZE, stdin);

    printf("Enter the message to be hidden: ");
    fgets(hiddenMsg, MAX_MSG_SIZE, stdin);

    printf("Enter the name of the output image file: ");
    fgets(outputFilename, MAX_FILENAME_SIZE, stdin);

    int imageFileSize;
    unsigned char* imageFileData = malloc(sizeof(unsigned char) * 250000);

    readImage(sourceFilename, imageFileData, &imageFileSize);

    unsigned char* outputImageData = malloc(sizeof(unsigned char) * 250000);

    hideMessage(imageFileData, hiddenMsg, outputImageData);

    writeImage(outputFilename, outputImageData, imageFileSize);

    char extractedMsg[MAX_MSG_SIZE];
    extractMessage(outputImageData, extractedMsg);
    printf("Extracted Message: %s", extractedMsg);

    free(imageFileData);
    free(outputImageData);

    return 0;
}

void readImage(char* filename, unsigned char* fileData, int* fileSize)
{
    FILE* imageFile = fopen(filename, "rb");
    if (imageFile == NULL)
    {
        printf("Failed to open image file %s.", filename);
        exit(1);
    }

    fseek(imageFile, 0, SEEK_END);
    *fileSize = ftell(imageFile);
    rewind(imageFile);

    fread(fileData, sizeof(unsigned char), *fileSize, imageFile);

    fclose(imageFile);
}

void writeImage(char* filename, unsigned char* imageData, int fileSize)
{
    FILE* outputFile = fopen(filename, "wb");
    if (outputFile == NULL)
    {
        printf("Failed to create output file %s.", filename);
        exit(1);
    }

    fwrite(imageData, sizeof(unsigned char), fileSize, outputFile);

    fclose(outputFile);
}

void hideMessage(unsigned char* imageData, char* message, unsigned char* outputImageData)
{
    int imageDataIndex = 54;
    int outputImageDataIndex = 54;

    int messageLength = strlen(message);
    char messageLengthStr[9];
    sprintf(messageLengthStr, "%08d", messageLength);

    int i;
    for (i = 0; i < 8; i++)
    {
        unsigned char mask = 0x80;
        unsigned char val = (unsigned char)(messageLengthStr[i]);

        int j;
        for (j = 0; j < 8; j++)
        {
            unsigned char bit = (mask & val) ? 1 : 0;

            unsigned char imageDataByte = imageData[imageDataIndex];
            unsigned char newDataByte = imageDataByte & 0xFE;
            newDataByte |= bit;

            outputImageData[outputImageDataIndex] = newDataByte;

            imageDataIndex++;
            outputImageDataIndex++;
            mask = mask >> 1;
        }
    }

    int messageIndex;
    for (messageIndex = 0; messageIndex < messageLength; messageIndex++)
    {
        char messageChar = message[messageIndex];

        unsigned char mask = 0x80;
        unsigned char val = (unsigned char)(messageChar);

        int j;
        for (j = 0; j < 8; j++)
        {
            unsigned char bit = (mask & val) ? 1 : 0;

            unsigned char imageDataByte = imageData[imageDataIndex];
            unsigned char newDataByte = imageDataByte & 0xFE;
            newDataByte |= bit;

            outputImageData[outputImageDataIndex] = newDataByte;

            imageDataIndex++;
            outputImageDataIndex++;
            mask = mask >> 1;
        }
    }

    memcpy(outputImageData, imageData, 54);
}

void extractMessage(unsigned char* imageData, char* extractedMsg)
{
    int imageDataIndex = 54;

    char messageLengthStr[9];
    messageLengthStr[8] = '\0';

    int i;
    for (i = 0; i < 8; i++)
    {
        unsigned char mask = 0x01;
        unsigned char val = 0;
        int j;
        for (j = 0; j < 8; j++)
        {
            unsigned char imageDataByte = imageData[imageDataIndex];
            unsigned char lsb = imageDataByte & 0x01;
            val |= (lsb << (7 - j));
            imageDataIndex++;
        }
        messageLengthStr[i] = val;
    }

    int messageLength = atoi(messageLengthStr);

    int messageIndex;
    for (messageIndex = 0; messageIndex < messageLength; messageIndex++)
    {
        char messageChar = 0;

        unsigned char mask = 0x01;
        unsigned char val = 0;
        int j;
        for (j = 0; j < 8; j++)
        {
            unsigned char imageDataByte = imageData[imageDataIndex];
            unsigned char lsb = imageDataByte & 0x01;
            val |= (lsb << (7 - j));
            imageDataIndex++;
        }
        messageChar = (char)val;
        extractedMsg[messageIndex] = messageChar;
    }
    extractedMsg[messageLength] = '\0';
}