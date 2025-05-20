//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "image.bmp" // Name of the input image file

#pragma pack(push, 1) //pack the below structure so it can be read in 1 go
typedef struct {
    unsigned char header[54];
    unsigned int width, height; // Dimensions of the image
    unsigned char data[3];
} image_info;
#pragma pack(pop)

void flip_image(image_info *image) {
    int row_size = (image->width * 3 + 3) & ~3; // Round up to the nearest multiple of 4 bytes
    int half_height = image->height / 2;
    unsigned char row[row_size];
    for (int i = 0; i < half_height; i++) {
        unsigned char *row1 = image->data + i * row_size;
        unsigned char *row2 = image->data + (image->height - 1 - i) * row_size;
        memcpy(row, row1, row_size);
        memcpy(row1, row2, row_size);
        memcpy(row2, row, row_size);
    }
}

void adjust_brightness(image_info *image, double brightness_factor) {
    for (int i = 0; i < image->width * image->height * 3; i++) {
        int value = image->data[i] * brightness_factor;
        if (value > 255) {
            value = 255;
        }
        image->data[i] = value;
    }
}

void adjust_contrast(image_info *image, double contrast_factor) {
    double contrast_coefficient = (100 - contrast_factor) / 100.0;
    contrast_coefficient = contrast_coefficient * contrast_coefficient; // Square the coefficient
    double contrast_table[256];
    for (int i = 0; i < 256; i++) {
        contrast_table[i] = i * contrast_coefficient;
        contrast_table[i] += (i - contrast_table[i]) * (1.0 - contrast_coefficient);
    }
    for (int i = 0; i < image->width * image->height * 3; i++) {
        int value = contrast_table[image->data[i]];
        if (value > 255) {
            value = 255;
        } else if (value < 0) {
            value = 0;
        }
        image->data[i] = value;
    }
}

int main() {
    FILE *image_file = fopen(FILENAME, "rb");
    if (!image_file) {
        fprintf(stderr, "Error: unable to open %s for reading\n", FILENAME);
        return 1;
    }
    image_info image;
    fread(&image, sizeof(image), 1, image_file);
    fclose(image_file);
    flip_image(&image);
    adjust_brightness(&image, 2.0);
    adjust_contrast(&image, 50.0);
    image_file = fopen("output.bmp", "wb");
    if (!image_file) {
        fprintf(stderr, "Error: unable to open output.bmp for writing\n");
        return 1;
    }
    fwrite(&image, sizeof(image), 1, image_file);
    fclose(image_file);
    return 0;
}