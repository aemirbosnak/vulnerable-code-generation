//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // Ensure structure packing for BMP header

typedef struct {
    unsigned short type;      // BMP file type
    unsigned int size;       // BMP file size in bytes
    unsigned short reserved1; // Reserved
    unsigned short reserved2; // Reserved
    unsigned int offset;      // Offset to bitmap data
} BMPHeader;

typedef struct {
    unsigned int size;         // Size of the header
    int width;                 // Width of the image
    int height;                // Height of the image
    unsigned short planes;     // Number of color planes
    unsigned short bitsPerPixel; // Bits per pixel
    unsigned int compression;   // Compression type
    unsigned int sizeImage;     // Image size
    int xPixelsPerMeter;        // Horizontal resolution
    int yPixelsPerMeter;        // Vertical resolution
    unsigned int colorsUsed;     // Number of colors in the palette
    unsigned int colorsImportant; // Important colors
} BMPInfoHeader;

void embedMessageInBitmap(const char *bmpFile, const char *message) {
    FILE *bmp = fopen(bmpFile, "rb+");
    if (!bmp) {
        printf("Error: Cannot open file %s\n", bmpFile);
        return; 
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    
    fread(&bmpHeader, sizeof(BMPHeader), 1, bmp);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, bmp);
    
    // Validate BMP format
    if (bmpHeader.type != 0x4D42) {
        printf("Error: Not a valid BMP file\n");
        fclose(bmp);
        return;
    }

    // Prepare the message by calculating its length
    int messageLength = strlen(message);
    int messageSizeWithTerminate = messageLength + 1; // +1 for null terminator
    
    // Ensure the message can fit in the image
    int totalPixels = bmpInfoHeader.width * bmpInfoHeader.height;
    if (messageSizeWithTerminate * 8 > totalPixels) {
        printf("Error: Message too long to embed in this image.\n");
        fclose(bmp);
        return;
    }

    // Seek to the pixel data position
    fseek(bmp, bmpHeader.offset, SEEK_SET);

    // Encode the message in the least significant bit of the pixels
    for (int i = 0; i < messageSizeWithTerminate; i++) {
        char currentChar = message[i];
        for (int bit = 0; bit < 8; bit++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, bmp);

            // Modify the LSB of blue channel
            pixel[0] = (pixel[0] & 0xFE) | ((currentChar >> (7 - bit)) & 0x01);

            // Write the modified pixel back
            fseek(bmp, -3, SEEK_CUR); // Move back to write
            fwrite(pixel, sizeof(unsigned char), 3, bmp);
        }
    }

    fclose(bmp);
}

void extractMessageFromBitmap(const char *bmpFile) {
    FILE *bmp = fopen(bmpFile, "rb");
    if (!bmp) {
        printf("Error: Cannot open file %s\n", bmpFile);
        return; 
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, bmp);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, bmp);

    if (bmpHeader.type != 0x4D42) {
        printf("Error: Not a valid BMP file\n");
        fclose(bmp);
        return;
    }

    fseek(bmp, bmpHeader.offset, SEEK_SET);

    char extractedMessage[1024] = {0}; // Assume maximum message size
    int index = 0;
    
    // Extract the message from the least significant bits
    while (index < 1023) {
        int currentChar = 0;
        for (int bit = 0; bit < 8; bit++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, bmp);

            // Get the LSB of the blue channel
            currentChar = (currentChar << 1) | (pixel[0] & 0x01);
        }

        if (currentChar == 0) {
            break; // Null terminator reached
        }
        extractedMessage[index++] = (char)currentChar;
    }

    fclose(bmp);
    printf("Extracted Message: %s\n", extractedMessage);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed/extract> <image_file> [<message>]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0 && argc == 4) {
        embedMessageInBitmap(argv[2], argv[3]);
        printf("Message embedded successfully.\n");
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessageFromBitmap(argv[2]);
    } else {
        printf("Invalid arguments.\n");
    }

    return 0;
}