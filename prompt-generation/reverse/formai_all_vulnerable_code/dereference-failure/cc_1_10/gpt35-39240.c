//FormAI DATASET v1.0 Category: Image compression ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform RLE compression on given image data
void RLE_Compress(unsigned char *source, int size, unsigned char *dest, int max_size) {
    int count;
    unsigned char value;

    int i, j;
    for (i = 0, j = 0; i < size && j < max_size; i++) {
        value = source[i];
        count = 1;
        while (i + count < size && source[i + count] == value && count < 255)
            count++;

        dest[j++] = count;
        dest[j++] = value;
        i += count - 1;
    }
}

// Function to perform RLE decompression on given compressed image data
void RLE_Decompress(unsigned char *source, int size, unsigned char *dest, int max_size) {
    int count;
    unsigned char value;

    int i, j;
    for (i = 0, j = 0; i < size && j < max_size; i += 2) {
        count = source[i];
        value = source[i + 1];
        while (count-- > 0 && j < max_size)
            dest[j++] = value;
    }
}

int main(int argc, char *argv[]) {
    unsigned char *image_data = NULL;
    unsigned char *compressed_data = NULL;
    unsigned char *decompressed_data = NULL;

    int image_size, compressed_size, decompressed_size;

    // Load image data from file or somewhere
    // ...

    // Compress the image data using RLE
    compressed_data = (unsigned char *) malloc(image_size);
    RLE_Compress(image_data, image_size, compressed_data, image_size);

    // Save the compressed data to a file or send over network
    // ...

    // Decompress the compressed data using RLE
    decompressed_data = (unsigned char *) malloc(image_size);
    RLE_Decompress(compressed_data, compressed_size, decompressed_data, image_size);

    // Verify if the decompressed data matches with original image data
    if (memcmp(image_data, decompressed_data, image_size) == 0) {
        printf("RLE Compression success! Image data is compressed and decompressed successfully.\n");
    } else {
        printf("RLE Compression failed! Image data is not compressed and decompressed correctly.\n");
    }

    // Free allocated memory
    free(image_data);
    free(compressed_data);
    free(decompressed_data);

    return 0;
}