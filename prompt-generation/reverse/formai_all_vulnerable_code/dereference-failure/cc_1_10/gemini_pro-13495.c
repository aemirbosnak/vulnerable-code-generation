//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures
typedef struct {
    char *data;
    int size;
} Buffer;

// Function Declarations
Buffer *create_buffer(int size);
void destroy_buffer(Buffer *buffer);
Buffer *compress(Buffer *buffer);
Buffer *decompress(Buffer *buffer);

// Main Function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a random buffer of data
    Buffer *buffer = create_buffer(1024);
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] = (char) (rand() % 256);
    }

    // Compress the buffer
    Buffer *compressed_buffer = compress(buffer);

    // Decompress the compressed buffer
    Buffer *decompressed_buffer = decompress(compressed_buffer);

    // Compare the original and decompressed buffers
    if (memcmp(buffer->data, decompressed_buffer->data, buffer->size) == 0) {
        printf("Compression and decompression successful!\n");
    } else {
        printf("Compression or decompression failed!\n");
    }

    // Destroy the buffers
    destroy_buffer(buffer);
    destroy_buffer(compressed_buffer);
    destroy_buffer(decompressed_buffer);

    return 0;
}

// Function Definitions
Buffer *create_buffer(int size) {
    Buffer *buffer = malloc(sizeof(Buffer));
    buffer->data = malloc(size);
    buffer->size = size;
    return buffer;
}

void destroy_buffer(Buffer *buffer) {
    free(buffer->data);
    free(buffer);
}

Buffer *compress(Buffer *buffer) {
    // Create a compressed buffer
    Buffer *compressed_buffer = create_buffer(buffer->size);

    // Compress the data
    int compressed_size = 0;
    for (int i = 0; i < buffer->size;) {
        // Find the length of the current run
        int run_length = 1;
        while (i + run_length < buffer->size && buffer->data[i] == buffer->data[i + run_length]) {
            run_length++;
        }

        // Compress the run
        if (run_length > 2) {
            compressed_buffer->data[compressed_size++] = run_length - 1;
        } else {
            for (int j = 0; j < run_length; j++) {
                compressed_buffer->data[compressed_size++] = buffer->data[i++];
            }
        }
    }

    // Set the compressed buffer size
    compressed_buffer->size = compressed_size;

    return compressed_buffer;
}

Buffer *decompress(Buffer *buffer) {
    // Create a decompressed buffer
    Buffer *decompressed_buffer = create_buffer(buffer->size * 2);

    // Decompress the data
    int decompressed_size = 0;
    for (int i = 0; i < buffer->size;) {
        // Is this a run?
        if (buffer->data[i] >= 2) {
            // Decompress the run
            for (int j = 0; j < buffer->data[i] + 1; j++) {
                decompressed_buffer->data[decompressed_size++] = buffer->data[i + 1];
            }
            i += 2;
        } else {
            // Decompress the single character
            decompressed_buffer->data[decompressed_size++] = buffer->data[i++];
        }
    }

    // Set the decompressed buffer size
    decompressed_buffer->size = decompressed_size;

    return decompressed_buffer;
}