//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
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
    int biXPixPerMeter;
    int biYPixPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void encodeMessage(BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih, const char* message, FILE* outputFile) {
    int i, j;
    unsigned char byte;
    int messageLength = strlen(message);
    
    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, outputFile);

    // Start at pixel data offset
    fseek(outputFile, bfh.bfOffBits, SEEK_SET);

    for (i = 0; i < bih.biHeight; i++) {
        for (j = 0; j < bih.biWidth * 3; j += 3) {
            if (i * bih.biWidth * 3 + j / 3 < messageLength) {
                byte = message[i * bih.biWidth * 3 + j / 3];
                unsigned char pixel[3];
                fread(pixel, sizeof(unsigned char), 3, outputFile);
                // Encode each character into least significant bit of the pixel
                pixel[0] = (pixel[0] & 0xFE) | ((byte >> 0) & 0x01);
                pixel[1] = (pixel[1] & 0xFE) | ((byte >> 1) & 0x01);
                pixel[2] = (pixel[2] & 0xFE) | ((byte >> 2) & 0x01);
                fseek(outputFile, -3, SEEK_CUR);
                fwrite(pixel, sizeof(unsigned char), 3, outputFile);
            } else {
                unsigned char pixel[3];
                fread(pixel, sizeof(unsigned char), 3, outputFile);
                fwrite(pixel, sizeof(unsigned char), 3, outputFile);
            }
        }
    }
}

void decodeMessage(const char* inputFileName) {
    FILE* inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Failed to open file");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, inputFile);

    fseek(inputFile, bfh.bfOffBits, SEEK_SET);
    
    printf("Decoded Message: ");
    for (int i = 0; ; i++) {
        char ch = 0;
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, inputFile);
            ch |= ((pixel[0] & 0x01) << 0);
            ch |= ((pixel[1] & 0x01) << 1);
            ch |= ((pixel[2] & 0x01) << 2);
        }
        if (i == 0 && ch == 0) break; // Stop reading if no message
        putchar(ch);
        if (ch == '\0') break; // End of string
    }
    printf("\n");
    fclose(inputFile);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <encode/decode> <input.bmp> <output.bmp/message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        FILE* inputFile = fopen(argv[2], "rb");
        if (!inputFile) {
            perror("Failed to open input file");
            return 1;
        }

        BITMAPFILEHEADER bfh;
        BITMAPINFOHEADER bih;

        fread(&bfh, sizeof(BITMAPFILEHEADER), 1, inputFile);
        fread(&bih, sizeof(BITMAPINFOHEADER), 1, inputFile);

        FILE* outputFile = fopen(argv[3], "wb");
        if (!outputFile) {
            perror("Failed to open output file");
            fclose(inputFile);
            return 1;
        }

        char message[256];
        printf("Enter a message to hide (max 255 chars): ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline

        encodeMessage(bfh, bih, message, outputFile);
        fclose(inputFile);
        fclose(outputFile);
        printf("Message encoded successfully!\n");
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessage(argv[2]);
    } else {
        printf("Invalid operation. Use 'encode' or 'decode'.\n");
        return 1;
    }

    return 0;
}