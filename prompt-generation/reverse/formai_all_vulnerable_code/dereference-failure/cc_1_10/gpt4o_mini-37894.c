//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    uint16_t bfType;      // Magic number for file
    uint32_t bfSize;      // Size of file in bytes
    uint16_t bfReserved1; // Reserved; must be zero
    uint16_t bfReserved2; // Reserved; must be zero
    uint32_t bfOffBits;   // Offset to the pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the image
    int32_t  biHeight;        // Height of the image
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Image size (can be 0 for uncompressed images)
    int32_t  biXPelsPerMeter;   // Horizontal resolution
    int32_t  biYPelsPerMeter;   // Vertical resolution
    uint32_t biClrUsed;       // Number of colors in the palette
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} PIXEL;

// Function prototypes
void encodeMessageToImage(const char *message, const char *inputImagePath, const char *outputImagePath);
void decodeMessageFromImage(const char *inputImagePath);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encode/decode> <image-path> <output-path/message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        const char *message = argv[3];
        encodeMessageToImage(message, argv[2], argv[3]);
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessageFromImage(argv[2]);
    } else {
        fprintf(stderr, "Invalid option. Use 'encode' or 'decode'.\n");
        return 1;
    }

    return 0;
}

void encodeMessageToImage(const char *message, const char *inputImagePath, const char *outputImagePath) {
    FILE *imageFile = fopen(inputImagePath, "rb");
    if (!imageFile) {
        perror("Error opening input image file");
        exit(1);
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, imageFile);
    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, imageFile);

    if (bih.biBitCount != 24) {
        fprintf(stderr, "Only 24-bit BMP images are supported.\n");
        fclose(imageFile);
        return;
    }

    // Move to the pixel array
    fseek(imageFile, bfh.bfOffBits, SEEK_SET);
    PIXEL *pixels = malloc(bih.biWidth * bih.biHeight * sizeof(PIXEL));
    fread(pixels, sizeof(PIXEL), bih.biWidth * bih.biHeight, imageFile);
    fclose(imageFile);

    // Prepare the message
    char messageWithTerminator[1024];
    snprintf(messageWithTerminator, sizeof(messageWithTerminator), "%s", message);
    
    // Append a delimiter
    strcat(messageWithTerminator, "<END>");
    size_t messageLen = strlen(messageWithTerminator);

    if (messageLen * 8 > bih.biWidth * bih.biHeight * 3) {
        fprintf(stderr, "Message is too long to encode in this image.\n");
        free(pixels);
        return;
    }

    // Encode message into image
    for (size_t i = 0; i < messageLen; i++) {
        for (int bit = 0; bit < 8; bit++) {
            size_t pixelIndex = i * 8 + bit;
            if (pixelIndex >= bih.biWidth * bih.biHeight) 
                break;

            uint8_t *byte = ((uint8_t *)&pixels[pixelIndex]);
            *byte = (*byte & 0xFE) | ((messageWithTerminator[i] >> (7 - bit)) & 1);
        }
    }

    // Write to a new output image
    FILE *outputFile = fopen(outputImagePath, "wb");
    if (!outputFile) {
        perror("Error opening output image file");
        free(pixels);
        return;
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fwrite(pixels, sizeof(PIXEL), bih.biWidth * bih.biHeight, outputFile);
    
    fclose(outputFile);
    free(pixels);
}

void decodeMessageFromImage(const char *inputImagePath) {
    FILE *imageFile = fopen(inputImagePath, "rb");
    if (!imageFile) {
        perror("Error opening input image file");
        exit(1);
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, imageFile);
    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, imageFile);

    if (bih.biBitCount != 24) {
        fprintf(stderr, "Only 24-bit BMP images are supported for decoding.\n");
        fclose(imageFile);
        return;
    }

    // Move to the pixel array
    fseek(imageFile, bfh.bfOffBits, SEEK_SET);
    PIXEL *pixels = malloc(bih.biWidth * bih.biHeight * sizeof(PIXEL));
    fread(pixels, sizeof(PIXEL), bih.biWidth * bih.biHeight, imageFile);
    fclose(imageFile);

    char message[1024] = {0};
    size_t index = 0;
    
    // Decode message from image
    for (size_t i = 0; i < bih.biWidth * bih.biHeight; i++) {
        for (int bit = 0; bit < 8; bit++) {
            if (index >= sizeof(message) - 1) {
                break;
            }
            uint8_t byte = ((uint8_t *)&pixels[i])[0]; // Get the R component for simplicity
            message[index] <<= 1;
            message[index] |= (byte & 0x01); // Add least significant bit

            if (index > 0 && strstr(message, "<END>") != NULL) {
                message[index + 1] = '\0'; // Null-terminate the message
                break;
            }
            if (!(byte & 0x01)) {
                index++; // Move to next character after one complete byte
            }
        }
    }

    printf("Decoded Message: %s\n", message);
    free(pixels);
}