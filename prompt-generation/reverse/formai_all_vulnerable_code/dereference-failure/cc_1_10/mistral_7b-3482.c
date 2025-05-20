//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024 * 1024 // 1MB buffer

void read_file(const char *input_file_path, char *buffer) {
    int file_descriptor = open(input_file_path, O_RDONLY);
    if (file_descriptor < 0) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    ssize_t bytes_read = read(file_descriptor, buffer, BUFFER_SIZE);
    close(file_descriptor);

    if (bytes_read < 0) {
        perror("Error reading from input file");
        exit(EXIT_FAILURE);
    }
}

void write_file(const char *output_file_path, const char *data, size_t data_length) {
    int file_descriptor = open(output_file_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (file_descriptor < 0) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    ssize_t bytes_written = write(file_descriptor, data, data_length);
    close(file_descriptor);

    if (bytes_written < 0) {
        perror("Error writing to output file");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char input_file_path[256];
    char output_file_path[256];
    strcpy(input_file_path, argv[1]);
    strcpy(output_file_path, argv[2]);

    char buffer[BUFFER_SIZE];

    // Read input file
    read_file(input_file_path, buffer);

    // Perform calculations
    int sum = 0;
    for (size_t i = 0; i < BUFFER_SIZE; i++) {
        sum += buffer[i];
    }

    double average = (double)sum / BUFFER_SIZE;

    // Write output file
    char data[128];
    sprintf(data, "%lf\n", average);

    write_file(output_file_path, data, strlen(data) + 1);

    return EXIT_SUCCESS;
}