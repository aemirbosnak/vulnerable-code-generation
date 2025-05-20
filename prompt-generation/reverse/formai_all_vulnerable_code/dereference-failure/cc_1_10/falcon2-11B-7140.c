//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Function to hide a message in an image
void hideMessage(char* imageName, char* secretMessage)
{
    FILE* inFile = fopen(imageName, "r");
    if (!inFile)
    {
        printf("Error opening file.\n");
        return;
    }

    FILE* outFile = fopen("stego.png", "w");
    if (!outFile)
    {
        printf("Error creating output file.\n");
        fclose(inFile);
        return;
    }

    int size;
    unsigned char* inBuffer = malloc(512);
    unsigned char* outBuffer = malloc(512);
    unsigned char* secretBuffer = malloc(512);
    char* ch;

    fread(inBuffer, 512, 1, inFile);
    size = strlen(secretMessage);

    for (int i = 0; i < size; i++)
    {
        ch = secretMessage[i];

        for (int j = 0; j < 8; j++)
        {
            if (isdigit(ch))
            {
                secretBuffer[i * 8 + j] = 0x41 + ch - '0';
            }
            else if (isalpha(ch))
            {
                secretBuffer[i * 8 + j] = 0x61 + ch - 'A';
            }
            else
            {
                secretBuffer[i * 8 + j] = 0x41 + ch - '0';
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            outBuffer[i * 8 + j] = inBuffer[i * 8 + j] ^ secretBuffer[i * 8 + j];
        }
    }

    fwrite(outBuffer, 512, 1, outFile);
    fclose(inFile);
    fclose(outFile);
    free(inBuffer);
    free(outBuffer);
    free(secretBuffer);
}

// Function to restore the original image
void restoreImage(char* imageName)
{
    FILE* inFile = fopen(imageName, "r");
    if (!inFile)
    {
        printf("Error opening file.\n");
        return;
    }

    FILE* outFile = fopen("image.png", "w");
    if (!outFile)
    {
        printf("Error creating output file.\n");
        fclose(inFile);
        return;
    }

    int size;
    unsigned char* inBuffer = malloc(512);
    unsigned char* outBuffer = malloc(512);
    char* ch;

    fread(inBuffer, 512, 1, inFile);
    size = strlen(inBuffer);

    for (int i = 0; i < size; i++)
    {
        ch = inBuffer[i];

        for (int j = 0; j < 8; j++)
        {
            if (isdigit(ch))
            {
                ch = 0x41 + ch - '0';
            }
            else if (isalpha(ch))
            {
                ch = 0x61 + ch - 'A';
            }
            else
            {
                ch = 0x41 + ch - '0';
            }
        }

        outBuffer[i] = ch;
    }

    fwrite(outBuffer, 512, 1, outFile);
    fclose(inFile);
    fclose(outFile);
    free(inBuffer);
    free(outBuffer);
}

int main()
{
    char* imageName = "image.png";
    char* secretMessage = "This is a secret message.";
    hideMessage(imageName, secretMessage);
    restoreImage(imageName);
    return 0;
}