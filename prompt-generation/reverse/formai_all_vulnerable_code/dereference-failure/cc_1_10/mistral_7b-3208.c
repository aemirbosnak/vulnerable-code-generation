//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PI 3.14159265358979323846
#define MAX_BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: %s <file> <output_file> <number_of_lines>\n", __FILE__);
}

int main(int argc, char *argv[]) {
    int file_fd, output_fd, i, num_lines, ch;
    char buffer[MAX_BUFFER_SIZE];
    struct stat file_stats;

    if (argc != 4) {
        print_usage();
        exit(1);
    }

    file_fd = open(argv[1], O_RDONLY);
    if (file_fd < 0) {
        perror("Error opening input file.");
        exit(1);
    }

    output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (output_fd < 0) {
        perror("Error opening output file.");
        close(file_fd);
        exit(1);
    }

    fstat(file_fd, &file_stats);
    num_lines = file_stats.st_size / MAX_BUFFER_SIZE;
    if (file_stats.st_size % MAX_BUFFER_SIZE != 0) {
        num_lines++;
    }

    if (argc < 4 || atoi(argv[3]) < 1 || atoi(argv[3]) > num_lines) {
        print_usage();
        close(file_fd);
        close(output_fd);
        exit(1);
    }

    for (i = 1; i < atoi(argv[3]); i++) {
        read(file_fd, buffer, MAX_BUFFER_SIZE);
        write(output_fd, buffer, MAX_BUFFER_SIZE);

        while ((ch = getc(file_fd)) != '\n') {
            ungetc(ch, file_fd);
            buffer[MAX_BUFFER_SIZE - 1] = '\0';
            read(file_fd, &buffer[MAX_BUFFER_SIZE - 1], 1);
        }
    }

    close(file_fd);
    close(output_fd);

    printf("Copied %d lines from %s to %s.\n", atoi(argv[3]), argv[1], argv[2]);

    return 0;
}