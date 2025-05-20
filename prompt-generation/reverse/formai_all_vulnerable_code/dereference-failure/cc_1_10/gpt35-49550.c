//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 4  // Define the size of the watermark in bytes

// Function to embed watermark in the least significant bits of image pixels
void embedWatermark(unsigned char *imageData, unsigned char *watermark, int size)
{
    int i, j;

    // Loop over each pixel in the image data
    for(i = 0; i < size; i += 4)
    {
        // Loop over the watermark bytes
        for(j = 0; j < WATERMARK_SIZE; j++)
        {
            // Get the current pixel value
            unsigned char pixelValue = imageData[i + j];

            // Clear the least significant bit and embed the watermark bit
            pixelValue &= 0xFE; // Clear the last bit of the pixel value
            pixelValue |= ((watermark[j] & 0x01) == 0x01); // Embed the watermark bit

            // Set the pixel value back to the image data
            imageData[i + j] = pixelValue;
        }
    }
}

// Function to extract watermark from the least significant bits of image pixels
void extractWatermark(unsigned char *imageData, unsigned char *watermark)
{
    int i, j;

    // Loop over each pixel in the image data
    for(i = 0; i < WATERMARK_SIZE * 4; i += 4)
    {
        // Loop over the watermark bytes
        for(j = 0; j < WATERMARK_SIZE; j++)
        {
            // Get the current pixel value
            unsigned char pixelValue = imageData[i + j];

            // Extract the watermark bit from the least significant bit of the pixel value
            watermark[j] <<= 1;
            watermark[j] |= (pixelValue & 0x01);
        }
    }
}

int main()
{
    FILE *fpIn, *fpOut;
    unsigned char *imageData, *watermark;
    int imageSize, watermarkSize;

    // Open the input image file in binary mode
    fpIn = fopen("inputImage.jpg", "rb");

    // Check if the input image file exists
    if(fpIn == NULL)
    {
        printf("Error: input image file not found!");
        return 1;
    }

    // Open the output image file in binary mode
    fpOut = fopen("outputImage.jpg", "wb");

    // Check if the output image file was created successfully
    if(fpOut == NULL)
    {
        printf("Error: could not create output image file!");
        return 1;
    }

    // Calculate the size of the input image file
    fseek(fpIn, 0L, SEEK_END);
    imageSize = ftell(fpIn);
    fseek(fpIn, 0L, SEEK_SET);

    // Allocate memory for the image data
    imageData = (unsigned char *)malloc(sizeof(unsigned char) * imageSize);

    // Read the image data from the input file into memory
    fread(imageData, imageSize, 1, fpIn);

    // Close the input image file
    fclose(fpIn);

    // Allocate memory for the watermark
    watermark = (unsigned char *)malloc(sizeof(unsigned char) * WATERMARK_SIZE);

    // Embed the watermark in the image data
    embedWatermark(imageData, watermark, imageSize);

    // Extract the watermark from the image data
    extractWatermark(imageData, watermark);

    // Write the modified image data to the output file
    fwrite(imageData, imageSize, 1, fpOut);

    // Close the output image file
    fclose(fpOut);

    // Free the memory used by the image data and watermark
    free(imageData);
    free(watermark);

    return 0;
}