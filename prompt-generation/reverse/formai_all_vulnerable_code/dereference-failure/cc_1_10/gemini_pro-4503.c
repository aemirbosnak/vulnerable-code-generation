//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BITMAP_HEADER_SIZE 54
#define LSB_MASK 0x01

void hide_watermark(const char *input_file, const char *watermark_file, const char *output_file) {
    FILE *input, *watermark, *output;
    uint8_t *input_buffer, *watermark_buffer, *output_buffer;
    size_t input_size, watermark_size, output_size;
    uint32_t i, j;

    // Read the input image file
    input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    fseek(input, 0, SEEK_END);
    input_size = ftell(input);
    rewind(input);
    input_buffer = malloc(input_size);
    if (input_buffer == NULL) {
        perror("Error allocating memory for input buffer");
        exit(EXIT_FAILURE);
    }
    fread(input_buffer, 1, input_size, input);
    fclose(input);

    // Read the watermark image file
    watermark = fopen(watermark_file, "rb");
    if (watermark == NULL) {
        perror("Error opening watermark file");
        exit(EXIT_FAILURE);
    }
    fseek(watermark, 0, SEEK_END);
    watermark_size = ftell(watermark);
    rewind(watermark);
    watermark_buffer = malloc(watermark_size);
    if (watermark_buffer == NULL) {
        perror("Error allocating memory for watermark buffer");
        exit(EXIT_FAILURE);
    }
    fread(watermark_buffer, 1, watermark_size, watermark);
    fclose(watermark);

    // Create the output image file
    output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }
    output_size = input_size + watermark_size;
    output_buffer = malloc(output_size);
    if (output_buffer == NULL) {
        perror("Error allocating memory for output buffer");
        exit(EXIT_FAILURE);
    }

    // Copy the input image header to the output image
    memcpy(output_buffer, input_buffer, BITMAP_HEADER_SIZE);

    // Store the watermark size in the output image header
    *(uint32_t *)(output_buffer + 10) = watermark_size;

    // Embed the watermark in the least significant bit of the input image
    for (i = BITMAP_HEADER_SIZE, j = 0; i < input_size && j < watermark_size; i++, j++) {
        output_buffer[i] = (input_buffer[i] & ~LSB_MASK) | ((watermark_buffer[j] & LSB_MASK) << 0);
    }

    // Write the output image to file
    fwrite(output_buffer, 1, output_size, output);
    fclose(output);

    // Free the allocated memory
    free(input_buffer);
    free(watermark_buffer);
    free(output_buffer);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <watermark_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    hide_watermark(argv[1], argv[2], argv[3]);
    return EXIT_SUCCESS;
}