//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGBPixel;

void loadBitmap(const char* filename, BITMAPFILEHEADER* bfh, BITMAPINFOHEADER* bih, RGBPixel** pixels) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    fread(bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(bih, sizeof(BITMAPINFOHEADER), 1, file);
    
    if (bfh->bfType != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    
    *pixels = malloc(bih->biSizeImage);
    fseek(file, bfh->bfOffBits, SEEK_SET);
    fread(*pixels, bih->biSizeImage, 1, file);
    
    fclose(file);
}

void saveBitmap(const char* filename, BITMAPFILEHEADER* bfh, BITMAPINFOHEADER* bih, RGBPixel* pixels) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Error saving file");
        exit(EXIT_FAILURE);
    }
    
    fwrite(bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(bih, sizeof(BITMAPINFOHEADER), 1, file);
    
    fseek(file, bfh->bfOffBits, SEEK_SET);
    fwrite(pixels, bih->biSizeImage, 1, file);
    
    fclose(file);
}

void invertColors(RGBPixel* pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = 255 - pixels[i].red;
        pixels[i].green = 255 - pixels[i].green;
        pixels[i].blue = 255 - pixels[i].blue;
    }
}

void grayscale(RGBPixel* pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        uint8_t gray = (pixels[i].red + pixels[i].green + pixels[i].blue) / 3;
        pixels[i].red = gray;
        pixels[i].green = gray;
        pixels[i].blue = gray;
    }
}

void printUsage() {
    printf("Usage: image_editor <input.bmp> <output.bmp> <action>\n");
    printf("Actions:\n");
    printf("  invert       - Inverts the colors of the image\n");
    printf("  grayscale    - Converts the image to grayscale\n");
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    RGBPixel* pixels = NULL;

    loadBitmap(argv[1], &bfh, &bih, &pixels);

    if (strcmp(argv[3], "invert") == 0) {
        invertColors(pixels, bih.biWidth, bih.biHeight);
    } else if (strcmp(argv[3], "grayscale") == 0) {
        grayscale(pixels, bih.biWidth, bih.biHeight);
    } else {
        printf("Unknown action: %s\n", argv[3]);
        free(pixels);
        printUsage();
        return EXIT_FAILURE;
    }

    saveBitmap(argv[2], &bfh, &bih, pixels);

    free(pixels);
    printf("Image processing completed successfully.\n");
    return EXIT_SUCCESS;
}