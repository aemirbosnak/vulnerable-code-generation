//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: recursive
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

void embedMessage(unsigned char *pixels, const char *message, int index, int messageLength) {
    if (index < messageLength) {
        // Modify the least significant bit of the pixel
        pixels[index] = (pixels[index] & ~1) | ((message[index] >> 7) & 1);
        embedMessage(pixels, message, index + 1, messageLength);
    }
}

void decodeMessage(unsigned char *pixels, char *message, int index, int messageLength) {
    if (index < messageLength) {
        // Retrieve the least significant bit from the pixel
        message[index] = (pixels[index] & 1) ? (message[index] | (1 << 7)) : (message[index] & ~(1 << 7));
        decodeMessage(pixels, message, index + 1, messageLength);
    }
}

void readBitmap(const char *filename, BITMAPFILEHEADER *bfh, BITMAPINFOHEADER *bih, unsigned char **pixels) {
    FILE *file = fopen(filename, "rb");
    fread(bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(bih, sizeof(BITMAPINFOHEADER), 1, file);

    size_t pixelDataSize = bih->biWidth * bih->biHeight * (bih->biBitCount / 8);
    *pixels = (unsigned char *)malloc(pixelDataSize);
    fseek(file, bfh->bfOffBits, SEEK_SET);
    fread(*pixels, pixelDataSize, 1, file);
    
    fclose(file);
}

void writeBitmap(const char *filename, BITMAPFILEHEADER *bfh, BITMAPINFOHEADER *bih, unsigned char *pixels) {
    FILE *file = fopen(filename, "wb");
    fwrite(bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(bih, sizeof(BITMAPINFOHEADER), 1, file);
    fseek(file, bfh->bfOffBits, SEEK_SET);
    size_t pixelDataSize = bih->biWidth * bih->biHeight * (bih->biBitCount / 8);
    fwrite(pixels, pixelDataSize, 1, file);
    
    fclose(file);
}

int main() {
    const char *inputFilename = "input.bmp";
    const char *outputFilename = "output.bmp";
    const char *message = "Hello!";
    int messageLength = strlen(message);

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    unsigned char *pixels = NULL;

    readBitmap(inputFilename, &bfh, &bih, &pixels);
    
    // Embed the message
    embedMessage(pixels, message, 0, messageLength);
    
    // Write the output image
    writeBitmap(outputFilename, &bfh, &bih, pixels);
    
    // Decode the message
    char *decodedMessage = (char *)malloc(messageLength + 1);
    memset(decodedMessage, 0, messageLength + 1);
    decodeMessage(pixels, decodedMessage, 0, messageLength);

    // Print the decoded message
    printf("Decoded message: %s\n", decodedMessage);
    
    free(pixels);
    free(decodedMessage);
    
    return 0;
}