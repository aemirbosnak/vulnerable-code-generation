//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_FILENAME_LENGTH 256
#define WATERMARK "WATERMARK"
#define WATERMARK_SIZE (sizeof(WATERMARK) - 1)

void embed_watermark(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    // Read the input file into memory
    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    uint8_t *file_buffer = malloc(file_size + WATERMARK_SIZE);
    if (!file_buffer) {
        perror("Memory allocation failed");
        fclose(input_file);
        fclose(output_file);
        exit(EXIT_FAILURE);
    }

    fread(file_buffer, 1, file_size, input_file);
    fclose(input_file);

    // Embed the watermark at the end of the file
    memcpy(file_buffer + file_size, WATERMARK, WATERMARK_SIZE);

    // Write the new file with the watermark
    fwrite(file_buffer, 1, file_size + WATERMARK_SIZE, output_file);
    fclose(output_file);
    free(file_buffer);

    printf("Watermark embedded successfully in %s\n", output_filename);
}

void extract_watermark(const char *output_filename) {
    FILE *output_file = fopen(output_filename, "rb");
    if (!output_file) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Seek to the end and read the watermark
    fseek(output_file, -WATERMARK_SIZE, SEEK_END);
    char watermark[WATERMARK_SIZE + 1] = {0};

    fread(watermark, 1, WATERMARK_SIZE, output_file);
    fclose(output_file);

    if (strcmp(watermark, WATERMARK) == 0) {
        printf("Watermark detected: %s\n", watermark);
    } else {
        printf("No watermark detected.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];

    // Step 1: Embed watermark in the output file
    embed_watermark(input_filename, output_filename);

    // Step 2: Extract the watermark from the output file
    extract_watermark(output_filename);

    return 0;
}