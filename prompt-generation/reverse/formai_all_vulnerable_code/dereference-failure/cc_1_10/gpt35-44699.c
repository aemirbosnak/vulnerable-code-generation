//FormAI DATASET v1.0 Category: Image compression ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16 // size of each block in pixels

// Helper function to read in an image file
unsigned char* read_image(char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file: %s\n", filename);
        return NULL;
    }

    // Read in header data (assuming 8-bit grayscale bmp)
    unsigned char header[54];
    fread(&header, sizeof(unsigned char), 54, file);
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];
    int data_size = *(int*)&header[34];

    unsigned char* image = malloc(data_size);
    if (image == NULL) {
        printf("Error: could not allocate memory for image\n");
        return NULL;
    }

    // Read in image data
    fseek(file, 54, SEEK_SET);
    fread(image, sizeof(unsigned char), data_size, file);

    fclose(file);
    return image;
}

// Helper function to write out an image file
void write_image(char* filename, unsigned char* image, int width, int height) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: could not open file: %s\n", filename);
        return;
    }

    // Write out header data (assuming 8-bit grayscale bmp)
    unsigned char header[54] = {
        'B','M',
        0,0,0,0, // file size filled in later
        0,0,0,0,
        54,0,0,0,
        40,0,0,0,
        0,0,0,0, // width filled in later
        0,0,0,0, // height filled in later
        1,0,
        8,0,
        0,0,0,0,
        0,0,0,0,
        0,0,0,0,
        0,0,0,0,
        0,0,0,0
    };
    *(int*)&header[2] = 54 + width * height;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    fwrite(&header, sizeof(unsigned char), 54, file);

    // Write out image data
    fwrite(image, sizeof(unsigned char), width * height, file);

    fclose(file);
}

// Helper function to compress a single block of pixels with run-length encoding
int compress_block(unsigned char* in, int in_size, unsigned char* out) {
    int i = 0, j = 0;
    while (i < in_size) {
        int count = 1;
        while (i < in_size - 1 && in[i] == in[i+1] && count < 127) {
            count++;
            i++;
        }
        out[j++] = count;
        out[j++] = in[i];
        i++;
    }
    return j;
}

// Helper function to decompress a single block of pixels with run-length encoding
int decompress_block(unsigned char* in, int in_size, unsigned char* out) {
    int i = 0, j = 0;
    while (i < in_size) {
        int count = in[i++];
        int value = in[i++];
        for (int k = 0; k < count; k++) {
            out[j++] = value;
        }
    }
    return j;
}

// Main function to compress an image with run-length encoding
void compress_image(char* in_filename, char* out_filename) {
    int width, height;
    unsigned char* in = read_image(in_filename, &width, &height);
    if (in == NULL) {
        return;
    }

    // Create output buffer
    int num_blocks = (width * height + BLOCK_SIZE - 1) / BLOCK_SIZE;
    unsigned char* out = malloc(num_blocks * (BLOCK_SIZE + 1));
    if (out == NULL) {
        printf("Error: could not allocate memory for output buffer\n");
        return;
    }

    // Compress each block
    int out_size = 0;
    for (int i = 0; i < width * height; i += BLOCK_SIZE) {
        unsigned char* block = &in[i];
        int block_size = BLOCK_SIZE;
        if (i + BLOCK_SIZE > width * height) {
            block_size = width * height - i;
        }
        out_size += compress_block(block, block_size, &out[out_size]);
    }

    // Write out compressed image
    write_image(out_filename, out, out_size, 1);

    free(in);
    free(out);
}

// Main function to decompress an image with run-length encoding
void decompress_image(char* in_filename, char* out_filename) {
    int width, height;
    unsigned char* in = read_image(in_filename, &width, &height);
    if (in == NULL) {
        return;
    }

    // Create output buffer
    int out_size = width * height;
    unsigned char* out = malloc(out_size);
    if (out == NULL) {
        printf("Error: could not allocate memory for output buffer\n");
        return;
    }

    // Decompress each block
    int in_idx = 0, out_idx = 0;
    while (in_idx < width * height) {
        int block_size = BLOCK_SIZE;
        if (in_idx + BLOCK_SIZE > width * height) {
            block_size = width * height - in_idx;
        }
        int out_block_size = decompress_block(&in[in_idx], block_size * 2, &out[out_idx]);
        in_idx += block_size * 2;
        out_idx += out_block_size;
    }

    // Write out decompressed image
    write_image(out_filename, out, width, height);

    free(in);
    free(out);
}

int main() {
    // Compress the image
    compress_image("input.bmp", "compressed.bmp");

    // Decompress the image
    decompress_image("compressed.bmp", "output.bmp");

    return 0;
}