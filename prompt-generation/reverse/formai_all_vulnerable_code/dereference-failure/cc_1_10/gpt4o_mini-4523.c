//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: scientific
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
} BMPFileHeader;

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
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;
#pragma pack(pop)

void embedMessageInBMP(const char* inputBMP, const char* outputBMP, const char* message) {
    FILE *inputFile = fopen(inputBMP, "rb");
    if (!inputFile) {
        perror("Error opening input BMP file");
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, inputFile);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    if (fileHeader.bfType != 0x4D42) {
        fprintf(stderr, "Error: Not a valid BMP file.\n");
        fclose(inputFile);
        return;
    }

    int messageLength = strlen(message);
    int totalPixels = (infoHeader.biWidth * infoHeader.biHeight);
    if (messageLength * 8 > totalPixels) {
        fprintf(stderr, "Error: Message is too long to embed in the image.\n");
        fclose(inputFile);
        return;
    }

    RGB *pixels = malloc(totalPixels * sizeof(RGB));
    fseek(inputFile, fileHeader.bfOffBits, SEEK_SET);
    fread(pixels, sizeof(RGB), totalPixels, inputFile);
    fclose(inputFile);

    // Embed the message in the least significant bits of the pixel data
    for (int i = 0; i < messageLength; ++i) {
        for (int j = 0; j < 8; ++j) {
            int pixelIndex = i * 8 + j;
            if (pixelIndex >= totalPixels) break;

            // Modify the blue component in the RGB pixel
            pixels[pixelIndex].blue = (pixels[pixelIndex].blue & 0xFE) | ((message[i] >> (7 - j)) & 0x01);
        }
    }

    // Write the modified pixels to a new BMP file
    FILE *outputFile = fopen(outputBMP, "wb");
    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, outputFile);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, outputFile);
    fwrite(pixels, sizeof(RGB), totalPixels, outputFile);
    fclose(outputFile);
    free(pixels);

    printf("Message embedded successfully in %s\n", outputBMP);
}

void extractMessageFromBMP(const char* inputBMP, int messageLength) {
    FILE *inputFile = fopen(inputBMP, "rb");
    if (!inputFile) {
        perror("Error opening BMP file");
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, inputFile);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    if (fileHeader.bfType != 0x4D42) {
        fprintf(stderr, "Error: Not a valid BMP file.\n");
        fclose(inputFile);
        return;
    }

    int totalPixels = (infoHeader.biWidth * infoHeader.biHeight);
    RGB *pixels = malloc(totalPixels * sizeof(RGB));
    fseek(inputFile, fileHeader.bfOffBits, SEEK_SET);
    fread(pixels, sizeof(RGB), totalPixels, inputFile);
    fclose(inputFile);

    char *extractedMessage = malloc(messageLength + 1);
    extractedMessage[messageLength] = '\0';

    // Extract the message from the least significant bits of the pixel data
    for (int i = 0; i < messageLength; ++i) {
        char byte = 0;
        for (int j = 0; j < 8; ++j) {
            int pixelIndex = i * 8 + j;
            if (pixelIndex >= totalPixels) break;

            // Read the blue component in the RGB pixel
            byte |= ((pixels[pixelIndex].blue & 0x01) << (7 - j));
        }
        extractedMessage[i] = byte;
    }
    
    free(pixels);
    printf("Extracted message: %s\n", extractedMessage);
    free(extractedMessage);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed/extract> <input.bmp> <output.bmp/message_length> [message]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0 && argc == 5) {
        embedMessageInBMP(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0 && argc == 4) {
        int messageLength = atoi(argv[3]);
        extractMessageFromBMP(argv[2], messageLength);
    } else {
        fprintf(stderr, "Invalid command or arguments.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}