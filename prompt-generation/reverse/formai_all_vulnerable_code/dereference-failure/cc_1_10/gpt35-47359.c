//FormAI DATASET v1.0 Category: Compression algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024   // Maximum size of the input file
#define CHAR_BIT 8      // Number of bits in a byte

int main(int argc, char **argv) {

    FILE *in_file, *out_file;   // Input and output file pointers
    char in_buf[MAX_SIZE];      // Buffer for the input data
    char out_buf[MAX_SIZE];     // Buffer for the output data
    size_t in_size, bit_pos, out_pos;
    unsigned char byte, mask;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    in_file = fopen(argv[1], "rb");
    if (!in_file) {
        fprintf(stderr, "Error opening input file '%s'\n", argv[1]);
        return 1;
    }

    out_file = fopen(argv[2], "wb");
    if (!out_file) {
        fprintf(stderr, "Error opening output file '%s'\n", argv[2]);
        return 1;
    }

    // Read input data into the buffer
    in_size = fread(in_buf, 1, MAX_SIZE, in_file);

    // Compress the data by replacing consecutive identical bytes with a marker
    out_pos = 0;
    for (size_t i = 0; i < in_size; i++) {
        if (in_buf[i] == out_buf[out_pos - 1]) {
            out_buf[out_pos - 1] = 0xFF;
        } else {
            out_buf[out_pos++] = in_buf[i];
        }
    }

    // Write the compressed data to the output file
    fwrite(out_buf, 1, out_pos, out_file);

    // Write the header to the output file
    byte = out_pos % CHAR_BIT;
    fwrite(&byte, 1, 1, out_file);

    bit_pos = 0;
    byte = 0;
    mask = 0x80;

    for (size_t i = 0; i < out_pos; i++) {
        if (out_buf[i] == 0xFF) {
            byte |= mask;
        }
        mask >>= 1;
        bit_pos++;
        if (bit_pos == CHAR_BIT) {
            fwrite(&byte, 1, 1, out_file);
            byte = 0;
            mask = 0x80;
            bit_pos = 0;
        }
    }

    // Clean up and exit
    fclose(in_file);
    fclose(out_file);
    return 0;
}