//FormAI DATASET v1.0 Category: Compression algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHUNK_SIZE 1024

char* compress(char* data, size_t size, size_t* out_size) {
    unsigned short freq[256] = { 0 };
    size_t i;
    for (i = 0; i < size; i++) {
        freq[(unsigned char)data[i]]++;
    }

    unsigned char* compressed_data = (unsigned char*)malloc(size);
    size_t offset = 0;
    for (i = 0; i < size; i++) {
        unsigned char c = data[i];
        if (!freq[c])
            continue;

        compressed_data[offset++] = c;
        compressed_data[offset++] = (unsigned char)freq[c];

        freq[c] = 0;
    }

    *out_size = offset;
    return (char*)compressed_data;
}

char* decompress(char* compressed_data, size_t size, size_t* out_size) {
    unsigned short freq[256] = { 0 };
    size_t i;
    for (i = 0; i < size; i += 2) {
        freq[(unsigned char)compressed_data[i]] = compressed_data[i+1];
    }

    unsigned char* data = (unsigned char*)malloc(size);
    size_t offset = 0;
    for (i = 0; i < size; i += 2) {
        unsigned char c = compressed_data[i];
        unsigned short f = freq[c];
        memset(&data[offset], c, f);
        offset += f;
    }

    *out_size = offset;
    return (char*)data;
}

int main() {
    char data[CHUNK_SIZE], * compressed_data, * decompressed_data;
    size_t data_size, compressed_size, decompressed_size;

    while ((data_size = fread(data, 1, CHUNK_SIZE, stdin)) > 0) {
        compressed_data = compress(data, data_size, &compressed_size);
        decompressed_data = decompress(compressed_data, compressed_size, &decompressed_size);

        printf("Original Size: %lu Bytes\n", data_size);
        printf("Compressed Size: %lu Bytes\n", compressed_size);
        printf("Decompressed Size: %lu Bytes\n", decompressed_size);

        free(compressed_data);
        free(decompressed_data);
    }

    return 0;
}