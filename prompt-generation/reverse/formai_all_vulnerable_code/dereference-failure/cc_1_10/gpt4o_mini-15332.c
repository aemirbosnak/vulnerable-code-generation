//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Simple bitmap structure for 24-bit BMP files
#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;       // BMP file type
    uint32_t bfSize;       // BMP file size
    uint16_t bfReserved1;  // Reserved
    uint16_t bfReserved2;  // Reserved
    uint32_t bfOffBits;    // Offset to the pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the bitmap
    int32_t  biHeight;        // Height of the bitmap
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Image size
    int32_t  biXPelsPerMeter;   // Horizontal resolution
    int32_t  biYPelsPerMeter;   // Vertical resolution
    uint32_t biClrUsed;        // Number of colors
    uint32_t biClrImportant;    // Important colors
} BITMAPINFOHEADER;

typedef struct {
    uint8_t Blue;
    uint8_t Green;
    uint8_t Red;
} PIXEL;
#pragma pack(pop)

// Function declarations
void embedMessage(const char* message, const char* inputImage, const char* outputImage);
void extractMessage(const char* inputImage);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("In a world of chaos and shadows, you must specify:\n");
        printf("Usage: %s <embed/extract> <image.bmp> <output.bmp|message>\n", argv[0]);
        return 1;
    }

    // Command line handling
    if (strcmp(argv[1], "embed") == 0) {
        char* message = "The truth lies beneath."; // Steganography message
        embedMessage(message, argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        printf("Unknown command. Choose 'embed' or 'extract'.\n");
    }

    return 0;
}

void embedMessage(const char* message, const char* inputImage, const char* outputImage) {
    FILE *imageFile = fopen(inputImage, "rb");
    if (!imageFile) {
        perror("Failed to open image file for embedding");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, imageFile);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, imageFile);

    // Verify that we are dealing with a 24-bit BMP
    if (fileHeader.bfType != 0x4D42 || infoHeader.biBitCount != 24) {
        fclose(imageFile);
        printf("Only 24-bit BMP files are supported.\n");
        return;
    }

    size_t messageLength = strlen(message);
    size_t pixelCount = (infoHeader.biWidth * infoHeader.biHeight);
    size_t totalPixels = (pixelCount * 3);

    if (messageLength * 8 > totalPixels) {
        fclose(imageFile);
        printf("Message is too long to embed in the image.\n");
        return;
    }

    fseek(imageFile, fileHeader.bfOffBits, SEEK_SET);
    PIXEL *pixels = malloc(totalPixels * sizeof(PIXEL));
    fread(pixels, sizeof(PIXEL), pixelCount, imageFile);
    fclose(imageFile);

    // Embed the message in the least significant bits of the pixel data
    for (size_t i = 0; i < messageLength; i++) {
        for (int bit = 0; bit < 8; bit++) {
            int pixelIndex = (i * 8 + bit) / 3; 
            int colorIndex = (i * 8 + bit) % 3; 

            // Store the bit in the least significant bit of the color component
            if (message[i] & (1 << (7 - bit))) {
                pixels[pixelIndex].Red |= 1; // Set LSB to 1
            } else {
                pixels[pixelIndex].Red &= 0xFE; // Set LSB to 0
            }
        }
    }

    // Save the new image with the embedded message
    FILE *outputFile = fopen(outputImage, "wb");
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fwrite(pixels, sizeof(PIXEL), pixelCount, outputFile);
    
    free(pixels);
    fclose(outputFile);
    printf("In the wasteland, the message has been embedded! Look closely.\n");
}

void extractMessage(const char* inputImage) {
    FILE *imageFile = fopen(inputImage, "rb");
    if (!imageFile) {
        perror("Failed to open image file for extraction");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, imageFile);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, imageFile);

    if (fileHeader.bfType != 0x4D42 || infoHeader.biBitCount != 24) {
        fclose(imageFile);
        printf("This isn't a 24-bit BMP image.\n");
        return;
    }

    size_t pixelCount = infoHeader.biWidth * infoHeader.biHeight;
    size_t totalPixels = (pixelCount * 3);
    PIXEL *pixels = malloc(totalPixels * sizeof(PIXEL));
    fseek(imageFile, fileHeader.bfOffBits, SEEK_SET);
    fread(pixels, sizeof(PIXEL), pixelCount, imageFile);
    fclose(imageFile);

    char message[256];
    size_t messageIndex = 0;
    for (size_t i = 0; i < 256; i++) {
        message[i] = 0;
    }

    // Extract the message
    for (size_t i = 0; messageIndex < 256 && i < totalPixels; i++) {
        if (i % 3 == 0) {
            for (int bit = 0; bit < 8; bit++) {
                if ((pixels[i].Red & 1) == 1) {
                    message[messageIndex] |= (1 << (7 - bit)); // Set the extracted bit
                }
                if (++messageIndex >= 256) {
                    break;
                }
            }
        }
    }

    printf("The message from the ruins:\n");
    printf("%s\n", message);

    free(pixels);
}