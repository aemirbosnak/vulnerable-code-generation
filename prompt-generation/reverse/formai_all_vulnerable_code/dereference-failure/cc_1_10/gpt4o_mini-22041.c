//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
#pragma pack(pop)

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    FILE *f = fopen(inputFile, "rb");
    if (!f) {
        printf("Error: Could not open file %s\n", inputFile);
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, f);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, f);

    unsigned char *data = (unsigned char *)malloc(bih.biSizeImage);
    fseek(f, bfh.bfOffBits, SEEK_SET);
    fread(data, bih.biSizeImage, 1, f);
    fclose(f);

    int wmLength = strlen(watermark);
    for (int i = 0; i < wmLength && i < bih.biSizeImage; i++) {
        // Embed each character's ASCII value into the least significant bit of the pixel data
        data[i] = (data[i] & 0xFE) | ((watermark[i] >> 7) & 0x01); // bit 7
        data[i + 1] = (data[i + 1] & 0xFE) | ((watermark[i] >> 6) & 0x01); // bit 6
        data[i + 2] = (data[i + 2] & 0xFE) | ((watermark[i] >> 5) & 0x01); // bit 5
        data[i + 3] = (data[i + 3] & 0xFE) | ((watermark[i] >> 4) & 0x01); // bit 4
        data[i + 4] = (data[i + 4] & 0xFE) | ((watermark[i] >> 3) & 0x01); // bit 3
        data[i + 5] = (data[i + 5] & 0xFE) | ((watermark[i] >> 2) & 0x01); // bit 2
        data[i + 6] = (data[i + 6] & 0xFE) | ((watermark[i] >> 1) & 0x01); // bit 1
        data[i + 7] = (data[i + 7] & 0xFE) | (watermark[i] & 0x01); // bit 0
    }

    f = fopen(outputFile, "wb");
    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, f);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, f);
    fwrite(data, bih.biSizeImage, 1, f);
    fclose(f);
    free(data);
    printf("Watermark embedded successfully!\n");
}

void extractWatermark(const char *inputFile, char *watermark, int wmLength) {
    FILE *f = fopen(inputFile, "rb");
    if (!f) {
        printf("Error: Could not open file %s\n", inputFile);
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, f);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, f);

    unsigned char *data = (unsigned char *)malloc(bih.biSizeImage);
    fseek(f, bfh.bfOffBits, SEEK_SET);
    fread(data, bih.biSizeImage, 1, f);
    fclose(f);

    for (int i = 0; i < wmLength; i++) {
        watermark[i] = 0;
        for (int j = 0; j < 8; j++) {
            watermark[i] <<= 1; 
            watermark[i] |= (data[i * 8 + j] & 0x01); // extracting bit
        }
    }
    watermark[wmLength] = '\0';  // terminate string
    free(data);
    printf("Extracted watermark: %s\n", watermark);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed|extract> <input.bmp> <output.bmp|watermark string>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedWatermark(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        char watermark[256];
        extractWatermark(argv[2], watermark, 32); // assuming watermark is max 32 characters
    } else {
        printf("Invalid command! Use 'embed' or 'extract'.\n");
    }

    return 0;
}