//Falcon-180B DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    char input_buf[BUF_SIZE];
    char output_buf[BUF_SIZE];
    int input_fd, output_fd;
    int bytes_read, bytes_written;

    input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
        printf("Error opening input file: %s\n", strerror(errno));
        return 1;
    }

    output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        printf("Error opening output file: %s\n", strerror(errno));
        close(input_fd);
        return 1;
    }

    while ((bytes_read = read(input_fd, input_buf, BUF_SIZE)) > 0) {
        if (write(output_fd, input_buf, bytes_read)!= bytes_read) {
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

    printf("File copied successfully!\n");

    return 0;
}