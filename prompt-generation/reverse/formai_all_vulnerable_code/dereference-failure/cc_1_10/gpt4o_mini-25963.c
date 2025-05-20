//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint32_t bfReserved;
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
} RGB;
#pragma pack(pop)

void convertToGrayscale(RGB *image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        uint8_t gray = (image[i].red * 0.299 + image[i].green * 0.587 + image[i].blue * 0.114);
        image[i].red = gray;
        image[i].green = gray;
        image[i].blue = gray;
    }
}

int loadBMP(const char *filename, RGB **image, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return -1;
    }
    
    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, file);
    
    if (bmpHeader.bfType != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(file);
        return -1;
    }

    BMPInfoHeader bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);

    *width = bmpInfoHeader.biWidth;
    *height = bmpInfoHeader.biHeight;

    fseek(file, bmpHeader.bfOffBits, SEEK_SET);
    
    int size = (*width) * (*height);
    *image = malloc(size * sizeof(RGB));

    for (int i = 0; i < size; i++) {
        fread(&(*image)[i], sizeof(RGB), 1, file);
    }

    fclose(file);
    return 0;
}

int saveBMP(const char *filename, RGB *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return -1;
    }

    BMPHeader bmpHeader;
    bmpHeader.bfType = 0x4D42;
    bmpHeader.bfReserved = 0;
    bmpHeader.bfOffBits = sizeof(BMPHeader) + sizeof(BMPInfoHeader);
    bmpHeader.bfSize = bmpHeader.bfOffBits + (width * height * sizeof(RGB));

    BMPInfoHeader bmpInfoHeader;
    bmpInfoHeader.biSize = sizeof(BMPInfoHeader);
    bmpInfoHeader.biWidth = width;
    bmpInfoHeader.biHeight = height;
    bmpInfoHeader.biPlanes = 1;
    bmpInfoHeader.biBitCount = 24;
    bmpInfoHeader.biCompression = 0;
    bmpInfoHeader.biSizeImage = 0;
    bmpInfoHeader.biXPelsPerMeter = 0;
    bmpInfoHeader.biYPelsPerMeter = 0;
    bmpInfoHeader.biClrUsed = 0;
    bmpInfoHeader.biClrImportant = 0;

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);
    fwrite(image, sizeof(RGB), width * height, file);

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    RGB *image;
    int width, height;

    if (loadBMP(argv[1], &image, &width, &height) != 0) {
        return EXIT_FAILURE;
    }

    convertToGrayscale(image, width, height);

    if (saveBMP(argv[2], image, width, height) != 0) {
        free(image);
        return EXIT_FAILURE;
    }

    free(image);
    printf("Conversion to grayscale completed successfully!\n");
    return EXIT_SUCCESS;
}