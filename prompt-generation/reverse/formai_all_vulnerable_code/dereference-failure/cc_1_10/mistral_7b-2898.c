//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILE_NAME "shocked.txt"

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(void) {
    int fd;
    char *buffer;
    size_t len;

    fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) {
        die("open failed!");
    }

    len = 100;
    buffer = malloc(len);
    if (buffer == NULL) {
        die("malloc failed!");
    }

    // FILL THE BUFFER WITH SOME SHOCKED TEXT
    memset(buffer, '!', len);
    buffer[len - 1] = '\n';

    if (write(fd, buffer, len) != len) {
        die("write failed!");
    }

    close(fd);
    free(buffer);

    fd = open(FILE_NAME, O_RDONLY);
    if (fd == -1) {
        die("open failed for reading!");
    }

    len = 1024;
    char read_buffer[len];
    ssize_t bytes_read;

    printf("\nReading shocked file:\n");

    while ((bytes_read = read(fd, read_buffer, len)) > 0) {
        write(STDOUT_FILENO, read_buffer, bytes_read);
    }

    close(fd);

    printf("\nShocked file has been read!\n");

    return EXIT_SUCCESS;
}