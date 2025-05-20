//FormAI DATASET v1.0 Category: Image Steganography ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_PIXEL 3
#define HEADER_SIZE 54
#define MAX_FILE_SIZE 2097152 // 2MB

#define BIT0 1
#define BIT1 2
#define BIT2 4
#define BIT3 8
#define BIT4 16
#define BIT5 32
#define BIT6 64
#define BIT7 128

void writeImageData(FILE *imageFile, unsigned char *imageData, long imageFileSize)
{
    fseek(imageFile, HEADER_SIZE, SEEK_SET);
    fwrite(imageData, sizeof(unsigned char), imageFileSize, imageFile);
}

long readImageData(FILE *imageFile, unsigned char *imageData)
{
    fseek(imageFile, HEADER_SIZE, SEEK_SET);
    return fread(imageData, sizeof(unsigned char), MAX_FILE_SIZE, imageFile);
}

unsigned char getLeastSignificantBit(unsigned char byte)
{
    return byte & 0x1;
}

int main(int argc, char **argv)
{
    // Usage: stegano <source image> <message file> <output image>
    if (argc != 4)
    {
        printf("Usage: %s <source image> <message file> <output image>\n", argv[0]);
        return -1;
    }

    // Open source image
    FILE *sourceFile = fopen(argv[1], "rb");
    if (!sourceFile)
    {
        printf("Unable to open source image file %s\n", argv[1]);
        return -1;
    }

    // Open message file
    FILE *messageFile = fopen(argv[2], "rb");
    if (!messageFile)
    {
        printf("Unable to open message file %s\n", argv[2]);
        fclose(sourceFile);
        return -1;
    }

    // Read source image file header
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, sourceFile);

    // Read source image file size
    fseek(sourceFile, 0L, SEEK_END);
    long sourceFileSize = ftell(sourceFile);
    fseek(sourceFile, 0L, SEEK_SET);

    // Read source image data
    unsigned char *sourceData = calloc(sourceFileSize - HEADER_SIZE + 1, sizeof(unsigned char));
    long sourceDataSize = readImageData(sourceFile, sourceData);

    // Read message file size
    fseek(messageFile, 0L, SEEK_END);
    long messageFileSize = ftell(messageFile);
    fseek(messageFile, 0L, SEEK_SET);

    // Allocate memory for message data
    unsigned char *messageData = calloc(messageFileSize + 1, sizeof(unsigned char));

    // Read message data
    int bytesRead = fread(messageData, sizeof(unsigned char), messageFileSize, messageFile);
    messageData[bytesRead] = '\0';

    // Check message length
    if (strlen(messageData) * BYTES_PER_PIXEL > sourceDataSize)
    {
        printf("Message too long to hide in this image\n");
        fclose(sourceFile);
        fclose(messageFile);
        free(sourceData);
        free(messageData);
        return -1;
    }

    // Append null terminator to message
    strcat((char *) messageData, "\0");

    // Hide message data in source image data
    int i, j, bitCount, index = 0;

    for (i = 0; i < strlen(messageData); i++)
    {
        for (j = 0; j < BYTES_PER_PIXEL; j++)
        {
            bitCount = 0;

            while (bitCount < 8)
            {
                if (index >= sourceDataSize)
                {
                    break;
                }

                unsigned char byte = sourceData[index];
                unsigned char bit = getLeastSignificantBit(byte);

                switch (bitCount)
                {
                    case 0:
                        byte = (messageData[i] & BIT0) ? byte | BIT0 : byte & ~BIT0;
                        break;

                    case 1:
                        byte = (messageData[i] & BIT1) ? byte | BIT0 : byte & ~BIT0;
                        break;

                    case 2:
                        byte = (messageData[i] & BIT2) ? byte | BIT0 : byte & ~BIT0;
                        break;

                    case 3:
                        byte = (messageData[i] & BIT3) ? byte | BIT0 : byte & ~BIT0;
                        break;

                    case 4:
                        byte = (messageData[i] & BIT4) ? byte | BIT0 : byte & ~BIT0;
                        break;

                    case 5:
                        byte = (messageData[i] & BIT5) ? byte | BIT0 : byte & ~BIT0;
                        break;

                    case 6:
                        byte = (messageData[i] & BIT6) ? byte | BIT0 : byte & ~BIT0;
                        break;

                    case 7:
                        byte = (messageData[i] & BIT7) ? byte | BIT0 : byte & ~BIT0;
                        break;
                }

                sourceData[index] = byte;
                index++;
                bitCount++;
            }
        }
    }

    // Open destination file
    FILE *destFile = fopen(argv[3], "wb");
    if (!destFile)
    {
        printf("Unable to open output file %s\n", argv[3]);
        fclose(sourceFile);
        fclose(messageFile);
        free(sourceData);
        free(messageData);
        return -1;
    }

    // Write header to destination file
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, destFile);

    // Write image data to destination file
    writeImageData(destFile, sourceData, sourceDataSize);

    // Clean up
    fclose(sourceFile);
    fclose(messageFile);
    fclose(destFile);
    free(sourceData);
    free(messageData);

    printf("Message hidden successfully!\n");

    return 0;
}