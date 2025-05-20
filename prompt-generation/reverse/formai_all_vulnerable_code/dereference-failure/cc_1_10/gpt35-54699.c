//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Implementation of Ken Thompson's compression algorithm */

#define BUFFER_SIZE 8   // Buffer size for reading in bytes

/* Function to compress the data */
void compress_file(FILE *src, FILE *dst)
{
    uint8_t buffer[BUFFER_SIZE];   // Buffer to hold input data
    uint8_t last_byte = 0;         // Last byte read
    int count = 0;                 // Count of consecutive bytes
    
    while (!feof(src)) {
        /* Read in a buffer of data from source */
        size_t bytes_read = fread(buffer, sizeof(uint8_t), BUFFER_SIZE, src);
        
        /* Check for error */
        if (ferror(src)) {
            perror("Error reading from source file");
            exit(EXIT_FAILURE);
        }
        
        /* Compress the data */
        for (size_t i = 0; i < bytes_read; i++) {
            /* Check if this byte matches the last byte */
            if (buffer[i] == last_byte) {
                /* Increment count */
                count++;
                
                /* Check if we have a run of 255 consecutive bytes */
                if (count == 255) {
                    /* Output compressed data */
                    fputc(last_byte, dst);
                    fputc(count, dst);
                    
                    /* Reset count */
                    count = 0;
                }
            } else {
                /* Output compressed data for previous run, if any */
                if (count) {
                    fputc(last_byte, dst);
                    fputc(count, dst);
                    count = 0;
                }
                
                /* Write out the current byte */
                fputc(buffer[i], dst);
                
                /* Update last byte */
                last_byte = buffer[i];
            }
        }
    }
    
    /* Output any remaining data */
    if (count) {
        fputc(last_byte, dst);
        fputc(count, dst);
    }
}

/* Function to decompress the data */
void decompress_file(FILE *src, FILE *dst)
{
    while (!feof(src)) {
        /* Read in the compressed data */
        uint8_t byte = fgetc(src);
        uint8_t count = fgetc(src);
        
        /* Check for error */
        if (ferror(src)) {
            perror("Error reading from source file");
            exit(EXIT_FAILURE);
        }
        
        /* Output the decompressed data */
        for (int i = 0; i < count; i++) {
            fputc(byte, dst);
        }
    }
}

int main(int argc, char *argv[])
{
    /* Check command line arguments */
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <compress|decompress> <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    /* Open input file */
    FILE *src = fopen(argv[2], "rb");
    if (!src) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    
    /* Open output file */
    FILE *dst = fopen(argv[3], "wb");
    if (!dst) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }
    
    /* Compress or decompress the data */
    if (strcmp(argv[1], "compress") == 0) {
        compress_file(src, dst);
    } else if (strcmp(argv[1], "decompress") == 0) {
        decompress_file(src, dst);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    /* Close files */
    fclose(src);
    fclose(dst);
    
    return 0;
}