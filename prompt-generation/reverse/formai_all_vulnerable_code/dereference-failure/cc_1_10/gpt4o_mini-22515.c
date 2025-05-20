//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: sophisticated
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
#pragma pack(pop)

void put_watermark(uint8_t *image, int width, int height, const char *watermark) {
    int watermark_length = strlen(watermark);
    for (int i = 0; i < watermark_length; i++) {
        int x = (i % width);
        int y = (i / width) % height;

        // Adjust pixel intensity based on watermark character value
        uint8_t br = watermark[i] % 256;  // Get a value to manipulate the pixel
        int pixel_index = (y * width + x) * 3; // RGB

        image[pixel_index] = (image[pixel_index] + br) % 256;      // R
        image[pixel_index + 1] = (image[pixel_index + 1] + br) % 256;  // G
        image[pixel_index + 2] = (image[pixel_index + 2] + br) % 256;  // B
    }
}

void read_bmp(const char *filename, uint8_t **image, BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fread(file_header, sizeof(BITMAPFILEHEADER), 1, file);
    fread(info_header, sizeof(BITMAPINFOHEADER), 1, file);

    // Allocate memory for the image
    *image = (uint8_t *)malloc(info_header->biWidth * info_header->biHeight * 3);
    fseek(file, file_header->bfOffBits, SEEK_SET);
    fread(*image, info_header->biWidth * info_header->biHeight * 3, 1, file);
    fclose(file);
}

void write_bmp(const char *filename, uint8_t *image, BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fwrite(file_header, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(info_header, sizeof(BITMAPINFOHEADER), 1, file);
    fseek(file, file_header->bfOffBits, SEEK_SET);
    fwrite(image, info_header->biWidth * info_header->biHeight * 3, 1, file);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *watermark = argv[3];

    uint8_t *image;
    BITMAPFILEHEADER file_header;
    BITMAPINFOHEADER info_header;

    read_bmp(input_file, &image, &file_header, &info_header);
    put_watermark(image, info_header.biWidth, info_header.biHeight, watermark);
    write_bmp(output_file, image, &file_header, &info_header);

    free(image);
    printf("Watermark applied successfully!\n");
    return EXIT_SUCCESS;
}