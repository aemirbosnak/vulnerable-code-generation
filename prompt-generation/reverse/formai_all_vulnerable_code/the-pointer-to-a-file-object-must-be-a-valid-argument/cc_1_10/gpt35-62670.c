//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: peaceful
#include<stdio.h>
#include<string.h>

// Function to embed the watermark in an image
void embedWatermark(char *image, char *watermark)
{
    FILE *fImage = fopen(image, "r");
    FILE *fWatermark = fopen(watermark, "r");
    FILE *fOutput = fopen("output.ppm", "w"); // Output image file

    char readLine[150], *imgSize = NULL, *lineBreak = NULL;
    int i, j, width, height, pixelRange, watermarkSize, k = 0;
    char watermarkData[1000], imageData[99999];

    // Read the image data 
    fgets(readLine, sizeof(readLine), fImage);
    if(readLine[0] == 'P' && readLine[1] == '6' && readLine[2] == '\n')
    {
        // Get the image size from the header
        fgets(readLine, sizeof(readLine), fImage);
        imgSize = strtok(readLine, " ");
        width = atoi(imgSize);
        imgSize = strtok(NULL, " ");
        height = atoi(imgSize);

        // Read the pixel range
        fgets(readLine, sizeof(readLine), fImage);
        pixelRange = atoi(readLine);

        // Get the watermark data
        fgets(watermarkData, sizeof(watermarkData), fWatermark);
        watermarkSize = strlen(watermarkData);

        // Embed the watermark in the image data
        fgets(imageData, sizeof(imageData), fImage);
        for(i = 0; i < height; i++)
        {
            for(j = 0; j < (width * 3); j++)
            {
                if(k < watermarkSize)
                {
                    // Change the least significant bit of each pixel to the corresponding bit of the watermark
                    imageData[j + (i * (width * 3))] &= 0xFE; // Set the least significant bit to 0
                    if((watermarkData[k/8] & (1 << (k%8))) != 0)
                        imageData[j + (i * (width * 3))] |= 0x01; // Set the least significant bit to the corresponding bit of the watermark
                    k++;
                }
            }
        }

        // Write the output data to the output file
        fprintf(fOutput, "P6\n%d %d\n%d\n", width, height, pixelRange);
        fwrite(imageData, sizeof(char), sizeof(imageData), fOutput);

        // Close the files
        fclose(fImage);
        fclose(fWatermark);
        fclose(fOutput);
    }   
}

// Function to extract the watermark from an image
void extractWatermark(char *image)
{
    FILE *fImage = fopen(image, "r");
    FILE *fOutput = fopen("extracted_watermark.txt", "w"); // Output file for the extracted watermark

    char readLine[150], *imgSize = NULL, *lineBreak = NULL;
    int i, j, width, height, pixelRange, watermarkSize, k = 0;
    char watermarkData[1000], imageData[99999];

    // Read the image data 
    fgets(readLine, sizeof(readLine), fImage);
    if(readLine[0] == 'P' && readLine[1] == '6' && readLine[2] == '\n')
    {
        // Get the image size from the header
        fgets(readLine, sizeof(readLine), fImage);
        imgSize = strtok(readLine, " ");
        width = atoi(imgSize);
        imgSize = strtok(NULL, " ");
        height = atoi(imgSize);

        // Read the pixel range
        fgets(readLine, sizeof(readLine), fImage);
        pixelRange = atoi(readLine);

        // Extract the watermark from the image data
        fgets(imageData, sizeof(imageData), fImage);
        for(i = 0; i < height; i++)
        {
            for(j = 0; j < (width * 3); j++)
            {
                if(k % 8 == 0)
                    watermarkData[k/8] = 0;
                // Get the least significant bit of each pixel
                watermarkData[k/8] |= ((imageData[j + (i * (width * 3))] & 0x01) << (k%8));
                k++;
            }
        }
        watermarkSize = strlen(watermarkData);

        // Write the extracted watermark to the output file
        for(i = 0; i < watermarkSize; i++)
            fprintf(fOutput, "%c", watermarkData[i]);

        // Close the files
        fclose(fImage);
        fclose(fOutput);
    }   
}

int main()
{
    char *image = "input.ppm"; // Input image file
    char *watermark = "watermark.txt"; // Input watermark file

    // Embed the watermark in the image file
    embedWatermark(image, watermark);

    // Extract the watermark from the watermarked image
    extractWatermark("output.ppm");

    return 0;
}