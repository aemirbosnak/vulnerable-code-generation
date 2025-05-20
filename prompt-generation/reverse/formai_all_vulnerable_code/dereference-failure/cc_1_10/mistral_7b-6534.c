//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BLOCK_SIZE 1024
#define ALPHABET_SIZE 256

typedef struct {
    unsigned char data[BLOCK_SIZE];
    unsigned char compressed[BLOCK_SIZE];
    unsigned char prev_byte;
    unsigned int freq[ALPHABET_SIZE];
} block;

void init_freq(block *b) {
    memset(b->freq, 0, ALPHABET_SIZE * sizeof(unsigned int));
    b->prev_byte = 0;
}

void compress_block(block *b) {
    unsigned int len = 0, pos = 0, code = 0;
    init_freq(b);

    for (int i = 0; i < BLOCK_SIZE; i++) {
        b->freq[(unsigned char)b->data[i]]++;
        if (b->prev_byte && (b->data[i] == b->prev_byte)) {
            len++;
            continue;
        }

        pos = (len > code ? len : code) + 1;
        code = (code << 1) | ((len > code) ? 1 : 0) | (unsigned int)b->data[i];

        b->compressed[i] = (unsigned char)(pos >> 1);
        b->prev_byte = b->data[i];
    }

    len = (code << (8 - (int)log2((double)pos))) | ((unsigned char)pos);
    b->compressed[BLOCK_SIZE - 1] = len;
}

size_t compress(const void *src, void *dst, size_t size) {
    block *b = malloc(sizeof(block));
    size_t bytes_written = 0;

    while (size > 0) {
        if (size < BLOCK_SIZE)
            size = BLOCK_SIZE;

        memcpy(b->data, src, size);
        compress_block(b);

        memcpy(dst, b->compressed, BLOCK_SIZE);
        dst = (void *)((char *)dst + BLOCK_SIZE);
        src += size;
        size -= size;
        bytes_written += BLOCK_SIZE;
    }

    free(b);
    return bytes_written;
}

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog.";
    char *compressed = NULL;
    size_t size = sizeof(text);

    printf("Original size: %ld bytes\n", size);

    compressed = malloc(size + 1);

    size_t compressed_size = compress(text, compressed, size);

    printf("Compressed size: %ld bytes\n", compressed_size);

    printf("Compressed data:\n");
    for (size_t i = 0; i < compressed_size; i++)
        printf("%02X ", compressed[i]);

    printf("\nDecompression is left as an exercise for the reader.\n");

    free(compressed);
    return 0;
}