//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
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

void encodeMessageInBitmap(const char *bitmapFilename, const char *message) {
    FILE *bitmapFile = fopen(bitmapFilename, "rb+");
    if (!bitmapFile) {
        perror("Could not open the bitmap file");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, bitmapFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, bitmapFile);

    // Go to pixel data start
    fseek(bitmapFile, bfh.bfOffBits, SEEK_SET);

    // Calculate how much space we have in the image for hiding the message
    long numberOfPixels = (bih.biWidth * bih.biHeight);
    long maxMessageSize = numberOfPixels * 3; // 3 bytes per pixel (RGB)
    
    if (strlen(message) * 8 > maxMessageSize) {
        printf("Error: Message is too large to hide in this image.\n");
        fclose(bitmapFile);
        return;
    }
    
    // Write the length of the message as a 32-bit value in the first four pixels
    unsigned int messageLength = strlen(message);
    for (int i = 0; i < 4; i++) {
        fputc((messageLength >> (i * 8)) & 0xFF, bitmapFile);
    }

    // Hide the message in the image
    for (int i = 0; i < messageLength; i++) {
        for (int bit = 0; bit < 8; bit++) {
            unsigned char pixelValue;
            fread(&pixelValue, sizeof(unsigned char), 1, bitmapFile);
            // Modify the least significant bit to match the message bit
            pixelValue = (pixelValue & ~0x01) | ((message[i] >> bit) & 0x01);
            fseek(bitmapFile, -1, SEEK_CUR);
            fwrite(&pixelValue, sizeof(unsigned char), 1, bitmapFile);
        }
    }

    fclose(bitmapFile);
    printf("Message encoded successfully in %s\n", bitmapFilename);
}

void decodeMessageFromBitmap(const char *bitmapFilename) {
    FILE *bitmapFile = fopen(bitmapFilename, "rb");
    if (!bitmapFile) {
        perror("Could not open the bitmap file");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, bitmapFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, bitmapFile);
    
    // Go to pixel data start
    fseek(bitmapFile, bfh.bfOffBits, SEEK_SET);

    // Read the length of the message first
    unsigned int messageLength = 0;
    for (int i = 0; i < 4; i++) {
        messageLength |= (fgetc(bitmapFile) << (i * 8));
    }

    char *message = (char *)malloc(messageLength + 1);
    if (message == NULL) {
        perror("Memory allocation failed");
        fclose(bitmapFile);
        return;
    }
    message[messageLength] = '\0'; // Null-terminate the string

    // Read the message from the image
    for (int i = 0; i < messageLength; i++) {
        char currentChar = 0;
        for (int bit = 0; bit < 8; bit++) {
            unsigned char pixelValue;
            fread(&pixelValue, sizeof(unsigned char), 1, bitmapFile);
            // Get the least significant bit
            currentChar |= ((pixelValue & 0x01) << bit);
        }
        message[i] = currentChar;
    }

    fclose(bitmapFile);
    printf("Decoded message: %s\n", message);
    free(message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <encode|decode> <bitmap_file> <message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encodeMessageInBitmap(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessageFromBitmap(argv[2]);
    } else {
        printf("Invalid option! Use 'encode' or 'decode'.\n");
        return 1;
    }

    return 0;
}