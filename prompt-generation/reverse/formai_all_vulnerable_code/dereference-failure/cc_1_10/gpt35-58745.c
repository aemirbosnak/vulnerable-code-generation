//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX_SIZE 1000000

int* decimalToBinary(int decimal, int noOfBits)
{
    int* binary = (int*) malloc(noOfBits * sizeof(int));
    int i;
    for(i=0;i<noOfBits;i++)
        binary[i] = 0;
    i=0;
    while(decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    return binary;
}

int binaryToDecimal(int* binary, int noOfBits)
{
    int decimal=0;
    int i;
    for(i=0;i<noOfBits;i++)
    {
        decimal += binary[i] * pow(2,i);
    }
    return decimal;
}

void printBits(int* bits, int noOfBits)
{
    int i;
    for(i=noOfBits-1;i>=0;i--)
        printf("%d",bits[i]);
}

void hideMessage(char* message, char* imageFileName, char* watermarkedImageFileName)
{
    FILE *imageFile;
    imageFile = fopen(imageFileName,"rb+");
    if(imageFile == NULL)
    {
        printf("\nError: Unable to open image file for reading!");
        return;
    }

    char imageHeader[54];
    int sizeOfHeader = 54;
    fread(imageHeader,sizeof(unsigned char),sizeOfHeader,imageFile);

    int imageSize = *((int*)(&imageHeader[2])) - sizeOfHeader;
    unsigned char imageBits[imageSize];
    fread(imageBits,sizeof(unsigned char),imageSize,imageFile);
    fclose(imageFile);

    FILE *watermarkedImageFile;
    watermarkedImageFile = fopen(watermarkedImageFileName,"wb+");
    if(watermarkedImageFile == NULL)
    {
        printf("\nError: Unable to open watermarked image file for writing!");
        return;
    }

    fwrite(imageHeader,sizeof(unsigned char),sizeOfHeader,watermarkedImageFile);

    int messageSize = strlen(message);
    int bitsNeededForMessageSize = log2(messageSize) + 1;
    int messageSizeBits[bitsNeededForMessageSize];
    int* tempBits = decimalToBinary(messageSize,bitsNeededForMessageSize);
    memcpy(messageSizeBits,tempBits,bitsNeededForMessageSize*sizeof(int));
    free(tempBits);

    int i,j;
    for(i=0;i<bitsNeededForMessageSize;i++)
    {
        fseek(watermarkedImageFile,sizeOfHeader + i*3,SEEK_SET);
        int imageByte = fgetc(watermarkedImageFile);
        int imageByteBits[8];
        tempBits = decimalToBinary(imageByte,8);
        memcpy(imageByteBits,tempBits,8*sizeof(int));
        free(tempBits);

        imageByteBits[0] = messageSizeBits[i];

        imageByte = binaryToDecimal(imageByteBits,8);
        fseek(watermarkedImageFile,-1,SEEK_CUR);
        fputc(imageByte,watermarkedImageFile);
    }

    int bitsNeededForMessage = bitsNeededForMessageSize*8;
    int messageBits[bitsNeededForMessage];
    tempBits = decimalToBinary((int)message[0],8);
    memcpy(messageBits,tempBits,8*sizeof(int));
    free(tempBits);
    for(i=1;i<messageSize;i++)
    {
        tempBits = decimalToBinary((int)message[i],8);
        memcpy(&messageBits[i*8],tempBits,8*sizeof(int));
        free(tempBits);
    }

    for(i=0;i<bitsNeededForMessage;i++)
    {
        fseek(watermarkedImageFile,sizeOfHeader + bitsNeededForMessageSize*3 + i*3,SEEK_SET);
        int imageByte = fgetc(watermarkedImageFile);
        int imageByteBits[8];
        tempBits = decimalToBinary(imageByte,8);
        memcpy(imageByteBits,tempBits,8*sizeof(int));
        free(tempBits);

        imageByteBits[0] = messageBits[i];

        imageByte = binaryToDecimal(imageByteBits,8);
        fseek(watermarkedImageFile,-1,SEEK_CUR);
        fputc(imageByte,watermarkedImageFile);
    }

    for(i=0;i<imageSize-bitsNeededForMessageSize*3-bitsNeededForMessage*3;i++)
    {
        fseek(watermarkedImageFile,sizeOfHeader + bitsNeededForMessageSize*3 + bitsNeededForMessage*3 + i,SEEK_SET);
        fputc(imageBits[i],watermarkedImageFile);
    }

    fclose(watermarkedImageFile);

    printf("\nMessage hidden successfully!\n");
}

void extractMessage(char* watermarkedImageFileName)
{
    FILE *watermarkedImageFile;
    watermarkedImageFile = fopen(watermarkedImageFileName,"rb+");
    if(watermarkedImageFile == NULL)
    {
        printf("\nError: Unable to open watermarked image file for reading!");
        return;
    }

    char imageHeader[54];
    int sizeOfHeader = 54;
    fread(imageHeader,sizeof(unsigned char),sizeOfHeader,watermarkedImageFile);

    int bitsNeededForMessageSize = 32/8;
    int messageSizeBits[bitsNeededForMessageSize];
    int i,j;
    for(i=0;i<bitsNeededForMessageSize;i++)
    {
        fseek(watermarkedImageFile,sizeOfHeader + i*3,SEEK_SET);
        int imageByte = fgetc(watermarkedImageFile);
        int imageByteBits[8];
        int* tempBits = decimalToBinary(imageByte,8);
        memcpy(imageByteBits,tempBits,8*sizeof(int));
        free(tempBits);

        messageSizeBits[i] = imageByteBits[0];
    }

    int messageSize = binaryToDecimal(messageSizeBits,32/8);
    char message[MAX_SIZE];
    memset(message,0,sizeof(message));

    int bitsNeededForMessage = messageSize*8;
    int messageBits[bitsNeededForMessage];
    for(i=0;i<bitsNeededForMessage;i++)
    {
        fseek(watermarkedImageFile,sizeOfHeader + bitsNeededForMessageSize*3 + i*3,SEEK_SET);
        int imageByte = fgetc(watermarkedImageFile);
        int imageByteBits[8];
        int* tempBits = decimalToBinary(imageByte,8);
        memcpy(imageByteBits,tempBits,8*sizeof(int));
        free(tempBits);

        messageBits[i] = imageByteBits[0];
    }

    int byteIndex=0;
    for(i=0;i<messageSize;i++)
    {
        int asciiDecimal = binaryToDecimal(&messageBits[i*8],8);
        message[byteIndex]=asciiDecimal;
        byteIndex++;
    }

    printf("\nExtracted message: %s\n",message);

    fclose(watermarkedImageFile);
}

int main()
{
    char message[] = "Hello World!";
    char imageFileName[] = "image.bmp";
    char watermarkedImageFileName[] = "watermarked_image.bmp";
    hideMessage(message,imageFileName,watermarkedImageFileName);
    extractMessage(watermarkedImageFileName);
    return 0;
}