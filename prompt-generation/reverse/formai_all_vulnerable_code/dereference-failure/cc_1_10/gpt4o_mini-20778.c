//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)  // Ensure structure packing for BMP format
typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} BMPHeader;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitCount;
    unsigned int compression;
    unsigned int sizeImage;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int crColorUsed;
    unsigned int crImportantColor;
} BMPInfoHeader;
#pragma pack(pop)

void embedMessage(const char* imagePath, const char* message) {
    FILE *imgFile = fopen(imagePath, "rb+");
    if (!imgFile) {
        perror("Error opening image file");
        return;
    }
    
    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, imgFile);
    
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, imgFile);
    
    // Calculate the size needed for the message
    size_t messageLength = strlen(message);
    size_t totalBytes = (messageLength + 1) * 8;  // +1 for null terminator
    size_t pixelCount = bmpInfoHeader.width * bmpInfoHeader.height;

    if (totalBytes > pixelCount) {
        printf("Message too long to embed in image.\n");
        fclose(imgFile);
        return;
    }

    fseek(imgFile, bmpHeader.offset, SEEK_SET);
    
    for (size_t i = 0; i < totalBytes; i++) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, imgFile);
        
        // Modify the least significant bit of the pixel color
        pixel[0] = (pixel[0] & 0xFE) | ((message[i / 8] >> (7 - (i % 8))) & 0x01);

        fseek(imgFile, -3, SEEK_CUR); // Go back to write the modified pixel
        fwrite(pixel, sizeof(unsigned char), 3, imgFile);
    }
    
    fclose(imgFile);
    printf("Message embedded successfully!\n");
}

void extractMessage(const char* imagePath) {
    FILE *imgFile = fopen(imagePath, "rb");
    if (!imgFile) {
        perror("Error opening image file");
        return;
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, imgFile);
    
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, imgFile);
    
    fseek(imgFile, bmpHeader.offset, SEEK_SET);
    
    char message[256];  // Arbitrary limit for extracted message
    memset(message, 0, sizeof(message));
    
    for (size_t i = 0; i < sizeof(message) * 8; i++) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, imgFile);
        
        // Extract the least significant bit of the pixel color
        if (i < (sizeof(message) * 8)) {
            message[i / 8] |= ((pixel[0] & 0x01) << (7 - (i % 8)));
        }
        
        // Stop extracting when we meet a null character
        if (message[i / 8] == '\0') {
            break;
        }
    }

    fclose(imgFile);
    printf("Extracted Message: \"%s\"\n", message);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <image_path> <message>\n", argv[0]);
        fprintf(stderr, "Or: %s <image_path> extract\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[2], "extract") == 0) {
        extractMessage(argv[1]);
    } else {
        embedMessage(argv[1], argv[2]);
    }

    return EXIT_SUCCESS;
}