//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define MAX_LINE_SIZE 1024
#define FILENAME "example.txt"

typedef struct {
    char str[MAX_LINE_SIZE];
    size_t len;
} my_string;

void my_error(const char *msg, int err) {
    if (err < 0) {
        perror(msg);
        exit(EXIT_FAILURE);
    }
}

int open_file(const char *filename, int flags, mode_t mode) {
    int fd = open(filename, flags, mode);
    if (fd < 0) {
        my_error("Failed to open file: ", fd);
        return -1;
    }
    return fd;
}

size_t read_file(int fd, my_string *str) {
    ssize_t bytes_read;
    char *ptr;

    ptr = mmap(NULL, MAX_LINE_SIZE, PROT_READ, MAP_PRIVATE, fd, 0);
    if (ptr == MAP_FAILED) {
        my_error("Failed to map file to memory: ", fd);
        close(fd);
        return 0;
    }

    bytes_read = read(fd, ptr, MAX_LINE_SIZE - 1);
    if (bytes_read < 0) {
        my_error("Failed to read from file: ", fd);
        munmap(ptr, MAX_LINE_SIZE);
        close(fd);
        return 0;
    }

    str->len = bytes_read;
    str->str[bytes_read] = '\0';

    munmap(ptr, MAX_LINE_SIZE);
    close(fd);

    return bytes_read;
}

void print_string(const my_string *str) {
    if (write(STDOUT_FILENO, str->str, str->len) < 0) {
        perror("Failed to write string to stdout");
    }
}

int main(int argc, char **argv) {
    int fd;
    my_string line;

    fd = open_file(FILENAME, O_RDONLY, 0);
    if (fd < 0) {
        return -1;
    }

    if (read_file(fd, &line) < 0) {
        return -1;
    }

    print_string(&line);

    free(line.str);
    close(fd);

    return 0;
}