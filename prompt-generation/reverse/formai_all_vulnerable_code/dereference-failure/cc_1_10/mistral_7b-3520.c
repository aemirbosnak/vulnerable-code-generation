//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

#define FILE_SIZE (1024 * 1024)
#define KEY_SIZE 32
#define IV_SIZE 16
#define BUFFER_SIZE 16

void aes_encrypt_file(const char *input_file, const char *output_file, const char *key) {
    AES_KEY aes_key;
    int iv_len = IV_SIZE;
    unsigned char iv[IV_SIZE];
    unsigned char *buffer;
    int fd_input, fd_output;
    struct stat file_stat;
    int read_len;

    if (AES_set_encrypt_key((unsigned char *)key, KEY_SIZE, &aes_key) != 1) {
        fprintf(stderr, "Failed to initialize AES key\n");
        exit(EXIT_FAILURE);
    }

    if (RAND_bytes(iv, iv_len) <= 0) {
        fprintf(stderr, "Failed to generate IV\n");
        exit(EXIT_FAILURE);
    }

    fd_input = open(input_file, O_RDONLY);
    if (fd_input < 0) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    fd_output = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_output < 0) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    buffer = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd_output, 0);
    if (buffer == MAP_FAILED) {
        perror("Failed to map output file");
        exit(EXIT_FAILURE);
    }

    if (fstat(fd_input, &file_stat) != 0) {
        perror("Failed to get file size");
        exit(EXIT_FAILURE);
    }

    while (read_len = read(fd_input, buffer, BUFFER_SIZE)) {
        AES_cbc_encrypt((unsigned char *)buffer, buffer, read_len, &aes_key, iv, iv_len);
        write(fd_output, buffer, read_len);
    }

    close(fd_input);
    close(fd_output);

    munmap(buffer, BUFFER_SIZE);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    aes_encrypt_file(argv[1], argv[2], argv[3]);

    return EXIT_SUCCESS;
}