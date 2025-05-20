//FormAI DATASET v1.0 Category: Image Steganography ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READ_BIT(char, n) ((char >> n) & 0x01)
#define SET_BIT(char, n, bit) (char = (bit == 0 ? (char & ~(0x01 << n)) : (char | (0x01 << n))))

typedef unsigned char byte;

void hideDataInImage(char *imageFileName, char *message, char *outputFileName)
{
    FILE *imgFile = fopen(imageFileName, "rb");
    if(imgFile == NULL)
    {
        printf("Error: Unable to open file %s.\n", imageFileName);
        exit(1);
    }

    FILE *outFile = fopen(outputFileName, "wb");
    if(outFile == NULL)
    {
        printf("Error: Unable to create file %s.\n", outputFileName);
        exit(1);
    }

    byte buffer[8];
    memset(buffer, 0, sizeof(buffer));
    int bufferIndex = 0;

    byte tempChar = '\0';
    int messageIndex = 0;

    int fileSize = 0;
    fseek(imgFile, 0, SEEK_END);
    fileSize = ftell(imgFile);
    fseek(imgFile, 0, SEEK_SET);

    for(int i = 0; i < fileSize; i++)
    {
        byte pixelValue;
        fread(&pixelValue, sizeof(byte), 1, imgFile);

        if(message[messageIndex] != '\0')
        {
            for(int j = 0; j <= 7; j++)
            {
                if(message[messageIndex] != '\0')
                {
                    SET_BIT(tempChar, bufferIndex, READ_BIT(pixelValue, j));
                    bufferIndex++;

                    if(bufferIndex == 8)
                    {
                        bufferIndex = 0;
                        fwrite(&tempChar, sizeof(byte), 1, outFile);
                        tempChar = '\0';
                    }
                }
                else
                {
                    SET_BIT(tempChar, bufferIndex, rand() % 2);
                    bufferIndex++;

                    if(bufferIndex == 8)
                    {
                        bufferIndex = 0;
                        fwrite(&tempChar, sizeof(byte), 1, outFile);
                        tempChar = '\0';
                    }
                }
            }

            if(message[messageIndex] == '\0')
            {
                break;
            }

            messageIndex++;
        }
        else
        {
            fwrite(&pixelValue, sizeof(byte), 1, outFile);
        }
    }

    fclose(imgFile);
    fclose(outFile);
}

void retrieveDataFromImage(char *imageFileName, char *outputFileName)
{
    FILE *imgFile = fopen(imageFileName, "rb");
    if(imgFile == NULL)
    {
        printf("Error: Unable to open file %s.\n", imageFileName);
        exit(1);
    }

    FILE *outFile = fopen(outputFileName, "wb");
    if(outFile == NULL)
    {
        printf("Error: Unable to create file %s.\n", outputFileName);
        exit(1);
    }

    byte tempChar = '\0';
    int bufferIndex = 0;

    int fileSize = 0;
    fseek(imgFile, 0, SEEK_END);
    fileSize = ftell(imgFile);
    fseek(imgFile, 0, SEEK_SET);

    for(int i = 0; i < fileSize; i++)
    {
        byte pixelValue;
        fread(&pixelValue, sizeof(byte), 1, imgFile);

        for(int j = 0; j <= 7; j++)
        {
            SET_BIT(tempChar, bufferIndex, READ_BIT(pixelValue, j));
            bufferIndex++;

            if(bufferIndex == 8)
            {
                bufferIndex = 0;
                if(tempChar != '\0')
                {
                    fwrite(&tempChar, sizeof(byte), 1, outFile);
                    tempChar = '\0';
                }
                else
                {
                    fclose(imgFile);
                    fclose(outFile);
                    return;
                }
            }
        }
    }

    fclose(imgFile);
    fclose(outFile);
}

int main()
{
    char message[] = "This is a secret message.";
    char imageFileName[] = "bird.bmp";
    char outputFileName[] = "output.bmp";

    hideDataInImage(imageFileName, message, outputFileName);
    retrieveDataFromImage(outputFileName, "retrieved_message.txt");

    return 0;
}