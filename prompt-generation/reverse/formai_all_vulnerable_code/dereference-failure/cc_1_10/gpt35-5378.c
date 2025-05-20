//FormAI DATASET v1.0 Category: Compression algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This compression algorithm reads in a file and compresses it using the following technique:
 * For every sequence of identical bytes found, record the byte and the length of the sequence.
 */

typedef struct {
    unsigned char byte;
    unsigned short length;
} compressed_t;

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    FILE *fptr = fopen(filename, "rb");

    if (fptr == NULL) {
        printf("Error: Unable to open file '%s' for reading.\n", filename);
        exit(EXIT_FAILURE);
    }

    // Get file size
    fseek(fptr, 0, SEEK_END);
    long file_length = ftell(fptr);
    rewind(fptr);

    // Read in file
    unsigned char *original_data = (unsigned char *)malloc(file_length * sizeof(unsigned char));
    fread(original_data, sizeof(unsigned char), file_length, fptr);

    // Compress data
    compressed_t *compressed_data = (compressed_t *)malloc(file_length * sizeof(compressed_t));
    unsigned int compressed_count = 0;

    unsigned char current_byte = original_data[0];
    unsigned short current_length = 1;
    for (unsigned int i = 1; i < file_length; i++) {
        if (original_data[i] == current_byte) {
            current_length++;
        } else {
            compressed_data[compressed_count].byte = current_byte;
            compressed_data[compressed_count].length = current_length;
            compressed_count++;

            current_byte = original_data[i];
            current_length = 1;
        }
    }

    compressed_data[compressed_count].byte = current_byte;
    compressed_data[compressed_count].length = current_length;
    compressed_count++;

    // Save compressed file
    FILE *output_fptr = fopen("compressed.bin", "wb");
    for (unsigned int i = 0; i < compressed_count; i++) {
        fwrite(&(compressed_data[i].byte), sizeof(unsigned char), 1, output_fptr);
        fwrite(&(compressed_data[i].length), sizeof(unsigned short), 1, output_fptr);
    }
    fclose(output_fptr);

    // Print compression ratio
    printf("Original file size: %ld bytes\n", file_length);
    printf("Compressed file size: %u bytes\n", compressed_count * (sizeof(unsigned char) + sizeof(unsigned short)));

    // Free memory
    free(original_data);
    free(compressed_data);

    return 0;
}