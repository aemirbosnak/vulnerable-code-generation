//FormAI DATASET v1.0 Category: Image compression ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

typedef struct CompressedImage {
    char header[54]; // BMP image header
    unsigned char *compressed_image; // compressed image array
    int compress_size; // size of compressed image
} CompressedImage;

typedef struct ImageData {
    char header[54]; // BMP image header
    unsigned char *data; // image data
    int width; // image width
    int height; // image height
} ImageData;

/**
 * Function to read the BMP image and return uncompressed image data
 */
void read_bmp(const char *input_file, ImageData *image_data) {
    FILE *input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fread(image_data->header, sizeof(char), 54, input_fp); // Read BMP image header

    // Read image width, height and pixel data
    image_data->width = *(int *)&image_data->header[18];
    image_data->height = *(int *)&image_data->header[22];
    int padding = (4 - (image_data->width * 3) % 4) % 4; // Calculate padding required for each scanline
    int img_size = (image_data->width * 3 + padding) * image_data->height;
    unsigned char *img_data = (unsigned char *)malloc(img_size * sizeof(unsigned char));
    fread(img_data, sizeof(unsigned char), img_size, input_fp);

    fclose(input_fp);

    // Create image data array without padding
    image_data->data = (unsigned char *)malloc((image_data->width * image_data->height) * sizeof(unsigned char));
    int index = 0;
    for (int i = 0; i < image_data->height; i++) {
        for (int j = 0; j < image_data->width; j++) {
            int pixel_index = i * (image_data->width * 3 + padding) + j * 3;
            image_data->data[index++] = img_data[pixel_index + 2]; // R component
            image_data->data[index++] = img_data[pixel_index + 1]; // G component
            image_data->data[index++] = img_data[pixel_index]; // B component
        }
    }
    free(img_data);
}

/**
 * Function to compress the image data
 */
void compress_image(unsigned char *data, int data_size, unsigned char *compressed_data, int *compressed_size) {
    // Compress the image using your compression algorithm
    // Here, I am simply copying the uncompressed data to compressed data
    memcpy(compressed_data, data, data_size);
    *compressed_size = data_size;
}

/**
 * Function to write BMP header and compressed data into output file
 */
void write_compressed_bmp(const char *output_file, CompressedImage *compressed_image) {
    FILE *output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fwrite(compressed_image->header, sizeof(char), 54, output_fp); // Write BMP image header
    fwrite(compressed_image->compressed_image, sizeof(unsigned char), compressed_image->compress_size, output_fp); // Write compressed data

    fclose(output_fp);
}

/**
 * Asynchronous function to compress the image
 */
void compress_image_async(ImageData *image_data, CompressedImage *compressed_image, int *compress_done) {
    unsigned char *compressed_data = (unsigned char *)malloc((image_data->width * image_data->height) * sizeof(unsigned char));
    compress_image(image_data->data, image_data->width * image_data->height, compressed_data, &compressed_image->compress_size);
    compressed_image->compressed_image = compressed_data;
    *compress_done = 1;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    ImageData image_data;
    read_bmp(argv[1], &image_data);

    CompressedImage compressed_image;
    memcpy(compressed_image.header, image_data.header, 54); // Copy BMP image header from uncompressed image to compressed image

    int compress_done = 0;
    compress_image_async(&image_data, &compressed_image, &compress_done);

    // Wait for compression to finish
    while (!compress_done) {
        printf("Compressing image...\n");
        sleep(1);
    }

    write_compressed_bmp(argv[2], &compressed_image);

    free(image_data.data);
    free(compressed_image.compressed_image);

    return 0;
}