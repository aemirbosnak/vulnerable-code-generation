//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024
#define MIN_LENGTH 32

void rle_encode(unsigned char *input, unsigned char *output, size_t length) {
    size_t i = 0, count = 1;

    while (i < length) {
        if (i + 1 < length && input[i] == input[i + 1]) {
            count++;
            i++;
        } else {
            output[i] = input[i];
            if (count > 1) {
                output[i + 1] = count | 0x80;
                i += 2;
                count = 1;
            }
        }
    }
}

void rle_decode(unsigned char *input, unsigned char *output, size_t length) {
    size_t i = 0;

    while (i < length) {
        if (input[i] & 0x80) {
            size_t j = i + 1;
            unsigned char count = input[i] & 0x7F;

            while (count--) {
                output[i++] = input[i];
            }
            i++;
        } else {
            output[i++] = input[i];
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <corrupted_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening file");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    size_t file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    unsigned char *input_buffer = calloc(BLOCK_SIZE, sizeof(unsigned char));
    unsigned char *output_buffer = calloc(BLOCK_SIZE, sizeof(unsigned char));

    size_t read_length = 0;

    while (read_length < file_size) {
        size_t read_count = fread(input_buffer, sizeof(unsigned char), BLOCK_SIZE, input_file);

        if (read_count > 0) {
            rle_encode(input_buffer, output_buffer, read_count);

            size_t written_length = fwrite(output_buffer, sizeof(unsigned char), read_count, stdout);

            if (written_length != read_count) {
                fprintf(stderr, "Error writing to output\n");
                free(input_buffer);
                free(output_buffer);
                fclose(input_file);
                return 1;
            }

            read_length += read_count;
        }
    }

    free(input_buffer);
    free(output_buffer);
    fclose(input_file);

    printf("\nData recovery complete.\n");

    return 0;
}