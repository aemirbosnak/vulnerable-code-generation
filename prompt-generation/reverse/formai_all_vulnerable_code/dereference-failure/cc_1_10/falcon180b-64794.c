//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 4
#define WATERMARK_VALUE 0xDEADBEEF

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Failed to open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: Failed to open output file.\n");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    char *input_buffer = (char *) malloc(input_file_size);
    if (input_buffer == NULL) {
        printf("Error: Failed to allocate memory for input buffer.\n");
        return 1;
    }

    size_t bytes_read = fread(input_buffer, 1, input_file_size, input_file);
    if (bytes_read!= input_file_size) {
        printf("Error: Failed to read input file.\n");
        return 1;
    }

    char *output_buffer = (char *) malloc(input_file_size + WATERMARK_SIZE);
    if (output_buffer == NULL) {
        printf("Error: Failed to allocate memory for output buffer.\n");
        return 1;
    }

    char *watermark = (char *) malloc(WATERMARK_SIZE);
    if (watermark == NULL) {
        printf("Error: Failed to allocate memory for watermark.\n");
        return 1;
    }

    memset(watermark, WATERMARK_VALUE, WATERMARK_SIZE);

    long watermark_position = input_file_size - WATERMARK_SIZE;
    memcpy(output_buffer + watermark_position, watermark, WATERMARK_SIZE);
    memcpy(output_buffer, input_buffer, input_file_size);

    size_t output_size = input_file_size + WATERMARK_SIZE;
    fwrite(output_buffer, 1, output_size, output_file);

    free(input_buffer);
    free(output_buffer);
    free(watermark);

    fclose(input_file);
    fclose(output_file);

    printf("Watermarking completed successfully.\n");

    return 0;
}