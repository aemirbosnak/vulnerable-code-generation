//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024
#define FILE_MODE 0644

typedef struct {
    char name[MAX_INPUT_SIZE];
    int fd;
    ssize_t read_size;
} FileHandle;

void die(const char *msg, int status) {
    perror(msg);
    if (status != EXIT_SUCCESS) {
        exit(status);
    }
}

FileHandle open_file(const char *filename) {
    FileHandle handle;
    memset(&handle, 0, sizeof(handle));
    if ((handle.fd = open(filename, O_RDONLY)) < 0) {
        die("Failed to open file: %s\n", filename);
    }
    strncpy(handle.name, filename, MAX_INPUT_SIZE);
    return handle;
}

ssize_t read_file(FileHandle *handle, void *buffer, size_t size) {
    ssize_t read_bytes = 0;
    if (handle->fd < 0) {
        die("Invalid file handle\n", EXIT_FAILURE);
    }
    if (buffer == NULL) {
        die("Buffer cannot be NULL\n", EXIT_FAILURE);
    }
    read_bytes = read(handle->fd, buffer, size);
    if (read_bytes < 0) {
        if (errno == EINTR) {
            // Interrupted system call, try again
            read_bytes = read_file(handle, buffer, size);
        } else {
            die("Failed to read file: %s\n", strerror(errno));
        }
    }
    handle->read_size += read_bytes;
    return read_bytes;
}

void close_file(FileHandle *handle) {
    if (handle->fd < 0) {
        die("Invalid file handle\n", EXIT_FAILURE);
    }
    close(handle->fd);
    handle->fd = -1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        die("Usage: %s <filename>\n", argv[0]);
    }

    FileHandle file = open_file(argv[1]);

    char buffer[MAX_INPUT_SIZE];
    ssize_t bytes_read = 0;

    while ((bytes_read = read_file(&file, buffer, MAX_INPUT_SIZE)) > 0) {
        fwrite(buffer, bytes_read, 1, stdout);
    }

    if (bytes_read < 0) {
        die("Error reading file: %s\n", strerror(errno));
    }

    close_file(&file);

    return EXIT_SUCCESS;
}