//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>

#define KEY_SIZE 25
#define BLOCK_SIZE 8

void encrypt_file(char *input_file, char *output_file, char *key) {
    int fd_input, fd_output;
    char buffer[BLOCK_SIZE];
    char key_char[KEY_SIZE + 1];
    char xor_key[BLOCK_SIZE];
    int key_index = 0;

    fd_input = open(input_file, O_RDONLY);
    fd_output = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd_input < 0 || fd_output < 0) {
        perror("Error opening files.");
        exit(EXIT_FAILURE);
    }

    while (read(fd_input, buffer, BLOCK_SIZE) > 0) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            xor_key[i] = key[key_index];
            key_index = (key_index + 1) % KEY_SIZE;
        }

        for (int i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= xor_key[i];
        }

        write(fd_output, buffer, BLOCK_SIZE);
    }

    close(fd_input);
    close(fd_output);
}

void generate_key(char *key) {
    int fd, i;

    fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0) {
        perror("Error opening /dev/urandom");
        exit(EXIT_FAILURE);
    }

    read(fd, key, KEY_SIZE);
    close(fd);

    for (i = 0; i < KEY_SIZE; i++) {
        if (isalpha(key[i])) {
            key[i] = toupper(key[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char input_file[100], output_file[100], key[KEY_SIZE + 1];
    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);

    generate_key(key);
    encrypt_file(input_file, output_file, key);

    printf("File '%s' encrypted successfully.\n", input_file);

    return EXIT_SUCCESS;
}