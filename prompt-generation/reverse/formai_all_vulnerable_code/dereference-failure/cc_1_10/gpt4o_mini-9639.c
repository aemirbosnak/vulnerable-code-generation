//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1) // Ensure no padding
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

typedef struct{
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

typedef struct {
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    RGB **pixels; // 2D array of pixels
} BMPImage;

BMPImage* loadBMP(const char *filename);
void saveBMP(const char *filename, BMPImage *image);
void flipImageHorizontally(BMPImage *image);
void changeBrightness(BMPImage *image, int value);
void freeBMPImage(BMPImage *image);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input.bmp> <output_flipped.bmp> <output_brightened.bmp>\n", argv[0]);
        return 1;
    }

    BMPImage *image = loadBMP(argv[1]);
    if (!image) {
        fprintf(stderr, "Failed to load BMP image.\n");
        return 1;
    }

    // Flip the image
    flipImageHorizontally(image);
    saveBMP(argv[2], image);

    // Change brightness
    changeBrightness(image, 50); // Brighten the image by 50
    saveBMP(argv[3], image);

    freeBMPImage(image);
    return 0;
}

BMPImage* loadBMP(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    BMPImage *image = malloc(sizeof(BMPImage));
    fread(&image->bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&image->bih, sizeof(BITMAPINFOHEADER), 1, file);

    image->pixels = malloc(sizeof(RGB*) * image->bih.biHeight);
    for (int i = 0; i < image->bih.biHeight; i++) {
        image->pixels[i] = malloc(sizeof(RGB) * image->bih.biWidth);
        fread(image->pixels[i], sizeof(RGB), image->bih.biWidth, file);
    }

    fclose(file);
    return image;
}

void saveBMP(const char *filename, BMPImage *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return;
    }

    fwrite(&image->bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&image->bih, sizeof(BITMAPINFOHEADER), 1, file);

    for (int i = 0; i < image->bih.biHeight; i++) {
        fwrite(image->pixels[i], sizeof(RGB), image->bih.biWidth, file);
    }

    fclose(file);
}

void flipImageHorizontally(BMPImage *image) {
    for (int i = 0; i < image->bih.biHeight; i++) {
        for (int j = 0; j < image->bih.biWidth / 2; j++) {
            RGB temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[i][image->bih.biWidth - 1 - j];
            image->pixels[i][image->bih.biWidth - 1 - j] = temp;
        }
    }
}

void changeBrightness(BMPImage *image, int value) {
    for (int i = 0; i < image->bih.biHeight; i++) {
        for (int j = 0; j < image->bih.biWidth; j++) {
            image->pixels[i][j].red = 
                (image->pixels[i][j].red + value > 255) ? 255 : 
                (image->pixels[i][j].red + value < 0) ? 0 : 
                image->pixels[i][j].red + value;

            image->pixels[i][j].green = 
                (image->pixels[i][j].green + value > 255) ? 255 : 
                (image->pixels[i][j].green + value < 0) ? 0 : 
                image->pixels[i][j].green + value;

            image->pixels[i][j].blue = 
                (image->pixels[i][j].blue + value > 255) ? 255 : 
                (image->pixels[i][j].blue + value < 0) ? 0 : 
                image->pixels[i][j].blue + value;
        }
    }
}

void freeBMPImage(BMPImage *image) {
    for (int i = 0; i < image->bih.biHeight; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}