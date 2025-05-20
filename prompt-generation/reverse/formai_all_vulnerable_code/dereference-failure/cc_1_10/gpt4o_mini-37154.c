//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    unsigned char signature[2]; // BMP file signature
    unsigned int fileSize; 
    unsigned short reserved1; 
    unsigned short reserved2; 
    unsigned int dataOffset; 
} BMPHeader;

typedef struct {
    unsigned int size; 
    int width; 
    int height; 
    unsigned short planes; 
    unsigned short bitsPerPixel; 
    unsigned int compression; 
    unsigned int imageSize; 
    int xPixelsPerMeter; 
    int yPixelsPerMeter; 
    unsigned int totalColors; 
    unsigned int importantColors; 
} BMPInfoHeader;

void embedWatermark(const char *bmpFile, const char *watermarkText) {
    FILE *file = fopen(bmpFile, "r+b");
    if (!file) {
        perror("Error opening BMP file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(bmpHeader), 1, file);
    fread(&bmpInfoHeader, sizeof(bmpInfoHeader), 1, file);

    if (bmpHeader.signature[0] != 'B' || bmpHeader.signature[1] != 'M') {
        printf("Not a valid BMP file.\n");
        fclose(file);
        return;
    }

    int x, y, byte;
    int watermarkLength = strlen(watermarkText);
    int watermarkBit = 0;

    // Loop through each pixel
    for (y = 0; y < bmpInfoHeader.height; y++) {
        for (x = 0; x < bmpInfoHeader.width; x++) {
            // Each pixel consists of 3 bytes (B, G, R)
            for (byte = 0; byte < 3; byte++) {
                unsigned char pixelValue;
                fread(&pixelValue, sizeof(unsigned char), 1, file);
                
                if (watermarkBit < watermarkLength * 8) {
                    // Get the bit to embed
                    unsigned char bit = (watermarkText[watermarkBit / 8] >> (7 - (watermarkBit % 8))) & 1;
                    // Set the least significant bit
                    if (bit) {
                        pixelValue |= 1;
                    } else {
                        pixelValue &= ~1;
                    }
                    watermarkBit++;
                }

                // Move the file pointer back to the correct position
                fseek(file, -1, SEEK_CUR);
                fwrite(&pixelValue, sizeof(unsigned char), 1, file);
            }
            // Important: Move to next pixel with padding if needed
            int rowSize = (bmpInfoHeader.bitsPerPixel * bmpInfoHeader.width + 31) / 32 * 4;
            int paddingSize = rowSize - bmpInfoHeader.width * 3;
            fseek(file, paddingSize, SEEK_CUR);
        }
    }

    fclose(file);
    printf("Watermark embedded successfully!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <BMP file> <watermark text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    embedWatermark(argv[1], argv[2]);
    return EXIT_SUCCESS;
}