//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define FILE_NAME_LENGTH 256
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    char input_file[FILE_NAME_LENGTH];
    char output_file[FILE_NAME_LENGTH];
    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);

    int file_descriptor_input = open(input_file, O_RDONLY);
    if (file_descriptor_input == -1) {
        perror("Error opening input file.\n");
        exit(1);
    }

    int file_descriptor_output = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (file_descriptor_output == -1) {
        perror("Error creating or opening output file.\n");
        close(file_descriptor_input);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    ssize_t read_bytes;

    time_t seed = time(NULL);
    srand(seed);
    int shift = rand() % 26;

    printf("File '%s' encrypted with shift '%d'\n", input_file, shift);

    while ((read_bytes = read(file_descriptor_input, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < read_bytes; i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = (char)(((int)buffer[i] + shift - 97) % 26 + 97);
            } else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = (char)(((int)buffer[i] + shift - 65) % 26 + 65);
            }
        }

        write(file_descriptor_output, buffer, read_bytes);
    }

    close(file_descriptor_input);
    close(file_descriptor_output);

    printf("File '%s' encrypted successfully.\n", output_file);

    return 0;
}