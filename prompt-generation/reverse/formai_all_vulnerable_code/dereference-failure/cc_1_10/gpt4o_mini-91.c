//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
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
} RGB;
#pragma pack(pop)

void invertImage(RGB *image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        image[i].red = 255 - image[i].red;
        image[i].green = 255 - image[i].green;
        image[i].blue = 255 - image[i].blue;
    }
}

void grayscaleImage(RGB *image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        uint8_t gray = (image[i].red + image[i].green + image[i].blue) / 3;
        image[i].red = image[i].green = image[i].blue = gray;
    }
}

void loadBitmap(const char *filename, BITMAPFILEHEADER *bfileheader, BITMAPINFOHEADER *binfoheader, RGB **image) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fread(bfileheader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(binfoheader, sizeof(BITMAPINFOHEADER), 1, file);

    if (bfileheader->bfType != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    *image = (RGB *)malloc(binfoheader->biWidth * binfoheader->biHeight * sizeof(RGB));
    fseek(file, bfileheader->bfOffBits, SEEK_SET);
    fread(*image, sizeof(RGB), binfoheader->biWidth * binfoheader->biHeight, file);

    fclose(file);
}

void saveBitmap(const char *filename, BITMAPFILEHEADER bfileheader, BITMAPINFOHEADER binfoheader, RGB *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fwrite(&bfileheader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&binfoheader, sizeof(BITMAPINFOHEADER), 1, file);
    fseek(file, bfileheader.bfOffBits, SEEK_SET);
    fwrite(image, sizeof(RGB), binfoheader.biWidth * binfoheader.biHeight, file);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.bmp> <output_inverted.bmp> <output_gray.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    BITMAPFILEHEADER bfileheader;
    BITMAPINFOHEADER binfoheader;
    RGB *image;

    loadBitmap(argv[1], &bfileheader, &binfoheader, &image);

    invertImage(image, binfoheader.biWidth, binfoheader.biHeight);
    saveBitmap(argv[2], bfileheader, binfoheader, image);

    grayscaleImage(image, binfoheader.biWidth, binfoheader.biHeight);
    saveBitmap(argv[3], bfileheader, binfoheader, image);

    free(image);
    printf("Image editing completed successfully.\n");
    return EXIT_SUCCESS;
}