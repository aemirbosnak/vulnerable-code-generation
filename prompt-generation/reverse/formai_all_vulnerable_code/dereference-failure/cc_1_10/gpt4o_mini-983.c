//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

uint8_t* load_image(const char* filename, BITMAPINFOHEADER* bmpInfoHeader) {
    BITMAPFILEHEADER bmpFileHeader;
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }
    
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    
    if (bmpFileHeader.bfType != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file.\n");
        exit(1);
    }
    
    uint8_t* pixelData = (uint8_t*)malloc(bmpInfoHeader->biSizeImage);
    fseek(file, bmpFileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, bmpInfoHeader->biSizeImage, 1, file);
    fclose(file);
    
    return pixelData;
}

void save_image(const char* filename, uint8_t* pixelData, BITMAPINFOHEADER* bmpInfoHeader) {
    BITMAPFILEHEADER bmpFileHeader;
    bmpFileHeader.bfType = 0x4D42;
    bmpFileHeader.bfReserved1 = bmpFileHeader.bfReserved2 = 0;
    bmpFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bmpFileHeader.bfSize = bmpFileHeader.bfOffBits + bmpInfoHeader->biSizeImage;

    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error saving file.\n");
        exit(1);
    }

    fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(pixelData, bmpInfoHeader->biSizeImage, 1, file);
    fclose(file);
}

void invert_colors(uint8_t* pixelData, int width, int height) {
    for (int i = 0; i < width * height * 3; i++) {
        pixelData[i] = 255 - pixelData[i];
    }
}

void grayscale(uint8_t* pixelData, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        int offset = i * 3;
        uint8_t gray = (uint8_t)(0.3 * pixelData[offset + 2] + 0.59 * pixelData[offset + 1] + 0.11 * pixelData[offset]);
        pixelData[offset] = gray;
        pixelData[offset + 1] = gray;
        pixelData[offset + 2] = gray;
    }
}

void mirror_image(uint8_t* pixelData, int width, int height) {
    int rowSize = width * 3;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            int leftIndex = (y * rowSize) + (x * 3);
            int rightIndex = (y * rowSize) + ((width - 1 - x) * 3);
            for (int color = 0; color < 3; color++) {
                uint8_t temp = pixelData[leftIndex + color];
                pixelData[leftIndex + color] = pixelData[rightIndex + color];
                pixelData[rightIndex + color] = temp;
            }
        }
    }
}

void apply_filter(uint8_t* pixelData, int width, int height, void (*filter)(uint8_t*, int, int)) {
    filter(pixelData, width, height);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> [filter]\n", argv[0]);
        fprintf(stderr, "Filters: invert, grayscale, mirror\n");
        return 1;
    }

    BITMAPINFOHEADER bmpInfoHeader;
    uint8_t* pixelData = load_image(argv[1], &bmpInfoHeader);
    
    if (argc == 4) {
        if (strcmp(argv[3], "invert") == 0) {
            apply_filter(pixelData, bmpInfoHeader.biWidth, bmpInfoHeader.biHeight, invert_colors);
        } else if (strcmp(argv[3], "grayscale") == 0) {
            apply_filter(pixelData, bmpInfoHeader.biWidth, bmpInfoHeader.biHeight, grayscale);
        } else if (strcmp(argv[3], "mirror") == 0) {
            apply_filter(pixelData, bmpInfoHeader.biWidth, bmpInfoHeader.biHeight, mirror_image);
        } else {
            fprintf(stderr, "Unknown filter: %s\n", argv[3]);
            free(pixelData);
            return 1;
        }
    } else {
        fprintf(stderr, "No filter specified, saving original image.\n");
    }

    save_image(argv[2], pixelData, &bmpInfoHeader);
    free(pixelData);

    printf("Image processing complete.\n");
    return 0;
}