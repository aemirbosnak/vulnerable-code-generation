//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensuring no padding in structs
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPHeader;

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
} BMPInfoHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;
#pragma pack(pop)

void embedMessage(const char *inputFile, const char *outputFile, const char *message) {
    FILE *in = fopen(inputFile, "rb");
    if (!in) {
        perror("Unable to open input BMP file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, in);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, in);

    int width = bmpInfoHeader.biWidth;
    int height = bmpInfoHeader.biHeight;
    int pixelCount = width * height;

    // Calculate bytes needed for message
    int messageLen = strlen(message);
    int bitsNeeded = messageLen * 8 + 1; // +1 for the null terminator
    int pixelsNeeded = (bitsNeeded + 23) / 24; // Each pixel can hold 3 bits

    if (pixelsNeeded > pixelCount) {
        printf("Message is too long to be embedded in this image.\n");
        fclose(in);
        return;
    }

    Pixel *pixels = malloc(pixelCount * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), pixelCount, in);
    fclose(in);

    // Embed the message into the least significant bits of the pixels
    int bitIndex = 0;
    for (int i = 0; i < pixelsNeeded; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (bitIndex < bitsNeeded) {
                pixels[i].blue = (pixels[i].blue & 0xFE) | ((message[bitIndex / 8] >> (bitIndex % 8)) & 0x01);
                bitIndex++;
            }
            if (bitIndex < bitsNeeded) {
                pixels[i].green = (pixels[i].green & 0xFE) | ((message[bitIndex / 8] >> (bitIndex % 8)) & 0x01);
                bitIndex++;
            }
            if (bitIndex < bitsNeeded) {
                pixels[i].red = (pixels[i].red & 0xFE) | ((message[bitIndex / 8] >> (bitIndex % 8)) & 0x01);
                bitIndex++;
            }
        }
    }

    FILE *out = fopen(outputFile, "wb");
    if (!out) {
        perror("Unable to create output BMP file");
        free(pixels);
        return;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, out);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, out);
    fwrite(pixels, sizeof(Pixel), pixelCount, out);
    fclose(out);
    free(pixels);

    printf("Message embedded successfully in %s\n", outputFile);
}

void extractMessage(const char *inputFile) {
    FILE *in = fopen(inputFile, "rb");
    if (!in) {
        perror("Unable to open BMP file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, in);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, in);

    int width = bmpInfoHeader.biWidth;
    int height = bmpInfoHeader.biHeight;
    int pixelCount = width * height;

    Pixel *pixels = malloc(pixelCount * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), pixelCount, in);
    fclose(in);

    char message[256] = {0};
    int bitIndex = 0;

    for (int i = 0; i < pixelCount; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (bitIndex < 2048) { // Limit the message size for practical purposes
                char bit = (j == 0) ? (pixels[i].blue & 0x01) :
                           (j == 1) ? (pixels[i].green & 0x01) :
                           (pixels[i].red & 0x01);
                message[bitIndex / 8] |= (bit << (bitIndex % 8));
                bitIndex++;
            }
        }
    }

    free(pixels);

    // Print the extracted message
    printf("Extracted Message: %s\n", message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed/extract> <input BMP file> <output BMP file/message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessage(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        printf("Invalid command. Use 'embed' or 'extract'.\n");
    }

    return 0;
}