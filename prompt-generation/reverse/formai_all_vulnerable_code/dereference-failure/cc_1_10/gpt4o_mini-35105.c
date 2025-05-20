//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char  bfType[2];
    unsigned int   bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int   bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int   biSize;
    int            biWidth;
    int            biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int   biCompression;
    unsigned int   biSizeImage;
    int            biXPelsPerMeter;
    int            biYPelsPerMeter;
    unsigned int   biClrUsed;
    unsigned int   biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void hideMessageInBMP(const char* bmpFile, const char* message) {
    FILE* file = fopen(bmpFile, "rb+");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", bmpFile);
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, file);

    if (bih.biBitCount != 24) {
        fprintf(stderr, "Only 24-bit BMP files are supported.\n");
        fclose(file);
        return;
    }

    fseek(file, bfh.bfOffBits, SEEK_SET);
    
    // Calculate the size of the message and ensure it fits
    size_t messageLen = strlen(message);
    if (messageLen > 255) {
        fprintf(stderr, "Message is too long, max length is 255 characters.\n");
        fclose(file);
        return;
    }

    // Write message length at the start of the pixels
    fputc(messageLen, file);

    // Embed message
    for (size_t i = 0; i < messageLen; i++) {
        unsigned char ch = message[i];
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, file);
            // Clear LSB and set LSB with message bit
            pixel[0] = (pixel[0] & 0xFE) | ((ch >> (7 - j)) & 0x01);
            fseek(file, -3, SEEK_CUR);
            fwrite(pixel, sizeof(unsigned char), 3, file);
        }
    }
    fclose(file);
    printf("Message hidden successfully.\n");
}

void extractMessageFromBMP(const char* bmpFile) {
    FILE* file = fopen(bmpFile, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", bmpFile);
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, file);

    if (bih.biBitCount != 24) {
        fprintf(stderr, "Only 24-bit BMP files are supported.\n");
        fclose(file);
        return;
    }

    fseek(file, bfh.bfOffBits, SEEK_SET);
    
    // Read message length
    size_t messageLen = fgetc(file);
    if (messageLen == EOF || messageLen > 255) {
        fprintf(stderr, "Could not read message or invalid length.\n");
        fclose(file);
        return;
    }

    char* message = (char*)malloc(messageLen + 1);
    if (!message) {
        fprintf(stderr, "Memory allocation failed!\n");
        fclose(file);
        return;
    }

    message[messageLen] = '\0';
    
    // Read embedded message
    for (size_t i = 0; i < messageLen; i++) {
        unsigned char ch = 0;
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, file);
            ch |= ((pixel[0] & 0x01) << (7 - j));
        }
        message[i] = ch;
    }
    fclose(file);
    
    printf("Extracted message: %s\n", message);
    free(message);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s [hide|extract] <bmp_file> [message]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "hide") == 0) {
        hideMessageInBMP(argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessageFromBMP(argv[2]);
    } else {
        printf("Invalid action. Use 'hide' to hide a message or 'extract' to retrieve a message.\n");
    }

    return 0;
}