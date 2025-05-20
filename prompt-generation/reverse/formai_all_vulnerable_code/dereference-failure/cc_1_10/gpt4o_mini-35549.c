//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)  // Ensure structure packing
typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} BMPFileHeader;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitCount;
    unsigned int compression;
    unsigned int sizeImage;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int colorsImportant;
} BMPInfoHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;

#pragma pack(pop)

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, input);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, input);
    
    int imageSize = infoHeader.width * infoHeader.height;
    Pixel *pixelArray = malloc(imageSize * sizeof(Pixel));
    fseek(input, fileHeader.offset, SEEK_SET);
    fread(pixelArray, sizeof(Pixel), imageSize, input);
    fclose(input);

    int watermarkLength = strlen(watermark);
    for (int i = 0; i < watermarkLength; i++) {
        int pixelIndex = (i % imageSize);
        pixelArray[pixelIndex].blue = (pixelArray[pixelIndex].blue & 0xFE) | ((watermark[i] >> 7) & 0x01);
        pixelArray[pixelIndex].green = (pixelArray[pixelIndex].green & 0xFE) | ((watermark[i] >> 6) & 0x01);
        pixelArray[pixelIndex].red = (pixelArray[pixelIndex].red & 0xFE) | ((watermark[i] >> 5) & 0x01);
    }

    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        perror("Error opening output file");
        free(pixelArray);
        exit(EXIT_FAILURE);
    }

    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, output);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, output);
    fseek(output, fileHeader.offset, SEEK_SET);
    fwrite(pixelArray, sizeof(Pixel), imageSize, output);

    free(pixelArray);
    fclose(output);
}

void printUsage() {
    printf("Usage: watermark <input BMP file> <output BMP file> <watermark string>\n");
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    const char *watermark = argv[3];

    embedWatermark(inputFile, outputFile, watermark);
    printf("Watermark embedded successfully!\n");
    
    return EXIT_SUCCESS;
}