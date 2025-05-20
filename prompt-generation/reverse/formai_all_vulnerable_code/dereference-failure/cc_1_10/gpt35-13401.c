//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54 // size of BMP header

int main()
{
    FILE *inputFile, *outputFile;
    unsigned char *header, *pixels;    // arrays to store BMP header and pixel data
    int i, width, height, size;
    float brightness = 1.0, contrast = 1.0; // default values for brightness and contrast

    // open input BMP file
    inputFile = fopen("input.bmp", "rb");
    if(inputFile == NULL)
    {
        printf("Error opening input file.\n");
        return 0;
    }

    // read BMP header
    header = (unsigned char*) malloc(BMP_HEADER_SIZE);
    fread(header, 1, BMP_HEADER_SIZE, inputFile);

    // get image width and height
    width = *(int*)&header[18];
    height = *(int*)&header[22];

    // calculate size of pixel data
    size = width * height * 3;
    pixels = (unsigned char*) malloc(size);

    // read pixel data
    fread(pixels, 1, size, inputFile);

    // close input file
    fclose(inputFile);

    // create output BMP file
    outputFile = fopen("output.bmp", "wb");
    if(outputFile == NULL)
    {
        printf("Error creating output file.\n");
        return 0;
    }

    // write BMP header
    fwrite(header, 1, BMP_HEADER_SIZE, outputFile);

    // flip image horizontally
    for(i = 0; i < height * width * 3; i += 3)
    {
        pixels[i] = pixels[(height * width * 3) - (i + 3)];
        pixels[i + 1] = pixels[(height * width * 3) - (i + 2)];
        pixels[i + 2] = pixels[(height * width * 3) - (i + 1)];
    }

    // adjust brightness and contrast
    for(i = 0; i < size; i++)
    {
        pixels[i] = (unsigned char) ((pixels[i] - 128) * contrast + 128 + 255 * brightness);
        if(pixels[i] < 0) pixels[i] = 0;
        if(pixels[i] > 255) pixels[i] = 255;
    }

    // write pixel data
    fwrite(pixels, 1, size, outputFile);

    // close output file
    fclose(outputFile);

    printf("Image processing completed successfully.\n");

    return 0;
}