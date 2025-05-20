//FormAI DATASET v1.0 Category: Image compression ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480
#define BLOCK_SIZE 8

typedef unsigned char byte;

// Calculate discrete cosine transform (DCT) of an 8x8 block
void dct(double *block) {
    double s, t;
    double a[8], b[8];

    // Compute 1-dimensional DCT for each row
    for (int row = 0; row < BLOCK_SIZE; row++) {
        for (int col = 0; col < BLOCK_SIZE; col++) {
            a[col] = block[row * BLOCK_SIZE + col];
        }

        for (int k = 0; k < BLOCK_SIZE; k++) {
            s = 0.0;
            for (int n = 0; n < BLOCK_SIZE; n++) {
                s += a[n] * cos((2 * n + 1) * k * M_PI / (2 * BLOCK_SIZE));
            }
            t = s * sqrt(2.0 / BLOCK_SIZE) * (k == 0 ? 1.0 / sqrt(2.0) : 1.0);
            b[k] = t;
        }

        for (int col = 0; col < BLOCK_SIZE; col++) {
            block[row * BLOCK_SIZE + col] = b[col];
        }
    }

    // Compute 1-dimensional DCT for each column
    for (int col = 0; col < BLOCK_SIZE; col++) {
        for (int row = 0; row < BLOCK_SIZE; row++) {
            a[row] = block[row * BLOCK_SIZE + col];
        }

        for (int k = 0; k < BLOCK_SIZE; k++) {
            s = 0.0;
            for (int n = 0; n < BLOCK_SIZE; n++) {
                s += a[n] * cos((2 * n + 1) * k * M_PI / (2 * BLOCK_SIZE));
            }
            t = s * sqrt(2.0 / BLOCK_SIZE) * (k == 0 ? 1.0 / sqrt(2.0) : 1.0);
            b[k] = t;
        }

        for (int row = 0; row < BLOCK_SIZE; row++) {
            block[row * BLOCK_SIZE + col] = b[row];
        }
    }
}

// Compress an 8x8 image block using JPEG compression
void compress_block(byte *block, byte *output) {
    double pixel, block_data[BLOCK_SIZE * BLOCK_SIZE];
    int index = 0;

    // Convert 8x8 block from pixel values to double precision
    for (int row = 0; row < BLOCK_SIZE; row++) {
        for (int col = 0; col < BLOCK_SIZE; col++) {
            pixel = *(block + row * IMAGE_WIDTH + col);
            block_data[index++] = (double) pixel;
        }
    }

    // Calculate discrete cosine transform (DCT) of 8x8 block
    dct(block_data);

    // Quantize DCT coefficients based on JPEG standard quantization table
    const int quantizer[BLOCK_SIZE][BLOCK_SIZE] = {
        {16, 11, 10, 16, 24, 40, 51, 61},
        {12, 12, 14, 19, 26, 58, 60, 55},
        {14, 13, 16, 24, 40, 57, 69, 56},
        {14, 17, 22, 29, 51, 87, 80, 62},
        {18, 22, 37, 56, 68, 109, 103, 77},
        {24, 35, 55, 64, 81, 104, 113, 92},
        {49, 64, 78, 87, 103, 121, 120, 101},
        {72, 92, 95, 98, 112, 100, 103, 99}
    };

    for (int row = 0; row < BLOCK_SIZE; row++) {
        for (int col = 0; col < BLOCK_SIZE; col++) {
            *(output + row * BLOCK_SIZE + col) = (byte) round(block_data[row * BLOCK_SIZE + col] / quantizer[row][col]);
        }
    }
}

// Compress an entire image using JPEG compression
void compress_image(byte *image, byte *output) {
    byte block_data[BLOCK_SIZE * BLOCK_SIZE], output_block[BLOCK_SIZE * BLOCK_SIZE];
    int num_blocks_x = IMAGE_WIDTH / BLOCK_SIZE;
    int num_blocks_y = IMAGE_HEIGHT / BLOCK_SIZE;

    for (int block_y = 0; block_y < num_blocks_y; block_y++) {
        for (int block_x = 0; block_x < num_blocks_x; block_x++) {
            // Extract 8x8 block from image
            for (int row = 0; row < BLOCK_SIZE; row++) {
                for (int col = 0; col < BLOCK_SIZE; col++) {
                    block_data[row * BLOCK_SIZE + col] = *(image + (block_y * BLOCK_SIZE + row) * IMAGE_WIDTH + block_x * BLOCK_SIZE + col);
                }
            }

            // Compress 8x8 block and write to output buffer
            compress_block(block_data, output_block);
            for (int row = 0; row < BLOCK_SIZE; row++) {
                for (int col = 0; col < BLOCK_SIZE; col++) {
                    *(output + (block_y * BLOCK_SIZE + row) * IMAGE_WIDTH + block_x * BLOCK_SIZE + col) = output_block[row * BLOCK_SIZE + col];
                }
            }
        }
    }
}

int main() {
    byte *image = (byte*) malloc(IMAGE_WIDTH * IMAGE_HEIGHT);
    byte *compressed_image = (byte*) malloc(IMAGE_WIDTH * IMAGE_HEIGHT);

    // Load image data from file or generate random image
    FILE *file = fopen("image.bin", "rb");
    if (file != NULL) {
        fread(image, sizeof(byte), IMAGE_WIDTH * IMAGE_HEIGHT, file);
        fclose(file);
    } else {
        for (int y = 0; y < IMAGE_HEIGHT; y++) {
            for (int x = 0; x < IMAGE_WIDTH; x++) {
                *(image + y * IMAGE_WIDTH + x) = rand() % 255;
            }
        }
    }

    // Compress image using JPEG compression
    compress_image(image, compressed_image);

    // Save compressed image data to file
    file = fopen("compressed_image.bin", "wb");
    fwrite(compressed_image, sizeof(byte), IMAGE_WIDTH * IMAGE_HEIGHT, file);
    fclose(file);

    free(image);
    free(compressed_image);
    return 0;
}