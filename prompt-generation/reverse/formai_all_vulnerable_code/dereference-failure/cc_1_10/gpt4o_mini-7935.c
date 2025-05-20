//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_CHUNK_SIZE 1024
#define VERSION "1.0"
#define AUTHOR "Neo-Cyber Compression"

void printBanner() {
    printf("========================================\n");
    printf("        Cyberpunk Data Compression        \n");
    printf("          Version: %s                   \n", VERSION);
    printf("          Author: %s                     \n", AUTHOR);
    printf("========================================\n");
}

typedef struct {
    unsigned char *data;
    size_t size;
} CompressedData;

CompressedData compress(const char *input) {
    size_t input_length = strlen(input);
    CompressedData compressed;
    compressed.data = malloc(input_length * 2); // Maximum possible size-wise.
    if (!compressed.data) {
        fprintf(stderr, "Memory allocation failed during compression!\n");
        exit(EXIT_FAILURE);
    }
    
    size_t count = 1;
    size_t compressed_index = 0;
    
    for (size_t i = 0; i < input_length; i++) {
        if (i + 1 < input_length && input[i] == input[i + 1]) {
            count++;
        } else {
            compressed.data[compressed_index++] = input[i];
            compressed.data[compressed_index++] = count;
            count = 1;  // Reset the count
        }
    }
    compressed.size = compressed_index;
    return compressed;
}

char* decompress(const CompressedData *cdata) {
    char *decompressed = malloc(MAX_CHUNK_SIZE); // Assuming decompressed data won't exceed this size.
    if (!decompressed) {
        fprintf(stderr, "Memory allocation failed during decompression!\n");
        exit(EXIT_FAILURE);
    }
    
    size_t decompressed_index = 0;
    
    for (size_t i = 0; i < cdata->size; i += 2) {
        unsigned char value = cdata->data[i + 1];
        for (unsigned char j = 0; j < value; j++) {
            if (decompressed_index >= MAX_CHUNK_SIZE - 1) {
                fprintf(stderr, "Decompressed data exceeded allocated size!\n");
                exit(EXIT_FAILURE);
            }
            decompressed[decompressed_index++] = cdata->data[i];
        }
    }
    decompressed[decompressed_index] = '\0'; // Null-terminate the string
    return decompressed;
}

void cleanup(CompressedData *cdata) {
    free(cdata->data);
}

int main(int argc, char *argv[]) {
    printBanner();
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text_to_compress>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *text_to_compress = argv[1];
    printf("Original Text: %s\n", text_to_compress);
    
    CompressedData compressed = compress(text_to_compress);
    printf("Compressed Size: %zu bytes\n", compressed.size);
    
    char *decompressed = decompress(&compressed);
    printf("Decompressed Text: %s\n", decompressed);
    
    cleanup(&compressed);
    free(decompressed);
    
    return EXIT_SUCCESS;
}