//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Disable padding
typedef struct {
    unsigned char  bfType[2];      // BMP file type (should be 'BM')
    unsigned int   bfSize;         // Size of the BMP file
    unsigned short bfReserved1;    // Reserved, must be zero
    unsigned short bfReserved2;    // Reserved, must be zero
    unsigned int   bfOffBits;      // Offset to the pixel data
} BITMAPFILEHEADER;

typedef struct {
    unsigned int   biSize;         // Size of this header (40 bytes)
    int            biWidth;        // Width of the image
    int            biHeight;       // Height of the image
    unsigned short biPlanes;       // Number of color planes, must be 1
    unsigned short biBitCount;     // Bits per pixel (1, 4, 8, 16, 24, or 32)
    unsigned int   biCompression;   // Compression type
    unsigned int   biSizeImage;    // Image size (can be zero for uncompressed)
    int            biXPelsPerMeter; // Horizontal resolution (pixels per meter)
    int            biYPelsPerMeter; // Vertical resolution (pixels per meter)
    unsigned int   biClrUsed;      // Number of colors in color palette
    unsigned int   biClrImportant;  // Important colors
} BITMAPINFOHEADER;

#pragma pack(pop)

void embedMessage(const char* inputImage, const char* outputImage, const char* message) {
    FILE *fpInput = fopen(inputImage, "rb");
    if (!fpInput) {
        printf("Error: Unable to open input image.\n");
        return;
    }

    BITMAPFILEHEADER bmpFileHeader;
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, fpInput);

    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fpInput);

    // Check if the file is a BMP image
    if (bmpFileHeader.bfType[0] != 'B' || bmpFileHeader.bfType[1] != 'M') {
        printf("Error: Not a BMP file.\n");
        fclose(fpInput);
        return;
    }

    // Calculate the size of the pixel data
    unsigned int pixelDataSize = bmpFileHeader.bfSize - bmpFileHeader.bfOffBits;
    unsigned char* pixelData = (unsigned char*)malloc(pixelDataSize);
    fseek(fpInput, bmpFileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, pixelDataSize, 1, fpInput);
    fclose(fpInput);

    // Check message length
    size_t messageLength = strlen(message);
    if (messageLength * 8 + 1 > pixelDataSize) {
        printf("Error: Message is too long to be embedded.\n");
        free(pixelData);
        return;
    }

    // Embed the message into pixel data
    unsigned char* messageBits = (unsigned char*)malloc(messageLength * 8 + 1); // +1 for null terminator
    for (size_t i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            messageBits[i * 8 + j] = (message[i] >> (7 - j)) & 1;
        }
    }
    messageBits[messageLength * 8] = '\0'; // Null-terminate

    for (size_t i = 0; i < messageLength * 8; i++) {
        pixelData[i] = (pixelData[i] & 0xFE) | messageBits[i];
    }

    // Write to output image
    FILE *fpOutput = fopen(outputImage, "wb");
    if (!fpOutput) {
        printf("Error: Unable to open output image.\n");
        free(pixelData);
        free(messageBits);
        return;
    }

    fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, fpOutput);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fpOutput);
    fwrite(pixelData, pixelDataSize, 1, fpOutput);
    fclose(fpOutput);

    free(pixelData);
    free(messageBits);
    printf("Message embedded successfully!\n");
}

void extractMessage(const char* inputImage) {
    FILE *fpInput = fopen(inputImage, "rb");
    if (!fpInput) {
        printf("Error: Unable to open input image.\n");
        return;
    }

    BITMAPFILEHEADER bmpFileHeader;
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, fpInput);

    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fpInput);

    // Check if the file is a BMP image
    if (bmpFileHeader.bfType[0] != 'B' || bmpFileHeader.bfType[1] != 'M') {
        printf("Error: Not a BMP file.\n");
        fclose(fpInput);
        return;
    }

    // Calculate the size of the pixel data
    unsigned int pixelDataSize = bmpFileHeader.bfSize - bmpFileHeader.bfOffBits;
    unsigned char* pixelData = (unsigned char*)malloc(pixelDataSize);
    fseek(fpInput, bmpFileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, pixelDataSize, 1, fpInput);
    fclose(fpInput);

    // Extract the message from pixel data
    char extractedMessage[256] = {0};
    size_t messageLength = 0;
    for (size_t i = 0; pixelData[i] != '\0'; i++) {
        if (i >= 8 * 256) break; // Prevent buffer overflow
        if ((pixelData[i] & 1) == 1) {
            extractedMessage[messageLength / 8] |= (1 << (7 - (messageLength % 8)));
        }
        messageLength++;
    }

    printf("Extracted Message: %s\n", extractedMessage);

    free(pixelData);
}

int main() {
    char inputImage[] = "input.bmp"; // Specify input BMP file
    char outputImage[] = "output.bmp"; // Specify output BMP file
    char message[] = "Hello, World!"; // Specify the message to hide

    embedMessage(inputImage, outputImage, message);
    extractMessage(outputImage);

    return 0;
}