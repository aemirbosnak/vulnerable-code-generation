//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define BMP header structure
#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BMPHeader;

typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BMPInfoHeader;
#pragma pack(pop)

typedef struct {
    uint8_t b, g, r; // Blue, Green, Red
} Pixel;

// Function declarations
void flipImageVertically(Pixel **image, int width, int height);
void adjustBrightness(Pixel **image, int width, int height, int value);
void adjustContrast(Pixel **image, int width, int height, float factor);
Pixel** readBMP(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader);
void writeBMP(const char *filename, Pixel **image, BMPHeader header, BMPInfoHeader infoHeader);
void freeImage(Pixel **image, int height);

int main() {
    const char *inputFile = "input.bmp";
    const char *outputFileFlipped = "flipped.bmp";
    const char *outputFileBright = "bright.bmp";
    const char *outputFileContrast = "contrast.bmp";

    BMPHeader header;
    BMPInfoHeader infoHeader;
    
    // Read the BMP image from file
    Pixel **image = readBMP(inputFile, &header, &infoHeader);
    if (image == NULL) {
        fprintf(stderr, "Error reading the BMP file.\n");
        return 1;
    }

    // Flip the image vertically
    flipImageVertically(image, infoHeader.biWidth, infoHeader.biHeight);
    writeBMP(outputFileFlipped, image, header, infoHeader);

    // Adjust brightness
    adjustBrightness(image, infoHeader.biWidth, infoHeader.biHeight, 50);
    writeBMP(outputFileBright, image, header, infoHeader);

    // Adjust contrast
    adjustContrast(image, infoHeader.biWidth, infoHeader.biHeight, 1.5);
    writeBMP(outputFileContrast, image, header, infoHeader);

    // Free the image memory
    freeImage(image, infoHeader.biHeight);

    printf("Image processing tasks completed!\n");
    return 0;
}

// Function to read BMP image
Pixel** readBMP(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    fread(header, sizeof(BMPHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);

    int width = infoHeader->biWidth;
    int height = infoHeader->biHeight;

    Pixel **image = (Pixel **)malloc(height * sizeof(Pixel *));
    for (int i = 0; i < height; i++) {
        image[i] = (Pixel *)malloc(width * sizeof(Pixel));
        fseek(file, header->bfOffBits + (i * width * sizeof(Pixel)), SEEK_SET);
        fread(image[i], sizeof(Pixel), width, file);
    }

    fclose(file);
    return image;
}

// Function to write BMP image
void writeBMP(const char *filename, Pixel **image, BMPHeader header, BMPInfoHeader infoHeader) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not write file");
        return;
    }

    fwrite(&header, sizeof(BMPHeader), 1, file);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;

    for (int i = 0; i < height; i++) {
        fwrite(image[i], sizeof(Pixel), width, file);
    }

    fclose(file);
}

// Function to flip the image vertically
void flipImageVertically(Pixel **image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            Pixel temp = image[i][j];
            image[i][j] = image[height - i - 1][j];
            image[height - i - 1][j] = temp;
        }
    }
}

// Function to adjust brightness
void adjustBrightness(Pixel **image, int width, int height, int value) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].r = (image[i][j].r + value > 255) ? 255 : (image[i][j].r + value < 0 ? 0 : image[i][j].r + value);
            image[i][j].g = (image[i][j].g + value > 255) ? 255 : (image[i][j].g + value < 0 ? 0 : image[i][j].g + value);
            image[i][j].b = (image[i][j].b + value > 255) ? 255 : (image[i][j].b + value < 0 ? 0 : image[i][j].b + value);
        }
    }
}

// Function to adjust contrast
void adjustContrast(Pixel **image, int width, int height, float factor) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].r = (image[i][j].r - 128) * factor + 128;
            image[i][j].g = (image[i][j].g - 128) * factor + 128;
            image[i][j].b = (image[i][j].b - 128) * factor + 128;

            image[i][j].r = (image[i][j].r < 0) ? 0 : (image[i][j].r > 255) ? 255 : image[i][j].r;
            image[i][j].g = (image[i][j].g < 0) ? 0 : (image[i][j].g > 255) ? 255 : image[i][j].g;
            image[i][j].b = (image[i][j].b < 0) ? 0 : (image[i][j].b > 255) ? 255 : image[i][j].b;
        }
    }
}

// Function to free image memory
void freeImage(Pixel **image, int height) {
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}