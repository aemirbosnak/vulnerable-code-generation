//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#pragma pack(1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} DIBHeader;

void encodeMessage(uint8_t *data, const char *message) {
    for (int i = 0; message[i] != '\0'; i++) {
        data[i] = (data[i] & 0xFE) | ((message[i] >> 7) & 0x01); // LSB
    }
}

void embedMessage(const char *inputFileName, const char *outputFileName, const char *message) {
    FILE *input = fopen(inputFileName, "rb");
    if (!input) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    DIBHeader dibHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, input);
    fread(&dibHeader, sizeof(DIBHeader), 1, input);

    if (bmpHeader.type != 0x4D42) {
        printf("Not a BMP file.\n");
        fclose(input);
        return;
    }

    uint32_t dataSize = dibHeader.width * dibHeader.height * (dibHeader.bitCount / 8);
    uint8_t *data = (uint8_t*)malloc(dataSize);
    fseek(input, bmpHeader.offset, SEEK_SET);
    fread(data, 1, dataSize, input);
    fclose(input);

    encodeMessage(data, message);

    FILE *output = fopen(outputFileName, "wb");
    if (!output) {
        perror("Error opening output file");
        free(data);
        exit(EXIT_FAILURE);
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, output);
    fwrite(&dibHeader, sizeof(DIBHeader), 1, output);
    fseek(output, bmpHeader.offset, SEEK_SET);
    fwrite(data, 1, dataSize, output);
    fclose(output);
    
    free(data);
    printf("Message embedded successfully!\n");
}

void decodeMessage(uint8_t *data, char *message, size_t messageLength) {
    for (int i = 0; i < messageLength; i++) {
        message[i] = 0; // Initialize character
        for (int bit = 0; bit < 8; bit++) {
            message[i] |= (data[i] & 0x01) << bit; // Retrieve LSB
            data[i] >>= 1; // Shift data to get the next LSB
        }
    }
    message[messageLength] = '\0'; // Null-terminate the string
}

void extractMessage(const char *inputFileName, size_t messageLength) {
    FILE *input = fopen(inputFileName, "rb");
    if (!input) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    DIBHeader dibHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, input);
    fread(&dibHeader, sizeof(DIBHeader), 1, input);
    
    if (bmpHeader.type != 0x4D42) {
        printf("Not a BMP file.\n");
        fclose(input);
        return;
    }

    uint32_t dataSize = dibHeader.width * dibHeader.height * (dibHeader.bitCount / 8);
    uint8_t *data = (uint8_t*)malloc(dataSize);
    fseek(input, bmpHeader.offset, SEEK_SET);
    fread(data, 1, dataSize, input);
    fclose(input);

    char *message = (char*)malloc(messageLength + 1);
    decodeMessage(data, message, messageLength);
    
    printf("Extracted Message: %s\n", message);
    
    free(data);
    free(message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s [embed/extract] [input bmp] [output bmp or length]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0) {
        const char *inputBMP = argv[2];
        const char *outputBMP = argv[3];
        const char *message = "Hello Steganography"; // Custom Message

        embedMessage(inputBMP, outputBMP, message);
    } else if (strcmp(argv[1], "extract") == 0) {
        const char *inputBMP = argv[2];
        size_t messageLength = atoi(argv[3]);

        extractMessage(inputBMP, messageLength);
    } else {
        printf("Invalid command. Use 'embed' or 'extract'.\n");
    }

    return EXIT_SUCCESS;
}