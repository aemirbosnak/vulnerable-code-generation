//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <math.h>

// Function to embed a watermark in a given image
void embedWatermark(int img[][3], int watermark[])
{
    // Calculate the total number of pixels in the image
    int imgSize = sizeof(img) / sizeof(img[0][0]);

    // Calculate the total number of pixels in the watermark
    int watermarkSize = sizeof(watermark) / sizeof(watermark[0]);

    // Determine the scaling factor based on the pixel range of the image
    int scale = ((int) pow(2, sizeof(img[0][0]) * 8) - 1) / 2;

    // Loop through each pixel of the image and embed the watermark
    int waterIndex = 0;
    for (int i = 0; i < imgSize; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Embed the least significant bit of the watermark to the pixel value
            img[i][j] = ((img[i][j] / scale) * scale) + (watermark[waterIndex] % scale);
            
            // Move to the next bit of the watermark
            waterIndex = (waterIndex + 1) % watermarkSize;
        }
    }
}

// Function to extract a watermark from a given image
void extractWatermark(int img[][3], int watermark[])
{
    // Calculate the total number of pixels in the image
    int imgSize = sizeof(img) / sizeof(img[0][0]);

    // Determine the scaling factor based on the pixel range of the image
    int scale = ((int) pow(2, sizeof(img[0][0]) * 8) - 1) / 2;

    // Loop through each pixel of the image and extract the watermark
    int waterIndex = 0;
    for (int i = 0; i < imgSize; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Extract the least significant bit of the pixel value to the watermark
            watermark[waterIndex] = img[i][j] % scale;

            // Move to the next bit of the watermark
            waterIndex = (waterIndex + 1) % sizeof(watermark);
        }
    }
}

// Test the Digital Watermarking functions
int main(void)
{
    // Create an example image
    int img[4][3] =
    {
        {255, 0, 0},
        {0, 255, 0},
        {0, 0, 255},
        {255, 255, 255}
    };

    // Create an example watermark
    int watermark[] = {1, 0, 1, 0, 0, 1, 0, 1};

    // Embed the watermark in the image
    embedWatermark(img, watermark);

    // Extract the watermark from the image
    int extractedWatermark[sizeof(watermark)];
    extractWatermark(img, extractedWatermark);

    // Print the original and extracted watermarks
    printf("Original Watermark: ");
    for (int i = 0; i < sizeof(watermark); i++)
    {
        printf("%d ", watermark[i]);
    }
    printf("\n");

    printf("Extracted Watermark: ");
    for (int i = 0; i < sizeof(extractedWatermark); i++)
    {
        printf("%d ", extractedWatermark[i]);
    }

    return 0;
}