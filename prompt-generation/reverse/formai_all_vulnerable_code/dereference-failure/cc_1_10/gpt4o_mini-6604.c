//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WATERMARK "WATERMARK"
#define WATERMARK_LEN (sizeof(WATERMARK) - 1)

void embed_watermark(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Failed to open input file");
        return;
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Failed to open output file");
        fclose(input_file);
        return;
    }

    // Read input file size
    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    // Allocate memory for the file content
    uint8_t *buffer = (uint8_t *)malloc(input_file_size + WATERMARK_LEN);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(input_file);
        fclose(output_file);
        return;
    }

    // Read the input file into buffer
    fread(buffer, 1, input_file_size, input_file);
    // Append watermark
    memcpy(buffer + input_file_size, WATERMARK, WATERMARK_LEN);

    // Write the buffer with embedded watermark to output file
    fwrite(buffer, 1, input_file_size + WATERMARK_LEN, output_file);

    // Clean up
    free(buffer);
    fclose(input_file);
    fclose(output_file);
}

int verify_watermark(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file for verification");
        return 0;
    }

    // Go to the end of the file to find the watermark
    fseek(file, -WATERMARK_LEN, SEEK_END);
    char watermark_read[WATERMARK_LEN + 1];
    fread(watermark_read, 1, WATERMARK_LEN, file);
    watermark_read[WATERMARK_LEN] = '\0'; // Null terminate for string comparison

    fclose(file);

    // Compare the watermark
    return (strcmp(watermark_read, WATERMARK) == 0);
}

void print_usage() {
    printf("Usage:\n");
    printf("  To embed watermark: ./watermark embed <input_file> <output_file>\n");
    printf("  To verify watermark: ./watermark verify <file>\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed_watermark(argv[2], argv[3]);
        printf("Watermark embedded successfully! Output file: %s\n", argv[3]);
    } else if (strcmp(argv[1], "verify") == 0) {
        if (verify_watermark(argv[2])) {
            printf("Watermark verified successfully in file: %s\n", argv[2]);
        } else {
            printf("Watermark verification failed for file: %s\n", argv[2]);
        }
    } else {
        print_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}