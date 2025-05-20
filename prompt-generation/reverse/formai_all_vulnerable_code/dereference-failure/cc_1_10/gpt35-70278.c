//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define BITS_PER_BYTE 8

// function prototypes
unsigned char *read_file(const char *filename, size_t *size);
int write_file(const char *filename, unsigned char *data, size_t size);
void print_binary(unsigned char byte);
void print_buffer(unsigned char *buffer, size_t size);
void compress(unsigned char *input, size_t size, unsigned char *output, size_t *compressed_size);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s [input file] [output file]\n", argv[0]);
        exit(1);
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    printf("Reading input file: %s\n", input_file);

    size_t input_size;
    unsigned char *input_data = read_file(input_file, &input_size);

    printf("Input size: %zu bytes\n", input_size);

    size_t compressed_size = input_size + (input_size / BITS_PER_BYTE) + 1; // upper bound on compressed size
    unsigned char *compressed_data = malloc(compressed_size);

    printf("Compressing data...\n");

    compress(input_data, input_size, compressed_data, &compressed_size);

    printf("Compressed size: %zu bytes\n", compressed_size);

    printf("Writing output file: %s\n", output_file);

    write_file(output_file, compressed_data, compressed_size);

    free(input_data);
    free(compressed_data);

    return 0;
}

/**
 * Reads a file and returns a buffer containing the contents of the file.
 * The size of the buffer is also returned via the size parameter.
 *
 * Returns NULL if there was an error reading the file.
 *
 * The returned buffer must be freed by the caller.
 */
unsigned char *read_file(const char *filename, size_t *size) {
    FILE *fp;
    unsigned char *buffer;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        return NULL;
    }

    // get file size
    fseek(fp, 0L, SEEK_END);
    *size = ftell(fp);
    rewind(fp);

    buffer = malloc(*size);
    if (buffer == NULL) {
        printf("Error: unable to allocate buffer for file %s\n", filename);
        fclose(fp);
        return NULL;
    }

    size_t bytes_read = fread(buffer, 1, *size, fp);
    if (bytes_read != *size) {
        printf("Error: unable to read file %s\n", filename);
        fclose(fp);
        free(buffer);
        return NULL;
    }

    fclose(fp);

    return buffer;
}

/**
 * Writes data to a file.
 *
 * Returns 0 on success, non-zero on error.
 */
int write_file(const char *filename, unsigned char *data, size_t size) {
    FILE *fp;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: unable to open file %s for writing\n", filename);
        return 1;
    }

    size_t bytes_written = fwrite(data, 1, size, fp);
    if (bytes_written != size) {
        printf("Error: unable to write full output to file %s\n", filename);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    return 0;
}

/**
 * Prints the binary representation of a byte to stdout.
 */
void print_binary(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
}

/**
 * Prints a buffer in hexadecimal and binary formats.
 */
void print_buffer(unsigned char *buffer, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%02x ", buffer[i]);
    }
    printf("\n");

    for (int i = 0; i < size; i++) {
        print_binary(buffer[i]);
        printf(" ");
    }
    printf("\n");
}

/**
 * Compresses data using a custom compression algorithm.
 *
 * The compressed data is returned in the output buffer, and its size is returned via the compressed_size parameter.
 */
void compress(unsigned char *input, size_t size, unsigned char *output, size_t *compressed_size) {
    unsigned char *output_start = output;
    unsigned char bit_count = 0;
    unsigned char current_byte = 0;

    // iterate over input bytes
    for (int i = 0; i < size; i++) {
        unsigned char byte = input[i];

        // check if byte is a repetition of previous byte
        if (i > 0 && byte == input[i - 1]) {
            // output repeating byte flag
            current_byte |= 1 << bit_count;
        } else {
            // output byte
            current_byte |= byte << bit_count;
            bit_count += BITS_PER_BYTE;
        }

        // check if current byte is full
        if (bit_count == BITS_PER_BYTE) {
            *output++ = current_byte;
            current_byte = 0;
            bit_count = 0;
        }
    }

    // output last byte (if needed)
    if (bit_count != 0) {
        *output++ = current_byte;
    }

    *compressed_size = output - output_start;
}