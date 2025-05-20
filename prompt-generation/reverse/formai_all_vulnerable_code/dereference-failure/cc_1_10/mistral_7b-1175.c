//MISTRAL-7B DATASET v1.0 Category: File Synchronizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 1024
#define FILENAME_MAX 256

void error_handler(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void print_usage(const char *program_name) {
    printf("Usage: %s <source_file> <destination_file>\n", program_name);
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
    }

    char source_file[FILENAME_MAX];
    char destination_file[FILENAME_MAX];

    strcpy(source_file, argv[1]);
    strcpy(destination_file, argv[2]);

    int source_file_fd = open(source_file, O_RDONLY);
    int destination_file_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (source_file_fd == -1 || destination_file_fd == -1) {
        error_handler("Error opening files");
    }

    char buffer[BUF_SIZE];
    ssize_t read_bytes;

    while ((read_bytes = read(source_file_fd, buffer, BUF_SIZE)) > 0) {
        write(destination_file_fd, buffer, read_bytes);
    }

    if (read_bytes == -1) {
        error_handler("Error reading from source file");
    }

    close(source_file_fd);
    close(destination_file_fd);

    printf("File '%s' synchronized with '%s'\n", source_file, destination_file);

    return EXIT_SUCCESS;
}