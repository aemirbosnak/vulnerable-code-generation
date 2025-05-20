//FormAI DATASET v1.0 Category: Image Editor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    unsigned char red, green, blue;
} pixel_t;

typedef struct {
    unsigned int width, height;
    pixel_t *pixels;
} bitmap_t;

void read_bmp_file(char *filename, bitmap_t *bitmap) {
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(1);
    }

    unsigned char header[54];
    int row_padding;
    unsigned char *row_buffer;
    unsigned char *bmp_buffer;
    unsigned int bmp_buffer_size;
    size_t result;

    result = fread(header, sizeof(unsigned char), 54, fp);
    if (result != 54) {
        fprintf(stderr, "Error: Invalid BMP format in file %s\n", filename);
        exit(1);
    }

    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: Invalid BMP format in file %s\n", filename);
        exit(1);
    }

    bmp_buffer_size = *(unsigned int *)(header + 0x22);
    bitmap->width = *(unsigned int *)(header + 0x12);
    bitmap->height = *(unsigned int *)(header + 0x16);
    row_padding = (4 - (bitmap->width * 3) % 4) % 4;
    bmp_buffer = (unsigned char *)malloc(bmp_buffer_size);
    row_buffer = (unsigned char *)malloc(bitmap->width * 3);

    result = fread(bmp_buffer, sizeof(unsigned char), bmp_buffer_size, fp);
    if (result != bmp_buffer_size) {
        fprintf(stderr, "Error: BMP data read error in file %s\n", filename);
        free(row_buffer);
        free(bmp_buffer);
        exit(1);
    }

    bitmap->pixels = (pixel_t *)malloc(bitmap->width * bitmap->height * sizeof(pixel_t));
    for (int y = bitmap->height - 1; y >= 0; y--) {
        memcpy(row_buffer, bmp_buffer + y * (bitmap->width * 3 + row_padding), bitmap->width * 3);
        for (int x = 0; x < bitmap->width; x++) {
            bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x].blue = row_buffer[x * 3 + 0];
            bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x].green = row_buffer[x * 3 + 1];
            bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x].red = row_buffer[x * 3 + 2];
        }
    }

    free(row_buffer);
    free(bmp_buffer);
    fclose(fp);
}

void write_bmp_file(char *filename, bitmap_t *bitmap) {
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to create file %s\n", filename);
        exit(1);
    }

    int row_padding;
    unsigned char *row_buffer;
    unsigned char *bmp_buffer;
    unsigned int bmp_buffer_size;
    size_t result;

    row_padding = (4 - (bitmap->width * 3) % 4) % 4;
    bmp_buffer_size = 54 + (bitmap->width * 3 + row_padding) * bitmap->height;
    bmp_buffer = (unsigned char *)malloc(bmp_buffer_size);
    row_buffer = (unsigned char *)malloc(bitmap->width * 3);

    memset(bmp_buffer, 0, bmp_buffer_size);

    bmp_buffer[0] = 'B';
    bmp_buffer[1] = 'M';
    *(unsigned int *)(bmp_buffer + 0x02) = bmp_buffer_size;
    *(unsigned int *)(bmp_buffer + 0x0A) = 54;
    *(unsigned int *)(bmp_buffer + 0x0E) = 40;
    *(unsigned int *)(bmp_buffer + 0x12) = bitmap->width;
    *(unsigned int *)(bmp_buffer + 0x16) = bitmap->height;
    *(unsigned short *)(bmp_buffer + 0x1A) = 1;
    *(unsigned short *)(bmp_buffer + 0x1C) = 24;
    *(unsigned int *)(bmp_buffer + 0x22) = (bitmap->width * 3 + row_padding) * bitmap->height;
    *(unsigned int *)(bmp_buffer + 0x2E) = 0x000000FF;
    *(unsigned int *)(bmp_buffer + 0x32) = 0x0000FF00;
    *(unsigned int *)(bmp_buffer + 0x36) = 0x00FF0000;

    for (int y = bitmap->height - 1; y >= 0; y--) {
        for (int x = 0; x < bitmap->width; x++) {
            row_buffer[x * 3 + 0] = bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x].blue;
            row_buffer[x * 3 + 1] = bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x].green;
            row_buffer[x * 3 + 2] = bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x].red;
        }
        fwrite(row_buffer, sizeof(unsigned char), bitmap->width * 3, fp);
        if (row_padding > 0) {
            fwrite(bmp_buffer, sizeof(unsigned char), row_padding, fp);
        }
    }

    free(row_buffer);
    free(bmp_buffer);
    fclose(fp);
}

void invert_colors(bitmap_t *bitmap) {
    for (int i = 0; i < bitmap->width * bitmap->height; i++) {
        bitmap->pixels[i].red = 255 - bitmap->pixels[i].red;
        bitmap->pixels[i].green = 255 - bitmap->pixels[i].green;
        bitmap->pixels[i].blue = 255 - bitmap->pixels[i].blue;
    }
}

void grayscale(bitmap_t *bitmap) {
    for (int i = 0; i < bitmap->width * bitmap->height; i++) {
        int gray = (bitmap->pixels[i].red + bitmap->pixels[i].green + bitmap->pixels[i].blue) / 3;
        bitmap->pixels[i].red = gray;
        bitmap->pixels[i].green = gray;
        bitmap->pixels[i].blue = gray;
    }
}

void brighten(bitmap_t *bitmap, int delta) {
    for (int i = 0; i < bitmap->width * bitmap->height; i++) {
        bitmap->pixels[i].red = MIN(bitmap->pixels[i].red + delta, 255);
        bitmap->pixels[i].green = MIN(bitmap->pixels[i].green + delta, 255);
        bitmap->pixels[i].blue = MIN(bitmap->pixels[i].blue + delta, 255);
    }
}

void darken(bitmap_t *bitmap, int delta) {
    for (int i = 0; i < bitmap->width * bitmap->height; i++) {
        bitmap->pixels[i].red = MAX(bitmap->pixels[i].red - delta, 0);
        bitmap->pixels[i].green = MAX(bitmap->pixels[i].green - delta, 0);
        bitmap->pixels[i].blue = MAX(bitmap->pixels[i].blue - delta, 0);
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Error: Insufficient arguments.\nUsage: ./image_editor <input_bmp_file> <output_bmp_file> <operation> <operation_param>\n");
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    char *operation = argv[3];
    int operation_param = argc > 4 ? atoi(argv[4]) : 0;

    bitmap_t bitmap;
    read_bmp_file(input_filename, &bitmap);

    if (strcmp(operation, "invert_colors") == 0) {
        invert_colors(&bitmap);
    } else if (strcmp(operation, "grayscale") == 0) {
        grayscale(&bitmap);
    } else if (strcmp(operation, "brighten") == 0) {
        brighten(&bitmap, operation_param);
    } else if (strcmp(operation, "darken") == 0) {
        darken(&bitmap, operation_param);
    } else {
        fprintf(stderr, "Error: Invalid operation.\nAvailable operations: invert_colors, grayscale, brighten, darken\n");
        return 1;
    }

    write_bmp_file(output_filename, &bitmap);

    free(bitmap.pixels);

    return 0;
}