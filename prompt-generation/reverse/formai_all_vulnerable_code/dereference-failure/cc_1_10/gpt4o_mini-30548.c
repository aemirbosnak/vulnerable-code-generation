//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: portable
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

void embed_watermark(const char *input_file, const char *output_file, const char *watermark) {
    FILE *infile = fopen(input_file, "rb");
    if (!infile) {
        fprintf(stderr, "Error opening input file.\n");
        exit(EXIT_FAILURE);
    }

    FILE *outfile = fopen(output_file, "wb");
    if (!outfile) {
        fclose(infile);
        fprintf(stderr, "Error opening output file.\n");
        exit(EXIT_FAILURE);
    }
    
    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, infile);
    
    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, infile);
    
    if (bfh.bfType != 0x4D42) {
        fprintf(stderr, "Not a BMP file.\n");
        fclose(infile);
        fclose(outfile);
        exit(EXIT_FAILURE);
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, outfile);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, outfile);
    
    int width = bih.biWidth;
    int height = bih.biHeight;
    int padding = (4 - (width * sizeof(RGB)) % 4) % 4;

    RGB *pixels = malloc(width * height * sizeof(RGB));
    if (!pixels) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(infile);
        fclose(outfile);
        exit(EXIT_FAILURE);
    }
    
    fread(pixels, sizeof(RGB), width * height, infile);
    fseek(infile, padding, SEEK_CUR);
    
    // Watermark embedding
    int watermark_length = strlen(watermark);
    for (int i = 0; i < width * height && i < watermark_length * 8; i++) {
        int b = (watermark[i / 8] >> (i % 8)) & 1; // Extract bit from watermark
        
        // Change least significant bit of the red channel
        if (b) {
            pixels[i].red |= 1; // Set LSB to 1
        } else {
            pixels[i].red &= ~1; // Set LSB to 0
        }
    }

    fwrite(pixels, sizeof(RGB), width * height, outfile);
    for (int i = 0; i < padding; i++) {
        fputc(0, outfile); // Write padding
    }

    free(pixels);
    fclose(infile);
    fclose(outfile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_bmp> <output_bmp> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }

    embed_watermark(argv[1], argv[2], argv[3]);
    printf("Watermark embedded successfully!\n");
    return EXIT_SUCCESS;
}