//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;
#pragma pack(pop)

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermarkFile) {
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "wb");
    FILE *watermark = fopen(watermarkFile, "rb");

    if (!input || !output || !watermark) {
        perror("File opening failed");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, input);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, input);

    // Check if the image is a 24-bit BMP
    if (infoHeader.biBitCount != 24) {
        fprintf(stderr, "Only 24-bit BMP files are supported.\n");
        fclose(input);
        fclose(output);
        fclose(watermark);
        return;
    }

    // Copy the original header to the output file
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, output);

    // Calculate the size of the image
    size_t pixelDataSize = infoHeader.biWidth * infoHeader.biHeight * 3;
    RGB *pixelData = (RGB *)malloc(pixelDataSize);
    fread(pixelData, sizeof(RGB), infoHeader.biWidth * infoHeader.biHeight, input);

    // Read the watermark data
    fseek(watermark, 0, SEEK_END);
    long watermarkSize = ftell(watermark);
    fseek(watermark, 0, SEEK_SET);

    uint8_t *watermarkData = (uint8_t *)malloc(watermarkSize);
    fread(watermarkData, 1, watermarkSize, watermark);

    // Simple embedding using LSB
    for (long i = 0; i < watermarkSize; i++) {
        if (i >= pixelDataSize) break;

        // Embed one bit into the LSB of the red channel
        pixelData[i].red = (pixelData[i].red & ~1) | ((watermarkData[i >> 3] >> (i & 7)) & 1);
    }

    // Write the modified pixel data to output
    fwrite(pixelData, sizeof(RGB), infoHeader.biWidth * infoHeader.biHeight, output);

    // Free resources
    free(pixelData);
    free(watermarkData);
    fclose(input);
    fclose(output);
    fclose(watermark);
}

void extractWatermark(const char *inputFile, const char *outputFile, long watermarkSize) {
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "wb");

    if (!input || !output) {
        perror("File opening failed");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, input);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, input);

    // Check if the image is a 24-bit BMP
    if (infoHeader.biBitCount != 24) {
        fprintf(stderr, "Only 24-bit BMP files are supported.\n");
        fclose(input);
        fclose(output);
        return;
    }

    // Skip pixel data to get to the beginning
    long pixelDataSize = infoHeader.biWidth * infoHeader.biHeight * 3;
    fseek(input, fileHeader.bfOffBits, SEEK_SET);

    uint8_t *extractedWatermark = (uint8_t *)malloc(watermarkSize);
    
    // Extract LSBs for the watermark
    for (long i = 0; i < watermarkSize * 8; i++) {
        if (i >= pixelDataSize) break;

        int bit = (fgetc(input) & 1);  // Get LSB of the red channel
        extractedWatermark[i / 8] |= (bit << (i % 8));
    }

    // Write the extracted watermark
    fwrite(extractedWatermark, 1, watermarkSize, output);

    // Free resources
    free(extractedWatermark);
    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <embed/extract> <input BMP> <output BMP> <watermark file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedWatermark(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        long watermarkSize = strlen(argv[4]); // Assuming size is provided correctly
        extractWatermark(argv[2], argv[3], watermarkSize);
    } else {
        fprintf(stderr, "Invalid command. Use 'embed' or 'extract'.\n");
        return 1;
    }

    return 0;
}