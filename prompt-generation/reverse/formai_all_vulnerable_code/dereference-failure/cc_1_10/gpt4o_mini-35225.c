//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to embed watermark into the image
void embedWatermark(const char *inputImage, const char *outputImage, const char *watermark) {
    FILE *inputFile = fopen(inputImage, "rb");
    FILE *outputFile = fopen(outputImage, "wb");
    
    if (!inputFile || !outputFile) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }
  
    unsigned char buffer[MAX_SIZE];
    size_t bytesRead;
    size_t watermarkLen = strlen(watermark);
    
    // Read input image file and write to output file while embedding watermark
    while ((bytesRead = fread(buffer, 1, MAX_SIZE, inputFile)) > 0) {
        // Embedding watermark in the least significant bit of each byte
        for (size_t i = 0; i < bytesRead && (i < watermarkLen); i++) {
            buffer[i] = (buffer[i] & 0xFE) | (watermark[i] & 0x01);
        }
        fwrite(buffer, 1, bytesRead, outputFile);
        // Repeat watermark if the input image is larger than the watermark size
    }
    
    fclose(inputFile);
    fclose(outputFile);
}

// Function to extract watermark from the image
void extractWatermark(const char *imageWithWatermark, char *extractedWatermark, size_t watermarkLen) {
    FILE *file = fopen(imageWithWatermark, "rb");
    
    if (!file) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[MAX_SIZE];
    size_t bytesRead;
  
    size_t watermarkIndex = 0;

    // Reading image to extract watermark
    while ((bytesRead = fread(buffer, 1, MAX_SIZE, file)) > 0 && watermarkIndex < watermarkLen) {
        for (size_t i = 0; i < bytesRead && watermarkIndex < watermarkLen; i++) {
            extractedWatermark[watermarkIndex++] = (buffer[i] & 0x01);
        }
    }
    
    fclose(file);
}

// Function to display the watermark
void displayWatermark(char *watermark, size_t watermarkLen) {
    printf("Extracted Watermark: ");
    for (size_t i = 0; i < watermarkLen; i++) {
        printf("%c", watermark[i] + '0'); // Convert binary to character representation
    }
    printf("\n");
}

int main() {
    const char *inputImage = "input_image.bmp";  // Provide path to your BMP image here
    const char *watermark = "101010";             // Example watermark in binary
    const char *outputImage = "output_image.bmp"; // Output image with watermark
    char extractedWatermark[100];
  
    embedWatermark(inputImage, outputImage, watermark);
    extractWatermark(outputImage, extractedWatermark, strlen(watermark));
    displayWatermark(extractedWatermark, strlen(watermark));
  
    return 0;
}