//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_BUFFER_SIZE 1024
#define WATERMARK_SIZE 32

void embed_watermark(const char *input_file, const char *output_file, const char *watermark) {
    FILE *infile = fopen(input_file, "rb");
    FILE *outfile = fopen(output_file, "wb");

    if (!infile || !outfile) {
        fprintf(stderr, "Error: Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    uint8_t buffer[MAX_BUFFER_SIZE];
    size_t bytesRead;

    // Start embedding the watermark
    while ((bytesRead = fread(buffer, 1, MAX_BUFFER_SIZE, infile)) > 0) {
        // Modify last bytes of buffer to embed watermark
        if (bytesRead >= WATERMARK_SIZE) {
            for (size_t i = 0; i < WATERMARK_SIZE; i++) {
                buffer[bytesRead - WATERMARK_SIZE + i] = watermark[i];
            }
            fwrite(buffer, 1, bytesRead, outfile);
        } else {
            fwrite(buffer, 1, bytesRead, outfile);
        }
    }

    fclose(infile);
    fclose(outfile);
}

void extract_watermark(const char *output_file) {
    FILE *infile = fopen(output_file, "rb");
    if (!infile) {
        fprintf(stderr, "Error: Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    uint8_t buffer[MAX_BUFFER_SIZE];
    size_t bytesRead;

    // Read the content and extract the watermark
    while ((bytesRead = fread(buffer, 1, MAX_BUFFER_SIZE, infile)) > 0) {
        // Extract watermark from the last bytes of the buffer
        if (bytesRead >= WATERMARK_SIZE) {
            printf("Extracted Watermark: ");
            for (size_t i = 0; i < WATERMARK_SIZE; i++) {
                putchar(buffer[bytesRead - WATERMARK_SIZE + i]);
            }
            printf("\n");
        }
    }

    fclose(infile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed|extract> <input_file> <output_file> [watermark_string]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0) {
        if (argc != 5) {
            fprintf(stderr, "Error: Please provide watermark string for embedding.\n");
            return EXIT_FAILURE;
        }
        embed_watermark(argv[2], argv[3], argv[4]);
        printf("Watermark embedded successfully!\n");
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_watermark(argv[3]);
    } else {
        fprintf(stderr, "Error: Invalid command. Use 'embed' or 'extract'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}