//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensures the proper packing of the BMP header
typedef struct {
    unsigned short bfType;      // File type
    unsigned int bfSize;        // File size in bytes
    unsigned short bfReserved1; // Reserved
    unsigned short bfReserved2; // Reserved
    unsigned int bfOffBits;     // Offset to start of pixel data
} BMPFileHeader;

typedef struct {
    unsigned int biSize;          // Size of the info header
    int biWidth;                  // Width of the image
    int biHeight;                 // Height of the image
    unsigned short biPlanes;      // Number of color planes
    unsigned short biBitCount;    // Bits per pixel
    unsigned int biCompression;    // Compression type
    unsigned int biSizeImage;      // Image size
    int biXPelsPerMeter;           // X pixels per meter
    int biYPelsPerMeter;           // Y pixels per meter
    unsigned int biClrUsed;        // Number of colors in the palette
    unsigned int biClrImportant;    // Important colors
} BMPInfoHeader;

#pragma pack(pop)

void embedMessage(const char *inputImage, const char *message, const char *outputImage) {
    FILE *fp = fopen(inputImage, "rb");
    if (!fp) {
        fprintf(stderr, "Could not open %s for reading.\n", inputImage);
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    
    fread(&fileHeader, sizeof(BMPFileHeader), 1, fp);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, fp);

    if (fileHeader.bfType != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(fp);
        return;
    }

    unsigned char *imageData = (unsigned char*)malloc(infoHeader.biSizeImage);
    fseek(fp, fileHeader.bfOffBits, SEEK_SET);
    fread(imageData, 1, infoHeader.biSizeImage, fp);
    fclose(fp);

    size_t messageLength = strlen(message);
    for (size_t i = 0; i < messageLength; ++i) {
        for (int j = 0; j < 8; ++j) {
            // Embed each bit of the character into the image
            int pixelIndex = (i * 8 + j) * 3; // Assuming 24-bit BMP (3 bytes per pixel)
            imageData[pixelIndex] = (imageData[pixelIndex] & 0xFE) | ((message[i] >> (7 - j)) & 0x01);
        }
    }

    // Write the modified image to a new file
    fp = fopen(outputImage, "wb");
    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, fp);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, fp);
    fseek(fp, fileHeader.bfOffBits, SEEK_SET);
    fwrite(imageData, 1, infoHeader.biSizeImage, fp);
    fclose(fp);
    free(imageData);

    printf("Message embedded successfully!\n");
}

void extractMessage(const char *inputImage) {
    FILE *fp = fopen(inputImage, "rb");
    if (!fp) {
        fprintf(stderr, "Could not open %s for reading.\n", inputImage);
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, fp);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, fp);

    if (fileHeader.bfType != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(fp);
        return;
    }

    unsigned char *imageData = (unsigned char*)malloc(infoHeader.biSizeImage);
    fseek(fp, fileHeader.bfOffBits, SEEK_SET);
    fread(imageData, 1, infoHeader.biSizeImage, fp);
    fclose(fp);

    char message[1024] = {0}; // Adjust size as needed
    size_t messageLength = 0;
    
    for (size_t i = 0; ; ++i) {
        char character = 0;
        for (int j = 0; j < 8; ++j) {
            // Extract each bit from the image
            int pixelIndex = (i * 8 + j) * 3;
            character |= ((imageData[pixelIndex] & 0x01) << (7 - j));
        }
        if (character == '\0' || messageLength >= sizeof(message) - 1) // Null terminator
            break;
        message[messageLength++] = character;
    }

    printf("Extracted Message: %s\n", message);
    free(imageData);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed/extract> <input_image> <message/output_image>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessage(argv[2], argv[3], "output.bmp");
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        fprintf(stderr, "Invalid option. Use 'embed' or 'extract'.\n");
        return 1;
    }
    return 0;
}