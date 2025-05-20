//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPelsPerMeter;
    int32_t yPelsPerMeter;
    uint32_t clrUsed;
    uint32_t clrImportant;
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;
#pragma pack(pop)

void flipImageVertically(Pixel **pixels, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            Pixel temp = pixels[i][j];
            pixels[i][j] = pixels[height - i - 1][j];
            pixels[height - i - 1][j] = temp;
        }
    }
}

void changeBrightness(Pixel **pixels, int width, int height, int brightnessOffset) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i][j].red = (pixels[i][j].red + brightnessOffset > 255) ? 255 : 
                               (pixels[i][j].red + brightnessOffset < 0) ? 0 : 
                               pixels[i][j].red + brightnessOffset;
            pixels[i][j].green = (pixels[i][j].green + brightnessOffset > 255) ? 255 : 
                                 (pixels[i][j].green + brightnessOffset < 0) ? 0 : 
                                 pixels[i][j].green + brightnessOffset;
            pixels[i][j].blue = (pixels[i][j].blue + brightnessOffset > 255) ? 255 : 
                                (pixels[i][j].blue + brightnessOffset < 0) ? 0 : 
                                pixels[i][j].blue + brightnessOffset;
        }
    }
}

void adjustContrast(Pixel **pixels, int width, int height, float contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i][j].red = (uint8_t) fminf(fmaxf((pixels[i][j].red - 128) * contrast + 128, 0), 255);
            pixels[i][j].green = (uint8_t) fminf(fmaxf((pixels[i][j].green - 128) * contrast + 128, 0), 255);
            pixels[i][j].blue = (uint8_t) fminf(fmaxf((pixels[i][j].blue - 128) * contrast + 128, 0), 255);
        }
    }
}

Pixel **readBMP(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }
    fread(header, sizeof(BMPHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);

    Pixel **pixels = malloc(infoHeader->height * sizeof(Pixel *));
    for (int i = 0; i < infoHeader->height; i++) {
        pixels[i] = malloc(infoHeader->width * sizeof(Pixel));
        fread(pixels[i], sizeof(Pixel), infoHeader->width, file);
    }

    fclose(file);
    return pixels;
}

void writeBMP(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader, Pixel **pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }
    fwrite(header, sizeof(BMPHeader), 1, file);
    fwrite(infoHeader, sizeof(BMPInfoHeader), 1, file);

    for (int i = 0; i < infoHeader->height; i++) {
        fwrite(pixels[i], sizeof(Pixel), infoHeader->width, file);
        free(pixels[i]);
    }

    free(pixels);
    fclose(file);
}

int main() {
    const char *filename = "input.bmp";
    const char *outputFile = "output.bmp";
    
    BMPHeader header;
    BMPInfoHeader infoHeader;
    
    Pixel **pixels = readBMP(filename, &header, &infoHeader);
    
    if (pixels == NULL) return -1; 

    printf("Image Size: %dx%d\n", infoHeader.width, infoHeader.height);
    
    // Example transformations
    printf("Flipping image vertically...\n");
    flipImageVertically(pixels, infoHeader.width, infoHeader.height);

    printf("Changing brightness (offset 20)...\n");
    changeBrightness(pixels, infoHeader.width, infoHeader.height, 20);

    printf("Adjusting contrast (1.5)...\n");
    adjustContrast(pixels, infoHeader.width, infoHeader.height, 1.5f);

    writeBMP(outputFile, &header, &infoHeader, pixels);
    
    printf("Image processing completed. Output written to %s\n", outputFile);
    
    return 0;
}