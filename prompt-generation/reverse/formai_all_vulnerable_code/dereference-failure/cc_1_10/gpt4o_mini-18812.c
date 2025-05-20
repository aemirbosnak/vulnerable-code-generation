//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // Ensure the structure is tightly packed
typedef struct {
    unsigned short bfType;      // BMP file type
    unsigned int bfSize;       // Size of the BMP file
    unsigned short bfReserved1; // Reserved; must be 0
    unsigned short bfReserved2; // Reserved; must be 0
    unsigned int bfOffBits;     // Offset to the pixel data
} BMPHeader;

typedef struct {
    unsigned int biSize;          // Size of the DIB header
    int biWidth;                  // Width of the bitmap
    int biHeight;                 // Height of the bitmap
    unsigned short biPlanes;      // Number of color planes
    unsigned short biBitCount;    // Number of bits per pixel
    unsigned int biCompression;    // Compression type
    unsigned int biSizeImage;      // Size of the image data
    int biXPelsPerMeter;          // Horizontal resolution
    int biYPelsPerMeter;          // Vertical resolution
    unsigned int biClrUsed;       // Number of colors in the color table
    unsigned int biClrImportant;  // Number of important colors
} DIBHeader;

void hideMessageInBMP(const char *imagePath, const char *message) {
    FILE *bmpFile = fopen(imagePath, "rb+");
    if (!bmpFile) {
        fprintf(stderr, "😱 ERROR: Can't open image '%s'!\n", imagePath);
        exit(1);
    }
    
    BMPHeader bmpHeader;
    DIBHeader dibHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    fread(&dibHeader, sizeof(DIBHeader), 1, bmpFile);

    if (bmpHeader.bfType != 0x4D42) {
        fprintf(stderr, "😱 ERROR: File is not a BMP format!\n");
        fclose(bmpFile);
        exit(1);
    }

    fseek(bmpFile, bmpHeader.bfOffBits, SEEK_SET);

    // Check message length
    size_t messageLength = strlen(message);
    if (messageLength > 255) {
        fprintf(stderr, "😱 ERROR: Message too long! Max is 255 characters.\n");
        fclose(bmpFile);
        exit(1);
    }

    // Write message length in the first pixel
    unsigned char pixel[3];
    fread(pixel, sizeof(pixel), 1, bmpFile);
    pixel[0] = messageLength;  // Store message length in the blue channel
    fseek(bmpFile, -3, SEEK_CUR); // Go back to write pixel
    fwrite(pixel, sizeof(pixel), 1, bmpFile);

    // Hide the message
    for (size_t i = 0; i < messageLength; i++) {
        fread(pixel, sizeof(pixel), 1, bmpFile);  // Read next pixel
        pixel[0] = (pixel[0] & 0xFE) | ((message[i] >> 0) & 0x01); // LSB of blue
        pixel[1] = (pixel[1] & 0xFE) | ((message[i] >> 1) & 0x01); // LSB of green
        pixel[2] = (pixel[2] & 0xFE) | ((message[i] >> 2) & 0x01); // LSB of red
        fseek(bmpFile, -3, SEEK_CUR);  // Go back to write pixel
        fwrite(pixel, sizeof(pixel), 1, bmpFile); // Write modified pixel
    }

    printf("💥 Message hidden in '%s'! 🎉\n", imagePath);
    fclose(bmpFile);
}

void revealMessageInBMP(const char *imagePath) {
    FILE *bmpFile = fopen(imagePath, "rb");
    if (!bmpFile) {
        fprintf(stderr, "😱 ERROR: Can't open image '%s'!\n", imagePath);
        exit(1);
    }

    BMPHeader bmpHeader;
    DIBHeader dibHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    fread(&dibHeader, sizeof(DIBHeader), 1, bmpFile);

    if (bmpHeader.bfType != 0x4D42) {
        fprintf(stderr, "😱 ERROR: File is not a BMP format!\n");
        fclose(bmpFile);
        exit(1);
    }

    fseek(bmpFile, bmpHeader.bfOffBits, SEEK_SET);

    unsigned char pixel[3];
    fread(pixel, sizeof(pixel), 1, bmpFile);
    
    // Retrieving message length
    size_t messageLength = pixel[0];  
    char *message = (char*) malloc(messageLength + 1);
    message[messageLength] = '\0'; // Null terminate the message

    for (size_t i = 0; i < messageLength; i++) {
        fread(pixel, sizeof(pixel), 1, bmpFile);
        // LSBs extraction
        message[i] = ((pixel[0] & 0x01) << 0) |
                     ((pixel[1] & 0x01) << 1) |
                     ((pixel[2] & 0x01) << 2);  
    }

    printf("🏴‍☠️ Hidden message revealed: '%s'\n", message);
    free(message);
    fclose(bmpFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "😱 ERROR: Usage: %s <hide/reveal> <image_path> <message(optional)>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "hide") == 0) {
        if (argc != 4) {
            fprintf(stderr, "😱 ERROR: A message is required to hide!\n");
            exit(1);
        }
        hideMessageInBMP(argv[2], argv[3]);
    } else if (strcmp(argv[1], "reveal") == 0) {
        revealMessageInBMP(argv[2]);
    } else {
        fprintf(stderr, "😱 ERROR: Unknown operation! Use 'hide' or 'reveal'.\n");
        exit(1);
    }

    return 0;
}