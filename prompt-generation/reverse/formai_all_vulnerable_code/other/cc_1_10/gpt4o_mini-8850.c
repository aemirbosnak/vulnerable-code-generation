//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024
#define WATERMARK "WATERMARKED"
#define FILE_HEADER_SIZE 54

typedef struct {
    unsigned char header[FILE_HEADER_SIZE];
    unsigned int width;
    unsigned int height;
} BMPImage;

void parseBMPHeader(BMPImage *img, FILE *file) {
    fread(img->header, sizeof(unsigned char), FILE_HEADER_SIZE, file);
    img->width = *(int*)&img->header[18];
    img->height = *(int*)&img->header[22];
}

void embedWatermark(BMPImage *img, FILE *file) {
    int pixelCount = img->width * img->height;
    fseek(file, FILE_HEADER_SIZE, SEEK_SET);
    
    unsigned char pixel[3];
    for (int i = 0; i < pixelCount && i < strlen(WATERMARK); i++) {
        fread(pixel, sizeof(unsigned char), 3, file);
        pixel[0] = (pixel[0] & 0xFE) | ((WATERMARK[i] >> 7) & 1);
        pixel[1] = (pixel[1] & 0xFE) | ((WATERMARK[i] >> 6) & 1);
        pixel[2] = (pixel[2] & 0xFE) | ((WATERMARK[i] >> 5) & 1);
        fseek(file, -3, SEEK_CUR);
        fwrite(pixel, sizeof(unsigned char), 3, file);
    }
}

void extractWatermark(BMPImage *img, FILE *file) {
    char extractedWatermark[sizeof(WATERMARK) + 1] = {0};
    fseek(file, FILE_HEADER_SIZE, SEEK_SET);
    
    unsigned char pixel[3];
    for (int i = 0; i < strlen(WATERMARK); i++) {
        fread(pixel, sizeof(unsigned char), 3, file);
        extractedWatermark[i] = ((pixel[0] & 1) << 7) | ((pixel[1] & 1) << 6) | ((pixel[2] & 1) << 5);
    }
    
    // Output extracted watermark
    printf("Extracted watermark: %s\n", extractedWatermark);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    BMPImage img;
    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    parseBMPHeader(&img, inputFile);

    FILE *outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Copy header to output file
    fwrite(img.header, sizeof(unsigned char), FILE_HEADER_SIZE, outputFile);

    // Embed the watermark
    embedWatermark(&img, inputFile);

    // Copy remaining data from input to output
    fseek(inputFile, FILE_HEADER_SIZE, SEEK_SET);
    unsigned char buffer[MAX_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, sizeof(unsigned char), MAX_SIZE, inputFile)) > 0) {
        fwrite(buffer, sizeof(unsigned char), bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    // Reopening output file to extract watermark
    outputFile = fopen(argv[2], "rb");
    if (!outputFile) {
        perror("Error reopening output file");
        return EXIT_FAILURE;
    }

    extractWatermark(&img, outputFile);

    fclose(outputFile);
    return EXIT_SUCCESS;
}