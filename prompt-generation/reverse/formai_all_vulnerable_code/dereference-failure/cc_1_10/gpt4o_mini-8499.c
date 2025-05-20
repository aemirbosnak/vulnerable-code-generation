//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define a struct for a BMP file header
#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // Magic number for BMP files
    uint32_t bfSize;      // Size of the BMP file
    uint16_t bfReserved1; // Reserved; must be 0
    uint16_t bfReserved2; // Reserved; must be 0
    uint32_t bfOffBits;   // Offset to start of pixel data
} BITMAPFILEHEADER;

// Define a struct for BMP info header
typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of image
    int32_t  biHeight;        // Height of image
    uint16_t biPlanes;        // Number of color planes; must be 1
    uint16_t biBitCount;      // Number of bits per pixel
    uint32_t biCompression;   // Type of compression
    uint32_t biSizeImage;     // Size of image data (can be zero for BI_RGB)
    int32_t  biXPelsPerMeter;  // Horizontal resolution
    int32_t  biYPelsPerMeter;  // Vertical resolution
    uint32_t biClrUsed;       // Number of colors in the palette
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;

// Function to encode a message into a BMP image
void encode(const char *inputImage, const char *message, const char *outputImage) {
    // Open the input image file
    FILE *imgFile = fopen(inputImage, "rb");
    if (!imgFile) {
        perror("Failed to open input image");
        exit(EXIT_FAILURE);
    }

    // Read BMP file header
    BITMAPFILEHEADER bmpFileHeader;
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, imgFile);

    // Read BMP info header
    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, imgFile);

    // Calculate the size of the image data
    size_t dataSize = bmpFileHeader.bfSize - bmpFileHeader.bfOffBits;
    uint8_t *imageData = (uint8_t *)malloc(dataSize);
    fseek(imgFile, bmpFileHeader.bfOffBits, SEEK_SET);
    fread(imageData, 1, dataSize, imgFile);
    
    fclose(imgFile);

    // Prepare the message to be encoded
    size_t messageLength = strlen(message);
    size_t totalBits = messageLength * 8 + 1; // +1 for the null terminator
    if (totalBits > dataSize * 8) {
        fprintf(stderr, "Message is too long to fit in the image\n");
        free(imageData);
        exit(EXIT_FAILURE);
    }

    // Encode the message into the image data
    for (size_t i = 0; i < totalBits; i++) {
        size_t byteIndex = i / 8;
        size_t bitIndex = i % 8;
        uint8_t messageBit = (message[i / 8] >> (7 - bitIndex)) & 1;

        // Set the least significant bit of the image data
        imageData[byteIndex] = (imageData[byteIndex] & ~1) | messageBit;
    }

    // Open the output file to save the modified image
    FILE *outFile = fopen(outputImage, "wb");
    if (!outFile) {
        perror("Failed to create output image");
        free(imageData);
        exit(EXIT_FAILURE);
    }

    // Write the original headers and the modified image data
    fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, outFile);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, outFile);
    fwrite(imageData, 1, dataSize, outFile);

    free(imageData);
    fclose(outFile);    
    printf("Message encoded successfully in %s\n", outputImage);
}

// Function to decode the message from a BMP image
void decode(const char *inputImage) {
    // Open the input image file
    FILE *imgFile = fopen(inputImage, "rb");
    if (!imgFile) {
        perror("Failed to open input image");
        exit(EXIT_FAILURE);
    }

    // Read BMP file header
    BITMAPFILEHEADER bmpFileHeader;
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, imgFile);

    // Read BMP info header
    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, imgFile);

    // Calculate the size of image data
    size_t dataSize = bmpFileHeader.bfSize - bmpFileHeader.bfOffBits;
    uint8_t *imageData = (uint8_t *)malloc(dataSize);
    fseek(imgFile, bmpFileHeader.bfOffBits, SEEK_SET);
    fread(imageData, 1, dataSize, imgFile);
    
    fclose(imgFile);

    // Decode the message from the image data
    char *message = (char *)malloc(dataSize * 8);
    size_t messageIndex = 0;
    
    // Read bits from the pixel data until a null terminator is found
    for (size_t i = 0; i < dataSize * 8; i++) {
        size_t byteIndex = i / 8;
        size_t bitIndex = i % 8;

        uint8_t messageBit = (imageData[byteIndex] & 1);
        message[messageIndex / 8] = (message[messageIndex / 8] << 1) | messageBit;

        if (messageIndex % 8 == 7) { // Check if we have a complete byte
            if (message[messageIndex / 8] == '\0') {
                break; // End of message
            }
        }
        messageIndex++;
    }

    printf("Decoded Message: %s\n", message);
    free(imageData);
    free(message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s encode|decode <input image> <message|output image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encode(argv[2], argv[3], "output.bmp");
    } else if (strcmp(argv[1], "decode") == 0) {
        decode(argv[2]);
    } else {
        fprintf(stderr, "Invalid option. Use 'encode' or 'decode'\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}