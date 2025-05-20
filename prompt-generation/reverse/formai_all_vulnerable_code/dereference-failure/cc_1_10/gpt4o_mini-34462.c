//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;       // File type: must be "BM"
    uint32_t bfSize;       // Size of the file in bytes
    uint16_t bfReserved1;  // Reserved; must be zero
    uint16_t bfReserved2;  // Reserved; must be zero
    uint32_t bfOffBits;    // Offset to the pixel data
} BMPHeader;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t biWidth;          // Width of the bitmap in pixels
    int32_t biHeight;         // Height of the bitmap in pixels
    uint16_t biPlanes;        // Number of color planes (must be 1)
    uint16_t biBitCount;      // Number of bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Size of the image data
    int32_t biXPelsPerMeter;   // Horizontal resolution
    int32_t biYPelsPerMeter;   // Vertical resolution
    uint32_t biClrUsed;       // Number of colors used
    uint32_t biClrImportant;   // Important color
} BMPInfoHeader;

#pragma pack(pop)

void embedMessageInBMP(const char *inputFileName, const char *outputFileName, const char *message) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    if (bmpHeader.bfType != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file\n");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    int messageLength = strlen(message);
    int totalBitsToEmbed = messageLength * 8 + 1; // +1 for null-terminator

    // Calculate the number of pixels
    int pixelCount = (bmpInfoHeader.biWidth * bmpInfoHeader.biHeight);

    if (totalBitsToEmbed > pixelCount * 3) {
        fprintf(stderr, "Message is too large to be embedded in this image\n");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    uint8_t pixel[3];
    fseek(inputFile, bmpHeader.bfOffBits, SEEK_SET);

    for (int i = 0; i < totalBitsToEmbed; i++) {
        fread(pixel, sizeof(uint8_t), 3, inputFile);

        // Modify the least significant bit of the pixel
        pixel[0] = (pixel[0] & 0xFE) | ((message[i / 8] >> (7 - (i % 8))) & 0x01);

        // Write the pixel back into the image
        fseek(inputFile, -3, SEEK_CUR);
        fwrite(pixel, sizeof(uint8_t), 3, inputFile);
    }

    // Copy the rest of the image data (if any)
    uint8_t *buffer = malloc(bmpInfoHeader.biSizeImage);
    fread(buffer, sizeof(uint8_t), bmpInfoHeader.biSizeImage, inputFile);
    fwrite(buffer, sizeof(uint8_t), bmpInfoHeader.biSizeImage, outputFileName);
    
    free(buffer);
    fclose(inputFile);
}

void readMessageFromBMP(const char *inputFileName) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);
    
    uint8_t pixel[3];
    fseek(inputFile, bmpHeader.bfOffBits, SEEK_SET);

    char message[256] = {0};
    int count = 0;

    while (count < 255) {
        fread(pixel, sizeof(uint8_t), 3, inputFile);
        message[count / 8] |= (pixel[0] & 0x01) << (7 - (count % 8));
        
        if (message[count / 8] == '\0') {
            break; // Stop if null character found
        }
        count++;
    }

    printf("Embedded message: %s\n", message);
    
    fclose(inputFile);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed/read> <image.bmp> <message/output.bmp>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessageInBMP(argv[2], argv[3], argv[2]);
        printf("Message embedded successfully.\n");
    } else if (strcmp(argv[1], "read") == 0) {
        readMessageFromBMP(argv[2]);
    } else {
        fprintf(stderr, "Invalid option. Use 'embed' or 'read'.\n");
    }

    return 0;
}