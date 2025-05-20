//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: scalable
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

void embed_watermark(const char *input_bmp, const char *output_bmp, const char *watermark) {
    FILE *in_file = fopen(input_bmp, "rb");
    FILE *out_file = fopen(output_bmp, "wb");
    if (in_file == NULL || out_file == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, in_file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, in_file);
    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, out_file);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, out_file);
    
    size_t pixel_array_size = bfh.bfSize - bfh.bfOffBits;
    RGB *pixels = malloc(pixel_array_size);
    fseek(in_file, bfh.bfOffBits, SEEK_SET);
    fread(pixels, pixel_array_size, 1, in_file);
    
    size_t watermark_len = strlen(watermark);
    for (size_t i = 0; i < watermark_len; ++i) {
        for (size_t j = 0; j < 8; ++j) { // embed 1 byte of watermark
            if (i * 8 + j < (pixel_array_size / sizeof(RGB))) {
                size_t pixel_index = i * 8 + j;
                if (watermark[i] & (1 << (7 - j))) {
                    pixels[pixel_index].blue |= 0x01; // set LSB to 1
                } else {
                    pixels[pixel_index].blue &= 0xFE; // set LSB to 0
                }
            }
        }
    }

    fseek(out_file, bfh.bfOffBits, SEEK_SET);
    fwrite(pixels, pixel_array_size, 1, out_file);

    free(pixels);
    fclose(in_file);
    fclose(out_file);
}

void extract_watermark(const char *input_bmp, char *watermark, size_t watermark_length) {
    FILE *in_file = fopen(input_bmp, "rb");
    if (in_file == NULL) {
        perror("Error opening file for extraction");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, in_file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, in_file);
    size_t pixel_array_size = bfh.bfSize - bfh.bfOffBits;
    RGB *pixels = malloc(pixel_array_size);
    fseek(in_file, bfh.bfOffBits, SEEK_SET);
    fread(pixels, pixel_array_size, 1, in_file);

    for (size_t i = 0; i < watermark_length; ++i) {
        watermark[i] = 0;
        for (size_t j = 0; j < 8; ++j) {
            size_t pixel_index = i * 8 + j;
            if (pixel_index < (pixel_array_size / sizeof(RGB))) {
                if (pixels[pixel_index].blue & 0x01) {
                    watermark[i] |= (1 << (7 - j)); // retrieve LSB
                }
            }
        }
    }
    watermark[watermark_length] = '\0'; // Null-terminate the string

    free(pixels);
    fclose(in_file);
}

int main() {
    const char *input_image = "input.bmp";
    const char *output_image = "watermarked_output.bmp";
    const char *watermark_string = "WATERMARK";

    embed_watermark(input_image, output_image, watermark_string);
    printf("Watermark embedded successfully. Result saved to %s\n", output_image);

    char extracted_watermark[100] = {0};
    extract_watermark(output_image, extracted_watermark, strlen(watermark_string));
    printf("Extracted Watermark: %s\n", extracted_watermark);

    return 0;
}