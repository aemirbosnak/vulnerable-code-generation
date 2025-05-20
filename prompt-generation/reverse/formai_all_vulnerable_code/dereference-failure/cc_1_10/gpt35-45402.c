//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WATERMARK_SIZE 16
#define CHUNK_SIZE 1024

typedef struct {
    uint8_t watermark[WATERMARK_SIZE];
} watermark_t;

// Helper function to read a chunk of data from file
uint8_t* read_chunk(FILE* file) {
    uint8_t* chunk = (uint8_t*) malloc(CHUNK_SIZE);
    size_t read_size = fread(chunk, sizeof(uint8_t), CHUNK_SIZE, file);
    chunk = (uint8_t*) realloc(chunk, read_size);
    return chunk;
}

// Helper function to write a chunk of data to file
void write_chunk(FILE* file, uint8_t* data, size_t size) {
    fwrite(data, sizeof(uint8_t), size, file);
}

// Function to embed the watermark into a file
void embed_watermark(char* source_file, char* dest_file, watermark_t* watermark) {
    FILE* in_file = fopen(source_file, "rb");
    if (!in_file) {
        printf("Error opening source file");
        exit(EXIT_FAILURE);
    }

    FILE* out_file = fopen(dest_file, "wb");
    if (!out_file) {
        printf("Error creating destination file");
        exit(EXIT_FAILURE);
    }

    // Write watermark to beginning of file
    write_chunk(out_file, watermark->watermark, WATERMARK_SIZE);

    // Embed watermark into file by XORing consecutive chunks
    uint8_t* prev_chunk = read_chunk(in_file);
    while (!feof(in_file)) {
        uint8_t* curr_chunk = read_chunk(in_file);
        for (int i = 0; i < CHUNK_SIZE; i++) {
            curr_chunk[i] ^= prev_chunk[i];
        }
        write_chunk(out_file, curr_chunk, CHUNK_SIZE);
        free(prev_chunk);
        prev_chunk = curr_chunk;
    }

    // Write last chunk, if it is not the same size as CHUNK_SIZE
    write_chunk(out_file, prev_chunk, fread(prev_chunk, sizeof(uint8_t), CHUNK_SIZE, in_file));

    // Clean up
    free(prev_chunk);
    fclose(in_file);
    fclose(out_file);
}

// Function to extract a watermark from a file
void extract_watermark(char* file, watermark_t* watermark) {
    FILE* in_file = fopen(file, "rb");
    if (!in_file) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the first WATERMARK_SIZE bytes of the file as the watermark
    fread(watermark->watermark, sizeof(uint8_t), WATERMARK_SIZE, in_file);

    // Extract watermark from file by XORing consecutive chunks
    uint8_t* prev_chunk = read_chunk(in_file);
    while (!feof(in_file)) {
        uint8_t* curr_chunk = read_chunk(in_file);
        for (int i = 0; i < CHUNK_SIZE; i++) {
            curr_chunk[i] ^= prev_chunk[i];
        }
        free(prev_chunk);
        prev_chunk = curr_chunk;
    }

    // Check if the extracted watermark matches the one at the beginning of the file
    if (memcmp(prev_chunk, watermark->watermark, WATERMARK_SIZE) != 0) {
        printf("Watermark not found in file");
        exit(EXIT_FAILURE);
    }

    // Clean up
    free(prev_chunk);
    fclose(in_file);
}

int main() {
    char source_file[] = "original.txt";
    char dest_file[] = "watermarked.txt";

    // Create a test watermark
    watermark_t watermark = { {0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88} };

    // Embed the watermark into the source file
    embed_watermark(source_file, dest_file, &watermark);

    // Extract the watermark from the watermarked file and check if it matches the original watermark
    watermark_t extracted_watermark;
    extract_watermark(dest_file, &extracted_watermark);
    if (memcmp(&extracted_watermark, &watermark, sizeof(watermark_t)) == 0) {
        printf("Watermark successfully extracted and verified");
    } else {
        printf("Watermark verification failed");
    }

    return 0;
}