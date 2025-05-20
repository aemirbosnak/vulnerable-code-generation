//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void embed_watermark(const char *input_file, const char *output_file, const char *watermark) {
    FILE *bmpFile = fopen(input_file, "rb");
    if (!bmpFile) {
        fprintf(stderr, "Error: Could not open input file.\n");
        return;
    }

    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, bmpFile);

    // Check if the file is a BMP
    if (bmpFileHeader.bfType != 0x4D42) {
        fprintf(stderr, "Error: Not a BMP file.\n");
        fclose(bmpFile);
        return;
    }

    // Open output file for writing
    FILE *outputFile = fopen(output_file, "wb");
    if (!outputFile) {
        fprintf(stderr, "Error: Could not open output file.\n");
        fclose(bmpFile);
        return;
    }

    // Write headers to the output file
    fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);

    // Write the bitmap pixels with watermark
    unsigned char pixel[3]; // For RGB pixel
    int index = 0;

    // Embed watermark bit by bit
    for (int y = 0; y < bmpInfoHeader.biHeight; y++) {
        for (int x = 0; x < bmpInfoHeader.biWidth; x++) {
            fread(pixel, sizeof(unsigned char), 3, bmpFile); // Read pixel
            // Embed current watermark bit in the least significant bit
            if (index < strlen(watermark) * 8) {
                int bit = (watermark[index / 8] >> (7 - (index % 8))) & 1;
                pixel[0] = (pixel[0] & ~1) | bit; // Modify the LSB of the blue component
                index++;
            }
            fwrite(pixel, sizeof(unsigned char), 3, outputFile); // Write modified pixel
        }
    }

    fclose(bmpFile);
    fclose(outputFile);
    printf("Watermark embedded successfully!\n");
}

void extract_watermark(const char *input_file, int watermark_size) {
    FILE *bmpFile = fopen(input_file, "rb");
    if (!bmpFile) {
        fprintf(stderr, "Error: Could not open input file.\n");
        return;
    }

    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, bmpFile);

    // Check if the file is a BMP
    if (bmpFileHeader.bfType != 0x4D42) {
        fprintf(stderr, "Error: Not a BMP file.\n");
        fclose(bmpFile);
        return;
    }

    char *watermark = (char *)malloc(watermark_size + 1);
    memset(watermark, 0, watermark_size + 1);

    unsigned char pixel[3];
    int index = 0;

    // Extract watermark bit by bit
    for (int y = 0; y < bmpInfoHeader.biHeight; y++) {
        for (int x = 0; x < bmpInfoHeader.biWidth; x++) {
            fread(pixel, sizeof(unsigned char), 3, bmpFile); // Read pixel
            if (index < watermark_size * 8) {
                int bit = pixel[0] & 1; // Get the LSB of the blue component
                watermark[index / 8] |= (bit << (7 - (index % 8))); // Set the watermark bit
                index++;
            }
        }
    }

    fclose(bmpFile);
    printf("Extracted Watermark: %s\n", watermark);
    free(watermark);
}

int main() {
    const char *input_image = "input.bmp"; // Ensure this file exists
    const char *output_image = "output.bmp";
    const char *watermark_text = "Hello!";

    embed_watermark(input_image, output_image, watermark_text);

    // Extract watermark from the output image
    extract_watermark(output_image, strlen(watermark_text));

    return 0;
}