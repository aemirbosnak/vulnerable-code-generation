//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char bfType[2];
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void hideMessageInBMP(const char *bmpFilePath, const char *message, const char *outputFilePath) {
    FILE *bmpFile = fopen(bmpFilePath, "rb");
    if (!bmpFile) {
        perror("Error opening BMP file");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, bmpFile);

    int width = bih.biWidth;
    int height = bih.biHeight;
    int rowSize = (width * bih.biBitCount / 8 + 3) & ~3; // Row size must be a multiple of 4
    unsigned char *data = (unsigned char *)malloc(rowSize * height);

    fseek(bmpFile, bfh.bfOffBits, SEEK_SET);
    fread(data, rowSize * height, 1, bmpFile);
    fclose(bmpFile);

    size_t messageLength = strlen(message);
    messageLength = messageLength > 255 ? 255 : messageLength; // Max 255 chars
    data[0] = messageLength; // Store the length of the message at the beginning

    for (size_t i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            int byteIndex = (i * 8 + j) / 8 + 1; // Skip the first byte where length is stored
            int bitIndex = (i * 8 + j) % 8;
            if (data[byteIndex] & 1) {
                data[byteIndex] |= (message[i] >> (7 - j)) & 1; // Set the LSB to the message bit
            } else {
                data[byteIndex] &= ~(1 << 0); // Ensure LSB is cleared
            }
        }
    }

    FILE *outputFile = fopen(outputFilePath, "wb");
    if (!outputFile) {
        perror("Error creating output BMP file");
        free(data);
        return;
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fwrite(data, rowSize * height, 1, outputFile);
    fclose(outputFile);
    free(data);

    printf("Message hidden in %s\n", outputFilePath);
}

void extractMessageFromBMP(const char *bmpFilePath) {
    FILE *bmpFile = fopen(bmpFilePath, "rb");
    if (!bmpFile) {
        perror("Error opening BMP file");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, bmpFile);

    int rowSize = (bih.biWidth * bih.biBitCount / 8 + 3) & ~3;
    unsigned char *data = (unsigned char *)malloc(rowSize * bih.biHeight);

    fseek(bmpFile, bfh.bfOffBits, SEEK_SET);
    fread(data, rowSize * bih.biHeight, 1, bmpFile);
    fclose(bmpFile);

    size_t messageLength = data[0];
    char message[256] = {0};

    for (size_t i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            int byteIndex = (i * 8 + j) / 8 + 1;
            int bitIndex = (i * 8 + j) % 8;
            if (data[byteIndex] & (1 << 0)) {
                message[i] |= (1 << (7 - j)); // Gather bits to form the character
            }
        }
    }

    printf("Extracted message: %s\n", message);
    free(data);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s [hide|extract] <bmp_file> <message|output_file> <output_file/message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "hide") == 0) {
        hideMessageInBMP(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessageFromBMP(argv[2]);
    } else {
        printf("Invalid command. Use 'hide' or 'extract'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}