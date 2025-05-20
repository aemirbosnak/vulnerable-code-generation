//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    unsigned char data[BUFFER_SIZE];
    size_t read_pos;
    size_t write_pos;
} buffer;

void rle_compress(unsigned char *input, size_t input_len, unsigned char *output) {
    size_t i = 0, j = 0;
    unsigned char curr_byte = input[0];
    size_t count = 1;

    while (i < input_len) {
        if (input[i] == curr_byte) {
            count++;
        } else {
            output[j++] = curr_byte;
            if (count > 1) {
                output[j++] = count;
                count = 0;
            }
            curr_byte = input[i++];
        }
    }

    if (count > 0) {
        output[j++] = curr_byte;
        if (count > 1) {
            output[j++] = count;
        }
    }
}

void write_to_file(unsigned char *data, size_t data_len, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(data, data_len, 1, file);
        fclose(file);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    size_t input_len = ftell(input_file);
    rewind(input_file);

    unsigned char *input_data = malloc(input_len);
    if (input_data == NULL) {
        perror("Error allocating memory for input data");
        fclose(input_file);
        return 1;
    }

    size_t bytes_read = fread(input_data, 1, input_len, input_file);
    if (bytes_read != input_len) {
        perror("Error reading input file");
        free(input_data);
        fclose(input_file);
        return 1;
    }

    fclose(input_file);

    size_t output_len = (input_len + 7) & ~7; // Round up to a multiple of 8 bytes
    unsigned char *output_data = malloc(output_len);

    rle_compress(input_data, input_len, output_data);

    write_to_file(output_data, output_len, argv[2]);

    free(output_data);
    free(input_data);

    printf("Compression successful!\n");

    return 0;
}