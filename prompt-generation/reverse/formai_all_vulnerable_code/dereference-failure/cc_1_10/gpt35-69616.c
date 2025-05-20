//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Donald Knuth
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#define WATERMARK_LENGTH 16

// Function to convert integer to binary string
void intToBinaryString(int integer, char *binaryString, int numOfBits)
{
    for(int i = numOfBits-1; i >= 0; i--)
    {
        binaryString[i] = (integer%2 == 0) ? '0' : '1';
        integer /= 2;
    }
}

// Function to convert binary string to integer
int binaryStringToInt(char *binaryString, int numOfBits)
{
    int integer = 0;
    for(int i = 0; i < numOfBits; i++)
        integer += (binaryString[i]-'0')*pow(2,numOfBits-i-1);
    return integer;
}

// Function to create digital watermark from input message
void createDigitalWatermark(char *inputMessage, char *watermark)
{
    int messageLength = strlen(inputMessage);
    int numOfBits = (int)ceil(log2(messageLength));
    int watermarkIndex = 0;
    char binaryString[numOfBits];

    for(int i = 0; i < messageLength; i++)
    {
        intToBinaryString(inputMessage[i], binaryString, 8);

        for(int j = 0; j < 8; j++)
        {
            watermark[watermarkIndex] = binaryString[j];
            watermarkIndex++;
            if(watermarkIndex == WATERMARK_LENGTH)
                break;
        }

        if(watermarkIndex == WATERMARK_LENGTH)
            break;
    }

    while(watermarkIndex < WATERMARK_LENGTH)
    {
        intToBinaryString(rand()%256, binaryString, 8);
        for(int j = 0; j < 8; j++)
        {
            watermark[watermarkIndex] = binaryString[j];
            watermarkIndex++;
            if(watermarkIndex == WATERMARK_LENGTH)
                break;
        }
    }
}

// Function to extract input message from digital watermark and print it
void extractAndPrintMessageFromWatermark(char *watermark)
{
    char binaryString[8];
    int integer;
    int messageLength = 0;

    for(int i = 0; i < WATERMARK_LENGTH; i+=8)
    {
        for(int j = 0; j < 8; j++)
            binaryString[j] = watermark[i+j];
        integer = binaryStringToInt(binaryString, 8);
        if(integer == 0)
            break;
        printf("%c", integer);
        messageLength++;
    }

    printf("\nMessage Length: %d\n", messageLength);
}

int main()
{
    // Test watermark creation and extraction
    char inputMessage[] = "Hello, world!";
    char watermark[WATERMARK_LENGTH];

    createDigitalWatermark(inputMessage, watermark);

    printf("Watermark: ");
    for(int i = 0; i < WATERMARK_LENGTH; i++)
        printf("%c",watermark[i]);

    printf("\n");

    extractAndPrintMessageFromWatermark(watermark);

    return 0;
}