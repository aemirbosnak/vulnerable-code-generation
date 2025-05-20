//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define a struct for storing pixel information.
#pragma pack(push, 1)
typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;
#pragma pack(pop)

// Function to read a BMP file into memory.
Pixel* readBMP(const char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open BMP file");
        return NULL;
    }

    fseek(file, 18, SEEK_SET);
    fread(width, sizeof(int), 1, file);
    fread(height, sizeof(int), 1, file);
    
    fseek(file, 54, SEEK_SET); // Skip the header
    long size = (*width) * (*height) * sizeof(Pixel);
    Pixel* pixels = malloc(size);
    
    if (!pixels) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }
    
    fread(pixels, size, 1, file);
    fclose(file);
    return pixels;
}

// Function to write pixel data back into a BMP file.
void writeBMP(const char* filename, Pixel* pixels, int width, int height) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open BMP file for writing");
        return;
    }
    
    // Write a simple BMP header
    uint16_t bfType = 0x4D42;
    uint32_t bfSize = 54 + sizeof(Pixel) * width * height; // Simple header
    uint16_t bfReserved1 = 0;
    uint16_t bfReserved2 = 0;
    uint32_t bfOffBits = 54; 

    fwrite(&bfType, sizeof(uint16_t), 1, file);
    fwrite(&bfSize, sizeof(uint32_t), 1, file);
    fwrite(&bfReserved1, sizeof(uint16_t), 1, file);
    fwrite(&bfReserved2, sizeof(uint16_t), 1, file);
    fwrite(&bfOffBits, sizeof(uint32_t), 1, file);
    
    // Write the DIB header
    uint32_t biSize = 40;
    uint32_t biWidth = width;
    uint32_t biHeight = height;
    uint16_t biPlanes = 1;
    uint16_t biBitCount = 24; 
    uint32_t biCompression = 0;
    uint32_t biSizeImage = 0;
    uint32_t biXPelsPerMeter = 0;
    uint32_t biYPelsPerMeter = 0;
    uint32_t biClrUsed = 0;
    uint32_t biClrImportant = 0;

    fwrite(&biSize, sizeof(uint32_t), 1, file);
    fwrite(&biWidth, sizeof(uint32_t), 1, file);
    fwrite(&biHeight, sizeof(uint32_t), 1, file);
    fwrite(&biPlanes, sizeof(uint16_t), 1, file);
    fwrite(&biBitCount, sizeof(uint16_t), 1, file);
    fwrite(&biCompression, sizeof(uint32_t), 1, file);
    fwrite(&biSizeImage, sizeof(uint32_t), 1, file);
    fwrite(&biXPelsPerMeter, sizeof(uint32_t), 1, file);
    fwrite(&biYPelsPerMeter, sizeof(uint32_t), 1, file);
    fwrite(&biClrUsed, sizeof(uint32_t), 1, file);
    fwrite(&biClrImportant, sizeof(uint32_t), 1, file);

    fwrite(pixels, sizeof(Pixel), width * height, file);
    fclose(file);
}

// Function to encode a message into the blue channel of the image pixels.
void encodeMessage(Pixel* pixels, int width, int height, const char* message) {
    int messageLen = strlen(message);
    int i, j;
    for (i = 0; i < messageLen; i++) {
        for (j = 0; j < 8; j++) {
            if (i * 8 + j >= width * height) {
                return; // Image is too small to contain the message
            }
            int pixelIndex = i * 8 + j;
            // Set the least significant bit of the blue color channel
            pixels[pixelIndex].blue = (pixels[pixelIndex].blue & ~1) | ((message[i] >> (7 - j)) & 1);
        }
    }
}

// Function to decode a message from the blue channel of the image pixels.
void decodeMessage(Pixel* pixels, int width, int height) {
    char message[1024];
    int index = 0;
    for (int i = 0; i < width * height; i++) {
        if (index >= 1023) {
            break; // Prevent buffer overflow
        }
        // Build the byte character by examining the least significant bits
        if (i % 8 == 0) {
            message[index] = 0; // Start a new byte
        }
        message[index] |= (pixels[i].blue & 1) << (7 - (i % 8));
        if (i % 8 == 7) {
            index++; // Move to next byte
        }
    }
    message[index] = '\0'; // Null terminate
    printf("Decoded Message: %s\n", message);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_bmp> <output_bmp> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    Pixel* pixels = readBMP(argv[1], &width, &height);
    if (!pixels) {
        return EXIT_FAILURE;
    }

    // Encode the message in the pixels
    encodeMessage(pixels, width, height, argv[3]);

    // Write the modified pixels to a new BMP file
    writeBMP(argv[2], pixels, width, height);
    
    // Optional: Decode the message to verify correctness
    decodeMessage(pixels, width, height);

    free(pixels);
    return EXIT_SUCCESS;
}