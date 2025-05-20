//FormAI DATASET v1.0 Category: Image Editor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BMP_HEADER_SIZE 54
#define MAX_IMAGE_SIZE 512

#pragma pack(push, 1)

typedef struct {
    uint16_t magic_number;
    uint32_t file_size;
    uint32_t reserved;
    uint32_t data_offset;
} bmp_file_header_t;

typedef struct {
    uint32_t header_size;
    int32_t width;
    int32_t height;
    uint16_t color_planes;
    uint16_t bpp;
    uint32_t compression;
    uint32_t image_size;
    int32_t x_res;
    int32_t y_res;
    uint32_t colors;
    uint32_t important_colors;
} bmp_info_header_t;

#pragma pack(pop)

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_t;

rgb_t image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];

int main() {
    bmp_file_header_t file_header;
    bmp_info_header_t info_header;
    FILE *fp = fopen("input.bmp", "rb");

    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    fread(&file_header, sizeof(bmp_file_header_t), 1, fp);
    fread(&info_header, sizeof(bmp_info_header_t), 1, fp);

    if (info_header.width > MAX_IMAGE_SIZE || info_header.height > MAX_IMAGE_SIZE) {
        fprintf(stderr, "Error: Image too big\n");
        exit(EXIT_FAILURE);
    }

    int row_padding = (4 - (info_header.width * sizeof(rgb_t)) % 4) % 4;

    for (int i = 0; i < info_header.height; i++) {
        for (int j = 0; j < info_header.width; j++) {
            fread(&image[i][j], sizeof(rgb_t), 1, fp);
        }

        fseek(fp, row_padding, SEEK_CUR);
    }

    fclose(fp);

    /* Do your image editing here */

    fp = fopen("output.bmp", "wb");

    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    fwrite(&file_header, sizeof(bmp_file_header_t), 1, fp);
    fwrite(&info_header, sizeof(bmp_info_header_t), 1, fp);

    for (int i = 0; i < info_header.height; i++) {
        for (int j = 0; j < info_header.width; j++) {
            fwrite(&image[i][j], sizeof(rgb_t), 1, fp);
        }

        for (int k = 0; k < row_padding; k++) {
            fputc(0x00, fp);
        }
    }

    fclose(fp);

    return 0;
}