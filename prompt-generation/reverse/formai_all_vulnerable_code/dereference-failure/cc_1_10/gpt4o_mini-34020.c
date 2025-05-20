//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define a structure to represent the BMP file header
#pragma pack(push, 1) // Ensure structure alignment
typedef struct {
    uint16_t fileType;          // BMP file type
    uint32_t fileSize;          // Size of the BMP file
    uint16_t reserved1;         // Reserved
    uint16_t reserved2;         // Reserved
    uint32_t offsetData;        // Offset to start of pixel data
} BMPHeader;

typedef struct {
    uint32_t size;              // Size of this header (40 bytes)
    int32_t width;              // Width of the bitmap in pixels
    int32_t height;             // Height of the bitmap in pixels
    uint16_t planes;            // Number of color planes
    uint16_t bitCount;          // Bits per pixel
    uint32_t compression;       // Compression type
    uint32_t sizeImage;         // Size of the raw bitmap data
    int32_t xPixelsPerMeter;     // Horizontal resolution
    int32_t yPixelsPerMeter;     // Vertical resolution
    uint32_t colorsUsed;        // Number of colors in the color palette
    uint32_t colorsImportant;   // Important colors
} BMPInfoHeader;
#pragma pack(pop)

// Function declarations
void embed_message(const char *input_filename, const char *output_filename, const char *message);
void extract_message(const char *filename);
void write_bmp_file(const char *filename, BMPHeader header, BMPInfoHeader infoHeader, uint8_t *pixels);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <embed/extract> <input_file> <output_file> <message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed_message(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_message(argv[2]);
    } else {
        printf("Invalid action. Use 'embed' or 'extract'.\n");
        return 1;
    }
    return 0;
}

void embed_message(const char *input_filename, const char *output_filename, const char *message) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Failed to open input file");
        exit(1);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    // Read BMP header
    fread(&bmpHeader, sizeof(BMPHeader), 1, input_file);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, input_file);

    // Check if it's a valid BMP file
    if (bmpHeader.fileType != 0x4D42) {
        printf("This is not a BMP file.\n");
        fclose(input_file);
        exit(1);
    }

    // Allocate memory for pixel data
    long pixelDataSize = bmpInfoHeader.sizeImage;
    uint8_t *pixels = (uint8_t *)malloc(pixelDataSize);
    fseek(input_file, bmpHeader.offsetData, SEEK_SET);
    fread(pixels, 1, pixelDataSize, input_file);
    fclose(input_file);

    // Determine the length of the message
    size_t messageLength = strlen(message);
    if (messageLength > pixelDataSize / 8) {
        printf("Message is too long to embed.\n");
        free(pixels);
        exit(1);
    }

    // Embed the message into the least significant bits of the pixel data
    for (size_t i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            // Set the LSB of the pixel to the message bit
            pixels[i * 8 + j] = (pixels[i * 8 + j] & ~1) | ((message[i] >> (7 - j)) & 1);
        }
    }

    // Write the modified pixel array to a new BMP file
    write_bmp_file(output_filename, bmpHeader, bmpInfoHeader, pixels);
    free(pixels);
}

void write_bmp_file(const char *filename, BMPHeader header, BMPInfoHeader infoHeader, uint8_t *pixels) {
    FILE *output_file = fopen(filename, "wb");
    if (!output_file) {
        perror("Failed to open output file");
        exit(1);
    }

    fwrite(&header, sizeof(BMPHeader), 1, output_file);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, output_file);
    fwrite(pixels, infoHeader.sizeImage, 1, output_file);
    fclose(output_file);
}

void extract_message(const char *filename) {
    FILE *input_file = fopen(filename, "rb");
    if (!input_file) {
        perror("Failed to open input file");
        exit(1);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    // Read BMP header
    fread(&bmpHeader, sizeof(BMPHeader), 1, input_file);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, input_file);

    // Check if it's a valid BMP file
    if (bmpHeader.fileType != 0x4D42) {
        printf("This is not a BMP file.\n");
        fclose(input_file);
        exit(1);
    }

    // Allocate memory for pixel data
    long pixelDataSize = bmpInfoHeader.sizeImage;
    uint8_t *pixels = (uint8_t *)malloc(pixelDataSize);
    fseek(input_file, bmpHeader.offsetData, SEEK_SET);
    fread(pixels, 1, pixelDataSize, input_file);
    fclose(input_file);

    // Extract the message from the least significant bits of the pixel data
    char message[256] = {0};
    for (size_t i = 0; i < 32; i++) { // Arbitrarily limit to 32 characters
        for (int j = 0; j < 8; j++) {
            message[i] = (message[i] << 1) | (pixels[i * 8 + j] & 1);
        }
        if (message[i] == '\0') break; // Stop if we hit the null terminator
    }

    printf("Extracted message: %s\n", message);
    free(pixels);
}