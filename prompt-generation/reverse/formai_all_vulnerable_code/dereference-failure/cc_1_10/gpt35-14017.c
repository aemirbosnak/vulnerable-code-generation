//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: lively
#include<stdio.h>
#include<string.h>

/**
 * Function to embed digital watermark into an image file
 * @param filepath Path to the image file
 * @param watermark The digital watermark to embed
 */
void embedWatermark(char* filepath, char* watermark)
{
    FILE* image = fopen(filepath, "r+");
    if (image == NULL) {
        printf("Error: Could not open file for embedding watermark\n");
        return;
    }

    // Set the pointer to the end of the image file
    fseek(image, 0, SEEK_END);
    int filesize = ftell(image);

    // Get the size of the watermark
    int watermarkSize = strlen(watermark);

    // Check if the watermark size is greater than the image size
    if (watermarkSize > filesize) {
        printf("Error: Cannot embed watermark. Watermark size is greater than the image size\n");
        fclose(image);
        return;
    }

    // Calculate the start point of the watermark in the image file
    int offset = filesize - watermarkSize;

    // Set the pointer to the start of the watermark in the image file
    fseek(image, offset, SEEK_SET);

    // Embed the watermark into the image file
    for (int i = 0; i < watermarkSize; i++) {
        fputc(watermark[i], image);
    }

    // Close the file
    fclose(image);

    printf("Digital watermark embedded successfully into the image file\n");
}

/**
 * Function to extract digital watermark from an image file
 * @param filepath Path to the image file
 * @param watermarkSize Size of the digital watermark to extract
 * @return The extracted digital watermark
 */
char* extractWatermark(char* filepath, int watermarkSize)
{
    FILE* image = fopen(filepath, "r");
    if (image == NULL) {
        printf("Error: Could not open file for extracting watermark\n");
        return NULL;
    }

    // Set the pointer to the start of the watermark in the image file
    fseek(image, -watermarkSize, SEEK_END);

    // Create an array to hold the extracted watermark
    char* watermark = malloc(watermarkSize + 1);

    // Extract the watermark from the image file
    for (int i = 0; i < watermarkSize; i++) {
        watermark[i] = fgetc(image);
    }

    // Add the null terminator to the extracted watermark
    watermark[watermarkSize] = '\0';

    // Close the file
    fclose(image);

    return watermark;
}

int main()
{
    char* filepath = "image.jpg";
    char* watermark = "This is my digital watermark";

    // Embed the digital watermark into the image file
    embedWatermark(filepath, watermark);

    // Extract the digital watermark from the image file
    char* extractedWatermark = extractWatermark(filepath, strlen(watermark));

    // Display the extracted digital watermark
    printf("Extracted Digital Watermark: %s\n", extractedWatermark);

    return 0;
}