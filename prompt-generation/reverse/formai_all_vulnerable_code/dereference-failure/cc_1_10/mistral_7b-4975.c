//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: ephemeral
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    char data;
    char count;
} RLE_COMPRESSED_DATA;
#pragma pack(pop)

void compress(const unsigned char* input, unsigned char* output, size_t size) {
    size_t index_input = 0;
    size_t index_output = 0;
    RLE_COMPRESSED_DATA compressed_data;

    while (index_input < size) {
        compressed_data.data = input[index_input];
        size_t current_count = 1;

        while (++index_input < size && input[index_input] == compressed_data.data) {
            current_count++;
        }

        compressed_data.count = current_count;
        output[index_output++] = compressed_data.data;
        output[index_output++] = compressed_data.count;
    }
}

void decompress(const unsigned char* input, unsigned char* output, size_t size) {
    size_t index_input = 0;
    size_t index_output = 0;
    RLE_COMPRESSED_DATA compressed_data;

    while (index_input < size && index_output < size) {
        compressed_data.data = input[index_input++];
        compressed_data.count = input[index_input++];

        size_t current_index = index_output;
        for (size_t i = 0; i < compressed_data.count; i++) {
            output[current_index++] = compressed_data.data;
        }
    }
}

int main(void) {
    const unsigned char original[] = { 'A', 'A', 'B', 'B', 'B', 'B', 'C', 'C', 'C' };
    size_t original_size = sizeof(original) / sizeof(original[0]);

    unsigned char compressed[original_size * 2];
    compress(original, compressed, original_size);

    printf("Original size: %zu bytes\n", original_size);
    printf("Compressed size: %zu bytes\n", (size_t) ((size_t) original_size * 2));

    unsigned char decompressed[original_size];
    decompress(compressed, decompressed, original_size * 2);

    size_t i;
    for (i = 0; i < original_size; i++) {
        if (original[i] != decompressed[i]) {
            printf("Decompression failed!\n");
            break;
        }
    }

    if (i == original_size) {
        printf("Decompression successful!\n");
    }

    free(compressed);
    return 0;
}