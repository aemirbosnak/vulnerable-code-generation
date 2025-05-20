//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_KEY_LENGTH 10
#define BUFFER_SIZE 1024

void encrypt_file(char *input_path, char *key) {
    int fd_input, fd_output;
    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];
    char c;
    int key_value;

    fd_input = open(input_path, O_RDONLY);
    if (fd_input < 0) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    fd_output = open("output.enc", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_output < 0) {
        perror("Error creating output file");
        close(fd_input);
        exit(EXIT_FAILURE);
    }

    key_value = 0;
    for (int i = 0; i < strlen(key) && key_value < 128; i++) {
        c = key[i];
        key_value += c;
    }

    while (read(fd_input, input_buffer, BUFFER_SIZE) > 0) {
        for (int i = 0; i < strlen(input_buffer); i++) {
            c = input_buffer[i];
            if (c >= 'A' && c <= 'Z') {
                c = (char)(((int)c - (int)'A' + key_value) % 26 + 'A');
            } else if (c >= 'a' && c <= 'z') {
                c = (char)(((int)c - (int)'a' + key_value) % 26 + 'a');
            }
            output_buffer[i] = c;
        }
        write(fd_output, output_buffer, strlen(output_buffer));
    }

    close(fd_input);
    close(fd_output);

    printf("Encryption completed.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    encrypt_file(argv[1], argv[2]);

    return EXIT_SUCCESS;
}