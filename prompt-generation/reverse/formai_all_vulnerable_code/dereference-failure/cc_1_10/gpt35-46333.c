//FormAI DATASET v1.0 Category: Image Editor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* A simple program to demonstrate an image editor */
/* This program can read a BMP file and crop or resize it */

/* BMP file format header - Windows */
#pragma pack(push, 1)
typedef struct {
    char format[2];         // BM - indicates a BMP file
    unsigned int size;      // Size of the BMP file in bytes
    unsigned short int reserved1, reserved2;   // Reserved
    unsigned int offset;    // Offset from the beginning of the file to the image data
    unsigned int header_size;   // Size of the header
    int width, height;      // Width and height of the image in pixels
    unsigned short int planes;  // Number of color planes (must be 1)
    unsigned short int bpp;     // Number of bits per pixel (usually 24 for true color)
    unsigned int compression;   // Compression method (usually 0 for no compression)
    unsigned int image_size;    // Size of the raw image data (including padding)
    int x_res, y_res;       // Resolution in pixels per meter (ignored usually)
    unsigned int colors;    // Number of colors in the palette (0 for no palette)
    unsigned int important_colors;  // Number of important colors (0 for all)
} bmp_header_t;
#pragma pack(pop)

/* Function prototypes */
unsigned char* read_bmp(const char* filename, bmp_header_t* header);
void write_bmp(const char* filename, bmp_header_t* header, unsigned char* data);
void crop_image(unsigned char* input, bmp_header_t* in_header, unsigned char** output, bmp_header_t* out_header, int x, int y, int w, int h);
void resize_image(unsigned char* input, bmp_header_t* in_header, unsigned char** output, bmp_header_t* out_header, int new_w, int new_h);

/* Main function */
int main(int argc, char** argv) {
    /* Check arguments */
    if (argc != 5) {
        printf("Usage: %s input_file output_file [crop x y width height | resize width height]\n", argv[0]);
        return 1;
    }

    /* Read input file */
    bmp_header_t header;
    unsigned char* data = read_bmp(argv[1], &header);
    if (!data) {
        printf("Could not read input file %s\n", argv[1]);
        return 2;
    }

    /* Perform requested action */
    int new_w = header.width;
    int new_h = header.height;
    if (strcmp(argv[3], "crop") == 0) {
        int x = atoi(argv[4]);
        int y = atoi(argv[5]);
        int w = atoi(argv[6]);
        int h = atoi(argv[7]);
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (x + w > header.width) w = header.width - x;
        if (y + h > header.height) h = header.height - y;
        if (w <= 0 || h <= 0) {
            printf("Invalid crop parameters\n");
            free(data);
            return 3;
        }
        bmp_header_t out_header;
        out_header = header;
        out_header.width = w;
        out_header.height = h;
        unsigned char* out_data = malloc(out_header.image_size);
        if (!out_data) {
            printf("Could not allocate memory for output data\n");
            free(data);
            return 4;
        }
        crop_image(data, &header, &out_data, &out_header, x, y, w, h);
        free(data);
        data = out_data;
        header = out_header;
    } else if (strcmp(argv[3], "resize") == 0) {
        int w = atoi(argv[4]);
        int h = atoi(argv[5]);
        if (w <= 0 || h <= 0) {
            printf("Invalid resize parameters\n");
            free(data);
            return 3;
        }
        bmp_header_t out_header;
        out_header = header;
        out_header.width = w;
        out_header.height = h;
        unsigned char* out_data = malloc(out_header.image_size);
        if (!out_data) {
            printf("Could not allocate memory for output data\n");
            free(data);
            return 4;
        }
        resize_image(data, &header, &out_data, &out_header, w, h);
        free(data);
        data = out_data;
        header = out_header;
    } else {
        printf("Invalid operation %s\n", argv[3]);
        free(data);
        return 5;
    }

    /* Write output file */
    write_bmp(argv[2], &header, data);

    /* Free memory */
    free(data);

    return 0;
}

/* Function to read a BMP file */
unsigned char* read_bmp(const char* filename, bmp_header_t* header) {
    FILE* file = fopen(filename, "rb");
    if (!file) return NULL;

    /* Read header */
    fread(header, sizeof(bmp_header_t), 1, file);

    /* Check format */
    if (header->format[0] != 'B' || header->format[1] != 'M') {
        fclose(file);
        return NULL;
    }

    /* Allocate memory for data */
    unsigned char* data = malloc(header->image_size);
    if (!data) {
        fclose(file);
        return NULL;
    }

    /* Read data */
    fseek(file, header->offset, SEEK_SET);
    if (fread(data, header->image_size, 1, file) != 1) {
        fclose(file);
        free(data);
        return NULL;
    }

    /* Close file and return data */
    fclose(file);
    return data;
}

/* Function to write a BMP file */
void write_bmp(const char* filename, bmp_header_t* header, unsigned char* data) {
    FILE* file = fopen(filename, "wb");
    if (!file) return;

    /* Write header */
    fwrite(header, sizeof(bmp_header_t), 1, file);

    /* Write data */
    fseek(file, header->offset, SEEK_SET);
    fwrite(data, header->image_size, 1, file);

    /* Close file */
    fclose(file);
}

/* Function to crop an image */
void crop_image(unsigned char* input, bmp_header_t* in_header, unsigned char** output, bmp_header_t* out_header, int x, int y, int w, int h) {
    int bpp = in_header->bpp / 8;
    unsigned char* in_data = input + in_header->offset;
    unsigned char* out_data = *output + out_header->offset;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < bpp; k++) {
                out_data[bpp * (i * w + j) + k] = in_data[bpp * ((y + i) * in_header->width + (x + j)) + k];
            }
        }
    }
}

/* Function to resize an image */
void resize_image(unsigned char* input, bmp_header_t* in_header, unsigned char** output, bmp_header_t* out_header, int new_w, int new_h) {
    int bpp = in_header->bpp / 8;
    unsigned char* in_data = input + in_header->offset;
    unsigned char* out_data = *output + out_header->offset;

    float x_ratio = (float)in_header->width / (float)new_w;
    float y_ratio = (float)in_header->height / (float)new_h;

    for (int i = 0; i < new_h; i++) {
        for (int j = 0; j < new_w; j++) {
            int x = (int)(j * x_ratio);
            int y = (int)(i * y_ratio);
            for (int k = 0; k < bpp; k++) {
                out_data[bpp * (i * new_w + j) + k] = in_data[bpp * (y * in_header->width + x) + k];
            }
        }
    }
}