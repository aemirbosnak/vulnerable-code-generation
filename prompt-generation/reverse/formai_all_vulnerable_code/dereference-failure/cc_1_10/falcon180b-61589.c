//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 8
#define WATERMARK_VALUE 0xDEADBEEF

int main() {
    char *input_file = "input.txt";
    char *output_file = "output.txt";
    FILE *in, *out;
    unsigned char watermark[WATERMARK_SIZE] = {0};
    int file_size;

    // Open input and output files
    in = fopen(input_file, "rb");
    if (in == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }
    out = fopen(output_file, "wb");
    if (out == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Get size of input file
    fseek(in, 0, SEEK_END);
    file_size = ftell(in);
    rewind(in);

    // Read input file into buffer
    char *buffer = malloc(file_size + WATERMARK_SIZE);
    if (buffer == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }
    fread(buffer, file_size, 1, in);
    fclose(in);

    // Embed watermark in buffer
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = buffer[i % file_size];
        buffer[i % file_size] = watermark[i];
    }

    // Write watermarked buffer to output file
    fwrite(buffer, file_size, 1, out);
    fclose(out);

    printf("Watermark embedded successfully.\n");
    return 0;
}