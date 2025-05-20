//Falcon-180B DATASET v1.0 Category: Error handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_LINE 1024

void error_handler(const char *message);

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    char input_path[MAX_PATH];
    char output_path[MAX_PATH];

    strcpy(input_path, argv[1]);
    strcpy(output_path, argv[2]);

    int input_fd = open(input_path, O_RDONLY);
    if (input_fd == -1) {
        error_handler("Failed to open input file");
        return 1;
    }

    int output_fd = open(output_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        error_handler("Failed to open output file");
        close(input_fd);
        return 1;
    }

    char buffer[MAX_LINE];
    ssize_t bytes_read;

    while ((bytes_read = read(input_fd, buffer, MAX_LINE)) > 0) {
        ssize_t bytes_written = write(output_fd, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            error_handler("Failed to write to output file");
            close(input_fd);
            close(output_fd);
            remove(output_path);
            return 1;
        }
    }

    if (bytes_read == -1) {
        error_handler("Failed to read from input file");
        close(input_fd);
        close(output_fd);
        remove(output_path);
        return 1;
    }

    close(input_fd);
    close(output_fd);

    printf("File copied successfully!\n");

    return 0;
}

void error_handler(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    if (errno!= 0) {
        fprintf(stderr, "Errno: %d (%s)\n", errno, strerror(errno));
    }
    exit(1);
}