//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;      // BMP file type
    unsigned int bfSize;       // Size of the BMP file
    unsigned short bfReserved1; // Reserved
    unsigned short bfReserved2; // Reserved
    unsigned int bfOffBits;    // Offset to start of pixel data
} BMPHeader;

typedef struct {
    unsigned int biSize;       // Size of the info header
    int biWidth;               // Width of the image
    int biHeight;              // Height of the image
    unsigned short biPlanes;    // Number of color planes
    unsigned short biBitCount;   // Number of bits per pixel
    unsigned int biCompression; // Compression type
    unsigned int biSizeImage;   // Size of the image data
    int biXPelsPerMeter;        // Horizontal resolution
    int biYPelsPerMeter;        // Vertical resolution
    unsigned int biClrUsed;     // Number of colors in the color table
    unsigned int biClrImportant; // Important colors
} BMPInfo;
#pragma pack(pop)

void readBMPHeader(FILE *fp, BMPHeader *bmpHeader);
void readBMPInfo(FILE *fp, BMPInfo *bmpInfo);
void embedMessageInBMP(const char *message, const char *inputFile, const char *outputFile);
void decodeMessageFromBMP(const char *inputFile);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <embed/decode> <input BMP file> <output file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        char message[256];
        printf("Enter a message to embed: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline

        embedMessageInBMP(message, argv[2], argv[3]);
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessageFromBMP(argv[2]);
    } else {
        printf("Invalid command. Use 'embed' or 'decode'.\n");
        return 1;
    }

    return 0;
}

void readBMPHeader(FILE *fp, BMPHeader *bmpHeader) {
    fread(bmpHeader, sizeof(BMPHeader), 1, fp);
}

void readBMPInfo(FILE *fp, BMPInfo *bmpInfo) {
    fread(bmpInfo, sizeof(BMPInfo), 1, fp);
}

void embedMessageInBMP(const char *message, const char *inputFile, const char *outputFile) {
    FILE *fpIn = fopen(inputFile, "rb");
    if (!fpIn) {
        perror("Error opening input file");
        return;
    }

    FILE *fpOut = fopen(outputFile, "wb");
    if (!fpOut) {
        perror("Error opening output file");
        fclose(fpIn);
        return;
    }

    BMPHeader bmpHeader;
    BMPInfo bmpInfo;
    readBMPHeader(fpIn, &bmpHeader);
    readBMPInfo(fpIn, &bmpInfo);

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, fpOut);
    fwrite(&bmpInfo, sizeof(BMPInfo), 1, fpOut);

    fseek(fpIn, bmpHeader.bfOffBits, SEEK_SET);
    fseek(fpOut, bmpHeader.bfOffBits, SEEK_SET);

    unsigned char buffer[3];
    size_t msgLen = strlen(message);
    size_t idx = 0;

    while (fread(buffer, 3, 1, fpIn) == 1) {
        for (int j = 0; j < 3; j++) {
            if (idx < msgLen) {
                buffer[j] = (buffer[j] & 0xFE) | ((message[idx] >> j) & 0x01);
            }
        }
        fwrite(buffer, 3, 1, fpOut);
        if (idx < msgLen) {
            idx++;
        }
    }
    
    fclose(fpIn);
    fclose(fpOut);
    printf("Message embedded successfully!\n");
}

void decodeMessageFromBMP(const char *inputFile) {
    FILE *fp = fopen(inputFile, "rb");
    if (!fp) {
        perror("Error opening input file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfo bmpInfo;
    readBMPHeader(fp, &bmpHeader);
    readBMPInfo(fp, &bmpInfo);

    fseek(fp, bmpHeader.bfOffBits, SEEK_SET);

    unsigned char buffer[3];
    char message[256];
    size_t msgLen = 0;

    while (fread(buffer, 3, 1, fp) == 1) {
        if (msgLen < sizeof(message) - 1) {
            message[msgLen] = 0;
            for (int j = 0; j < 3; j++) {
                message[msgLen] |= ((buffer[j] & 0x01) << j);
            }
            if (message[msgLen] == 0) break; // End of message
            msgLen++;
        }
    }
    message[msgLen] = '\0';
    fclose(fp);

    printf("Decoded message: %s\n", message);
}