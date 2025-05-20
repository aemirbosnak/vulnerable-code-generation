//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char header[54];
    unsigned int width;
    unsigned int height;
} BMPHeader;

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;
#pragma pack(pop)

// Function to open a BMP file and read its header and pixel data
Pixel** loadBMP(const char* filename, BMPHeader* bmpHeader) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    fread(bmpHeader->header, sizeof(unsigned char), 54, file);
    bmpHeader->width = *(unsigned int*)&bmpHeader->header[18];
    bmpHeader->height = *(unsigned int*)&bmpHeader->header[22];

    Pixel** pixels = (Pixel**)malloc(bmpHeader->height * sizeof(Pixel*));
    for (unsigned int i = 0; i < bmpHeader->height; i++) {
        pixels[i] = (Pixel*)malloc(bmpHeader->width * sizeof(Pixel));
        fread(pixels[i], sizeof(Pixel), bmpHeader->width, file);
    }

    fclose(file);
    return pixels;
}

// Function to save the modified BMP image
void saveBMP(const char* filename, BMPHeader* bmpHeader, Pixel** pixels) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file to write: %s\n", filename);
        return;
    }

    fwrite(bmpHeader->header, sizeof(unsigned char), 54, file);
    for (unsigned int i = 0; i < bmpHeader->height; i++) {
        fwrite(pixels[i], sizeof(Pixel), bmpHeader->width, file);
        free(pixels[i]); // Free row memory here
    }
    
    free(pixels); // Free pointer to rows
    fclose(file);
}

// Function to encode a message into the least significant bits of pixel colors
void encodeMessage(Pixel** pixels, BMPHeader* bmpHeader, const char* message) {
    int messageLength = strlen(message);
    int totalPixels = bmpHeader->width * bmpHeader->height;

    // Encode message length
    for (int i = 0; i < 32; i++) {
        if (i < 32) {
            // Get the bit value from the message length
            int bit = (messageLength >> i) & 1;
            // Write it in the least significant bit of the pixel
            if (i < totalPixels) {
                pixels[i / bmpHeader->width][i % bmpHeader->width].red = 
                    (pixels[i / bmpHeader->width][i % bmpHeader->width].red & 0xFE) | bit;
            }
        }
    }

    // Encode actual message
    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            int bit = (message[i] >> j) & 1;
            if ((32 + (i * 8 + j)) < totalPixels) {
                pixels[(32 + (i * 8 + j)) / bmpHeader->width]
                      [(32 + (i * 8 + j)) % bmpHeader->width].red = 
                      (pixels[(32 + (i * 8 + j)) / bmpHeader->width]
                             [(32 + (i * 8 + j)) % bmpHeader->width].red & 0xFE) | bit;
            }
        }
    }
}

// Function to decode a message from the least significant bits of pixel colors
void decodeMessage(Pixel** pixels, BMPHeader* bmpHeader, char* message) {
    int messageLength = 0;
    
    // Decode message length
    for (int i = 0; i < 32; i++) {
        if (i < (bmpHeader->width * bmpHeader->height)) {
            messageLength |= (pixels[i / bmpHeader->width][i % bmpHeader->width].red & 1) << i;
        }
    }

    // Decode actual message
    for (int i = 0; i < messageLength; i++) {
        char c = 0;
        for (int j = 0; j < 8; j++) {
            if ((32 + (i * 8 + j)) < (bmpHeader->width * bmpHeader->height)) {
                c |= (pixels[(32 + (i * 8 + j)) / bmpHeader->width]
                       [(32 + (i * 8 + j)) % bmpHeader->width].red & 1) << j;
            }
        }
        message[i] = c;
    }
    message[messageLength] = '\0'; // Null terminate the message
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <message>\n", argv[0]);
        return 1;
    }

    const char* inputFile = argv[1];
    const char* outputFile = argv[2];
    const char* message = argv[3];

    BMPHeader bmpHeader;
    Pixel** pixels = loadBMP(inputFile, &bmpHeader);
    if (!pixels) {
        return 1;
    }

    encodeMessage(pixels, &bmpHeader, message);
    saveBMP(outputFile, &bmpHeader, pixels);

    // Decode the message from the saved BMP to verify
    pixels = loadBMP(outputFile, &bmpHeader);
    char decodedMessage[256];
    decodeMessage(pixels, &bmpHeader, decodedMessage);
    
    printf("Decoded Message: %s\n", decodedMessage);

    return 0;
}