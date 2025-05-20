//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;      // File type
    unsigned int bfSize;        // File size in bytes
    unsigned short bfReserved1; // Reserved; must be zero
    unsigned short bfReserved2; // Reserved; must be zero
    unsigned int bfOffBits;     // Offset to start of pixel data
} BMPHeader;

typedef struct {
    unsigned int biSize;          // Size of this header
    int biWidth;                  // Width of bitmap in pixels
    int biHeight;                 // Height of bitmap in pixels
    unsigned short biPlanes;      // Number of color planes
    unsigned short biBitCount;    // Bits per pixel
    unsigned int biCompression;    // Compression type
    unsigned int biSizeImage;      // Size of image data
    int biXPixPerMeter;            // Horizontal resolution
    int biYPixPerMeter;            // Vertical resolution
    unsigned int biClrUsed;        // Number of colors in the palette
    unsigned int biClrImportant;    // Important colors
} BMPInfoHeader;

#pragma pack(pop)

void hideMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *input = fopen(inputImage, "rb");
    FILE *output = fopen(outputImage, "wb");

    if (!input || !output) {
        fprintf(stderr, "Error opening files.\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, input);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, input);

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, output);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, output);

    int messageLength = strlen(message);
    fputc(messageLength, output); // store the length of the message

    // Hide the message into the pixel data
    unsigned char pixel[3];
    for (int i = 0; i < messageLength; i++) {
        for (int bit = 0; bit < 8; bit++) {
            fread(pixel, sizeof(unsigned char), 3, input);
            int lsb = pixel[0] & 1; // Get the least significant bit of the blue component

            if (lsb == (message[i] >> (7 - bit) & 1)) {
                pixel[0] ^= 1; // Flip the lsb if it matches to embed the bit
            }
            fwrite(pixel, sizeof(unsigned char), 3, output);
        }
    }

    // Copy the rest of the pixel data
    while (fread(pixel, sizeof(unsigned char), 3, input) == 3) {
        fwrite(pixel, sizeof(unsigned char), 3, output);
    }

    fclose(input);
    fclose(output);
}

void extractMessage(const char *inputImage) {
    FILE *input = fopen(inputImage, "rb");
    if (!input) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, input);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, input);

    int messageLength = fgetc(input); // read the length of the message
    char *message = (char *)malloc(messageLength + 1);
    message[messageLength] = '\0'; // Null-terminate the string

    unsigned char pixel[3];
    for (int i = 0; i < messageLength; i++) {
        char character = 0;
        for (int bit = 0; bit < 8; bit++) {
            fread(pixel, sizeof(unsigned char), 3, input);
            character |= (pixel[0] & 1) << (7 - bit); // get the lsb of the blue pixel
        }
        message[i] = character;
    }

    printf("Extracted Message: %s\n", message);
    free(message);
    fclose(input);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <hide/extract> <image.bmp> <output.bmp/message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "hide") == 0) {
        hideMessage(argv[2], argv[3], argv[4]);
        printf("Message hidden in %s\n", argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        printf("Invalid command. Use 'hide' or 'extract'.\n");
    }

    return 0;
}