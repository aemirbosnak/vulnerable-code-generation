//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define KEY_SIZE 3
#define BLOCK_SIZE 16

void encrypt_file(char *input_file, char *output_file, int key[]) {
    int fd_input, fd_output;
    char buffer[BLOCK_SIZE];
    int bytes_read;

    fd_input = open(input_file, O_RDONLY);
    fd_output = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd_input == -1 || fd_output == -1) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = read(fd_input, buffer, BLOCK_SIZE)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = (((buffer[i] - 'A' + key[i % KEY_SIZE]) % 26) + 'A');
            } else if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = (((buffer[i] - 'a' + key[i % KEY_SIZE]) % 26) + 'a');
            }
        }

        write(fd_output, buffer, bytes_read);
    }

    close(fd_input);
    close(fd_output);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <key_value>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int key[KEY_SIZE];
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = atoi(argv[3 + i]);
    }

    encrypt_file(argv[1], argv[2], key);

    return EXIT_SUCCESS;
}