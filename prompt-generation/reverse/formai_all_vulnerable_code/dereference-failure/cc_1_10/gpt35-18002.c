//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Function to add digital watermark to input file
void add_watermark(FILE *input_file, FILE *output_file) {
    int watermark = 456731;

    // Read input file byte-by-byte
    int byte_read;
    while ((byte_read = fgetc(input_file)) != EOF) {
        // Add watermark to least significant bit of each byte
        int new_byte = byte_read | (watermark & 1);
        watermark >>= 1;

        // Write new byte to output file
        fputc(new_byte, output_file);
    }
}

// Function to extract digital watermark from input file
void extract_watermark(FILE *input_file) {
    int watermark = 0;

    // Read input file byte-by-byte
    int byte_read;
    while ((byte_read = fgetc(input_file)) != EOF) {
        // Extract least significant bit of each byte and append to watermark
        watermark = (watermark << 1) | (byte_read & 1);
    }

    printf("Extracted watermark: %d", watermark);
}

int main() {
    // Open input file
    FILE *input_file = fopen("input.txt", "rb");
    if (input_file == NULL) {
        printf("Error opening input file");
        exit(1);
    }

    // Open output file for writing
    FILE *output_file = fopen("output.txt", "wb");
    if (output_file == NULL) {
        printf("Error opening output file");
        exit(1);
    }

    // Add watermark to input file and write to output file
    add_watermark(input_file, output_file);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    // Reopen output file for reading
    FILE *extract_file = fopen("output.txt", "rb");
    if (extract_file == NULL) {
        printf("Error opening extracted file");
        exit(1);
    }

    // Extract watermark from output file
    extract_watermark(extract_file);

    // Close extracted file
    fclose(extract_file);

    return 0;
}