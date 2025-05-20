//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    int input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
        printf("Error opening input file: %s\n", strerror(errno));
        exit(1);
    }

    int output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        printf("Error opening output file: %s\n", strerror(errno));
        close(input_fd);
        exit(1);
    }

    char buffer[BUF_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(input_fd, buffer, BUF_SIZE)) > 0) {
        ssize_t bytes_written = write(output_fd, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            printf("Error writing to output file: %s\n", strerror(errno));
            close(input_fd);
            close(output_fd);
            unlink(argv[2]);
            exit(1);
        }
    }

    if (bytes_read == -1) {
        printf("Error reading from input file: %s\n", strerror(errno));
        close(input_fd);
        close(output_fd);
        unlink(argv[2]);
        exit(1);
    }

    close(input_fd);
    close(output_fd);

    printf("Data recovery completed successfully.\n");

    return 0;
}