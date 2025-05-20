//FormAI DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1000
#define MAX_MSG_SIZE 200

// Function to read image data from input file
void readImageData(FILE* inputFile, int* width, int* height, int* colordepth, unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][3]);

// Function to write image data to output file
void writeImageData(FILE* outputFile, int width, int height, int colordepth, unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][3]);

// Function to convert decimal to binary
void decimalToBinary(int decimal, int binary[]);

// Function to convert binary to decimal
int binaryToDecimal(int binary[]);

// Function to hide message in an image
void encodeMessage(int width, int height, unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][3], char* message);

// Function to extract message from an image
void decodeMessage(int width, int height, unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][3], char* decodedMsg);

// Main function for image steganography
int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        fprintf(stderr, "Usage: ./steg <inputfile> <outputfile> <message>\n");
        exit(EXIT_FAILURE);
    }

    char* message = argv[3];
    FILE* inputFile = fopen(argv[1], "rb");
    FILE* outputFile = fopen(argv[2], "wb");

    int width, height, colordepth;
    unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][3];

    readImageData(inputFile, &width, &height, &colordepth, pixels);

    // hide message in the image
    encodeMessage(width, height, pixels, message);

    // write the modified image data to output file
    writeImageData(outputFile, width, height, colordepth, pixels);

    fclose(inputFile);
    fclose(outputFile);

    // check if message is hidden successfully
    char decodedMsg[MAX_MSG_SIZE];
    FILE* encodedImage = fopen(argv[2], "rb");

    readImageData(encodedImage, &width, &height, &colordepth, pixels);

    decodeMessage(width, height, pixels, decodedMsg);

    printf("Original Message: %s\n", message);
    printf("Decoded Message: %s\n", decodedMsg);

    fclose(encodedImage);

    return 0;
}

void readImageData(FILE* inputFile, int* width, int* height, int* colordepth, unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][3])
{
    char format[3];
    fscanf(inputFile, "%s\n", format);

    fscanf(inputFile, "%d %d\n", width, height);
    fscanf(inputFile, "%d\n", colordepth);

    for (int i = 0; i < *height; i++)
    {
        for (int j = 0; j < *width; j++)
        {
            fscanf(inputFile, "%hhu %hhu %hhu", &pixels[i][j][0], &pixels[i][j][1], &pixels[i][j][2]);
        }
    }
}

void writeImageData(FILE* outputFile, int width, int height, int colordepth, unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][3])
{
    fprintf(outputFile, "P3\n");
    fprintf(outputFile, "%d %d\n", width, height);
    fprintf(outputFile, "%d\n", colordepth);
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fprintf(outputFile, "%d %d %d ", pixels[i][j][0], pixels[i][j][1], pixels[i][j][2]);
        }
        fprintf(outputFile, "\n");
    }
}

void decimalToBinary(int decimal, int binary[])
{
    int i = 0;
    while (decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
}

int binaryToDecimal(int binary[])
{
    int decimal = 0;
    for (int i = 0; i < 8; i++)
    {
        decimal += binary[i] * pow(2, i);
    }
    return decimal;
}

void encodeMessage(int width, int height, unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][3], char* message)
{
    int binaryMsg[MAX_MSG_SIZE * 8];
    int len = strlen(message);

    // encode message length in the image
    int binaryLen[8];
    decimalToBinary(len, binaryLen);

    int k = 0;

    // hiding message length
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int binaryPixel[8];
            decimalToBinary(pixels[0][k][j], binaryPixel);
            binaryPixel[7] = binaryLen[i];
            pixels[0][k][j] = binaryToDecimal(binaryPixel);
            k++;
        }
    }

    // encoding message
    int i, j;
    for (int l = 0; l < len; l++)
    {
        decimalToBinary(message[l], &binaryMsg[l*8]);
    }

    for (int l = 0; l < len*8; l++)
    {
        i = (l*3 + k/3) / width;
        j = (l*3 + k/3) % width;

        if (k % 3 == 0)
        {
            int binaryPixel[8];
            decimalToBinary(pixels[i][j][0], binaryPixel);
            binaryPixel[7] = binaryMsg[l];
            pixels[i][j][0] = binaryToDecimal(binaryPixel);
        }
        else if (k % 3 == 1)
        {
            int binaryPixel[8];
            decimalToBinary(pixels[i][j][1], binaryPixel);
            binaryPixel[7] = binaryMsg[l];
            pixels[i][j][1] = binaryToDecimal(binaryPixel);
        }
        else if (k % 3 == 2)
        {
            int binaryPixel[8];
            decimalToBinary(pixels[i][j][2], binaryPixel);
            binaryPixel[7] = binaryMsg[l];
            pixels[i][j][2] = binaryToDecimal(binaryPixel);
        }

        k++;
    }
}

void decodeMessage(int width, int height, unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][3], char* decodedMsg)
{
    // decoding message length
    int binaryLen[8];
    int k = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int binaryPixel[8];
            decimalToBinary(pixels[0][k][j], binaryPixel);
            binaryLen[i] = binaryPixel[7];
            k++;
        }
    }

    int len = binaryToDecimal(binaryLen);

    // decoding message
    int binaryMsg[MAX_MSG_SIZE * 8];
    int i, j;
    k = 0;
    for (int l = 0; l < len*8; l++)
    {
        i = (l*3 + k/3) / width;
        j = (l*3 + k/3) % width;

        int binaryPixel[8];
        if (k % 3 == 0)
        {
            decimalToBinary(pixels[i][j][0], binaryPixel);
            binaryMsg[l] = binaryPixel[7];
        }
        else if (k % 3 == 1)
        {
            decimalToBinary(pixels[i][j][1], binaryPixel);
            binaryMsg[l] = binaryPixel[7];
        }
        else if (k % 3 == 2)
        {
            decimalToBinary(pixels[i][j][2], binaryPixel);
            binaryMsg[l] = binaryPixel[7];
        }

        k++;
    }

    for (int l = 0; l < len; l++)
    {
        decodedMsg[l] = (char) binaryToDecimal(&binaryMsg[l*8]);
    }
    decodedMsg[len] = '\0';
}