//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM_PIXEL_VALUE (255)

/* ASCII characters to represent different shades of grey */
const char* ASCII_CHARS[] = {" ", ".", "-", "+", "*", "X", "%", "#", "@"};

/* Number of ASCII characters to represent a pixel */
#define ASCII_CHAR_COUNT (sizeof(ASCII_CHARS)/sizeof(ASCII_CHARS[0]))

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <image_file_name>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "rb");

    if (inputFile == NULL)
    {
        printf("Could not open input file %s\n", argv[1]);
        return 1;
    }

    /* Read the image header */
    char header[128];
    fgets(header, sizeof(header), inputFile);

    /* Image width, height, and maximum pixel value */
    int width, height, maxPixelValue;
    fscanf(inputFile, "%d %d %d", &width, &height, &maxPixelValue);

    /* Allocate memory for the pixel data */
    unsigned char* pixels = (unsigned char*)malloc(width * height * sizeof(unsigned char));

    /* Read the pixel data */
    fread(pixels, sizeof(unsigned char), width * height, inputFile);

    /* Close the input file */
    fclose(inputFile);

    /* Open the output file */
    FILE* outputFile = fopen("output.txt", "w");

    if (outputFile == NULL)
    {
        printf("Could not open output file\n");
        return 1;
    }

    /* Convert the pixels to ASCII art */
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            /* Calculate the index for the pixel at (x,y) */
            int pixelIndex = y * width + x;

            /* Normalized pixel value between 0 and 1 */
            double normalizedPixelValue = (double)pixels[pixelIndex] / (double)MAXIMUM_PIXEL_VALUE;

            /* Calculate the ASCII character index based on the normalized pixel value and the number of ASCII characters available */
            int asciiIndex = (int)(floor(normalizedPixelValue * (double)(ASCII_CHAR_COUNT - 1.0)));

            /* Write the ASCII character to the output file */
            fprintf(outputFile, "%s", ASCII_CHARS[asciiIndex]);
        }

        /* Start a new line for the next row */
        fprintf(outputFile, "\n");
    }

    /* Close the output file */
    fclose(outputFile);

    printf("Done!\n");

    return 0;
}