//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_BUFF_SIZE 1024

void print_error_and_exit(const char *msg, int err_num);
int create_file(const char *filename, mode_t mode);
int read_file(int fd, char *buf, size_t count);
int write_file(int fd, const char *buf, size_t count);
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }

    const char *source_file = argv[1];
    const char *destination_file = argv[2];

    int fd_source = open(source_file, O_RDONLY);
    if (fd_source == -1) {
        print_error_and_exit("Could not open source file", errno);
    }

    int fd_destination = create_file(destination_file, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_destination == -1) {
        close(fd_source);
        print_error_and_exit("Could not create destination file", errno);
    }

    char buf[MAX_BUFF_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read_file(fd_source, buf, MAX_BUFF_SIZE)) > 0) {
        if (write_file(fd_destination, buf, bytes_read) != bytes_read) {
            close(fd_source);
            close(fd_destination);
            print_error_and_exit("Error writing to destination file", errno);
        }
    }

    if (bytes_read == -1) {
        close(fd_source);
        close(fd_destination);
        print_error_and_exit("Error reading from source file", errno);
    }

    close(fd_source);
    close(fd_destination);
    printf("File copied successfully.\n");

    return 0;
}

void print_error_and_exit(const char *msg, int err_num) {
    perror(msg);
    fprintf(stderr, "Error number: %d\n", err_num);
    exit(1);
}

int create_file(const char *filename, mode_t mode) {
    int fd = open(filename, O_CREAT | O_EXCL | O_WRONLY, mode);

    if (fd != -1) {
        close(fd);
        return 1;
    }

    if (errno != EEXIST) {
        return -1;
    }

    return 0;
}

int read_file(int fd, char *buf, size_t count) {
    ssize_t bytes_read = read(fd, buf, count);

    if (bytes_read == -1) {
        return -1;
    }

    if (bytes_read == 0) {
        return 0;
    }

    return (int) bytes_read;
}

int write_file(int fd, const char *buf, size_t count) {
    ssize_t bytes_written = write(fd, buf, count);

    if (bytes_written == -1) {
        return -1;
    }

    return (int) bytes_written;
}