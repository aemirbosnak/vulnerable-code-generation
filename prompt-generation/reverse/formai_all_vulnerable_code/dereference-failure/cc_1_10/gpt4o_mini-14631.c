//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Ensure structure is packed
typedef struct {
    uint16_t bfType;       // Magic number for file
    uint32_t bfSize;       // Size of the file in bytes
    uint16_t bfReserved1;  // Reserved; must be 0
    uint16_t bfReserved2;  // Reserved; must be 0
    uint32_t bfOffBits;     // Offset to the bitmap data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;             // Size of this header
    int32_t  biWidth;            // Width of the bitmap in pixels
    int32_t  biHeight;           // Height of the bitmap in pixels
    uint16_t biPlanes;           // Number of color planes
    uint16_t biBitCount;         // Number of bits per pixel
    uint32_t biCompression;      // Type of compression
    uint32_t biSizeImage;        // Image size in bytes
    int32_t  biXPelsPerMeter;     // Horizontal resolution
    int32_t  biYPelsPerMeter;     // Vertical resolution
    uint32_t biClrUsed;          // Number of colors in the color palette
    uint32_t biClrImportant;     // Number of important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

void flipImage(uint8_t *data, int width, int height) {
    int rowSize = (width * 3 + 3) & (~3); // Row size aligned to 4 bytes
    uint8_t *flippedRow = malloc(rowSize);
    
    for (int i = 0; i < height / 2; i++) {
        memcpy(flippedRow, data + i * rowSize, rowSize);
        memcpy(data + i * rowSize, data + (height - 1 - i) * rowSize, rowSize);
        memcpy(data + (height - 1 - i) * rowSize, flippedRow, rowSize);
    }
    
    free(flippedRow);
}

void changeBrightness(uint8_t *data, int width, int height, int value) {
    int rowSize = (width * 3 + 3) & (~3);
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            uint8_t *pixel = data + i * rowSize + j * 3;

            for (int k = 0; k < 3; k++) {
                int newVal = pixel[k] + value;
                pixel[k] = (newVal < 0) ? 0 : (newVal > 255) ? 255 : newVal;
            }
        }
    }
}

void writeBitmap(const char *filename, BITMAPFILEHEADER *bfHeader, BITMAPINFOHEADER *biHeader, uint8_t *data) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Unable to create file");
        exit(1);
    }
    fwrite(bfHeader, sizeof(BITMAPFILEHEADER), 1, fp);
    fwrite(biHeader, sizeof(BITMAPINFOHEADER), 1, fp);
    fwrite(data, biHeader->biSizeImage, 1, fp);
    fclose(fp);
}

uint8_t *readBitmap(const char *filename, BITMAPFILEHEADER *bfHeader, BITMAPINFOHEADER *biHeader) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Unable to open file");
        exit(1);
    }
    fread(bfHeader, sizeof(BITMAPFILEHEADER), 1, fp);
    fread(biHeader, sizeof(BITMAPINFOHEADER), 1, fp);

    if (bfHeader->bfType != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        exit(1);
    }
    
    uint8_t *data = malloc(biHeader->biSizeImage);
    fseek(fp, bfHeader->bfOffBits, SEEK_SET);
    fread(data, biHeader->biSizeImage, 1, fp);
    fclose(fp);
    return data;
}

void printUsage() {
    printf("Usage: imageproc <input.bmp> <output.bmp> <brightness_change> <flip(0/1)>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printUsage();
        return 1;
    }
    
    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    int brightnessChange = atoi(argv[3]);
    int flip = atoi(argv[4]);

    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;
    uint8_t *imageData = readBitmap(inputFile, &bfHeader, &biHeader);

    if (flip) {
        flipImage(imageData, biHeader.biWidth, biHeader.biHeight);
    }

    changeBrightness(imageData, biHeader.biWidth, biHeader.biHeight, brightnessChange);

    writeBitmap(outputFile, &bfHeader, &biHeader, imageData);
    free(imageData);

    printf("Image processing complete.\n");
    return 0;
}