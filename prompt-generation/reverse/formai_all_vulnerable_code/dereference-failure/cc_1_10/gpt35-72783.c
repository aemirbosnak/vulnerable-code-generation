//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_PIXEL_VALUE 255
#define MAX_CHAR_VALUE 200

// Function to convert pixel values to ASCII characters
char pixelToChar(int pixelValue)
{
    char asciiChar[] = "$@B%8&WM#*oahkbdpwmZO0QCJYXzcvnxyu" \
                       "rjft/\|()1{}[]?-+_<>i!lI;:,\"^`'. ";
    int numChars = strlen(asciiChar);
    int charValue = (int)(pixelValue * (numChars - 1) / MAX_PIXEL_VALUE);
    char c = asciiChar[charValue];

    return c;
}

// Function to convert the image to ASCII art
void convertToASCII(FILE *inputFile, FILE *outputFile, int width, int height, int scaleFactor)
{
    int pixelCount = width * height;
    int pixels[pixelCount];
    int chHeight = height / scaleFactor;
    int chWidth = width / scaleFactor;
    int charCount = chHeight * chWidth;
    char asciiChars[charCount];

    // Read the image pixels
    for(int i = 0; i < pixelCount; i++)
    {
        int pixelValue = fgetc(inputFile);
        pixels[i] = pixelValue;
    }

    // Convert pixels to ASCII characters
    for(int i = 0; i < chHeight; i++)
    {
        for(int j = 0; j < chWidth; j++)
        {
            int avgPixelValue = 0;
            int startIndex = i * scaleFactor * width + j * scaleFactor;

            for(int k = 0; k < scaleFactor; k++)
            {
                for(int l = 0; l < scaleFactor; l++)
                {
                    int index = startIndex + k * width + l;
                    avgPixelValue += pixels[index];
                }
            }

            avgPixelValue /= (scaleFactor * scaleFactor);
            char c = pixelToChar(avgPixelValue);
            asciiChars[i * chWidth + j] = c;
        }
    }

    // Write the ASCII characters to the output file
    for(int i = 0; i < charCount; i++)
    {
        fputc(asciiChars[i], outputFile);
    }
}

int main(int argc, char *argv[])
{
    // Check for the correct argument count
    if(argc != 5)
    {
        printf("Usage: ./asciiconverter inputFile outputFile width height\n");
        exit(1);
    }

    char *inputFileName = argv[1];
    char *outputFileName = argv[2];
    int width = atoi(argv[3]);
    int height = atoi(argv[4]);

    // Open the input file
    FILE *inputFile = fopen(inputFileName, "rb");
    if(inputFile == NULL)
    {
        printf("Error opening input file!");
        exit(1);
    }

    // Open the output file
    FILE *outputFile = fopen(outputFileName, "w");
    if(outputFile == NULL)
    {
        printf("Error opening output file!");
        fclose(inputFile);
        exit(1);
    }

    convertToASCII(inputFile, outputFile, width, height, 4);

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Image converted successfully!\n");

    return 0;
}