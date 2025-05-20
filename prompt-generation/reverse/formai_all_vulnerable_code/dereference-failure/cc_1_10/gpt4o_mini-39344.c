//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Structure to hold BMP file header
#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BMPFileHeader;

// Structure to hold BMP information header
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
} BMPInfoHeader;
#pragma pack(pop)

void encodeMessageInImage(const char *imagePath, const char *message, const char *outputPath) {
    FILE *imageFile = fopen(imagePath, "rb");
    if (!imageFile) {
        perror("Could not open image file");
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, imageFile);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, imageFile);

    if (fileHeader.bfType != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(imageFile);
        return;
    }

    long imageSize = infoHeader.biWidth * abs(infoHeader.biHeight) * (infoHeader.biBitCount / 8);
    long messageLength = strlen(message);
    if (messageLength * 8 > imageSize) {
        fprintf(stderr, "Message is too long to encode in this image\n");
        fclose(imageFile);
        return;
    }

    unsigned char *imageData = (unsigned char *)malloc(imageSize);
    fseek(imageFile, fileHeader.bfOffBits, SEEK_SET);
    fread(imageData, 1, imageSize, imageFile);
    fclose(imageFile);

    // Append a null terminator to the message
    char *messageBinary = (char *)malloc(messageLength * 8 + 1);
    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            messageBinary[i * 8 + j] = (message[i] & (1 << (7 - j))) ? '1' : '0';
        }
    }
    messageBinary[messageLength * 8] = '\0';

    for (long i = 0; i < messageLength * 8; i++) {
        if (messageBinary[i] == '1') {
            imageData[i] |= 1; // Set the least significant bit to 1
        } else {
            imageData[i] &= ~1; // Set the least significant bit to 0
        }
    }

    FILE *outputFile = fopen(outputPath, "wb");
    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, outputFile);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, outputFile);
    fwrite(imageData, 1, imageSize, outputFile);

    free(imageData);
    free(messageBinary);
    fclose(outputFile);

    printf("Message encoded in %s successfully!\n", outputPath);
}

void decodeMessageFromImage(const char *imagePath) {
    FILE *imageFile = fopen(imagePath, "rb");
    if (!imageFile) {
        perror("Could not open image file");
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, imageFile);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, imageFile);

    if (fileHeader.bfType != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(imageFile);
        return;
    }

    long imageSize = infoHeader.biWidth * abs(infoHeader.biHeight) * (infoHeader.biBitCount / 8);
    unsigned char *imageData = (unsigned char *)malloc(imageSize);
    fseek(imageFile, fileHeader.bfOffBits, SEEK_SET);
    fread(imageData, 1, imageSize, imageFile);
    fclose(imageFile);

    char *messageBinary = (char *)malloc(imageSize * 8 + 1);
    for (long i = 0; i < imageSize * 8; i++) {
        messageBinary[i] = (imageData[i / 8] & (1 << (7 - (i % 8)))) ? '1' : '0';
    }
    messageBinary[imageSize * 8] = '\0';

    printf("Decoded message (in binary):\n");
    for (long i = 0; i < imageSize * 8; i += 8) {
        if (i + 7 < imageSize * 8) {
            // If we encounter a null byte, we stop decoding
            if (messageBinary[i] == '0' && messageBinary[i + 1] == '0' && messageBinary[i + 2] == '0' && 
                messageBinary[i + 3] == '0' && messageBinary[i + 4] == '0' && messageBinary[i + 5] == '0' && 
                messageBinary[i + 6] == '0' && messageBinary[i + 7] == '0') {
                break;
            }
            char character = 0;
            for (int j = 0; j < 8; j++) {
                character |= (messageBinary[i + j] - '0') << (7 - j);
            }
            putchar(character);
        }
    }
    putchar('\n');

    free(imageData);
    free(messageBinary);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encode/decode> <image path> <message/output>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encodeMessageInImage(argv[2], argv[3], "output.bmp");
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessageFromImage(argv[2]);
    } else {
        fprintf(stderr, "Invalid option. Use 'encode' or 'decode'.\n");
    }

    return EXIT_SUCCESS;
}