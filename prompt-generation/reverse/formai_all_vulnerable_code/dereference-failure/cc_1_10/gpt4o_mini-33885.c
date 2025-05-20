//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 4096

// Function prototypes
void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark);
void extractWatermark(const char *inputFile, const char *watermarkOutputFile, int watermarkLength);
void printError(const char *msg);

// Structure to hold the image data
typedef struct {
    uint8_t header[54]; // BMP header
    uint32_t width;
    uint32_t height;
    uint32_t dataSize;
    uint8_t *data;
} BMPImage;

// Function to read BMP image
BMPImage readBMP(const char *filename) {
    BMPImage img;
    FILE *file = fopen(filename, "rb");
    
    if (!file) {
        printError("Unable to open BMP file.");
        exit(EXIT_FAILURE);
    }
    
    fread(img.header, sizeof(uint8_t), 54, file);
    
    img.width = *(uint32_t *)&img.header[18];
    img.height = *(uint32_t *)&img.header[22];
    img.dataSize = img.width * img.height * 3; // assuming 24 bits per pixel
    img.data = (uint8_t *)malloc(img.dataSize);
    
    fseek(file, 54, SEEK_SET); // Jump to the pixel data
    fread(img.data, sizeof(uint8_t), img.dataSize, file);
    fclose(file);
    
    return img;
}

// Function to write BMP image
void writeBMP(const BMPImage *img, const char *filename) {
    FILE *file = fopen(filename, "wb");
    
    if (!file) {
        printError("Unable to write the BMP file.");
        exit(EXIT_FAILURE);
    }
    
    fwrite(img->header, sizeof(uint8_t), 54, file);
    fwrite(img->data, sizeof(uint8_t), img->dataSize, file);
    fclose(file);
}

// Function to embed watermark into image
void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    BMPImage img = readBMP(inputFile);
    size_t watermarkLen = strlen(watermark);
    
    if (watermarkLen * 8 > img.dataSize) {
        printError("Watermark is too large to embed in the image.");
        exit(EXIT_FAILURE);
    }
    
    for (size_t i = 0; i < watermarkLen; ++i) {
        for (int j = 0; j < 8; ++j) {
            // Embed one bit of the watermark into the least significant bit
            int bit = (watermark[i] >> (7 - j)) & 1;
            img.data[i * 8 + j] = (img.data[i * 8 + j] & ~1) | bit; // Change LSB
        }
    }
    
    writeBMP(&img, outputFile);
    free(img.data);
    printf("Watermark embedded successfully.\n");
}

// Function to extract watermark from the image
void extractWatermark(const char *inputFile, const char *watermarkOutputFile, int watermarkLength) {
    BMPImage img = readBMP(inputFile);
    char *watermark = (char *)malloc(watermarkLength + 1);
    watermark[watermarkLength] = '\0'; // Null-terminate the string

    for (size_t i = 0; i < watermarkLength; ++i) {
        uint8_t byte = 0;
        for (int j = 0; j < 8; ++j) {
            // Extract the least significant bit
            byte <<= 1;
            byte |= (img.data[i * 8 + j] & 1); // Get LSB
        }
        watermark[i] = byte;
    }

    FILE *file = fopen(watermarkOutputFile, "w");
    if (!file) {
        printError("Unable to write the output watermark file.");
        exit(EXIT_FAILURE);
    }
    
    fprintf(file, "%s", watermark);
    fclose(file);
    free(watermark);
    free(img.data);
    printf("Watermark extracted successfully.\n");
}

// Function to print error messages
void printError(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printError("Usage: ./watermark <embed/extract> <input_image> <output_file> <watermark or watermark_length>");
        exit(EXIT_FAILURE);
    }
    
    if (strcmp(argv[1], "embed") == 0) {
        embedWatermark(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        int watermarkLength = atoi(argv[4]);
        extractWatermark(argv[2], argv[3], watermarkLength);
    } else {
        printError("Invalid option. Use 'embed' or 'extract'.");
        exit(EXIT_FAILURE);
    }

    return 0;
}