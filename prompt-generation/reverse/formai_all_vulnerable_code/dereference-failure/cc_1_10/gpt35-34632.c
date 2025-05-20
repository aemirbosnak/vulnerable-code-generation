//FormAI DATASET v1.0 Category: Compression algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 100

void compress_file(FILE* src, FILE* dest);
int compress_chunk(unsigned char* src, int size, unsigned char* dest);
void write_header(FILE* dest, int size);
int read_header(FILE* src);

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: compress <source> <destination>\n");
        return 1;
    }
    // Open source file for reading
    FILE* src = fopen(argv[1], "rb");
    if (src == NULL) {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
        return 1;
    }
    // Open destination file for writing
    FILE* dest = fopen(argv[2], "wb");
    if (dest == NULL) {
        fprintf(stderr, "Error: can't open file %s\n", argv[2]);
        return 1;
    }
    // Compress the file
    compress_file(src, dest);
    // Close files
    fclose(src);
    fclose(dest);
    return 0;
}

void compress_file(FILE* src, FILE* dest) {
    // Get size of source file
    fseek(src, 0L, SEEK_END);
    unsigned int size = ftell(src);
    fseek(src, 0L, SEEK_SET);
    // Write header to destination file
    write_header(dest, size);
    // Allocate memory for read buffer
    unsigned char* read_buf = (unsigned char*)malloc(CHUNK_SIZE * sizeof(unsigned char));
    // Allocate memory for compressed buffer
    unsigned char* comp_buf = (unsigned char*)malloc(CHUNK_SIZE * sizeof(unsigned char));
    // Read and compress chunks from source file
    int read_size, comp_size;
    while (size > 0) {
        // Determine size of next chunk
        read_size = (size > CHUNK_SIZE) ? CHUNK_SIZE : size;
        // Read chunk from source file
        fread(read_buf, sizeof(unsigned char), read_size, src);
        // Compress chunk
        comp_size = compress_chunk(read_buf, read_size, comp_buf);
        // Write compressed chunk to destination file
        fwrite(comp_buf, sizeof(unsigned char), comp_size, dest);
        // Update file size
        size -= read_size;
    }
    // Free memory
    free(read_buf);
    free(comp_buf);
}

int compress_chunk(unsigned char* src, int size, unsigned char* dest) {
    int i, j, count;
    unsigned char curr, next;
    // Initialize variables
    i = j = count = 0;
    curr = src[i];
    // Compress chunk
    while (i < size) {
        next = src[i+1];
        if (next == curr) {
            count++;
        } else {
            dest[j++] = curr;
            if (count > 0) {
                dest[j++] = count;
            }
            curr = next;
            count = 0;
        }
        i++;
    }
    // Write final symbol and count
    dest[j++] = curr;
    if (count > 0) {
        dest[j++] = count;
    }
    // Return compressed size
    return j;
}

void write_header(FILE* dest, int size) {
    // Write file size as first 4 bytes
    fwrite(&size, sizeof(unsigned int), 1, dest);
}

int read_header(FILE* src) {
    // Read file size from first 4 bytes
    unsigned int size;
    fread(&size, sizeof(unsigned int), 1, src);
    return size;
}