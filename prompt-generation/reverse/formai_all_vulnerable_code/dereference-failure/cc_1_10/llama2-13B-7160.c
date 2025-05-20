//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: detailed
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    uint32_t value;
    uint32_t reference;
} self_ref_t;

self_ref_t *create_self_ref(uint32_t value) {
    self_ref_t *ref = (self_ref_t *)calloc(1, sizeof(self_ref_t));
    ref->value = value;
    ref->reference = 0;
    return ref;
}

void free_self_ref(self_ref_t *ref) {
    free(ref);
}

size_t compress(const uint8_t *data, size_t size, uint8_t *compressed) {
    size_t compressed_size = 0;
    self_ref_t *ref_table = (self_ref_t *)calloc(size, sizeof(self_ref_t));

    for (size_t i = 0; i < size; i++) {
        uint32_t current = data[i];
        if (current == 0) {
            // Special case for zero values, as they can be represented as a reference to the previous value
            ref_table[i].value = data[i - 1];
            ref_table[i].reference = i - 1;
        } else {
            // Calculate the reference for the current value
            uint32_t j = i - 1;
            while (j > 0 && data[j] == 0) {
                j--;
            }
            ref_table[i].value = data[j];
            ref_table[i].reference = j;
        }
    }

    // Compress the reference table
    for (size_t i = 0; i < size; i++) {
        compressed_size += snprintf(compressed + compressed_size, BUFFER_SIZE - compressed_size, "%u", ref_table[i].reference);
    }

    // Free the reference table
    free(ref_table);

    return compressed_size;
}

size_t decompress(const uint8_t *compressed, size_t size, uint8_t *data) {
    size_t data_size = 0;
    self_ref_t *ref_table = (self_ref_t *)calloc(size, sizeof(self_ref_t));

    for (size_t i = 0; i < size; i++) {
        uint32_t ref = strtoul(compressed + i * 3, NULL, 10);
        ref_table[i].reference = ref;
        data_size += ref_table[i].value = data[ref];
    }

    // Free the reference table
    free(ref_table);

    return data_size;
}

int main() {
    uint8_t data[] = {1, 2, 0, 3, 0, 4, 0, 5, 0, 6};
    size_t compressed_size = compress(data, 8, NULL);
    uint8_t compressed[compressed_size];
    compress(data, 8, compressed);

    size_t decompressed_size = decompress(compressed, compressed_size, NULL);
    uint8_t decompressed[decompressed_size];
    decompress(compressed, compressed_size, decompressed);

    printf("Original data: ");
    for (size_t i = 0; i < 8; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("Compressed data: ");
    for (size_t i = 0; i < compressed_size; i++) {
        printf("%d ", compressed[i]);
    }
    printf("\n");

    printf("Decompressed data: ");
    for (size_t i = 0; i < decompressed_size; i++) {
        printf("%d ", decompressed[i]);
    }
    printf("\n");

    return 0;
}