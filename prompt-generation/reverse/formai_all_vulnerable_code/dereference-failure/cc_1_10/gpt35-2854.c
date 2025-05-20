//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns number of bits required to represent num.
int bitCount(int num)
{
    int count = 0;
    while(num)
    {
        count++;
        num >>= 1;
    }
    return count;
}

 // Adds a bit to given num at given position.
void addBit(int *num, int bit, int pos)
{
    int mask = 1 << pos;
    if(bit)
        *num |= mask;
    else
        *num &= ~mask;
}

// Retrieves a bit at given position in given num.
int getBit(int num, int pos)
{
    int mask = 1 << pos;
    return (num & mask) != 0;
}

// Embeds watermark into given image.
void embedWatermark(unsigned char *image, const char *watermark)
{
    int wmLen = strlen(watermark);
    int wmBits = wmLen * 8;
    int imgOffset = 0;

    while(wmBits--)
    {
        int byteIndex = imgOffset / 8;
        int bitIndex = imgOffset % 8;

        int currByte = image[byteIndex];
        int currBit = getBit(currByte, bitIndex);

        int wmByte = watermark[wmBits/8];
        int wmBit = getBit(wmByte, wmBits%8);

        if(currBit != wmBit)
        {
            addBit(&currByte, wmBit, bitIndex);
            image[byteIndex] = currByte;
        }

        imgOffset++;
    }
}

// Retrieves watermark from given image.
void retrieveWatermark(unsigned char *image, int imgSize, char *watermarkBuffer, int wmLen)
{
    int wmBits = wmLen * 8;
    int imgOffset = 0;

    for(int i=0; i<wmBits; i++)
    {
        int byteIndex = imgOffset / 8;
        int bitIndex = imgOffset % 8;

        int currByte = image[byteIndex];
        int currBit = getBit(currByte, bitIndex);

        int wmByte = watermarkBuffer[i/8];
        int wmBit = getBit(wmByte, i%8);

        addBit(&wmByte, currBit, i%8);
        watermarkBuffer[i/8] = wmByte;

        imgOffset++;
    }

    watermarkBuffer[wmLen] = '\0';
}

int main()
{
    // Read image data.
    unsigned char imageData[] = {0x38, 0x4F, 0xBB, 0xC4, 0x40, 0x7C, 0x1C, 0x52, 0x4A, 0xC7, 0x4E, 0x55};
    int imgSize = sizeof(imageData) / sizeof(imageData[0]);

    // Embed watermark into image.
    const char *watermark = "This is a test watermark.";
    embedWatermark(imageData, watermark);

    // Retrieve watermark from image.
    char watermarkBuffer[strlen(watermark) + 1];
    retrieveWatermark(imageData, imgSize, watermarkBuffer, strlen(watermark));

    // Print original and retrieved watermarks.
    printf("Original watermark: %s\n", watermark);
    printf("Retrieved watermark: %s\n", watermarkBuffer);

    return 0;
}