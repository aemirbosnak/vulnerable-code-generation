//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITSPERBYTE 8

unsigned char *bitmapData = NULL;
int bitmapWidth = 0, bitmapHeight = 0;

int ReadBitmapFile(char *filename)
{
    FILE *bitmapFile = fopen(filename, "rb");
    if (bitmapFile == NULL)
    {
        perror("Error opening bitmap file");
        return -1;
    }

    // Read the bitmap header
    unsigned char header[54];
    if (fread(header, sizeof(char), 54, bitmapFile) != 54)
    {
        perror("Error reading bitmap header");
        fclose(bitmapFile);
        return -1;
    }

    // Check if the bitmap is valid
    if (header[0] != 'B' || header[1] != 'M')
    {
        fprintf(stderr, "Error: Invalid bitmap file\n");
        fclose(bitmapFile);
        return -1;
    }

    // Get the bitmap width and height
    bitmapWidth = *(int *)&header[18];
    bitmapHeight = *(int *)&header[22];

    // Allocate memory for the bitmap data
    bitmapData = (unsigned char *)malloc(bitmapWidth * bitmapHeight * 3);
    if (bitmapData == NULL)
    {
        perror("Error allocating memory for bitmap data");
        fclose(bitmapFile);
        return -1;
    }

    // Read the bitmap data
    if (fread(bitmapData, sizeof(char), bitmapWidth * bitmapHeight * 3, bitmapFile) != bitmapWidth * bitmapHeight * 3)
    {
        perror("Error reading bitmap data");
        fclose(bitmapFile);
        free(bitmapData);
        return -1;
    }

    fclose(bitmapFile);
    return 0;
}

int WriteBitmapFile(char *filename)
{
    FILE *bitmapFile = fopen(filename, "wb");
    if (bitmapFile == NULL)
    {
        perror("Error opening bitmap file");
        return -1;
    }

    // Write the bitmap header
    unsigned char header[54];
    memcpy(header, "BM", 2);
    *(int *)&header[2] = sizeof(header) + bitmapWidth * bitmapHeight * 3;
    *(int *)&header[10] = sizeof(header);
    *(int *)&header[18] = bitmapWidth;
    *(int *)&header[22] = bitmapHeight;
    *(short *)&header[28] = 1;
    *(short *)&header[30] = 24;
    if (fwrite(header, sizeof(char), 54, bitmapFile) != 54)
    {
        perror("Error writing bitmap header");
        fclose(bitmapFile);
        return -1;
    }

    // Write the bitmap data
    if (fwrite(bitmapData, sizeof(char), bitmapWidth * bitmapHeight * 3, bitmapFile) != bitmapWidth * bitmapHeight * 3)
    {
        perror("Error writing bitmap data");
        fclose(bitmapFile);
        return -1;
    }

    fclose(bitmapFile);
    return 0;
}

int HideMessageInBitmap(char *message, char *filename)
{
    // Read the bitmap file
    if (ReadBitmapFile(filename) != 0)
    {
        return -1;
    }

    // Convert the message to a binary string
    int messageLength = strlen(message);
    char *binaryMessage = (char *)malloc(messageLength * BITSPERBYTE);
    for (int i = 0; i < messageLength; i++)
    {
        for (int j = BITSPERBYTE - 1; j >= 0; j--)
        {
            binaryMessage[i * BITSPERBYTE + j] = (message[i] >> j) & 1;
        }
    }

    // Hide the binary message in the bitmap data
    int bitmapIndex = 0;
    for (int i = 0; i < messageLength * BITSPERBYTE; i++)
    {
        bitmapData[bitmapIndex] = (bitmapData[bitmapIndex] & ~1) | binaryMessage[i];
        bitmapIndex++;
        if (bitmapIndex >= bitmapWidth * bitmapHeight * 3)
        {
            break;
        }
    }

    // Write the modified bitmap file
    if (WriteBitmapFile(filename) != 0)
    {
        return -1;
    }

    return 0;
}

int ExtractMessageFromBitmap(char *filename)
{
    // Read the bitmap file
    if (ReadBitmapFile(filename) != 0)
    {
        return -1;
    }

    // Extract the binary message from the bitmap data
    int messageLength = 0;
    for (int bitmapIndex = 0;
         bitmapIndex < bitmapWidth * bitmapHeight * 3 && messageLength < 8 * bitmapWidth * bitmapHeight;
         bitmapIndex++)
    {
        if ((bitmapData[bitmapIndex] & 1) == 1)
        {
            messageLength++;
        }
    }

    char *binaryMessage = (char *)malloc(messageLength);
    for (int i = 0, bitmapIndex = 0;
         i < messageLength && bitmapIndex < bitmapWidth * bitmapHeight * 3;
         i++)
    {
        for (int j = BITSPERBYTE - 1; j >= 0; j--)
        {
            binaryMessage[i] |= ((bitmapData[bitmapIndex] & 1) << j);
            bitmapIndex++;
        }
    }

    // Convert the binary message to a text message
    char *message = (char *)malloc(messageLength / BITSPERBYTE + 1);
    for (int i = 0; i < messageLength / BITSPERBYTE; i++)
    {
        for (int j = 0; j < BITSPERBYTE; j++)
        {
            message[i] |= ((binaryMessage[i * BITSPERBYTE + j]) << j);
        }
    }
    message[messageLength / BITSPERBYTE] = '\0';

    printf("Extracted message: %s\n", message);

    free(message);
    free(binaryMessage);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        fprintf(stderr, "Usage: %s <hide/extract> <bitmap file> <message>\n", argv[0]);
        return -1;
    }

    if (strcmp(argv[1], "hide") == 0)
    {
        if (HideMessageInBitmap(argv[3], argv[2]) != 0)
        {
            fprintf(stderr, "Error hiding message in bitmap file\n");
            return -1;
        }
        printf("Message hidden in bitmap file\n");
    }
    else if (strcmp(argv[1], "extract") == 0)
    {
        if (ExtractMessageFromBitmap(argv[2]) != 0)
        {
            fprintf(stderr, "Error extracting message from bitmap file\n");
            return -1;
        }
    }
    else
    {
        fprintf(stderr, "Error: Invalid command\n");
        return -1;
    }

    return 0;
}