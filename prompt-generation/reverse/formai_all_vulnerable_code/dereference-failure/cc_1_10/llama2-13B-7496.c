//LLAMA2-13B DATASET v1.0 Category: File system simulation ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1024 * 1024 * 10

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    size_t size;
    int file_descriptor;
} file_t;

#define MAP_FAILED  (-1)

file_t* file_create(const char* name, size_t size) {
    file_t* file = malloc(sizeof(file_t));
    file->name[0] = '\0';
    file->size = size;
    file->file_descriptor = -1;

    if (name != NULL) {
        strncpy(file->name, name, MAX_FILE_NAME_LENGTH);
    }

    return file;
}

int file_open(file_t* file, int flags) {
    if (file->file_descriptor != -1) {
        close(file->file_descriptor);
    }

    file->file_descriptor = open(file->name, flags, 0644);
    if (file->file_descriptor == MAP_FAILED) {
        perror("open");
        return -1;
    }

    return 0;
}

int file_read(file_t* file, void* buffer, size_t size) {
    if (file->file_descriptor == -1) {
        perror("file not open");
        return -1;
    }

    ssize_t ret = read(file->file_descriptor, buffer, size);
    if (ret == -1) {
        perror("read");
        return -1;
    }

    return ret;
}

int file_write(file_t* file, const void* buffer, size_t size) {
    if (file->file_descriptor == -1) {
        perror("file not open");
        return -1;
    }

    ssize_t ret = write(file->file_descriptor, buffer, size);
    if (ret == -1) {
        perror("write");
        return -1;
    }

    return ret;
}

int file_close(file_t* file) {
    if (file->file_descriptor == -1) {
        return 0;
    }

    close(file->file_descriptor);
    file->file_descriptor = -1;

    return 0;
}

int main() {
    file_t* file = file_create("example.txt", 1024);
    if (file == NULL) {
        perror("file_create");
        return 1;
    }

    if (file_open(file, O_RDWR | O_CREAT) == -1) {
        perror("file_open");
        return 2;
    }

    char buffer[1024];
    if (file_read(file, buffer, 1024) == -1) {
        perror("file_read");
        return 3;
    }

    if (file_write(file, buffer, 1024) == -1) {
        perror("file_write");
        return 4;
    }

    if (file_close(file) == -1) {
        perror("file_close");
        return 5;
    }

    return 0;
}