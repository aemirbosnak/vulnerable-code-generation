//FormAI DATASET v1.0 Category: Image compression ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 8
#define MAX_PIXEL 255
#define MIN_BLOCK_SIZE 1

// function to compress image
void compress_image(unsigned char *image_data, int width, int height, FILE *fp_compressed) {
    unsigned char *block_data = (unsigned char*) malloc(sizeof(unsigned char) * BLOCK_SIZE * BLOCK_SIZE);
    int num_blocks_width = width / BLOCK_SIZE;
    int num_blocks_height = height / BLOCK_SIZE;

    // write width and height information to compressed file
    fwrite(&width, sizeof(int), 1, fp_compressed);
    fwrite(&height, sizeof(int), 1, fp_compressed);

    // loop through each block and compress
    for (int i = 0; i < num_blocks_height; i++) {
        for (int j = 0; j < num_blocks_width; j++) {
            // loop through each pixel in the block and find the average value
            int sum = 0;
            for (int k = 0; k < BLOCK_SIZE; k++) {
                for (int l = 0; l < BLOCK_SIZE; l++) {
                    int pixel_value = *(image_data + (i * BLOCK_SIZE + k) * width + j * BLOCK_SIZE + l);
                    sum += pixel_value;
                }
            }
            int avg_value = sum / (BLOCK_SIZE * BLOCK_SIZE);
            *(block_data + (i * num_blocks_width + j)) = (unsigned char) avg_value;
        }
    }

    // write compressed data to file
    fwrite(block_data, sizeof(unsigned char), num_blocks_width * num_blocks_height, fp_compressed);

    free(block_data);
}

// function to decompress image
unsigned char* decompress_image(FILE *fp_compressed, int *width, int *height) {
    // read width and height information from compressed file
    fread(width, sizeof(int), 1, fp_compressed);
    fread(height, sizeof(int), 1, fp_compressed);

    int num_blocks_width = *width / BLOCK_SIZE;
    int num_blocks_height = *height / BLOCK_SIZE;

    // allocate memory for decompressed image
    unsigned char *decompressed_image = (unsigned char*) malloc(sizeof(unsigned char) * (*width) * (*height));

    // loop through each block and decompress
    for (int i = 0; i < num_blocks_height; i++) {
        for (int j = 0; j < num_blocks_width; j++) {
            unsigned char block_value;
            fread(&block_value, sizeof(unsigned char), 1, fp_compressed);

            // loop through each pixel in the block and set the value to the block value
            for (int k = 0; k < BLOCK_SIZE; k++) {
                for (int l = 0; l < BLOCK_SIZE; l++) {
                    int pixel_index = (i * BLOCK_SIZE + k) * (*width) + j * BLOCK_SIZE + l;
                    *(decompressed_image + pixel_index) = block_value;
                }
            }
        }
    }

    return decompressed_image;
}

int main() {
    // read image data
    FILE *fp_original = fopen("original_image.bmp", "rb");
    if (fp_original == NULL) {
        printf("Cannot open original image file.");
        return 1;
    }
    fseek(fp_original, 0L, SEEK_END);
    long size = ftell(fp_original);
    fseek(fp_original, 0L, SEEK_SET);
    unsigned char *image_data = (unsigned char*) malloc(sizeof(unsigned char) * size);
    fread(image_data, sizeof(unsigned char), size, fp_original);
    fclose(fp_original);

    // get image width and height information
    int width = *(int*)(image_data + 18);
    int height = *(int*)(image_data + 22);

    // compress image
    FILE *fp_compressed = fopen("compressed_image.bin", "wb");
    if (fp_compressed == NULL) {
        printf("Cannot open compressed image file.");
        return 1;
    }
    compress_image(image_data + 54, width, height, fp_compressed);
    fclose(fp_compressed);

    // decompress image
    fp_compressed = fopen("compressed_image.bin", "rb");
    if (fp_compressed == NULL) {
        printf("Cannot open compressed image file.");
        return 1;
    }
    unsigned char *decompressed_image = decompress_image(fp_compressed, &width, &height);
    fclose(fp_compressed);

    // write decompressed image data to file
    FILE *fp_decompressed = fopen("decompressed_image.bmp", "wb");
    if (fp_decompressed == NULL) {
        printf("Cannot open decompressed image file.");
        return 1;
    }
    memcpy(decompressed_image + 18, &width, sizeof(int));
    memcpy(decompressed_image + 22, &height, sizeof(int));
    fwrite(decompressed_image, sizeof(unsigned char), size, fp_decompressed);
    fclose(fp_decompressed);

    free(decompressed_image);
    free(image_data);

    return 0;
}