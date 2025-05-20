//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
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
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} PIXEL;
#pragma pack(pop)

void embedMessageInBMP(const char *bmpFilePath, const char *message, const char *outputFilePath) {
    FILE *bmpFile = fopen(bmpFilePath, "rb");
    if (!bmpFile) {
        fprintf(stderr, "Error opening BMP file.\n");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, bmpFile);

    long pixelArrayOffset = bfh.bfOffBits;
    fseek(bmpFile, pixelArrayOffset, SEEK_SET);

    long totalPixels = bih.biWidth * bih.biHeight;
    size_t messageLength = strlen(message);
    size_t messageBits = messageLength * 8 + 1; // +1 for the null terminator

    if (messageBits > totalPixels) {
        fprintf(stderr, "Message is too long to embed in this BMP file.\n");
        fclose(bmpFile);
        exit(EXIT_FAILURE);
    }

    PIXEL *pixelArray = (PIXEL *)malloc(totalPixels * sizeof(PIXEL));
    fread(pixelArray, sizeof(PIXEL), totalPixels, bmpFile);
    fclose(bmpFile);

    for (size_t i = 0; i < messageBits; i++) {
        size_t pixelIndex = i / 8;
        size_t bitIndex = i % 8;

        uint8_t bit = (message[i / 8] >> (7 - bitIndex)) & 1;
        if (bit) {
            pixelArray[pixelIndex].red |= 1;    // Set LSB to 1
        } else {
            pixelArray[pixelIndex].red &= ~1;   // Set LSB to 0
        }
    }

    FILE *outputFile = fopen(outputFilePath, "wb");
    if (!outputFile) {
        fprintf(stderr, "Error creating output BMP file.\n");
        free(pixelArray);
        exit(EXIT_FAILURE);
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fwrite(pixelArray, sizeof(PIXEL), totalPixels, outputFile);
    
    free(pixelArray);
    fclose(outputFile);
}

void extractMessageFromBMP(const char *bmpFilePath) {
    FILE *bmpFile = fopen(bmpFilePath, "rb");
    if (!bmpFile) {
        fprintf(stderr, "Error opening BMP file.\n");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, bmpFile);

    long pixelArrayOffset = bfh.bfOffBits;
    fseek(bmpFile, pixelArrayOffset, SEEK_SET);

    long totalPixels = bih.biWidth * bih.biHeight;

    char *message = (char *)malloc(totalPixels / 8 + 1);
    size_t messageIndex = 0;

    PIXEL pixel;
    for (size_t i = 0; i < totalPixels; i++) {
        fread(&pixel, sizeof(PIXEL), 1, bmpFile);
        message[messageIndex] <<= 1; // Shift left
        message[messageIndex] |= (pixel.red & 1); // Get LSB

        if ((i + 1) % 8 == 0) {
            messageIndex++;
            if (messageIndex >= (totalPixels / 8)) break; // Limit to message length
        }
    }
    
    message[messageIndex] = '\0'; // Null-terminate the message
    printf("Extracted message: %s\n", message);
    
    free(message);
    fclose(bmpFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed/extract> <BMP file path> <message/output file path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessageInBMP(argv[2], argv[3], "output.bmp");
        printf("Message embedded into 'output.bmp'.\n");
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessageFromBMP(argv[2]);
    } else {
        fprintf(stderr, "Unknown action: %s. Use 'embed' or 'extract'.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}