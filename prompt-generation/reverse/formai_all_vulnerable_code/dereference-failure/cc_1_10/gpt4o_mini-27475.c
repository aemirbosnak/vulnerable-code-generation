//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    unsigned short bfType;      // Magic Number
    unsigned int bfSize;       // Size of BMP file
    unsigned short bfReserved1; // Reserved
    unsigned short bfReserved2; // Reserved
    unsigned int bfOffBits;    // Offset to start of pixel data
} BMPFileHeader;

typedef struct {
    unsigned int biSize;           // Size of this header
    int biWidth;                   // Width of image
    int biHeight;                  // Height of image
    unsigned short biPlanes;       // Number of color planes
    unsigned short biBitCount;     // Bits per pixel
    unsigned int biCompression;     // Compression type
    unsigned int biSizeImage;      // Image size (can be 0 for BI_RGB)
    int biXPelsPerMeter;           // Pixels per meter in X
    int biYPelsPerMeter;           // Pixels per meter in Y
    unsigned int biClrUsed;        // Number of colors in palette
    unsigned int biClrImportant;    // Important colors
} BMPInfoHeader;

void encodeMessageInBMP(const char *bmpFile, const char *message) {
    FILE *file = fopen(bmpFile, "rb+");
    if (!file) {
        fprintf(stderr, "Error opening the BMP file.\n");
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    fseek(file, fileHeader.bfOffBits, SEEK_SET);
    
    // Calculate starting position for message encoding
    size_t messageLength = strlen(message);
    unsigned int totalPixels = infoHeader.biWidth * infoHeader.biHeight;
    
    if (messageLength * 8 > totalPixels) {
        fprintf(stderr, "Message is too long to fit in this image.\n");
        fclose(file);
        return;
    }

    // Encode message
    for (size_t i = 0; i < messageLength; i++) {
        for (int bit = 7; bit >= 0; bit--) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, file);

            // Encode the message bit in the least significant bit of the blue channel
            if ((message[i] >> bit) & 1) {
                pixel[0] |= 1;  // Set LSB to 1
            } else {
                pixel[0] &= ~1; // Set LSB to 0
            }

            fseek(file, -3, SEEK_CUR); // Move back to rewrite
            fwrite(pixel, sizeof(unsigned char), 3, file);
        }
    }

    // Null-terminate the message
    for (int bit = 7; bit >= 0; bit--) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, file);
        
        if (0 & 1) {
            pixel[0] |= 1; // Set LSB to 1
        } else {
            pixel[0] &= ~1; // Set LSB to 0
        }

        fseek(file, -3, SEEK_CUR);
        fwrite(pixel, sizeof(unsigned char), 3, file);
    }

    fclose(file);
    printf("Message encoded successfully into %s!\n", bmpFile);
}

void decodeMessageFromBMP(const char *bmpFile) {
    FILE *file = fopen(bmpFile, "rb");
    if (!file) {
        fprintf(stderr, "Error opening the BMP file.\n");
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    fseek(file, fileHeader.bfOffBits, SEEK_SET);

    char message[256];
    memset(message, 0, sizeof(message));
    unsigned char byte = 0;
    int bitIndex = 0;

    for (int i = 0; i < 256 * 8; i++) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, file);

        // Extract the LSB from the blue channel
        byte = (byte << 1) | (pixel[0] & 1);

        bitIndex++;
        if (bitIndex == 8) {
            if (byte == 0) break; // End of message
            message[bitIndex / 8 - 1] = byte;
            byte = 0;
            bitIndex = 0;
        }
    }

    fclose(file);
    printf("Decoded message: %s\n", message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <encode|decode> <BMP file> <message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encodeMessageInBMP(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessageFromBMP(argv[2]);
    } else {
        printf("Invalid action. Use 'encode' or 'decode'.\n");
    }

    return 0;
}