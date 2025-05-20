//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t *data;
    size_t size;
} buffer_t;

static size_t file_size(FILE *file) {
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

static buffer_t *load_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    size_t size = file_size(file);
    buffer_t *buffer = malloc(sizeof(buffer_t));
    if (buffer == NULL) {
        fclose(file);
        return NULL;
    }

    buffer->data = malloc(size);
    if (buffer->data == NULL) {
        fclose(file);
        free(buffer);
        return NULL;
    }

    buffer->size = size;
    fread(buffer->data, sizeof(uint8_t), size, file);
    fclose(file);

    return buffer;
}

static void free_buffer(buffer_t *buffer) {
    if (buffer == NULL) {
        return;
    }

    free(buffer->data);
    free(buffer);
}

static uint8_t *compress(const uint8_t *data, size_t size, size_t *compressed_size) {
    // Create a new buffer for the compressed data.
    uint8_t *compressed_data = malloc(size);
    if (compressed_data == NULL) {
        return NULL;
    }

    // Create a pointer to the current position in the compressed data.
    uint8_t *compressed_ptr = compressed_data;

    // Iterate over the input data.
    const uint8_t *data_ptr = data;
    while (data_ptr < data + size) {
        // Find the longest run of identical bytes.
        size_t run_length = 1;
        while (data_ptr + run_length < data + size &&
               *(data_ptr + run_length) == *data_ptr) {
            run_length++;
        }

        // Store the run length and the value of the byte.
        if (run_length <= 3) {
            *compressed_ptr++ = *data_ptr++;
        } else {
            *compressed_ptr++ = 0xFF;
            *compressed_ptr++ = run_length;
            *compressed_ptr++ = *data_ptr++;
        }
    }

    // Store the compressed size.
    *compressed_size = compressed_ptr - compressed_data;

    return compressed_data;
}

static uint8_t *decompress(const uint8_t *data, size_t size, size_t *decompressed_size) {
    // Create a new buffer for the decompressed data.
    uint8_t *decompressed_data = malloc(size);
    if (decompressed_data == NULL) {
        return NULL;
    }

    // Create a pointer to the current position in the decompressed data.
    uint8_t *decompressed_ptr = decompressed_data;

    // Iterate over the compressed data.
    const uint8_t *data_ptr = data;
    while (data_ptr < data + size) {
        // Check if the current byte is a run length.
        if (*data_ptr == 0xFF) {
            // Read the run length and the value of the byte.
            size_t run_length = *(data_ptr + 1);
            uint8_t value = *(data_ptr + 2);

            // Write the run of identical bytes to the decompressed data.
            for (size_t i = 0; i < run_length; i++) {
                *decompressed_ptr++ = value;
            }

            // Advance the pointer to the next byte in the compressed data.
            data_ptr += 3;
        } else {
            // Write the current byte to the decompressed data.
            *decompressed_ptr++ = *data_ptr++;
        }
    }

    // Store the decompressed size.
    *decompressed_size = decompressed_ptr - decompressed_data;

    return decompressed_data;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load the file into a buffer.
    buffer_t *buffer = load_file(argv[1]);
    if (buffer == NULL) {
        fprintf(stderr, "Error: Could not load file '%s'.\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Compress the data.
    size_t compressed_size;
    uint8_t *compressed_data = compress(buffer->data, buffer->size, &compressed_size);
    if (compressed_data == NULL) {
        fprintf(stderr, "Error: Could not compress data.\n");
        return EXIT_FAILURE;
    }

    // Print the compressed size.
    printf("Compressed size: %zu\n", compressed_size);

    // Decompress the data.
    size_t decompressed_size;
    uint8_t *decompressed_data = decompress(compressed_data, compressed_size, &decompressed_size);
    if (decompressed_data == NULL) {
        fprintf(stderr, "Error: Could not decompress data.\n");
        return EXIT_FAILURE;
    }

    // Check if the decompressed data matches the original data.
    if (memcmp(buffer->data, decompressed_data, buffer->size) != 0) {
        fprintf(stderr, "Error: Decompressed data does not match original data.\n");
        return EXIT_FAILURE;
    }

    // Free the buffers.
    free_buffer(buffer);
    free(compressed_data);
    free(decompressed_data);

    return EXIT_SUCCESS;
}