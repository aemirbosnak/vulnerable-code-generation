//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1)

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

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;

// Function to read the BMP file
void readBMP(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader, Pixel **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file %s. Please check the path and try again!\n", filename);
        exit(1);
    }

    fread(header, sizeof(BMPHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);

    // Allocate pixel data
    int width = infoHeader->biWidth;
    int height = infoHeader->biHeight;
    *pixels = malloc(width * height * sizeof(Pixel));

    // Read pixel data
    fseek(file, header->bfOffBits, SEEK_SET);
    fread(*pixels, sizeof(Pixel), width * height, file);
    fclose(file);
}

// Function to write the BMP file
void writeBMP(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader, Pixel *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Could not write file %s. Please check the path and try again!\n", filename);
        exit(1);
    }

    fwrite(header, sizeof(BMPHeader), 1, file);
    fwrite(infoHeader, sizeof(BMPInfoHeader), 1, file);
    fwrite(pixels, sizeof(Pixel), infoHeader->biWidth * infoHeader->biHeight, file);
    fclose(file);
}

// Function to flip the image vertically
void flipImageVertically(int width, int height, Pixel *pixels) {
    printf("Flipping the image vertically! Yay!\n");
    for (int i = 0; i < height / 2; ++i) {
        for (int j = 0; j < width; ++j) {
            Pixel temp = pixels[i * width + j];
            pixels[i * width + j] = pixels[(height - i - 1) * width + j];
            pixels[(height - i - 1) * width + j] = temp;
        }
    }
}

// Function to adjust brightness
void changeBrightness(int width, int height, Pixel *pixels, int adjustment) {
    printf("Adjusting brightness! Let's brighten things up (or darken them) by %d!\n", adjustment);
    for (int i = 0; i < width * height; i++) {
        int newRed = pixels[i].red + adjustment;
        int newGreen = pixels[i].green + adjustment;
        int newBlue = pixels[i].blue + adjustment;

        pixels[i].red = newRed < 0 ? 0 : (newRed > 255 ? 255 : newRed);
        pixels[i].green = newGreen < 0 ? 0 : (newGreen > 255 ? 255 : newGreen);
        pixels[i].blue = newBlue < 0 ? 0 : (newBlue > 255 ? 255 : newBlue);
    }
}

// Function to change contrast
void changeContrast(int width, int height, Pixel *pixels, float factor) {
    printf("Changing contrast! Let's crank up the contrast by a factor of %.2f!\n", factor);
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = ((int)((pixels[i].red - 128) * factor + 128));
        pixels[i].green = ((int)((pixels[i].green - 128) * factor + 128));
        pixels[i].blue = ((int)((pixels[i].blue - 128) * factor + 128));

        pixels[i].red = pixels[i].red < 0 ? 0 : (pixels[i].red > 255 ? 255 : pixels[i].red);
        pixels[i].green = pixels[i].green < 0 ? 0 : (pixels[i].green > 255 ? 255 : pixels[i].green);
        pixels[i].blue = pixels[i].blue < 0 ? 0 : (pixels[i].blue > 255 ? 255 : pixels[i].blue);
    }
}

int main() {
    BMPHeader header;
    BMPInfoHeader infoHeader;
    Pixel *pixels;

    const char *inputFilename = "input.bmp";
    const char *outputFilename = "output.bmp";

    readBMP(inputFilename, &header, &infoHeader, &pixels);
    printf("Yay! Successfully read the image: %s\n", inputFilename);

    flipImageVertically(infoHeader.biWidth, infoHeader.biHeight, pixels);
    
    changeBrightness(infoHeader.biWidth, infoHeader.biHeight, pixels, 40);
    changeContrast(infoHeader.biWidth, infoHeader.biHeight, pixels, 1.2);

    writeBMP(outputFilename, &header, &infoHeader, pixels);
    printf("Hooray! The image transformations are complete! Saved as: %s\n", outputFilename);

    free(pixels);
    return 0;
}