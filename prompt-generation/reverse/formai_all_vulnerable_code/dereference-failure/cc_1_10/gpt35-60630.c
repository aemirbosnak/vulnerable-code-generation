//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) 
{
    // Read input image file
    FILE *inputImage = fopen("input.bmp", "rb");
    if (inputImage == NULL) {
        printf("Error opening input image file!");
        return 0;
    }

    // Read header file of input image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, inputImage);

    // Extract image width, height, and size information
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int size = width * height;

    // Read input image pixel values
    unsigned char *imageData = (unsigned char*)malloc(size * sizeof(unsigned char));
    fread(imageData, sizeof(unsigned char), size, inputImage);

    // Initialize watermark data
    char *watermark = "This is a sample digital watermark!";
    int wmSize = strlen(watermark);
    unsigned char wmData[wmSize];
    memcpy(wmData, watermark, wmSize);

    // Embed watermark into the LSB of the input image's pixel values
    int bitCounter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 8; j++) {
            if (bitCounter < wmSize * 8) {
                imageData[i] = (imageData[i] & ~(1 << j)) | ((wmData[bitCounter / 8] >> (bitCounter % 8)) & 1) << j;
            }
            bitCounter++;
        }
    }

    // Write output watermarked image file
    FILE *outputImage = fopen("output.bmp", "wb");
    if (outputImage == NULL) {
        printf("Error opening output image file!");
        return 0;
    }

    // Write header file of output watermarked image
    fwrite(header, sizeof(unsigned char), 54, outputImage);

    // Write watermarked pixel values to output watermarked image
    fwrite(imageData, sizeof(unsigned char), size, outputImage);

    // Cleanup
    fclose(inputImage);
    fclose(outputImage);
    free(imageData);

    return 0;
}