//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// This function is used to embed the digital watermark into an image
void embedWatermark(unsigned char* image, int imageWidth, int imageHeight, unsigned char* watermarkMsg, int msgSize) {
    int i, j;

    // Loop through every pixel in the image
    for (i = 0; i < imageHeight; i++) {
        for (j = 0; j < imageWidth; j++) {
            // Calculate the index of the current pixel
            int idx = (i * imageWidth + j) * 3;

            // Check whether the pixel is in the border region of the image
            if (i < 20 || i > imageHeight - 20 || j < 20 || j > imageWidth - 20) {
                // Embed the watermark into the blue channel of the pixel
                image[idx + 2] = (image[idx + 2] & 0xFE) | ((watermarkMsg[(i + j) % msgSize] >> 7) & 0x01);
                // Shift the watermark message bit to the left by 1
                watermarkMsg[(i + j) % msgSize] <<= 1;
            }
        }
    }
}

// This function is used to extract the digital watermark from an image
void extractWatermark(unsigned char* image, int imageWidth, int imageHeight, unsigned char* watermarkMsg, int msgSize) {
    int i, j;

    // Loop through every pixel in the image
    for (i = 0; i < imageHeight; i++) {
        for (j = 0; j < imageWidth; j++) {
            // Calculate the index of the current pixel
            int idx = (i * imageWidth + j) * 3;

            // Check whether the pixel is in the border region of the image
            if (i < 20 || i > imageHeight - 20 || j < 20 || j > imageWidth - 20) {
                // Extract the watermark from the blue channel of the pixel
                watermarkMsg[(i + j) % msgSize] = (watermarkMsg[(i + j) % msgSize] << 1) | (image[idx + 2] & 0x01);
            }
        }
    }
}

int main() {
    // Define the size of the image and watermark message
    int imageWidth = 400;
    int imageHeight = 300;
    int msgSize = 256;

    // Allocate memory for the image and watermark message
    unsigned char* image = (unsigned char*)malloc(imageWidth * imageHeight * 3 * sizeof(unsigned char));
    unsigned char* watermarkMsg = (unsigned char*)malloc(msgSize * sizeof(unsigned char));

    // Initialize the image and watermark message with random data
    int i, j;
    for (i = 0; i < imageHeight; i++) {
        for (j = 0; j < imageWidth; j++) {
            int idx = (i * imageWidth + j) * 3;
            image[idx] = rand() % 256;
            image[idx + 1] = rand() % 256;
            image[idx + 2] = rand() % 256;
        }
    }
    for (i = 0; i < msgSize; i++) {
        watermarkMsg[i] = rand() % 256;
    }

    // Embed the watermark into the image
    embedWatermark(image, imageWidth, imageHeight, watermarkMsg, msgSize);

    // Extract the watermark from the image
    unsigned char* extractedWatermarkMsg = (unsigned char*)malloc(msgSize * sizeof(unsigned char));
    extractWatermark(image, imageWidth, imageHeight, extractedWatermarkMsg, msgSize);

    // Compare the original and extracted watermark messages
    int mismatchCount = 0;
    for (i = 0; i < msgSize; i++) {
        if (watermarkMsg[i] != extractedWatermarkMsg[i]) {
            mismatchCount++;
        }
    }

    // Print the results
    printf("Embedding and extracting digital watermarking completed successfully.\n");
    printf("Original watermark message:\n");
    for (i = 0; i < msgSize; i++) {
        printf("%x ", watermarkMsg[i]);
    }
    printf("\n");

    printf("Extracted watermark message:\n");
    for (i = 0; i < msgSize; i++) {
        printf("%x ", extractedWatermarkMsg[i]);
    }
    printf("\n");

    printf("Number of mismatches between original and extracted watermark messages: %d\n", mismatchCount);

    // Free memory
    free(image);
    free(watermarkMsg);
    free(extractedWatermarkMsg);

    return 0;
}