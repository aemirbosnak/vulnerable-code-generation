//FormAI DATASET v1.0 Category: Image Steganography ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_PIXEL 3

// Image header structure
typedef struct {
    unsigned char signature[2];
    unsigned int fileSize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int dataOffset;
    unsigned int headerSize;
    unsigned int imageWidth;
    unsigned int imageHeight;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compressionMethod;
    unsigned int imageSize;
    unsigned int horizontalResolution;
    unsigned int verticalResolution;
    unsigned int colorsUsed;
    unsigned int importantColors;
} ImageHeader;

// Function to get binary string of character
char *getBinaryString(char ch)
{
    char *binary = (char*)malloc(sizeof(char) * 9);
    int index = 0;
    while(ch != 0) {
        binary[index++] = (ch % 2) + '0';
        ch = ch / 2;
    }
    while(index < 8) {
        binary[index++] = '0';
    }
    binary[index--] = '\0';
    char temp;
    for(int i=0; i<index; i++, index--) {
        temp = binary[i], binary[i] = binary[index], binary[index] = temp;
    }
    return binary;
}

// Function to read an image from file
unsigned char *readImage(char *fileName, ImageHeader *header)
{
    FILE *imageFile;
    if((imageFile = fopen(fileName, "rb")) == NULL) {
        printf("Error: could not open file \"%s\"\n", fileName);
        exit(EXIT_FAILURE);
    }

    if(fread(header, sizeof(ImageHeader), 1, imageFile) != 1) {
        printf("Error reading image header.\n");
        exit(EXIT_FAILURE);
    }

    if(header->signature[0] != 'B' || header->signature[1] != 'M') {
        printf("Error: \"%s\" is not a bitmap file\n", fileName);
        exit(EXIT_FAILURE);
    }

    unsigned char *imageData = (unsigned char*)malloc(sizeof(unsigned char) * header->imageSize);
    if(fread(imageData, sizeof(unsigned char), header->imageSize, imageFile) != header->imageSize) {
        printf("Error: Not enough memory available to store \"%s\" image data\n", fileName);
        exit(EXIT_FAILURE);
    }

    if(fclose(imageFile) != 0) {
        printf("Error closing \"%s\"\n", fileName);
    }

    return imageData;
}

// Function to write an image to file
void writeImage(char *fileName, ImageHeader header, unsigned char *imageData)
{
    FILE *outputFile;
    if((outputFile = fopen(fileName, "wb")) == NULL) {
        printf("Error: could not open file \"%s\"\n", fileName);
        exit(EXIT_FAILURE);
    }

    if(fwrite(&header, sizeof(ImageHeader), 1, outputFile) != 1) {
        printf("Error writing image header.\n");
        exit(EXIT_FAILURE);
    }

    if(fwrite(imageData, sizeof(unsigned char), header.imageSize, outputFile) != header.imageSize) {
        printf("Error writing image data.\n");
        exit(EXIT_FAILURE);
    }

    if(fclose(outputFile) != 0) {
        printf("Error closing \"%s\"\n", fileName);
    }
}

// Function to hide a message in image
void hideMessage(char *inputFileName, char *outputFileName, char *message)
{
    ImageHeader header;
    unsigned char * imageData = readImage(inputFileName, &header);

    int messageLength = strlen(message);
    char *binaryMessage = (char*)malloc(messageLength * BYTES_PER_PIXEL * 8 + 9);
    int binaryIndex = 0;
    for(int i=0; i<messageLength; i++) {
        char *binary = getBinaryString(message[i]);
        for(int j=0; j<BYTES_PER_PIXEL * 8; j++) {
            binaryMessage[binaryIndex++] = binary[j];
        }
        free(binary);
    }
    for(int i=0; i<8; i++) {
        binaryMessage[binaryIndex++] = '0';
    }
    int binaryMessageIndex = 0;
    for(int i=header.dataOffset; i<header.imageSize; i += BYTES_PER_PIXEL, binaryMessageIndex += 3) {
        if(binaryMessageIndex >= binaryIndex) {
            break;
        }
        for(int j=0; j<BYTES_PER_PIXEL; j++) {
            imageData[i+j] &= 0xFE;
            imageData[i+j] |= binaryMessage[binaryMessageIndex+j] - '0';
        }
    }

    free(binaryMessage);
    writeImage(outputFileName, header, imageData);
    free(imageData);
}

// Function to extract a message from image
char *extractMessage(char *inputFileName)
{
    ImageHeader header;
    unsigned char * imageData = readImage(inputFileName, &header);

    int binaryMessageIndex = 0;
    char *binaryMessage = (char*)malloc(sizeof(char) * 8 * header.imageSize);
    for(int i=header.dataOffset; i<header.imageSize; i += BYTES_PER_PIXEL) {
        if(binaryMessageIndex >= 8 * (int)strlen("Hello, World!") * BYTES_PER_PIXEL) {
            break;
        }
        for(int j=0; j<BYTES_PER_PIXEL; j++) {
            binaryMessage[binaryMessageIndex++] = (imageData[i+j] & 1) + '0';
        }
    }

    int messageLength = binaryMessageIndex / (BYTES_PER_PIXEL * 8);
    char *message = (char*)malloc(sizeof(char) * (messageLength+1));
    binaryMessageIndex = 0;
    for(int i=0; i<messageLength; i++) {
        char ch = 0;
        for(int j=0; j<8; j++) {
            ch = ch * 2 + (binaryMessage[binaryMessageIndex++] - '0');
        }
        message[i] = ch;
    }
    message[messageLength] = '\0';

    free(binaryMessage);
    free(imageData);
    return message;
}

// Main function
int main()
{
    char *inputFileName = "image.bmp";
    char *outputFileName = "stego.bmp";
    char *message = "Hello, World!";

    hideMessage(inputFileName, outputFileName, message);

    char *extractedMessage = extractMessage(outputFileName);
    printf("Extracted Message: %s\n", extractedMessage);
    free(extractedMessage);

    return 0;
}