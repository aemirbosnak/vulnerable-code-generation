//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1) // Ensure no padding between struct members
typedef struct {
    uint16_t type;      // File type, should be 'BM'
    uint32_t size;      // Size of the file in bytes
    uint16_t reserved1; // Reserved; must be zero
    uint16_t reserved2; // Reserved; must be zero
    uint32_t offset;    // Offset to start of pixel data
} BitmapFileHeader;

typedef struct {
    uint32_t size;         // Size of this header in bytes
    int32_t width;         // Width of the bitmap in pixels
    int32_t height;        // Height of the bitmap in pixels
    uint16_t planes;       // Number of color planes, must be 1
    uint16_t bitsPerPixel; // Bits per pixel
    uint32_t compression;  // Compression type
    uint32_t imageSize;    // Image size in bytes
    int32_t xPixelsPerMeter; // Horizontal resolution
    int32_t yPixelsPerMeter; // Vertical resolution
    uint32_t colorsUsed;    // Number of colors in the palette
    uint32_t importantColors; // Important colors
} BitmapInfoHeader;
#pragma pack(pop)

void readBitmap(const char *filename, uint8_t **image, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    BitmapFileHeader fileHeader;
    fread(&fileHeader, sizeof(BitmapFileHeader), 1, file);

    BitmapInfoHeader infoHeader;
    fread(&infoHeader, sizeof(BitmapInfoHeader), 1, file);

    *width = infoHeader.width;
    *height = infoHeader.height;
    
    *image = malloc(3 * (*width) * (*height));
    fseek(file, fileHeader.offset, SEEK_SET);
    fread(*image, 3, (*width) * (*height), file);
    fclose(file);
}

void writeBitmap(const char *filename, uint8_t *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    BitmapFileHeader fileHeader = {0};
    fileHeader.type = 0x4D42;
    fileHeader.size = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + (3 * width * height);
    fileHeader.offset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    BitmapInfoHeader infoHeader = {0};
    infoHeader.size = sizeof(BitmapInfoHeader);
    infoHeader.width = width;
    infoHeader.height = height;
    infoHeader.planes = 1;
    infoHeader.bitsPerPixel = 24;
    infoHeader.compression = 0; // No compression
    infoHeader.imageSize = 3 * width * height;

    fwrite(&fileHeader, sizeof(BitmapFileHeader), 1, file);
    fwrite(&infoHeader, sizeof(BitmapInfoHeader), 1, file);
    fwrite(image, 3, width * height, file);
    fclose(file);
}

void flipImage(uint8_t *image, int width, int height) {
    uint8_t *flippedImage = malloc(3 * width * height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            flippedImage[(height - 1 - y) * width * 3 + x * 3 + 0] = image[y * width * 3 + x * 3 + 0]; // R
            flippedImage[(height - 1 - y) * width * 3 + x * 3 + 1] = image[y * width * 3 + x * 3 + 1]; // G
            flippedImage[(height - 1 - y) * width * 3 + x * 3 + 2] = image[y * width * 3 + x * 3 + 2]; // B
        }
    }
    memcpy(image, flippedImage, 3 * width * height);
    free(flippedImage);
}

void changeBrightness(uint8_t *image, int width, int height, int offset) {
    for (int i = 0; i < width * height * 3; ++i) {
        int newVal = image[i] + offset;
        image[i] = (newVal < 0) ? 0 : (newVal > 255) ? 255 : newVal;
    }
}

void changeContrast(uint8_t *image, int width, int height, double factor) {
    for (int i = 0; i < width * height * 3; ++i) {
        int newVal = (int)((image[i] - 128) * factor + 128);
        image[i] = (newVal < 0) ? 0 : (newVal > 255) ? 255 : newVal;
    }
}

int main() {
    int width, height;
    uint8_t *image;

    readBitmap("input.bmp", &image, &width, &height);

    printf("Cheery Image Processing Start! 🎉\n");
    
    printf("Flipping the image...\n");
    flipImage(image, width, height);
    printf("Image flipped! 👍\n");

    printf("Changing brightness (increase by 30)...\n");
    changeBrightness(image, width, height, 30);
    printf("Brightness changed! 🌟\n");

    printf("Changing contrast (factor = 1.2)...\n");
    changeContrast(image, width, height, 1.2);
    printf("Contrast changed! 🌈\n");

    writeBitmap("output.bmp", image, width, height);
    printf("All done! Your processed image is ready: output.bmp 🌟\n");

    free(image);
    return 0;
}