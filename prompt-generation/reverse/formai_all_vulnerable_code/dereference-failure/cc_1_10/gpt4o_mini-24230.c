//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char  header[2];
    unsigned int   file_size;
    unsigned int   reserved;
    unsigned int   data_offset;
} BMPFileHeader;

typedef struct {
    unsigned int   size;
    int            width;
    int            height;
    unsigned short planes;
    unsigned short bits_per_pixel;
    unsigned int   compression;
    unsigned int   image_size;
    int            x_pixels_per_meter;
    int            y_pixels_per_meter;
    unsigned int   colors_used;
    unsigned int   important_colors;
} BMPInfoHeader;
#pragma pack(pop)

void embed_watermark(const char *input_file, const char *output_file, const char *watermark) {
    FILE *file = fopen(input_file, "rb");
    if (!file) {
        perror("Error opening input file");
        return;
    }

    BMPFileHeader bmp_header;
    fread(&bmp_header, sizeof(BMPFileHeader), 1, file);

    BMPInfoHeader bmp_info;
    fread(&bmp_info, sizeof(BMPInfoHeader), 1, file);

    if (bmp_info.bits_per_pixel != 24) {
        printf("Only 24-bit BMP files are supported!\n");
        fclose(file);
        return;
    }

    int watermark_length = strlen(watermark);
    if (watermark_length > 63) {
        printf("Watermark is too long! Max length is 63 characters.\n");
        fclose(file);
        return;
    }

    // Move to the beginning where pixel data starts
    fseek(file, bmp_header.data_offset, SEEK_SET);
    unsigned char *image_data = (unsigned char *)malloc(bmp_info.image_size);
    fread(image_data, bmp_info.image_size, 1, file);
    fclose(file);

    // Embed watermark
    for (int i = 0; i < watermark_length; i++) {
        for (int j = 0; j < 8; j++) {
            int pixel_index = (i * 8 + j) * 3; // 3 bytes per pixel
            if (pixel_index < bmp_info.image_size) {
                // Clear the least significant bit and set it to the watermark bit
                image_data[pixel_index] &= 0xFE; // Clear LSB
                image_data[pixel_index] |= ((watermark[i] >> (7 - j)) & 0x01); // Set LSB to watermark bit
            }
        }
    }

    // Save output image
    file = fopen(output_file, "wb");
    if (!file) {
        perror("Error opening output file");
        free(image_data);
        return;
    }

    fwrite(&bmp_header, sizeof(BMPFileHeader), 1, file);
    fwrite(&bmp_info, sizeof(BMPInfoHeader), 1, file);
    fwrite(image_data, bmp_info.image_size, 1, file);
    fclose(file);

    free(image_data);
    printf("Watermark embedded successfully!\n");
}

void extract_watermark(const char *input_file) {
    FILE *file = fopen(input_file, "rb");
    if (!file) {
        perror("Error opening input file");
        return;
    }

    BMPFileHeader bmp_header;
    fread(&bmp_header, sizeof(BMPFileHeader), 1, file);

    BMPInfoHeader bmp_info;
    fread(&bmp_info, sizeof(BMPInfoHeader), 1, file);

    if (bmp_info.bits_per_pixel != 24) {
        printf("Only 24-bit BMP files are supported!\n");
        fclose(file);
        return;
    }

    fseek(file, bmp_header.data_offset, SEEK_SET);
    unsigned char *image_data = (unsigned char *)malloc(bmp_info.image_size);
    fread(image_data, bmp_info.image_size, 1, file);
    fclose(file);

    char watermark[64] = {0};
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 8; j++) {
            int pixel_index = (i * 8 + j) * 3;
            if (pixel_index < bmp_info.image_size) {
                watermark[i] |= ((image_data[pixel_index] & 0x01) << (7 - j));
            }
        }
    }

    printf("Extracted Watermark: %s\n", watermark);
    free(image_data);
}

int main() {
    const char *input_file = "input.bmp";
    const char *output_file = "output.bmp";
    const char *watermark = "Watermarked by C Watermarking!";

    printf("Embedding watermark...\n");
    embed_watermark(input_file, output_file, watermark);

    printf("Extracting watermark...\n");
    extract_watermark(output_file);

    return 0;
}