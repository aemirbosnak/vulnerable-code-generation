//FormAI DATASET v1.0 Category: Image Steganography ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IMAGE_SIZE 10000

typedef unsigned char ubyte;

int main()
{
    FILE *imgFile, *secretFile, *stegFile;
    char imgFileName[50], secretFileName[50], stegFileName[50], stegMessage[10000], ch;
    ubyte imgData[MAX_IMAGE_SIZE];
    int i, j, fileSize, key = 0;

    printf("\nEnter the name of the image file: ");
    scanf("%s", imgFileName);

    printf("\nEnter the name of the secret file: ");
    scanf("%s", secretFileName);

    printf("\nEnter the name of the steganography file to be created: ");
    scanf("%s", stegFileName);

    imgFile = fopen(imgFileName, "rb");
    secretFile = fopen(secretFileName, "rb");

    fseek(secretFile, 0L, SEEK_END);
    fileSize = ftell(secretFile);
    rewind(secretFile);

    printf("\nSecret file size: %d bytes", fileSize);

    if(fileSize > MAX_IMAGE_SIZE * 3 / 8)
    {
        printf("\nCannot hide secret file within the image. Choose a larger image!\n");
        exit(0);
    }

    fread(imgData, sizeof(ubyte), MAX_IMAGE_SIZE, imgFile);

    for(i = 0; i < fileSize; i++)
    {
        ch = fgetc(secretFile);
        for(j = 0; j < 8; j++)
        {
            if(ch & (1 << j))
            {
                imgData[key] = (imgData[key] | 1);
            }
            else
            {
                imgData[key] = (imgData[key] & ~1);
            }
            key++;
        }
    }

    fclose(secretFile);
    stegFile = fopen(stegFileName, "wb");

    fwrite(imgData, sizeof(ubyte), MAX_IMAGE_SIZE, stegFile);

    fclose(imgFile);
    fclose(stegFile);

    printf("\nSteganography completed successfully!\n");

    return 0;
}