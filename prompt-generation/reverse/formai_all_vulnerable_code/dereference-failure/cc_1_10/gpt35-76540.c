//FormAI DATASET v1.0 Category: Image compression ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 8

struct image {
    unsigned char *data;
    int width;
    int height;
};

void compress_image(struct image *img) {
    int num_blocks = (img->width * img->height) / (BLOCK_SIZE * BLOCK_SIZE);
    unsigned char *output = malloc(num_blocks * BLOCK_SIZE * sizeof(unsigned char));

    int block_index = 0;
    for(int y = 0; y < img->height; y += BLOCK_SIZE) {
        for(int x = 0; x < img->width; x += BLOCK_SIZE) {
            unsigned char *block = img->data + y * img->width + x;
            unsigned char mean = 0;
            for(int i = 0; i < BLOCK_SIZE * BLOCK_SIZE; i++) {
                mean += block[i];
            }
            mean /= BLOCK_SIZE * BLOCK_SIZE;

            for(int i = 0; i < BLOCK_SIZE * BLOCK_SIZE; i++) {
                if(block[i] >= mean) {
                    output[block_index] |= (1 << (i % BLOCK_SIZE));
                }
                if((i % BLOCK_SIZE) == BLOCK_SIZE - 1) {
                    block_index++;
                }
            }
        }
    }

    free(img->data);
    img->data = output;
}

void decompress_image(struct image *img) {
    unsigned char *output = malloc(img->width * img->height * sizeof(unsigned char));

    int block_index = 0;
    for(int y = 0; y < img->height; y += BLOCK_SIZE) {
        for(int x = 0; x < img->width; x += BLOCK_SIZE) {
            unsigned char *block = output + y * img->width + x;
            unsigned char byte = img->data[block_index];
            for(int i = 0; i < BLOCK_SIZE * BLOCK_SIZE; i++) {
                block[i] = (byte & (1 << (i % BLOCK_SIZE))) ? 255 : 0;
                if((i % BLOCK_SIZE) == BLOCK_SIZE - 1) {
                    block += img->width;
                }
            }
            block_index++;
        }
    }

    free(img->data);
    img->data = output;
}

int main() {
    // Load image from file
    FILE *f = fopen("image.raw", "rb");
    if(f == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    int width = 0, height = 0;
    fread(&width, sizeof(int), 1, f);
    fread(&height, sizeof(int), 1, f);

    struct image img;
    img.width = width;
    img.height = height;
    img.data = malloc(width * height * sizeof(unsigned char));
    fread(img.data, sizeof(unsigned char), width * height, f);

    fclose(f);

    // Compress image
    compress_image(&img);

    // Write compressed image to file
    FILE *f_out = fopen("image_compressed.bin", "wb");
    fwrite(&img.width, sizeof(int), 1, f_out);
    fwrite(&img.height, sizeof(int), 1, f_out);
    fwrite(img.data, sizeof(unsigned char), (img.width * img.height) / 8, f_out);
    fclose(f_out);

    // Decompress image
    f_out = fopen("image_compressed.bin", "rb");
    fread(&width, sizeof(int), 1, f_out);
    fread(&height, sizeof(int), 1, f_out);

    img.width = width;
    img.height = height;
    img.data = malloc(width * height * sizeof(unsigned char) / 8);
    fread(img.data, sizeof(unsigned char), (img.width * img.height) / 8, f_out);
    fclose(f_out);

    decompress_image(&img);

    // Write decompressed image to file
    f_out = fopen("image_decompressed.raw", "wb");
    fwrite(&img.width, sizeof(int), 1, f_out);
    fwrite(&img.height, sizeof(int), 1, f_out);
    fwrite(img.data, sizeof(unsigned char), img.width * img.height, f_out);
    fclose(f_out);

    free(img.data);

    return 0;
}