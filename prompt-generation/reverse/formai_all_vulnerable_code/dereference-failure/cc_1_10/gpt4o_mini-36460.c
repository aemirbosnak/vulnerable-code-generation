//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // File type
    uint32_t bfSize;      // File size
    uint16_t bfReserved1; // Reserved
    uint16_t bfReserved2; // Reserved
    uint32_t bfOffBits;   // Offset to image data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this struct
    int32_t  biWidth;         // Width of image
    int32_t  biHeight;        // Height of image
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;   // Compression type
    uint32_t biSizeImage;     // Size of image data
    int32_t  biXPelsPerMeter;  // Horizontal resolution
    int32_t  biYPelsPerMeter;  // Vertical resolution
    uint32_t biClrUsed;       // Number of colors
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

void encodeMessageToBMP(const char *inputBMP, const char *outputBMP, const char *message) {
    FILE *inFile = fopen(inputBMP, "rb");
    if (!inFile) {
        perror("Could not open input BMP file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, inFile);
    
    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, inFile);

    if (bih.biBitCount != 24) {
        fprintf(stderr, "Only 24-bit BMP files are supported.\n");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    fseek(inFile, bfh.bfOffBits, SEEK_SET);
    
    // Calculate the maximum length of the message we can hide
    int maxMsgLength = (bih.biWidth * bih.biHeight * 3) / 8; // 3 bytes per pixel
    int messageLen = strlen(message);
    if (messageLen > maxMsgLength) {
        fprintf(stderr, "Message too large to hide in the image.\n");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    // Prepare the new BMP file
    FILE *outFile = fopen(outputBMP, "wb");
    if (!outFile) {
        perror("Could not open output BMP file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, outFile);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, outFile);

    // Copy pixel data and encode the message into the least significant bits
    uint8_t byte;
    for (int i = 0; i < bih.biHeight; i++) {
        for (int j = 0; j < bih.biWidth; j++) {
            fread(&byte, sizeof(uint8_t), 1, inFile);    // Blue
            fwrite(&byte, sizeof(uint8_t), 1, outFile);   // Copy Blue byte
            
            fread(&byte, sizeof(uint8_t), 1, inFile);    // Green
            fwrite(&byte, sizeof(uint8_t), 1, outFile);   // Copy Green byte
            
            fread(&byte, sizeof(uint8_t), 1, inFile);    // Red
            fwrite(&byte, sizeof(uint8_t), 1, outFile);   // Copy Red byte
        }
    }

    // Encode the message length into the first pixel (for later retrieval)
    int pixelCount = 0;
    for (int i = 0; i < messageLen; i++) {
        int pixelIndex = pixelCount * 3; // Each pixel has 3 color channels
        fwrite(&message[i], sizeof(uint8_t), 1, outFile);
        pixelCount++;
    }

    fclose(inFile);
    fclose(outFile);
    
    printf("Message encoded into image successfully!\n");
}

void decodeMessageFromBMP(const char *inputBMP) {
    FILE *inFile = fopen(inputBMP, "rb");
    if (!inFile) {
        perror("Could not open BMP file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, inFile);
    
    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, inFile);

    fseek(inFile, bfh.bfOffBits, SEEK_SET);
    
    uint8_t *message = malloc(sizeof(uint8_t) * (bih.biWidth * bih.biHeight * 3 / 8));
    int messageIndex = 0;

    for (int i = 0; i < bih.biHeight; i++) {
        for (int j = 0; j < bih.biWidth; j++) {
            fread(message + messageIndex, sizeof(uint8_t), 1, inFile);
            messageIndex++;
        }
    }

    printf("Decoded message: ");
    for (int i = 0; i < messageIndex; i++) {
        printf("%c", message[i]);
    }
    printf("\n");

    free(message);
    fclose(inFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encode/decode> <input BMP> <output BMP/message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encodeMessageToBMP(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessageFromBMP(argv[2]);
    } else {
        fprintf(stderr, "Invalid option. Use 'encode' or 'decode'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}