//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WATERMARK "WATERMARK"
#define WATERMARK_LENGTH 9 // Length of the watermark string
#define BUFFER_SIZE 4096 // Size of the buffer for file operations

void embed_watermark(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");
    if (!input || !output) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }

    uint8_t buffer[BUFFER_SIZE];
    size_t read_bytes;
    size_t watermark_pos = 0;

    // Read the input file and embed the watermark
    while ((read_bytes = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < read_bytes; i++) {
            // Modifying the least significant bit to hide the watermark
            if (watermark_pos < WATERMARK_LENGTH) {
                buffer[i] = (buffer[i] & ~1) | ((WATERMARK[watermark_pos] >> 7) & 1);
                watermark_pos++;
            }
        }
        fwrite(buffer, 1, read_bytes, output);
    }

    fclose(input);
    fclose(output);
    printf("Watermark embedded successfully into '%s'\n", output_file);
}

void extract_watermark(const char *watermarked_file) {
    FILE *input = fopen(watermarked_file, "rb");
    if (!input) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }

    uint8_t buffer[BUFFER_SIZE];
    size_t read_bytes;
    char extracted_watermark[WATERMARK_LENGTH + 1] = {0};
    size_t watermark_pos = 0;

    // Read the watermarked file and extract the watermark
    while ((read_bytes = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < read_bytes && watermark_pos < WATERMARK_LENGTH; i++) {
            extracted_watermark[watermark_pos] <<= 1;
            extracted_watermark[watermark_pos] |= (buffer[i] & 1);
            if (++watermark_pos % 8 == 0) {
                watermark_pos++;
            }
        }
    }

    fclose(input);
    printf("Extracted watermark: ");
    for (size_t i = 0; i < WATERMARK_LENGTH; i++) {
        printf("%c", extracted_watermark[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed/extract> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed_watermark(argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_watermark(argv[2]);
    } else {
        fprintf(stderr, "Invalid operation. Use 'embed' or 'extract'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}