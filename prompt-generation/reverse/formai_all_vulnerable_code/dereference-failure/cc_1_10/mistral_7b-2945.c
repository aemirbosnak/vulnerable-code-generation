//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_CHAR 256
#define BLOCK_SIZE 64

void encrypt_char(int shift, char *char_ptr) {
    int ascii_val = *char_ptr;

    if (islower(*char_ptr)) {
        ascii_val = (ascii_val + shift - 97) % 26 + 97;
    } else if (isupper(*char_ptr)) {
        ascii_val = (ascii_val + shift - 65) % 26 + 65;
    }

    *char_ptr = ascii_val;
}

void encrypt_file(const char *input_file, const char *output_file, int shift) {
    int fd_input, fd_output, i;
    char input_buffer[BLOCK_SIZE];
    char output_buffer[BLOCK_SIZE];

    fd_input = open(input_file, O_RDONLY);
    fd_output = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    while (read(fd_input, input_buffer, BLOCK_SIZE) > 0) {
        for (i = 0; i < BLOCK_SIZE; ++i) {
            encrypt_char(shift, &input_buffer[i]);
            output_buffer[i] = input_buffer[i];
        }

        write(fd_output, output_buffer, BLOCK_SIZE);
    }

    close(fd_input);
    close(fd_output);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <shift>\n", argv[0]);
        return 1;
    }

    int shift = atoi(argv[3]);
    encrypt_file(argv[1], argv[2], shift);

    return 0;
}