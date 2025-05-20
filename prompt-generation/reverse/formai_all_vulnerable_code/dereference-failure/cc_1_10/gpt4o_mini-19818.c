//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;      // Magic number for BMP files
    unsigned int bfSize;       // Size of the BMP file
    unsigned short bfReserved1; // Reserved; always 0
    unsigned short bfReserved2; // Reserved; always 0
    unsigned int bfOffBits;     // Offset to start of pixel data
} BMPFileHeader;

typedef struct {
    unsigned int biSize;          // Size of this header
    int biWidth;                  // Width of the image
    int biHeight;                 // Height of the image
    unsigned short biPlanes;      // Number of color planes
    unsigned short biBitCount;    // Bits per pixel
    unsigned int biCompression;    // Compression type
    unsigned int biSizeImage;     // Size of the image data
    int biXPelsPerMeter;          // Pixels per meter in X
    int biYPelsPerMeter;          // Pixels per meter in Y
    unsigned int biClrUsed;       // Number of colors in the palette
    unsigned int biClrImportant;   // Important colors
} BMPInfoHeader;

#pragma pack(pop)

void encodeMessageInBMP(const char *bmpFile, const char *message) {
    FILE *file = fopen(bmpFile, "rb+");
    if (!file) {
        perror("Error opening BMP file");
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    if (fileHeader.bfType != 0x4D42) {
        printf("Not a valid BMP file.\n");
        fclose(file);
        return;
    }

    fseek(file, fileHeader.bfOffBits, SEEK_SET);

    // Prepare message for encoding (ending with a null character)
    char *dataToEncode = malloc(strlen(message) + 1);
    strcpy(dataToEncode, message);
    dataToEncode[strlen(message)] = '\0'; // Null-terminator

    // Count the number of bits needed (8 bits for each character)
    size_t msgLen = strlen(dataToEncode);
    size_t totalBits = msgLen * 8;

    // Encode each character
    for (size_t i = 0; i < totalBits; i++) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, file);

        // Get the bit no. i in msg
        unsigned char bit = (dataToEncode[i / 8] >> (7 - (i % 8))) & 1;
        // Set the least significant bit of the pixel to the bit to encode
        pixel[0] = (pixel[0] & 0xFE) | bit;

        // Write modified pixel back
        fseek(file, -3, SEEK_CUR);
        fwrite(pixel, sizeof(unsigned char), 3, file);
    }

    free(dataToEncode);
    fclose(file);
    printf("Message encoded successfully!\n");
}

void decodeMessageFromBMP(const char *bmpFile) {
    FILE *file = fopen(bmpFile, "rb");
    if (!file) {
        perror("Error opening BMP file");
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    if (fileHeader.bfType != 0x4D42) {
        printf("Not a valid BMP file.\n");
        fclose(file);
        return;
    }

    fseek(file, fileHeader.bfOffBits, SEEK_SET);

    // Prepare to decode the message
    char currentChar = 0;
    size_t bitCount = 0;
    printf("Decoded message: ");

    while (1) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, file);

        // Read the least significant bit
        currentChar = (currentChar << 1) | (pixel[0] & 1);
        if (++bitCount == 8) {
            if (currentChar == '\0') break; // End of message
            putchar(currentChar);
            currentChar = 0;
            bitCount = 0;
        }
    }

    fclose(file);
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <bmp_file> <message>\n", argv[0]);
        printf("Or use: %s <bmp_file> decode\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[2], "decode") == 0) {
        decodeMessageFromBMP(argv[1]);
    } else {
        encodeMessageInBMP(argv[1], argv[2]);
    }
    
    return EXIT_SUCCESS;
}