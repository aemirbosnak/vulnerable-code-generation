//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>

#define BLOCK_SIZE 4096
#define ARRAY_SIZE 1024 * 1024
#define FILENAME "input.txt"
#define OUTPUT_FILENAME "output.bin"

int custom_operation(int num) {
    return num * num;
}

int main() {
    int *input_array = NULL;
    int *output_array = NULL;
    int fd_input, fd_output;
    int i;

    // Open input file in read-only mode
    fd_input = open(FILENAME, O_RDONLY);
    if (fd_input == -1) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Map input file into memory
    input_array = mmap(NULL, ARRAY_SIZE * sizeof(int), PROT_READ, MAP_PRIVATE, fd_input, 0);
    if (input_array == MAP_FAILED) {
        perror("Error mapping input file to memory");
        exit(EXIT_FAILURE);
    }

    // Open output file in write-only mode and truncate it
    fd_output = open(OUTPUT_FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_output == -1) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Perform custom operation on each integer and write the result to the output file
    for (i = 0; i < ARRAY_SIZE; ++i) {
        output_array[i] = custom_operation(input_array[i]);
        write(fd_output, &output_array[i], sizeof(int));
    }

    // Unmap input file from memory
    munmap(input_array, ARRAY_SIZE * sizeof(int));

    // Close input and output files
    close(fd_input);
    close(fd_output);

    exit(EXIT_SUCCESS);
}