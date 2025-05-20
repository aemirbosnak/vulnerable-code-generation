//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char bfType[2];
    uint32_t bfSize;
    uint32_t bfReserved;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

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
} BITMAPINFOHEADER;
#pragma pack(pop)

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

void applyGrayscale(Pixel *pixel) {
    unsigned char gray = (pixel->red + pixel->green + pixel->blue) / 3;
    pixel->red = gray;
    pixel->green = gray;
    pixel->blue = gray;
}

void applyInvert(Pixel *pixel) {
    pixel->red = 255 - pixel->red;
    pixel->green = 255 - pixel->green;
    pixel->blue = 255 - pixel->blue;
}

void processImage(const char *inputFile, const char *outputFile, void (*operation)(Pixel *)) {
    FILE *file = fopen(inputFile, "rb");
    if (!file) {
        perror("Error opening input file");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    if (infoHeader.biBitCount != 24) {
        printf("Only 24-bit BMP files are supported.\n");
        fclose(file);
        return;
    }

    int row_padded = (infoHeader.biWidth * 3 + 3) & (~3);
    Pixel *pixels = malloc(row_padded * infoHeader.biHeight);
    if (!pixels) {
        perror("Error allocating memory for image pixels");
        fclose(file);
        return;
    }

    fread(pixels, sizeof(unsigned char), row_padded * infoHeader.biHeight, file);
    fclose(file);

    for (int i = 0; i < infoHeader.biHeight; i++) {
        for (int j = 0; j < infoHeader.biWidth; j++) {
            Pixel *pixel = (Pixel *)&pixels[i * row_padded + j * 3];
            operation(pixel);
        }
    }

    file = fopen(outputFile, "wb");
    if (!file) {
        perror("Error opening output file");
        free(pixels);
        return;
    }

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(pixels, sizeof(unsigned char), row_padded * infoHeader.biHeight, file);
    
    fclose(file);
    free(pixels);
    printf("Processing complete. Saved to %s\n", outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input.bmp> <output.bmp> <operation (grayscale|invert)>\n", argv[0]);
        return 1;
    }

    void (*operation)(Pixel *);
    if (strcmp(argv[3], "grayscale") == 0) {
        operation = applyGrayscale;
    } else if (strcmp(argv[3], "invert") == 0) {
        operation = applyInvert;
    } else {
        printf("Invalid operation. Use 'grayscale' or 'invert'.\n");
        return 1;
    }

    processImage(argv[1], argv[2], operation);
    return 0;
}