//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // Ensure structures are tightly packed

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

unsigned char* loadBMP(const char* filename, BMPHeader* bmpHeader, BMPInfoHeader* bmpInfoHeader) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    fread(bmpHeader, sizeof(BMPHeader), 1, file);
    fread(bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);
    
    unsigned char* data = (unsigned char*)malloc(bmpHeader->bfSize - bmpHeader->bfOffBits);
    fseek(file, bmpHeader->bfOffBits, SEEK_SET);
    fread(data, bmpHeader->bfSize - bmpHeader->bfOffBits, 1, file);
    
    fclose(file);
    return data;
}

void saveBMP(const char* filename, BMPHeader bmpHeader, BMPInfoHeader bmpInfoHeader, unsigned char* data) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error saving file: %s\n", filename);
        return;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);
    fseek(file, bmpHeader.bfOffBits, SEEK_SET);
    fwrite(data, bmpHeader.bfSize - bmpHeader.bfOffBits, 1, file);
    
    fclose(file);
}

void encodeMessage(unsigned char* bmpData, const char* message) {
    size_t messageLength = strlen(message);
    size_t dataIndex = 0;
    
    // Encode message length
    for (int i = 0; i < 8; i++) {
        bmpData[dataIndex] = (bmpData[dataIndex] & 0xFE) | ((messageLength >> i) & 0x01);
        dataIndex += (dataIndex % 3 == 2) ? 2 : 1; // Skip to next pixel
    }
    
    // Encode message
    for (size_t i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            bmpData[dataIndex] = (bmpData[dataIndex] & 0xFE) | ((message[i] >> j) & 0x01);
            dataIndex += (dataIndex % 3 == 2) ? 2 : 1; // Skip to next pixel
        }
    }
}

void decodeMessage(unsigned char* bmpData, char* message) {
    size_t messageLength = 0;
    
    // Decode message length
    for (int i = 0; i < 8; i++) {
        messageLength |= ((bmpData[i] & 0x01) << i);
    }

    // Decode message
    for (size_t i = 0; i < messageLength; i++) {
        char character = 0;
        for (int j = 0; j < 8; j++) {
            character |= ((bmpData[i * 8 + 8 + j] & 0x01) << j);
        }
        message[i] = character;
    }
    message[messageLength] = '\0'; // Null-terminated string
}

int main() {
    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    // Load BMP image
    unsigned char* bmpData = loadBMP("input.bmp", &bmpHeader, &bmpInfoHeader);
    if (!bmpData) return 1;

    // Encode a message
    const char* message = "Hello, Steganography!";
    encodeMessage(bmpData, message);
    saveBMP("output.bmp", bmpHeader, bmpInfoHeader, bmpData);

    // Decode the message from the modified BMP
    char decodedMessage[256];
    decodeMessage(bmpData, decodedMessage);
    
    printf("Decoded message: %s\n", decodedMessage);

    free(bmpData);
    return 0;
}