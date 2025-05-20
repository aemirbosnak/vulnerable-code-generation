//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1)

typedef struct {
    uint8_t  signature[2];
    uint32_t fileSize;
    uint32_t reserved;
    uint32_t dataOffset;
} BMPHeader;

typedef struct {
    uint32_t headerSize;
    int32_t  width;
    int32_t  height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    int32_t  xPixelsPerMeter;
    int32_t  yPixelsPerMeter;
    uint32_t totalColors;
    uint32_t importantColors;
} DIBHeader;

void encodeBMP(const char *bmpFile, const char *secretMessage);
void decodeBMP(const char *bmpFile);
void insertBit(uint8_t *byte, int bit);
int extractBit(uint8_t byte, int bitPosition);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <bmp_file> <secret_message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    encodeBMP(argv[1], argv[2]);
    decodeBMP(argv[1]);

    return 0;
}

void encodeBMP(const char *bmpFile, const char *secretMessage) {
    FILE *file = fopen(bmpFile, "r+b");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    DIBHeader dibHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, file);
    fread(&dibHeader, sizeof(DIBHeader), 1, file);
    
    fseek(file, bmpHeader.dataOffset, SEEK_SET);

    size_t messageLength = strlen(secretMessage);
    size_t totalBits = messageLength * 8 + 1; // + 1 for null terminator

    for (size_t i = 0; i < totalBits; ++i) {
        uint8_t pixelByte;
        fread(&pixelByte, sizeof(uint8_t), 1, file);

        int bitToInsert = (i < messageLength * 8) ? (secretMessage[i / 8] >> (7 - (i % 8)) & 1) : 0;
        insertBit(&pixelByte, bitToInsert);
        
        fseek(file, -1, SEEK_CUR);
        fwrite(&pixelByte, sizeof(uint8_t), 1, file);
    }

    fclose(file);
    printf("Message encoded into BMP file.\n");
}

void decodeBMP(const char *bmpFile) {
    FILE *file = fopen(bmpFile, "rb");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    DIBHeader dibHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, file);
    fread(&dibHeader, sizeof(DIBHeader), 1, file);
    
    fseek(file, bmpHeader.dataOffset, SEEK_SET);

    char *extractedMessage = (char *)malloc(256);
    size_t index = 0;

    while (1) {
        uint8_t pixelByte;
        fread(&pixelByte, sizeof(uint8_t), 1, file);
        
        int extractedBit = extractBit(pixelByte, 0);
        if (index < 255) {
            extractedMessage[index / 8] |= extractedBit << (7 - (index % 8));
            if (extractedBit == 0 && (index % 8 == 7)) { // Check end of message
                break;
            }
            index++;
        } else {
            break;
        }
    }

    extractedMessage[index / 8] = '\0'; // Null terminate the message
    fclose(file);

    printf("Extracted Message: %s\n", extractedMessage);
    free(extractedMessage);
}

void insertBit(uint8_t *byte, int bit) {
    if (bit) {
        *byte |= 1;   // Set LSB to 1
    } else {
        *byte &= ~1;  // Set LSB to 0
    }
}

int extractBit(uint8_t byte, int bitPosition) {
    return (byte >> bitPosition) & 1;
}