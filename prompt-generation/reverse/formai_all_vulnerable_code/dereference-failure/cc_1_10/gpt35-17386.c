//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define BIT_SIZE 8

/* This function takes two bytes and converts them
   to a short integer. */
short bytesToShort(unsigned char *bytes)
{
    short result = (bytes[0] << BIT_SIZE) + bytes[1];
    return result;
}

/* This function takes a short integer and converts it
   to two bytes. */
void shortToBytes(short number, unsigned char *bytes)
{
    bytes[0] = (number >> BIT_SIZE) & 0xFF;
    bytes[1] = number & 0xFF;
}

/* This function adds a digital watermark to an image file. */
void addWatermark(char *filename, short watermark)
{
    FILE *file = fopen(filename, "r+b");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    /* Find the size of the file in bytes. */
    fseek(file, 0L, SEEK_END);
    long int size = ftell(file);
    rewind(file);

    /* Create a buffer to read the file into. */
    unsigned char *buffer = (unsigned char *) malloc(size * sizeof(unsigned char));
    if (buffer == NULL) {
        printf("Error: Could not allocate memory for buffer\n");
        fclose(file);
        exit(1);
    }

    /* Read the file into the buffer. */
    fread(buffer, sizeof(unsigned char), size, file);

    /* Determine the number of pixels in the image. */
    int width = bytesToShort(buffer + 18);
    int height = bytesToShort(buffer + 22);
    int numPixels = width * height;

    /* Find the byte location of the pixel data. */
    int pixelOffset = bytesToShort(buffer + 10);

    /* Add the watermark to the pixel data. */
    for (int i = 0; i < numPixels; i++) {
        int index = pixelOffset + 3 * i;
        short pixelValue = bytesToShort(buffer + index);

        pixelValue ^= watermark;        

        shortToBytes(pixelValue, buffer + index);
    }

    /* Write the modified buffer back to the file. */
    rewind(file);
    fwrite(buffer, sizeof(unsigned char), size, file);

    /* Free the memory. */
    free(buffer);

    /* Close the file. */
    fclose(file);
}

/* This function extracts a digital watermark from an image file. */
short extractWatermark(char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    /* Find the size of the file in bytes. */
    fseek(file, 0L, SEEK_END);
    long int size = ftell(file);
    rewind(file);

    /* Create a buffer to read the file into. */
    unsigned char *buffer = (unsigned char *) malloc(size * sizeof(unsigned char));
    if (buffer == NULL) {
        printf("Error: Could not allocate memory for buffer\n");
        fclose(file);
        exit(1);
    }

    /* Read the file into the buffer. */
    fread(buffer, sizeof(unsigned char), size, file);

    /* Determine the number of pixels in the image. */
    int width = bytesToShort(buffer + 18);
    int height = bytesToShort(buffer + 22);
    int numPixels = width * height;

    /* Find the byte location of the pixel data. */
    int pixelOffset = bytesToShort(buffer + 10);

    /* Extract the watermark from the pixel data. */
    short watermark = 0;
    for (int i = 0; i < numPixels; i++) {
        int index = pixelOffset + 3 * i;
        short pixelValue = bytesToShort(buffer + index);

        watermark ^= pixelValue;
    }

    /* Free the memory. */
    free(buffer);

    /* Close the file. */
    fclose(file);

    return watermark;
}

int main()
{
    char *inputFilename = "image.bmp";
    char *outputFilename = "watermarked.bmp";
    short watermark = 0x1234;

    /* Add the watermark to the image file. */
    addWatermark(inputFilename, watermark);

    /* Extract the watermark from the watermarked image file. */
    short extractedWatermark = extractWatermark(outputFilename);

    /* Print the extracted watermark. */
    printf("Extracted watermark: 0x%X\n", extractedWatermark);

    return 0;
}