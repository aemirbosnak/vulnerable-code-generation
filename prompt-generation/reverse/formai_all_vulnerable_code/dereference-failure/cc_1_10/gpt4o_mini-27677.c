//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;        // Bitmap file type
    uint32_t bfSize;        // Size of the file
    uint16_t bfReserved1;   // Reserved
    uint16_t bfReserved2;   // Reserved
    uint32_t bfOffBits;     // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the image
    int32_t  biHeight;        // Height of the image
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Image size
    int32_t  biXPelsPerMeter;   // X pixels per meter
    int32_t  biYPelsPerMeter;   // Y pixels per meter
    uint32_t biClrUsed;        // Number of colors in the palette
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;            // Blue value
    uint8_t green;           // Green value
    uint8_t red;             // Red value
} PIXEL;
#pragma pack(pop)

void encodeMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *img = fopen(inputImage, "rb");
    FILE *outImg = fopen(outputImage, "wb");
    if (!img || !outImg) {
        printf("Error opening files.\n");
        exit(1);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, img);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, img);

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, outImg);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, outImg);

    int totalPixels = abs(bih.biWidth * bih.biHeight);
    PIXEL *pixels = malloc(totalPixels * sizeof(PIXEL));
    fread(pixels, sizeof(PIXEL), totalPixels, img);

    size_t msgLen = strlen(message);
    if (msgLen > totalPixels / 8) {
        printf("Message too long for image capacity.\n");
        free(pixels);
        fclose(img);
        fclose(outImg);
        exit(1);
    }

    for (size_t i = 0; i < msgLen; i++) {
        for (int j = 0; j < 8; j++) {
            int pixelIndex = i * 8 + j;
            if (pixelIndex < totalPixels) {
                pixels[pixelIndex].red = (pixels[pixelIndex].red & 0xFE) | ((message[i] >> (7 - j)) & 1);
            }
        }
    }

    fwrite(pixels, sizeof(PIXEL), totalPixels, outImg);
    free(pixels);
    fclose(img);
    fclose(outImg);
}

void decodeMessage(const char *inputImage) {
    FILE *img = fopen(inputImage, "rb");
    if (!img) {
        printf("Error opening image file.\n");
        exit(1);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, img);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, img);

    int totalPixels = abs(bih.biWidth * bih.biHeight);
    PIXEL *pixels = malloc(totalPixels * sizeof(PIXEL));
    fread(pixels, sizeof(PIXEL), totalPixels, img);

    char message[256] = {0}; 
    for (size_t i = 0; i < 256; i++) {
        char byte = 0;
        for (int j = 0; j < 8; j++) {
            int pixelIndex = i * 8 + j;
            if (pixelIndex >= totalPixels) break;
            byte |= ((pixels[pixelIndex].red & 1) << (7 - j));
        }
        if (byte == 0) break; // End of message
        message[i] = byte;
    }

    printf("Decoded Message: %s\n", message);

    free(pixels);
    fclose(img);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <encode/decode> <input_image> <output_image/message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encodeMessage(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessage(argv[2]);
    } else {
        printf("Invalid operation. Use 'encode' or 'decode'.\n");
    }

    return 0;
}