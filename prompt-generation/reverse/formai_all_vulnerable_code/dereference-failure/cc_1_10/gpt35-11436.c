//FormAI DATASET v1.0 Category: Image Editor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel_t;

typedef struct image {
    unsigned int width;
    unsigned int height;
    pixel_t *data;
} image_t;

int main()
{
    // Load image, assumes it's in a 24-bit BMP format
    FILE *img_file = fopen("image.bmp", "rb");
    if (!img_file) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }
    fseek(img_file, 10, SEEK_SET);
    unsigned int data_offset;
    fread(&data_offset, sizeof(unsigned int), 1, img_file);
    fseek(img_file, 18, SEEK_SET);
    unsigned int img_width, img_height;
    fread(&img_width, sizeof(unsigned int), 1, img_file);
    fread(&img_height, sizeof(unsigned int), 1, img_file);
    fseek(img_file, data_offset, SEEK_SET);

    // Allocate image data buffer
    image_t img;
    img.width = img_width;
    img.height = img_height;
    img.data = malloc(img_width * img_height * sizeof(pixel_t));
    if (!img.data) {
        perror("Error allocating image buffer");
        return EXIT_FAILURE;
    }

    // Read image data
    for (int i = 0; i < img_width * img_height; i++) {
        fread(&img.data[i].blue, sizeof(unsigned char), 1, img_file);
        fread(&img.data[i].green, sizeof(unsigned char), 1, img_file);
        fread(&img.data[i].red, sizeof(unsigned char), 1, img_file);
    }

    // Apply image filter
    bool filter_enabled = true;
    // ... do some processing on img.data ...
    if (filter_enabled) {
        for (int i = 0; i < img_width * img_height; i++) {
            img.data[i].red = img.data[i].red * 0.8;
            img.data[i].green = img.data[i].green * 1.2;
            img.data[i].blue = img.data[i].blue * 0.9;
        }
    }

    // Save processed image
    FILE *out_file = fopen("out.bmp", "wb");
    if (!out_file) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }
    fwrite("BM", sizeof(char), 2, out_file); // BMP file header
    unsigned int bmp_size = img_width * img_height * 3 + 54;
    fwrite(&bmp_size, sizeof(unsigned int), 1, out_file); // Size of BMP file
    fwrite("\0\0\0\0", sizeof(unsigned int), 1, out_file); // Reserved value
    unsigned int data_offset_out = 54;
    fwrite(&data_offset_out, sizeof(unsigned int), 1, out_file); // Offset of data array
    unsigned int dib_header_size = 40;
    fwrite(&dib_header_size, sizeof(unsigned int), 1, out_file); // Size of DIB header
    fwrite(&img_width, sizeof(int), 1, out_file); // Width of image
    fwrite(&img_height, sizeof(int), 1, out_file); // Height of image
    unsigned short int color_planes = 1;
    fwrite(&color_planes, sizeof(unsigned short int), 1, out_file); // Color planes
    unsigned short int bits_per_pixel = 24;
    fwrite(&bits_per_pixel, sizeof(unsigned short int), 1, out_file); // Bits per pixel
    unsigned int compression_mode = 0;
    fwrite(&compression_mode, sizeof(unsigned int), 1, out_file); // Compression mode
    unsigned int data_size = bmp_size - 54;
    fwrite(&data_size, sizeof(unsigned int), 1, out_file); // Size of data array
    unsigned int print_res = 2835;
    fwrite(&print_res, sizeof(int), 1, out_file); // Print resolution in pixels/meter
    fwrite(&print_res, sizeof(int), 1, out_file); // Print resolution in pixels/meter
    fwrite("\0\0\0\0", sizeof(unsigned int), 1, out_file); // Number of colors used
    fwrite("\0\0\0\0", sizeof(unsigned int), 1, out_file); // Number of important colors
    for (int i = 0; i < img_width * img_height; i++) {
        fwrite(&img.data[i].blue, sizeof(unsigned char), 1, out_file);
        fwrite(&img.data[i].green, sizeof(unsigned char), 1, out_file);
        fwrite(&img.data[i].red, sizeof(unsigned char), 1, out_file);
    }

    // Cleanup
    fclose(img_file);
    fclose(out_file);
    free(img.data);
    return EXIT_SUCCESS;
}