//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
typedef struct {
    unsigned short bfType;      // 2 bytes
    unsigned int bfSize;       // 4 bytes
    unsigned short bfReserved1; // 2 bytes
    unsigned short bfReserved2; // 2 bytes
    unsigned int bfOffBits;     // 4 bytes
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;        // 4 bytes
    int biWidth;                // 4 bytes
    int biHeight;               // 4 bytes
    unsigned short biPlanes;    // 2 bytes
    unsigned short biBitCount;   // 2 bytes
    unsigned int biCompression;  // 4 bytes
    unsigned int biSizeImage;    // 4 bytes
    int biXPelsPerMeter;         // 4 bytes
    int biYPelsPerMeter;         // 4 bytes
    unsigned int biClrUsed;      // 4 bytes
    unsigned int biClrImportant;  // 4 bytes
} BITMAPINFOHEADER;

void convertToGrayscale(unsigned char* pixelData, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char gray = (pixelData[i*3] + pixelData[i*3 + 1] + pixelData[i*3 + 2]) / 3;
        pixelData[i*3] = gray;       // Red
        pixelData[i*3 + 1] = gray;   // Green
        pixelData[i*3 + 2] = gray;   // Blue
    }
}

void saveBitmap(const char* filename, BITMAPFILEHEADER fileHeader, BITMAPINFOHEADER infoHeader, unsigned char* pixelData) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to save the file");
        exit(1);
    }

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(pixelData, sizeof(unsigned char), infoHeader.biSizeImage, file);

    fclose(file);
}

unsigned char* loadBitmap(const char* filename, BITMAPFILEHEADER* fileHeader, BITMAPINFOHEADER* infoHeader) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open the file");
        exit(1);
    }

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    if (fileHeader->bfType != 0x4D42) { // 'BM'
        fclose(file);
        fprintf(stderr, "Not a valid BMP file\n");
        exit(1);
    }

    unsigned char* pixelData = malloc(infoHeader->biSizeImage);
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fread(pixelData, sizeof(unsigned char), infoHeader->biSizeImage, file);

    fclose(file);
    return pixelData;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input-bmp> <output-bmp> <mode>\n", argv[0]);
        fprintf(stderr, "       mode: 0 for original, 1 for grayscale\n");
        return 1;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    unsigned char* pixelData = loadBitmap(argv[1], &fileHeader, &infoHeader);

    if (atoi(argv[3]) == 1) {
        convertToGrayscale(pixelData, infoHeader.biWidth, infoHeader.biHeight);
    }

    saveBitmap(argv[2], fileHeader, infoHeader, pixelData);
    free(pixelData);
    
    printf("Image processing complete. Saved as %s\n", argv[2]);
    return 0;
}