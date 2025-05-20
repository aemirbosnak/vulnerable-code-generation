//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

void compress(const char *input, char *output) {
    char curr_char = *input;
    char *out_ptr = output;
    int count = 0;

    while (*input) {
        if (*input == curr_char) {
            count++;
        } else {
            *out_ptr++ = curr_char;
            if (count > 127) {
                *out_ptr++ = (char)(count >> 4);
                *out_ptr++ = (char)(count & 0xF);
            } else {
                *out_ptr++ = (char)count;
            }
            curr_char = *input++;
            count = 1;
        }
    }

    // Add the last character and its count to the output
    *out_ptr++ = curr_char;
    if (count > 127) {
        *out_ptr++ = (char)(count >> 4);
        *out_ptr++ = (char)(count & 0xF);
    } else {
        *out_ptr++ = (char)count;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *in_file = fopen(argv[1], "r");
    if (!in_file) {
        perror("Error opening input file");
        return 1;
    }

    char *input_buf = malloc(BUF_SIZE);
    char *output_buf = malloc(BUF_SIZE);

    size_t bytes_read;
    while ((bytes_read = fread(input_buf, 1, BUF_SIZE, in_file))) {
        compress(input_buf, output_buf);
        size_t bytes_written = fwrite(output_buf, 1, bytes_read + sizeof(char) * (bytes_read / 2 + 1), stdout);
        if (bytes_written != (bytes_read + sizeof(char) * (bytes_read / 2 + 1))) {
            perror("Error writing to output");
            free(input_buf);
            free(output_buf);
            fclose(in_file);
            return 1;
        }
    }

    free(input_buf);
    free(output_buf);
    fclose(in_file);

    return 0;
}