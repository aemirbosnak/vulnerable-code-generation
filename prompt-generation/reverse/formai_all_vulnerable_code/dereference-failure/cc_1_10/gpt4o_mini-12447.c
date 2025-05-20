//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WATERMARK_LENGTH 16
#define MAX_FILENAME_LENGTH 256

void apply_watermark(const char *input_filename, const char *output_filename, const char *watermark);
void encode_watermark(uint8_t *data, size_t size, const char *watermark);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    const char *watermark = argv[3];

    if (strlen(watermark) > WATERMARK_LENGTH) {
        fprintf(stderr, "Error: Watermark length must not exceed %d characters.\n", WATERMARK_LENGTH);
        return EXIT_FAILURE;
    }

    apply_watermark(input_filename, output_filename, watermark);

    return EXIT_SUCCESS;
}

void apply_watermark(const char *input_filename, const char *output_filename, const char *watermark) {
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

    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    uint8_t *file_data = (uint8_t *) malloc(file_size);
    if (!file_data) {
        perror("Memory allocation failed");
        fclose(input_file);
        fclose(output_file);
        exit(EXIT_FAILURE);
    }

    fread(file_data, 1, file_size, input_file);
    encode_watermark(file_data, file_size, watermark);

    fwrite(file_data, 1, file_size, output_file);

    free(file_data);
    fclose(input_file);
    fclose(output_file);

    printf("Watermark applied successfully to %s and saved as %s\n", input_filename, output_filename);
}

void encode_watermark(uint8_t *data, size_t size, const char *watermark) {
    size_t watermark_length = strlen(watermark);
    for (size_t i = 0; i < watermark_length; i++) {
        data[i] = (data[i] & 0xFE) | (watermark[i] & 0x01);
    }
}

void print_usage(const char *program_name) {
    printf("Usage: %s <input_file> <output_file> <watermark>\n", program_name);
    printf("Watermark length must not exceed %d characters.\n", WATERMARK_LENGTH);
}