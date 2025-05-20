//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensure proper structure alignment for BMP file
typedef struct {
    unsigned short bfType;      // Magic number for file
    unsigned long bfSize;       // Size of the file in bytes
    unsigned short bfReserved1; // Reserved
    unsigned short bfReserved2; // Reserved
    unsigned long bfOffBits;     // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    unsigned long biSize;          // Size of the header
    long biWidth;                  // Width of the image
    long biHeight;                 // Height of the image
    unsigned short biPlanes;       // Number of color planes
    unsigned short biBitCount;     // Bits per pixel
    unsigned long biCompression;    // Compression type
    unsigned long biSizeImage;      // Size of the image data
    long biXPelsPerMeter;           // Horizontal resolution
    long biYPelsPerMeter;           // Vertical resolution
    unsigned long biClrUsed;        // Number of colors in the palette
    unsigned long biClrImportant;   // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

// Function prototypes
void encodeMessage(const char *inputImage, const char *outputImage, const char *message);
void decodeMessage(const char *inputImage);
void handleError(const char *message);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Encoding
    encodeMessage(argv[1], argv[2], argv[3]);
    // Decoding (for demonstration, uncomment to decode after hiding)
    // decodeMessage(argv[2]);

    return EXIT_SUCCESS;
}

void encodeMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *inputFile = fopen(inputImage, "rb");
    if (!inputFile) handleError("Could not open input file.");

    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;

    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);
 
    // Calculate the ending position based on message length
    size_t messageLength = strlen(message);
    if (messageLength > 255) handleError("Message too long to encode.");
    
    // Read BMP pixel data
    size_t pixelArraySize = bmpFileHeader.bfSize - bmpFileHeader.bfOffBits;
    unsigned char *pixelData = (unsigned char *)malloc(pixelArraySize);
    fseek(inputFile, bmpFileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, sizeof(unsigned char), pixelArraySize, inputFile);
    fclose(inputFile);
    
    // Embed the message length at the last pixel
    pixelData[pixelArraySize - 1] = (unsigned char)messageLength;
    for (size_t i = 0; i < messageLength; i++) {
        pixelData[pixelArraySize - 2 - i] = (pixelData[pixelArraySize - 2 - i] & 0xFE) | ((message[i] >> 7) & 0x01); // LSB
        for (int j = 6; j >= 0; j--) { // Embed the remaining bits
            pixelData[pixelArraySize - 2 - i] = (pixelData[pixelArraySize - 2 - i] & 0xFE) | ((message[i] >> j) & 0x01);
        }
    }
    
    // Write the modified pixel data to the output file
    FILE *outputFile = fopen(outputImage, "wb");
    if (!outputFile) handleError("Could not open output file.");
    
    fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fwrite(pixelData, sizeof(unsigned char), pixelArraySize, outputFile);

    free(pixelData);
    fclose(outputFile);

    printf("Message successfully encoded into %s\n", outputImage);
}

void decodeMessage(const char *inputImage) {
    FILE *inputFile = fopen(inputImage, "rb");
    if (!inputFile) handleError("Could not open input file.");

    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;

    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    // Read BMP pixel data
    size_t pixelArraySize = bmpFileHeader.bfSize - bmpFileHeader.bfOffBits;
    unsigned char *pixelData = (unsigned char *)malloc(pixelArraySize);
    fseek(inputFile, bmpFileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, sizeof(unsigned char), pixelArraySize, inputFile);
    fclose(inputFile);

    // Extract the message length
    size_t messageLength = (size_t)pixelData[pixelArraySize - 1];
    
    char *message = (char *)malloc(messageLength + 1);
    message[messageLength] = '\0'; // null-terminate the string

    for (size_t i = 0; i < messageLength; i++) {
        unsigned char pixel = pixelData[pixelArraySize - 2 - i];
        message[i] = 0; // clear the byte
        for (int j = 7; j >= 0; j--) {
            message[i] |= ((pixel & 0x01) << j); // retrieve each bit
            pixel >>= 1;
        }
    }

    printf("Decoded message: %s\n", message);
    free(message);
    free(pixelData);
}

void handleError(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}