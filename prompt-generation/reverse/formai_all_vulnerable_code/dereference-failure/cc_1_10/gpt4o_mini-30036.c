//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char bfType[2];      // Bitmap file type
    unsigned int bfSize;          // Size of the BMP file
    unsigned short bfReserved1;   // Reserved
    unsigned short bfReserved2;   // Reserved
    unsigned int bfOffBits;       // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;              // Size of this header
    int biWidth;                       // Width of the bitmap
    int biHeight;                      // Height of the bitmap
    unsigned short biPlanes;           // Number of color planes
    unsigned short biBitCount;         // Bits per pixel
    unsigned int biCompression;        // Compression type
    unsigned int biSizeImage;          // Size of pixel data
    int biXPelsPerMeter;               // Horizontal resolution
    int biYPelsPerMeter;               // Vertical resolution
    unsigned int biClrUsed;            // Number of colors
    unsigned int biClrImportant;       // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

void embed_message(const char* bmp_file, const char* message, const char* output_file) {
    FILE* fp = fopen(bmp_file, "rb");
    if (fp == NULL) {
        perror("Could not open BMP file");
        return;
    }

    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;

    fread(&bfHeader, sizeof(BITMAPFILEHEADER), 1, fp);
    fread(&biHeader, sizeof(BITMAPINFOHEADER), 1, fp);

    if (bfHeader.bfType[0] != 'B' || bfHeader.bfType[1] != 'M') {
        printf("Not a valid BMP file.\n");
        fclose(fp);
        return;
    }

    unsigned char* pixelData = malloc(biHeader.biSizeImage);
    if (pixelData == NULL) {
        perror("Unable to allocate memory for pixel data");
        fclose(fp);
        return;
    }

    fseek(fp, bfHeader.bfOffBits, SEEK_SET);
    fread(pixelData, biHeader.biSizeImage, 1, fp);
    fclose(fp);

    size_t message_len = strlen(message);
    if (message_len > biHeader.biSizeImage * 8 / 3) {
        printf("Message is too long to be embedded in this BMP file.\n");
        free(pixelData);
        return;
    }

    pixelData[0] = (pixelData[0] & 0xFE) | 0x01; // Mark the last byte of the message
    for (size_t i = 0; i < message_len; i++) {
        for (int j = 0; j < 8; j++) {
            unsigned char mask = (message[i] >> (7 - j)) & 0x01;
            pixelData[1 + i * 8 + j] = (pixelData[1 + i * 8 + j] & 0xFE) | mask;  // embed message in LSB
        }
    }

    FILE* out_fp = fopen(output_file, "wb");
    if (out_fp == NULL) {
        perror("Could not open output file");
        free(pixelData);
        return;
    }

    fwrite(&bfHeader, sizeof(BITMAPFILEHEADER), 1, out_fp);
    fwrite(&biHeader, sizeof(BITMAPINFOHEADER), 1, out_fp);
    fwrite(pixelData, biHeader.biSizeImage, 1, out_fp);
    
    fclose(out_fp);
    free(pixelData);

    printf("Message embedded successfully into %s\n", output_file);
}

void extract_message(const char* bmp_file) {
    FILE* fp = fopen(bmp_file, "rb");
    if (fp == NULL) {
        perror("Could not open BMP file");
        return;
    }

    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;

    fread(&bfHeader, sizeof(BITMAPFILEHEADER), 1, fp);
    fread(&biHeader, sizeof(BITMAPINFOHEADER), 1, fp);

    unsigned char* pixelData = malloc(biHeader.biSizeImage);
    if (pixelData == NULL) {
        perror("Unable to allocate memory for pixel data");
        fclose(fp);
        return;
    }

    fseek(fp, bfHeader.bfOffBits, SEEK_SET);
    fread(pixelData, biHeader.biSizeImage, 1, fp);
    fclose(fp);

    size_t message_len = 0;
    while ((pixelData[1 + message_len * 8] & 0x01) != 0) {
        message_len++;
    }

    char* message = malloc(message_len + 1);
    if (message == NULL) {
        perror("Unable to allocate memory for message");
        free(pixelData);
        return;
    }

    for (size_t i = 0; i < message_len; i++) {
        message[i] = 0;
        for (int j = 0; j < 8; j++) {
            message[i] = (message[i] << 1) | (pixelData[1 + i * 8 + j] & 0x01);
        }
    }
    message[message_len] = '\0';

    printf("Extracted message: %s\n", message);
    free(message);
    free(pixelData);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed/extract> <bmp_file> [message/output_file]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        if (argc != 4) {
            printf("Usage for embedding: %s embed <bmp_file> <message>\n", argv[0]);
            return 1;
        }
        embed_message(argv[2], argv[3], "output.bmp");
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_message(argv[2]);
    } else {
        printf("Unknown command '%s'. Use 'embed' or 'extract'.\n", argv[1]);
        return 1;
    }

    return 0;
}