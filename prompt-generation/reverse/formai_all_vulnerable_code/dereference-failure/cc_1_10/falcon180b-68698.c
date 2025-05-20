//Falcon-180B DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
        printf("Error opening input file: %s\n", strerror(errno));
        return 1;
    }

    int output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        printf("Error opening output file: %s\n", strerror(errno));
        close(input_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(output_fd, buffer, bytes_read)!= bytes_read) {
            printf("Error writing to output file: %s\n", strerror(errno));
            close(input_fd);
            close(output_fd);
            return 1;
        }
    }

    if (bytes_read == -1) {
        printf("Error reading from input file: %s\n", strerror(errno));
        close(input_fd);
        close(output_fd);
        return 1;
    }

    close(input_fd);
    close(output_fd);

    return 0;
}