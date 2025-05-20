//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define WATERMARK "SURVIVOR"

void embed_watermark(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Failed to open output file");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    // Read the input file size
    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    // Allocate memory for the input file content
    char *file_content = (char *)malloc(file_size);
    if (!file_content) {
        perror("Failed to allocate memory");
        fclose(input_file);
        fclose(output_file);
        exit(EXIT_FAILURE);
    }

    // Read the file into memory
    fread(file_content, file_size, 1, input_file);
    fclose(input_file);

    // Embed the watermark
    int watermark_length = strlen(WATERMARK);
    for (int i = 0; i < watermark_length; ++i) {
        file_content[file_size - watermark_length + i] ^= WATERMARK[i]; // Simple XOR method
    }

    // Write the modified content to the output file
    fwrite(file_content, file_size, 1, output_file);
    fclose(output_file);
    free(file_content);

    printf("Watermark embedded successfully: %s added to %s\n", WATERMARK, output_filename);
}

void extract_watermark(const char *output_filename) {
    FILE *output_file = fopen(output_filename, "rb");
    if (!output_file) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    // Read the output file size
    fseek(output_file, 0, SEEK_END);
    long file_size = ftell(output_file);
    fseek(output_file, 0, SEEK_SET);

    // Allocate memory for the output file content
    char *file_content = (char *)malloc(file_size);
    if (!file_content) {
        perror("Failed to allocate memory");
        fclose(output_file);
        exit(EXIT_FAILURE);
    }

    // Read the file into memory
    fread(file_content, file_size, 1, output_file);
    fclose(output_file);

    // Extract the watermark
    char extracted_watermark[100];
    int watermark_length = strlen(WATERMARK);
    for (int i = 0; i < watermark_length; ++i) {
        extracted_watermark[i] = file_content[file_size - watermark_length + i] ^ WATERMARK[i];
    }
    extracted_watermark[watermark_length] = '\0';

    printf("Extracted watermark: %s\n", extracted_watermark);
    free(file_content);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed/extract> <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed_watermark(argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_watermark(argv[3]);
    } else {
        fprintf(stderr, "Invalid action. Use 'embed' or 'extract'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}