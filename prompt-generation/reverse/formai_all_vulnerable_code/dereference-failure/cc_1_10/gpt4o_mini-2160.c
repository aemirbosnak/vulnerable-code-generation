//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define the BMP header sizes
#define BMP_HEADER_SIZE 54
#define BMP_INFO_HEADER_SIZE 40

typedef struct {
    uint8_t Blue;
    uint8_t Green;
    uint8_t Red;
} RGB;

typedef struct {
    uint8_t header[BMP_HEADER_SIZE];
    uint32_t width;
    uint32_t height;
    uint32_t paddedRowSize;
} BMPImage;

void applyGrayscale(RGB* pixel) {
    uint8_t grayValue = (pixel->Red + pixel->Green + pixel->Blue) / 3;
    pixel->Red = grayValue;
    pixel->Green = grayValue;
    pixel->Blue = grayValue;
}

void processImage(const char* inputFilename, const char* outputFilename) {
    FILE* inputFile = fopen(inputFilename, "rb");
    if (!inputFile) {
        fprintf(stderr, "Unable to open input file %s\n", inputFilename);
        exit(EXIT_FAILURE);
    }

    BMPImage bmpImage;
    
    // Read the BMP header
    fread(bmpImage.header, sizeof(uint8_t), BMP_HEADER_SIZE, inputFile);

    // Get the dimensions of the image
    bmpImage.width = *(uint32_t*)&bmpImage.header[18];
    bmpImage.height = *(uint32_t*)&bmpImage.header[22];
    bmpImage.paddedRowSize = ((bmpImage.width * 3 + 3) / 4) * 4;

    // Allocate memory for the image
    RGB* pixelData = (RGB*)malloc(bmpImage.paddedRowSize * bmpImage.height);
    if (!pixelData) {
        fclose(inputFile);
        fprintf(stderr, "Unable to allocate memory for image\n");
        exit(EXIT_FAILURE);
    }

    // Read the pixel data
    fseek(inputFile, BMP_HEADER_SIZE, SEEK_SET);
    fread(pixelData, sizeof(RGB), bmpImage.width * bmpImage.height, inputFile);
    fclose(inputFile);

    // Apply grayscale filter
    for (uint32_t i = 0; i < bmpImage.width * bmpImage.height; i++) {
        applyGrayscale(&pixelData[i]);
    }

    // Open output file
    FILE* outputFile = fopen(outputFilename, "wb");
    if (!outputFile) {
        free(pixelData);
        fprintf(stderr, "Unable to open output file %s\n", outputFilename);
        exit(EXIT_FAILURE);
    }

    // Write the BMP header
    fwrite(bmpImage.header, sizeof(uint8_t), BMP_HEADER_SIZE, outputFile);
    fseek(outputFile, BMP_HEADER_SIZE, SEEK_SET);
    fwrite(pixelData, sizeof(RGB), bmpImage.width * bmpImage.height, outputFile);
    
    fclose(outputFile);
    free(pixelData);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    processImage(argv[1], argv[2]);

    printf("Grayscale filter applied from %s to %s successfully.\n", argv[1], argv[2]);
    return EXIT_SUCCESS;
}