//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;
#pragma pack(pop)

void flipImage(RGB** image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            RGB temp = image[y][x];
            image[y][x] = image[y][width - 1 - x];
            image[y][width - 1 - x] = temp;
        }
    }
}

void changeBrightness(RGB** image, int width, int height, int brightness) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y][x].red = (image[y][x].red + brightness > 255) ? 255 : (image[y][x].red + brightness < 0 ? 0 : image[y][x].red + brightness);
            image[y][x].green = (image[y][x].green + brightness > 255) ? 255 : (image[y][x].green + brightness < 0 ? 0 : image[y][x].green + brightness);
            image[y][x].blue = (image[y][x].blue + brightness > 255) ? 255 : (image[y][x].blue + brightness < 0 ? 0 : image[y][x].blue + brightness);
        }
    }
}

void changeContrast(RGB** image, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y][x].red = (factor * (image[y][x].red - 128) + 128);
            image[y][x].green = (factor * (image[y][x].green - 128) + 128);
            image[y][x].blue = (factor * (image[y][x].blue - 128) + 128);
            image[y][x].red = (image[y][x].red > 255) ? 255 : (image[y][x].red < 0 ? 0 : image[y][x].red);
            image[y][x].green = (image[y][x].green > 255) ? 255 : (image[y][x].green < 0 ? 0 : image[y][x].green);
            image[y][x].blue = (image[y][x].blue > 255) ? 255 : (image[y][x].blue < 0 ? 0 : image[y][x].blue);
        }
    }
}

void readBMP(const char* filename, BITMAPFILEHEADER* bfh, BITMAPINFOHEADER* bih, RGB*** pixels) {
    FILE* file = fopen(filename, "rb");
    fread(bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(bih, sizeof(BITMAPINFOHEADER), 1, file);
    
    int width = bih->biWidth;
    int height = abs(bih->biHeight);
    *pixels = malloc(height * sizeof(RGB*));
    for (int i = 0; i < height; i++) {
        (*pixels)[i] = malloc(width * sizeof(RGB));
        fread((*pixels)[i], sizeof(RGB), width, file);
        fseek(file, (4 - (width * sizeof(RGB)) % 4) % 4, SEEK_CUR); // align to the nearest 4 byte boundary
    }
    fclose(file);
}

void writeBMP(const char* filename, BITMAPFILEHEADER* bfh, BITMAPINFOHEADER* bih, RGB** pixels) {
    FILE* file = fopen(filename, "wb");
    fwrite(bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(bih, sizeof(BITMAPINFOHEADER), 1, file);
    
    int width = bih->biWidth;
    int height = abs(bih->biHeight);
    for (int i = 0; i < height; i++) {
        fwrite(pixels[i], sizeof(RGB), width, file);
        for (int j = 0; j < (4 - (width * sizeof(RGB)) % 4) % 4; j++) {
            fputc(0, file); // padding
        }
    }
    fclose(file);
}

void freeImage(RGB** image, int height) {
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}

int main() {
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    RGB** pixels;

    // Read the BMP file
    readBMP("input.bmp", &bfh, &bih, &pixels);

    // Flip the image
    flipImage(pixels, bih.biWidth, abs(bih.biHeight));

    // Change brightness
    changeBrightness(pixels, bih.biWidth, abs(bih.biHeight), 50);

    // Change contrast
    changeContrast(pixels, bih.biWidth, abs(bih.biHeight), 50.0f);

    // Write the modified image to a new BMP file
    writeBMP("output.bmp", &bfh, &bih, pixels);

    // Free the allocated memory
    freeImage(pixels, abs(bih.biHeight));

    return 0;
}