//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_CHUNK_SIZE 1024
#define VALID_SIGNATURE "MAGIC_SIGNATURE"
#define OUTPUT_FILE "output.bin"

int main(int argc, char **argv) {
    int input_file_fd, output_file_fd;
    char input_file_path[1024];
    char output_file_path[1024];
    char chunk[MAX_CHUNK_SIZE];
    int signature_length = strlen(VALID_SIGNATURE);
    ssize_t bytes_read;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    strcpy(input_file_path, argv[1]);
    strcpy(output_file_path, OUTPUT_FILE);

    input_file_fd = open(input_file_path, O_RDONLY);
    if (input_file_fd == -1) {
        perror("Error opening input file");
        exit(1);
    }

    output_file_fd = open(output_file_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (output_file_fd == -1) {
        perror("Error opening output file");
        close(input_file_fd);
        exit(1);
    }

    while ((bytes_read = read(input_file_fd, chunk, MAX_CHUNK_SIZE)) > 0) {
        if (memcmp(chunk, VALID_SIGNATURE, signature_length) == 0) {
            size_t data_length = *((size_t *) (chunk + signature_length));
            write(output_file_fd, chunk + signature_length, data_length);
        }
    }

    close(input_file_fd);
    close(output_file_fd);

    return 0;
}