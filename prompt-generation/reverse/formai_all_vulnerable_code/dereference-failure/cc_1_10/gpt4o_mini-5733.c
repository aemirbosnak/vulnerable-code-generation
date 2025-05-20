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
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void hideMessageInBMP(const char *inputFile, const char *outputFile, const char *message) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, input);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, input);

    if (bfh.bfType != 0x4D42) { // 'BM'
        fprintf(stderr, "Not a BMP file.\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    // Calculate the size of the data field
    unsigned int pixelArrayOffset = bfh.bfOffBits;
    unsigned int imageSize = bih.biWidth * bih.biHeight * (bih.biBitCount / 8);
    fseek(input, pixelArrayOffset, SEEK_SET);
    unsigned char *pixelData = malloc(imageSize);
    fread(pixelData, 1, imageSize, input);
    fclose(input);

    // Hide the message in the pixel data
    size_t messageLength = strlen(message);
    if (messageLength * 8 > imageSize) {
        fprintf(stderr, "Message is too long to hide in the image.\n");
        free(pixelData);
        exit(EXIT_FAILURE);
    }

    // Hide message in pixel data
    for (size_t i = 0; i < messageLength; i++) {
        for (int bit = 0; bit < 8; bit++) {
            int pixelIndex = (i * 8 + bit) * 3; // 3 bytes per pixel for RGB
            if (pixelIndex < imageSize) {
                pixelData[pixelIndex] = (pixelData[pixelIndex] & ~1) | ((message[i] >> (7 - bit)) & 1);
            }
        }
    }

    // Mark the end of the message with a terminator
    for (int bit = 0; bit < 8; bit++) {
        int pixelIndex = (messageLength * 8 + bit) * 3; // 3 bytes per pixel for RGB
        if (pixelIndex < imageSize) {
            pixelData[pixelIndex] = (pixelData[pixelIndex] & ~1) | ((0 >> (7 - bit)) & 1);
        }
    }

    // Write the new image with hidden message
    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        perror("Error opening output file");
        free(pixelData);
        exit(EXIT_FAILURE);
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, output);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, output);
    fseek(output, pixelArrayOffset, SEEK_SET);
    fwrite(pixelData, 1, imageSize, output);
    fclose(output);
    free(pixelData);
    
    printf("Message hidden successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input BMP file> <output BMP file> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    hideMessageInBMP(argv[1], argv[2], argv[3]);
    return EXIT_SUCCESS;
}