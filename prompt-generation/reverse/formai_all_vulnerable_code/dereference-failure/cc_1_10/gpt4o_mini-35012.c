//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1) // Ensure packed structure
typedef struct {
    uint16_t bfType;      // File type
    uint32_t bfSize;      // File size in bytes
    uint16_t bfReserved1; // Reserved
    uint16_t bfReserved2; // Reserved
    uint32_t bfOffBits;   // Offset to image data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of image
    int32_t  biHeight;        // Height of image
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;      // Image size
    int32_t  biXPelsPerMeter;   // Pixels per meter in X
    int32_t  biYPelsPerMeter;   // Pixels per meter in Y
    uint32_t biClrUsed;        // Number of colors
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

void adjust_brightness_and_contrast(RGB *pixel, float brightness_factor, float contrast_factor) {
    pixel->red = (uint8_t) fmin(fmax(pixel->red * contrast_factor + brightness_factor, 0), 255);
    pixel->green = (uint8_t) fmin(fmax(pixel->green * contrast_factor + brightness_factor, 0), 255);
    pixel->blue = (uint8_t) fmin(fmax(pixel->blue * contrast_factor + brightness_factor, 0), 255);
}

void process_image(const char *input_filename, const char *output_filename, float brightness, float contrast) {
    FILE *f = fopen(input_filename, "rb");
    if (!f) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, f);
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, f);
    
    if (bf.bfType != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(f);
        exit(EXIT_FAILURE);
    }

    RGB *image_data = (RGB*)malloc(bi.biWidth * bi.biHeight * sizeof(RGB));
    fseek(f, bf.bfOffBits, SEEK_SET);
    fread(image_data, sizeof(RGB), bi.biWidth * bi.biHeight, f);
    fclose(f);
    
    for (int y = 0; y < bi.biHeight; y++) {
        for (int x = 0; x < bi.biWidth; x++) {
            RGB *pixel = &image_data[y * bi.biWidth + x];
            adjust_brightness_and_contrast(pixel, brightness, contrast);
        }
    }

    f = fopen(output_filename, "wb");
    if (!f) {
        perror("Could not open output file");
        free(image_data);
        exit(EXIT_FAILURE);
    }

    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, f);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, f);
    fwrite(image_data, sizeof(RGB), bi.biWidth * bi.biHeight, f);
    
    fclose(f);
    free(image_data);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input_bmp> <output_bmp> <brightness> <contrast>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float brightness = atof(argv[3]);
    float contrast = atof(argv[4]);
    
    process_image(input_file, output_file, brightness, contrast);
    
    printf("Image processing completed successfully.\n");
    return 0;
}