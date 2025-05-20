//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void compress(unsigned char *input, unsigned char *output, size_t length) {
    unsigned char buffer[BUFFER_SIZE];
    size_t buffer_index = 0;
    size_t current_char_count = 1;

    for (size_t i = 0; i < length; ++i) {
        buffer[buffer_index] = input[i];
        if (i < length - 1 && buffer[buffer_index] == input[i + 1]) {
            ++current_char_count;
        } else {
            if (current_char_count > 1) {
                output[i] = buffer[buffer_index];
                printf("%hhu %hhu\n", buffer[buffer_index], current_char_count);
                current_char_count = 1;
            } else {
                output[i] = buffer[buffer_index];
            }
            if (buffer_index < BUFFER_SIZE - 1) {
                ++buffer_index;
            } else {
                buffer_index = 0;
            }
        }
    }

    if (buffer_index > 0) {
        output[length] = buffer[buffer_index];
        printf("%hhu %hhu\n", buffer[buffer_index], current_char_count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    size_t input_file_size = fseek(input_file, 0, SEEK_END);
    fseek(input_file, 0, SEEK_SET);

    unsigned char *input = malloc(input_file_size);
    if (!input) {
        perror("Error allocating memory for input buffer");
        fclose(input_file);
        return 1;
    }

    size_t bytes_read = fread(input, 1, input_file_size, input_file);
    if (bytes_read != input_file_size) {
        perror("Error reading input file");
        free(input);
        fclose(input_file);
        return 1;
    }

    fclose(input_file);

    unsigned char *output = malloc(input_file_size);
    if (!output) {
        perror("Error allocating memory for output buffer");
        free(input);
        return 1;
    }

    compress(input, output, input_file_size);

    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        perror("Error opening output file");
        free(input);
        free(output);
        return 1;
    }

    size_t output_bytes_written = fwrite(output, 1, input_file_size, output_file);
    if (output_bytes_written != input_file_size) {
        perror("Error writing output file");
        free(input);
        free(output);
        fclose(output_file);
        return 1;
    }

    free(input);
    free(output);
    fclose(output_file);

    printf("Compression successful.\n");

    return 0;
}