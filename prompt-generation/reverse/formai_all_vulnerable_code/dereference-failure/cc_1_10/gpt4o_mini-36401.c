//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // Magic number for the bitmap
    uint32_t bfSize;      // Size of the bitmap file
    uint16_t bfReserved1; // Reserved; must be zero
    uint16_t bfReserved2; // Reserved; must be zero
    uint32_t bfOffBits;   // Offset to bitmap data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;           // Size of this header
    int32_t  biWidth;          // Width of the bitmap in pixels
    int32_t  biHeight;         // Height of the bitmap in pixels
    uint16_t biPlanes;         // Number of color planes
    uint16_t biBitCount;       // Number of bits per pixel
    uint32_t biCompression;     // Compression type
    uint32_t biSizeImage;      // Image size (in bytes)
    int32_t  biXPixPerMeter;    // Horizontal resolution
    int32_t  biYPixPerMeter;    // Vertical resolution
    uint32_t biClrUsed;        // Number of colors in the bitmap
    uint32_t biClrImportant;    // Important colors
} BITMAPINFOHEADER;

#pragma pack(pop)

void encodeMessageInBitmap(const char* bitmapPath, const char* message, const char* outputPath) {
    FILE *inputFile = fopen(bitmapPath, "rb");
    if (!inputFile) {
        fprintf(stderr, "Error: Cannot open input bitmap file!\n");
        exit(1);
    }

    BITMAPFILEHEADER bmfHeader;
    BITMAPINFOHEADER bmiHeader;
    fread(&bmfHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&bmiHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);
    
    if (bmfHeader.bfType != 0x4D42) {
        fprintf(stderr, "Error: Not a valid BMP file!\n");
        fclose(inputFile);
        exit(1);
    }

    FILE *outputFile = fopen(outputPath, "wb");
    if (!outputFile) {
        fprintf(stderr, "Error: Cannot open output bitmap file!\n");
        fclose(inputFile);
        exit(1);
    }

    fwrite(&bmfHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bmiHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);

    uint32_t pixelDataSize = bmfHeader.bfSize - bmfHeader.bfOffBits;
    fseek(inputFile, bmfHeader.bfOffBits, SEEK_SET);
    
    uint8_t *pixelData = (uint8_t *)malloc(pixelDataSize);
    fread(pixelData, pixelDataSize, 1, inputFile);
    
    size_t messageLength = strlen(message);
    if (messageLength > pixelDataSize) {
        fprintf(stderr, "Error: Message is too long for the given bitmap!\n");
        free(pixelData);
        fclose(inputFile);
        fclose(outputFile);
        exit(1);
    }

    // Encode message length in the last byte of the last pixel
    pixelData[pixelDataSize - 1] = (uint8_t)messageLength;

    // Embed the message in the pixel data
    for (size_t i = 0; i < messageLength; ++i) {
        pixelData[i * 8]     = (pixelData[i * 8] & 0xFE) | ((message[i] >> 7) & 0x01);
        pixelData[i * 8 + 1] = (pixelData[i * 8 + 1] & 0xFE) | ((message[i] >> 6) & 0x01);
        pixelData[i * 8 + 2] = (pixelData[i * 8 + 2] & 0xFE) | ((message[i] >> 5) & 0x01);
        pixelData[i * 8 + 3] = (pixelData[i * 8 + 3] & 0xFE) | ((message[i] >> 4) & 0x01);
        pixelData[i * 8 + 4] = (pixelData[i * 8 + 4] & 0xFE) | ((message[i] >> 3) & 0x01);
        pixelData[i * 8 + 5] = (pixelData[i * 8 + 5] & 0xFE) | ((message[i] >> 2) & 0x01);
        pixelData[i * 8 + 6] = (pixelData[i * 8 + 6] & 0xFE) | ((message[i] >> 1) & 0x01);
        pixelData[i * 8 + 7] = (pixelData[i * 8 + 7] & 0xFE) | (message[i] & 0x01);
    }

    fwrite(pixelData, pixelDataSize, 1, outputFile);

    free(pixelData);
    fclose(inputFile);
    fclose(outputFile);
    
    printf("Success! The message has been encoded into %s.\n", outputPath);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_bmp> <message> <output_bmp>\n", argv[0]);
        return 1;
    }

    encodeMessageInBitmap(argv[1], argv[2], argv[3]);
    return 0;
}