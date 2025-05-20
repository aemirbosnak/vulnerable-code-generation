//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // Magic number for bitmap files
    uint32_t bfSize;      // Size of the file in bytes
    uint16_t bfReserved1; // Reserved; must be zero
    uint16_t bfReserved2; // Reserved; must be zero
    uint32_t bfOffBits;   // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the bitmap in pixels
    int32_t  biHeight;        // Height of the bitmap in pixels
    uint16_t biPlanes;        // Number of color planes; must be 1
    uint16_t biBitCount;      // Number of bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Size of the image data
    int32_t  biXPelsPerMeter;   // Horizontal resolution
    int32_t  biYPelsPerMeter;   // Vertical resolution
    uint32_t biClrUsed;        // Number of colors in the color palette
    uint32_t biClrImportant;    // Number of important colors
} BITMAPINFOHEADER;

#pragma pack(pop)

void flip_image(uint8_t *image, int width, int height, int padding) {
    uint8_t *temp_row = malloc(width * sizeof(uint8_t) * 3);
    if (!temp_row) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < height / 2; i++) {
        // Swap the rows
        memcpy(temp_row, image + i * (width * 3 + padding), width * 3);
        memcpy(image + i * (width * 3 + padding), image + (height - 1 - i) * (width * 3 + padding), width * 3);
        memcpy(image + (height - 1 - i) * (width * 3 + padding), temp_row, width * 3);
    }

    free(temp_row);
}

void change_brightness(uint8_t *image, int width, int height, int padding, int change) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                int pixel_index = (i * (width * 3 + padding)) + (j * 3) + k;
                int new_value = image[pixel_index] + change;
                image[pixel_index] = (new_value > 255) ? 255 : (new_value < 0) ? 0 : new_value;
            }
        }
    }
}

void change_contrast(uint8_t *image, int width, int height, int padding, float factor) {
    float contrast_factor = (259 * (factor + 255))/(255 * (259 - factor)); 
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                int pixel_index = (i * (width * 3 + padding)) + (j * 3) + k;
                int new_value = contrast_factor * (image[pixel_index] - 128) + 128;
                image[pixel_index] = (new_value > 255) ? 255 : (new_value < 0) ? 0 : new_value;
            }
        }
    }
}

void save_bmp(const char *filename, BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header, uint8_t *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file for writing\n");
        return;
    }
    
    fwrite(file_header, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(info_header, sizeof(BITMAPINFOHEADER), 1, file);
    
    int padding = (4 - (info_header->biWidth * 3) % 4) % 4;
    for (int i = 0; i < info_header->biHeight; i++) {
        fwrite(image + i * (info_header->biWidth * 3 + padding), 1, info_header->biWidth * 3, file);
        fwrite("\0\0\0", 1, padding, file);
    }
    
    fclose(file);
}

void load_bmp(const char *filename, BITMAPFILEHEADER *file_header, BITMAPINFOHEADER *info_header, uint8_t **image) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file for reading\n");
        return;
    }
    
    fread(file_header, sizeof(BITMAPFILEHEADER), 1, file);
    fread(info_header, sizeof(BITMAPINFOHEADER), 1, file);
    
    int size = info_header->biWidth * info_header->biHeight * 3 + (4 - (info_header->biWidth * 3) % 4) % 4 * info_header->biHeight;
    *image = malloc(size);
    if (!*image) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return;
    }
    
    fread(*image, 1, size, file);
    fclose(file);
}

int main() {
    BITMAPFILEHEADER file_header;
    BITMAPINFOHEADER info_header;
    uint8_t *image = NULL;
    
    const char *input_filename = "input.bmp";
    const char *output_filename = "output.bmp";

    load_bmp(input_filename, &file_header, &info_header, &image);
    if (!image) {
        return 1;
    }

    int padding = (4 - (info_header.biWidth * 3) % 4) % 4;

    // Flip the image
    flip_image(image, info_header.biWidth, info_header.biHeight, padding);

    // Change brightness
    change_brightness(image, info_header.biWidth, info_header.biHeight, padding, 30); // Increase brightness

    // Change contrast
    change_contrast(image, info_header.biWidth, info_header.biHeight, padding, 50.0); // Increase contrast

    // Save the modified image
    save_bmp(output_filename, &file_header, &info_header, image);

    free(image);
    return 0;
}