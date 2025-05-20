//FormAI DATASET v1.0 Category: Compression algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define CHUNK_SIZE 1024

int compress(char* original, char* compressed);

int main()
{
    char* original = "Hello, world!";
    char* compressed = (char*)malloc(strlen(original) * sizeof(char));
    int size = compress(original, compressed);

    printf("Original size: %lu\n", strlen(original));
    printf("Compressed size: %d\n", size);

    return 0;
}

int compress(char* original, char* compressed)
{
    int original_size = strlen(original);
    int chunk_size, num_chunks;

    if(original_size < CHUNK_SIZE) {
        chunk_size = original_size;
        num_chunks = 1;
    } else {
        // Divide original into chunks of CHUNK_SIZE
        chunk_size = CHUNK_SIZE;
        num_chunks = ceil(original_size / (float)CHUNK_SIZE);
    }

    int* chunk_sizes = (int*)calloc(num_chunks, sizeof(int));
    char** chunks = (char**)malloc(num_chunks * sizeof(char*));

    // Divide original into chunks
    int i, j, k;
    for(i = 0, k = 0; i < num_chunks; i++, k += chunk_size) {
        if(i == num_chunks - 1) {
            chunk_size = original_size - k;
        }
        chunks[i] = (char*)malloc(chunk_size * sizeof(char));
        memcpy(chunks[i], &original[k], chunk_size * sizeof(char));
        chunk_sizes[i] = chunk_size;
    }

    // Compress each chunk with RLE
    int compressed_size = 0;
    for(i = 0; i < num_chunks; i++) {
        char* chunk = chunks[i];
        int size = chunk_sizes[i];
        char curr_char = chunk[0];
        int count = 1;

        for(j = 1; j < size; j++) {
            if(chunk[j] == curr_char) {
                count++;
            } else {
                // Write compressed data to compressed array
                compressed[compressed_size++] = curr_char;
                compressed[compressed_size++] = count;
                curr_char = chunk[j];
                count = 1;
            }
        }

        // Write final compressed data to compressed array
        compressed[compressed_size++] = curr_char;
        compressed[compressed_size++] = count;
    }

    // Free dynamically allocated memory
    for(i = 0; i < num_chunks; i++) {
        free(chunks[i]);
    }
    free(chunks);
    free(chunk_sizes);

    return compressed_size;
}