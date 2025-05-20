//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// BMP file header structure
#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // BMP file type
    uint32_t bfSize;      // BMP file size in bytes
    uint16_t bfUnused1;   // Unused
    uint16_t bfUnused2;   // Unused
    uint32_t bfOffBits;   // Offset to the pixel data
} BMPHeader;

// BMP info header structure
typedef struct {
    uint32_t biSize;          // Size of the info header
    int32_t  biWidth;         // Width of the image
    int32_t  biHeight;        // Height of the image
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;   // Compression method
    uint32_t biSizeImage;     // Image size
    int32_t  biXPelsPerMeter;  // Horizontal resolution
    int32_t  biYPelsPerMeter;  // Vertical resolution
    uint32_t biClrUsed;       // Number of colors
    uint32_t biClrImportant;   // Important colors
} BMPInfoHeader;
#pragma pack(pop)

// Function prototypes
void embedMessage(const char *inputImage, const char *outputImage, const char *message);
void extractMessage(const char *inputImage, char *outputMessage, size_t maxMessageLength);
uint8_t getLSB(uint8_t byte);
void setLSB(uint8_t *byte, uint8_t bit);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <embed/extract> <input_image> <output_image/message_buffer> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessage(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        char message[256] = {0};
        extractMessage(argv[2], message, sizeof(message));
        printf("Extracted Message: %s\n", message);
    } else {
        printf("Invalid option. Use 'embed' or 'extract'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void embedMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *inputFile = fopen(inputImage, "rb");
    if (!inputFile) {
        perror("Failed to open input image");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputImage, "wb");
    if (!outputFile) {
        perror("Failed to open output image");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);

    size_t messageLength = strlen(message);
    size_t totalBytes = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * (bmpInfoHeader.biBitCount / 8);
    
    fseek(inputFile, bmpHeader.bfOffBits, SEEK_SET);
    fseek(outputFile, bmpHeader.bfOffBits, SEEK_SET);

    uint8_t pixelData[3];
    size_t messageIndex = 0;

    for (size_t i = 0; i < totalBytes; i += 3) {
        fread(pixelData, 1, 3, inputFile);

        for (int j = 0; j < 3; ++j) {
            if (messageIndex < messageLength || (j == 2 && messageIndex == messageLength)) {
                uint8_t bit = (messageIndex < messageLength) ? (message[messageIndex] >> (7 - (i % 8))) & 1 : 0;
                setLSB(&pixelData[j], bit);
                if (j == 2) messageIndex++;
            }
        }
        fwrite(pixelData, 1, 3, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Message embedded successfully.\n");
}

void extractMessage(const char *inputImage, char *outputMessage, size_t maxMessageLength) {
    FILE *inputFile = fopen(inputImage, "rb");
    if (!inputFile) {
        perror("Failed to open input image");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    fseek(inputFile, bmpHeader.bfOffBits, SEEK_SET);

    uint8_t pixelData[3];
    size_t messageIndex = 0;
    char message[256] = {0};

    for (size_t i = 0; i < (bmpInfoHeader.biWidth * bmpInfoHeader.biHeight) * 3; i += 3) {
        fread(pixelData, 1, 3, inputFile);

        for (int j = 0; j < 3; ++j) {
            if (messageIndex < 256) {
                if (j == 2) {  // Get the LSB from the blue channel
                    message[messageIndex] |= (getLSB(pixelData[j]) << (7 - (i % 8)));
                    if ((i % 24) == 23) messageIndex++;
                }
            }
        }
    }

    fclose(inputFile);
    strncpy(outputMessage, message, maxMessageLength);
    printf("Message extracted successfully.\n");
}

uint8_t getLSB(uint8_t byte) {
    return byte & 1;
}

void setLSB(uint8_t *byte, uint8_t bit) {
    if (bit) {
        *byte |= 1;  // Set the least significant bit to 1
    } else {
        *byte &= ~1;  // Set the least significant bit to 0
    }
}