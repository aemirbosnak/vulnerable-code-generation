//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)

// BMP file header structure
typedef struct {
    unsigned short bfType;      // BMP file type
    unsigned int bfSize;        // BMP file size
    unsigned short bfReserved1; // Reserved
    unsigned short bfReserved2; // Reserved
    unsigned int bfOffBits;     // Offset to pixel data
} BMPHeader;

// BMP info header structure
typedef struct {
    unsigned int biSize;        // Info header size
    int biWidth;                // Width of image
    int biHeight;               // Height of image
    unsigned short biPlanes;     // Number of planes
    unsigned short biBitCount;   // Bits per pixel
    unsigned int biCompression;  // Compression type
    unsigned int biSizeImage;    // Image size
    int biXPelsPerMeter;         // Pixels per meter in X
    int biYPelsPerMeter;         // Pixels per meter in Y
    unsigned int biClrUsed;      // Number of colors used
    unsigned int biClrImportant;  // Important colors
} BMPInfoHeader;

// Function prototypes
void hideMessageInBMP(const char *bmpFile, const char *messageFile);
void extractMessageFromBMP(const char *bmpFile);
void appendTextToFile(const char *fileName, const char *text);
void readMessageFromFile(const char *fileName);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s hide <bmp_file> <message_file>\n", argv[0]);
        printf("   or: %s extract <bmp_file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "hide") == 0) {
        hideMessageInBMP(argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessageFromBMP(argv[2]);
    } else {
        printf("Invalid command. Use 'hide' or 'extract'.\n");
        return 1;
    }

    return 0;
}

void hideMessageInBMP(const char *bmpFile, const char *messageFile) {
    FILE *bmp = fopen(bmpFile, "r+b");
    if (!bmp) {
        perror("Failed to open BMP file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, bmp);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, bmp);

    // Seek to pixel data
    fseek(bmp, bmpHeader.bfOffBits, SEEK_SET);

    char message[256];
    FILE *msgFile = fopen(messageFile, "r");
    if (!msgFile) {
        perror("Failed to open message file");
        fclose(bmp);
        return;
    }
    
    fgets(message, sizeof(message), msgFile);
    fclose(msgFile);

    // Add null byte to indicate end of message
    strncat(message, "\0", sizeof(message) - strlen(message) - 1);

    for (int i = 0; message[i] != '\0'; i++) {
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, 3, 1, bmp);

            if (i * 8 + j < bmpInfoHeader.biWidth * bmpInfoHeader.biHeight) {
                // Modify the least significant bit of the blue channel
                pixel[0] = (pixel[0] & 0xFE) | ((message[i] >> (7 - j)) & 1);
            }

            fseek(bmp, -3, SEEK_CUR); // Move back 3 bytes to overwrite the pixel data
            fwrite(pixel, 3, 1, bmp);
        }
    }

    fclose(bmp);
    printf("Message hidden in BMP file successfully.\n");
}

void extractMessageFromBMP(const char *bmpFile) {
    FILE *bmp = fopen(bmpFile, "rb");
    if (!bmp) {
        perror("Failed to open BMP file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, bmp);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, bmp);

    // Seek to pixel data
    fseek(bmp, bmpHeader.bfOffBits, SEEK_SET);

    char message[256] = {0};
    for (int i = 0; i < 256; i++) {
        unsigned char byte = 0;
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, 3, 1, bmp);

            // Read the least significant bit of the blue channel
            byte = (byte << 1) | (pixel[0] & 1);
        }
        message[i] = byte;
        if (byte == '\0') break; // Stop reading if null byte found
    }

    fclose(bmp);
    printf("Extracted message: %s\n", message);
}