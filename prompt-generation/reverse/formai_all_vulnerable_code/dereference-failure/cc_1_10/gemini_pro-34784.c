//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    unsigned int size;
} compressed_data;

compressed_data *compress(unsigned char *data, unsigned int size) {
    compressed_data *compressed = malloc(sizeof(compressed_data));
    compressed->data = malloc(size);
    compressed->size = size;

    unsigned int i = 0, j = 0;
    while (i < size) {
        unsigned char byte = data[i];
        unsigned int count = 1;
        while (i + count < size && data[i + count] == byte) {
            count++;
        }
        compressed->data[j++] = byte;
        compressed->data[j++] = count;
        i += count;
    }

    compressed->size = j;
    return compressed;
}

unsigned char *decompress(compressed_data *compressed) {
    unsigned char *decompressed = malloc(compressed->size);
    unsigned int i = 0, j = 0;
    while (i < compressed->size) {
        unsigned char byte = compressed->data[i++];
        unsigned int count = compressed->data[i++];
        while (count--) {
            decompressed[j++] = byte;
        }
    }

    return decompressed;
}

int main() {
    unsigned char *data = "Hello, world!";
    unsigned int size = strlen(data);

    compressed_data *compressed = compress(data, size);
    unsigned char *decompressed = decompress(compressed);

    printf("%s\n", decompressed);

    free(compressed->data);
    free(compressed);
    free(decompressed);

    return 0;
}