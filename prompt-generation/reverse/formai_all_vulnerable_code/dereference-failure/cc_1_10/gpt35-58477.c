//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ultraprecise
#include <stdio.h>

// function to embed watermark in an image file
void embedWatermark(FILE *imageFile, FILE *watermarkFile)
{
    int imageBufferSize = 1024, watermarkBufferSize = 512;
    unsigned char imageBuffer[imageBufferSize], watermarkBuffer[watermarkBufferSize];
    int i = 0, j = 0;

    // read the image file header
    fread(imageBuffer, sizeof(unsigned char), imageBufferSize, imageFile);

    // read the watermark file header
    fread(watermarkBuffer, sizeof(unsigned char), watermarkBufferSize, watermarkFile);

    // start embedding the watermark into the image
    while (!feof(watermarkFile))
    {
        // read a chunk of data from the watermark file
        fread(watermarkBuffer, sizeof(unsigned char), watermarkBufferSize, watermarkFile);

        // loop through the data, bit by bit
        for (i = 0; i < watermarkBufferSize; i++)
        {
            for (j = 0; j < 8; j++)
            {
                // get the image buffer data
                int imageByteIndex = (i * 8 + j) * 3 + 54;
                unsigned char imageByte = imageBuffer[imageByteIndex];

                // get the watermark buffer data
                int watermarkByteIndex = i;
                unsigned char watermarkByte = watermarkBuffer[watermarkByteIndex];

                // get the bit from the watermark buffer
                int watermarkBitIndex = 7 - j;
                unsigned char watermarkBit = (watermarkByte >> watermarkBitIndex) & 1;

                // set the least significant bit of the image byte to the watermark bit
                if (watermarkBit == 0)
                {
                    unsigned char newByte = imageByte & 0xfe;
                    imageBuffer[imageByteIndex] = newByte;
                }
                else
                {
                    unsigned char newByte = imageByte | 0x01;
                    imageBuffer[imageByteIndex] = newByte;
                }
            }
        }

        // write the chunk of data to the image file
        fwrite(imageBuffer, sizeof(unsigned char), imageBufferSize, imageFile);
    }

    printf("Watermark embedded successfully!\n");
}

// function to extract watermark from an image file
void extractWatermark(FILE *imageFile, FILE *outputFile)
{
    int imageBufferSize = 1024;
    unsigned char imageBuffer[imageBufferSize];
    int i = 0, j = 0;

    // read the image file header
    fread(imageBuffer, sizeof(unsigned char), imageBufferSize, imageFile);

    // start extracting the watermark from the image
    while (!feof(imageFile))
    {
        // read a chunk of data from the image file
        fread(imageBuffer, sizeof(unsigned char), imageBufferSize, imageFile);

        // loop through the data, bit by bit
        for (i = 0; i < imageBufferSize / 3; i++)
        {
            for (j = 0; j < 8; j++)
            {
                // get the image buffer data
                int imageByteIndex = (i * 8 + j) * 3 + 54;
                unsigned char imageByte = imageBuffer[imageByteIndex];

                // get the least significant bit from the image byte
                unsigned char watermarkBit = imageByte & 0x01;

                // write the bit to the output file
                fwrite(&watermarkBit, sizeof(unsigned char), 1, outputFile);
            }
        }
    }

    printf("Watermark extracted successfully!\n");
}

int main()
{
    FILE *imageFile, *watermarkFile, *outputFile;
    char imageFileName[] = "image.bmp";
    char watermarkFileName[] = "watermark.txt";
    char outputFileName[] = "output.txt";

    // open the image file
    imageFile = fopen(imageFileName, "rb");
    if (imageFile == NULL)
    {
        printf("Error: Image file not found!\n");
        return 1;
    }

    // open the watermark file
    watermarkFile = fopen(watermarkFileName, "rb");
    if (watermarkFile == NULL)
    {
        printf("Error: Watermark file not found!\n");
        return 1;
    }

    // embed the watermark into the image file
    embedWatermark(imageFile, watermarkFile);

    // close the image and watermark files
    fclose(imageFile);
    fclose(watermarkFile);

    // open the image file again
    imageFile = fopen(imageFileName, "rb");
    if (imageFile == NULL)
    {
        printf("Error: Image file not found!\n");
        return 1;
    }

    // open the output file
    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL)
    {
        printf("Error: Could not create output file!\n");
        return 1;
    }

    // extract the watermark from the image file
    extractWatermark(imageFile, outputFile);

    // close the image and output files
    fclose(imageFile);
    fclose(outputFile);

    return 0;
}