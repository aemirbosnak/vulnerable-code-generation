//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define SHIFT_KEY 3

void encrypt_char(char *input_char) {
    for (int i = 0; input_char[i] != '\0'; i++) {
        if (input_char[i] >= 'A' && input_char[i] <= 'Z') {
            input_char[i] = (input_char[i] + SHIFT_KEY - 65) % 26 + 65;
        } else if (input_char[i] >= 'a' && input_char[i] <= 'z') {
            input_char[i] = (input_char[i] + SHIFT_KEY - 97) % 26 + 97;
        }
    }
}

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    int input_file_fd = open(input_file, O_RDONLY);
    if (input_file_fd == -1) {
        perror("Error opening input file.");
        return 1;
    }

    struct stat input_file_stat;
    fstat(input_file_fd, &input_file_stat);

    char *input_buffer = (char *)malloc(input_file_stat.st_size);
    read(input_file_fd, input_buffer, input_file_stat.st_size);
    close(input_file_fd);

    encrypt_char(input_buffer);

    int output_file_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (output_file_fd == -1) {
        perror("Error opening or creating output file.");
        free(input_buffer);
        return 1;
    }

    write(output_file_fd, input_buffer, input_file_stat.st_size);
    close(output_file_fd);

    free(input_buffer);

    printf("File %s encrypted and saved as %s.\n", input_file, output_file);

    return 0;
}