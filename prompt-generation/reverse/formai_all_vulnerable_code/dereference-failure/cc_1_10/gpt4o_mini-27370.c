//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} BMPHeader;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitCount;
    unsigned int compression;
    unsigned int sizeImage;
    int xPelsPerMeter;
    int yPelsPerMeter;
    unsigned int clrUsed;
    unsigned int clrImportant;
} BMPInfoHeader;
#pragma pack(pop)

void embedMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *inFile = fopen(inputImage, "rb");
    if (inFile == NULL) {
        perror("Unable to open input image");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inFile);

    if (bmpHeader.type != 0x4D42) {
        fclose(inFile);
        fprintf(stderr, "Not a BMP file\n");
        exit(EXIT_FAILURE);
    }

    int imgSize = bmpInfoHeader.width * bmpInfoHeader.height * 3; // Assuming 24 bits/pixel
    unsigned char *imageData = malloc(imgSize);
    fread(imageData, 1, imgSize, inFile);
    fclose(inFile);

    int messageLen = strlen(message);
    if (messageLen * 8 > imgSize) {
        fprintf(stderr, "Message is too long to embed in the image.\n");
        free(imageData);
        exit(EXIT_FAILURE);
    }

    // Embed the message bit by bit into the least significant bits of the image data
    for (int i = 0; i < messageLen; i++) {
        for (int b = 0; b < 8; b++) {
            int bit = (message[i] >> (7 - b)) & 1;
            imageData[i * 8 + b] = (imageData[i * 8 + b] & 0xFE) | bit;
        }
    }

    FILE *outFile = fopen(outputImage, "wb");
    if (outFile == NULL) {
        perror("Unable to open output image");
        free(imageData);
        exit(EXIT_FAILURE);
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outFile);
    fwrite(imageData, 1, imgSize, outFile);
    fclose(outFile);
    free(imageData);
    printf("Message embedded successfully!\n");
}

void extractMessage(const char *inputImage, char *outputMessage, int maxLength) {
    FILE *inFile = fopen(inputImage, "rb");
    if (inFile == NULL) {
        perror("Unable to open input image");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inFile);

    if (bmpHeader.type != 0x4D42) {
        fclose(inFile);
        fprintf(stderr, "Not a BMP file\n");
        exit(EXIT_FAILURE);
    }

    int imgSize = bmpInfoHeader.width * bmpInfoHeader.height * 3; // Assuming 24 bits/pixel
    unsigned char *imageData = malloc(imgSize);
    fread(imageData, 1, imgSize, inFile);
    fclose(inFile);

    int messageLen = 0;
    for (int i = 0; i < maxLength; i++) {
        char character = 0;
        for (int b = 0; b < 8; b++) {
            character |= ((imageData[i * 8 + b] & 1) << (7 - b));
        }
        if (character == '\0') break;
        outputMessage[i] = character;
        messageLen++;
    }
    outputMessage[messageLen] = '\0';
    free(imageData);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed/extract> <image> <output/message> [message]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0) {
        if (argc != 5) {
            fprintf(stderr, "Usage for embed: %s embed <input_image> <output_image> <message>\n", argv[0]);
            return EXIT_FAILURE;
        }
        embedMessage(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        char message[256];
        extractMessage(argv[2], message, 256);
        printf("Extracted message: %s\n", message);
    } else {
        fprintf(stderr, "Invalid action. Use 'embed' or 'extract'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}