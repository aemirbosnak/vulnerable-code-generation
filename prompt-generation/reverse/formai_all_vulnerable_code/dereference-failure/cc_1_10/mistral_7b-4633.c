//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_DEPTH 10
#define BUF_SIZE 1024

typedef struct {
    char* file_path;
    char* buffer;
    int fd;
    int depth;
} FileHandler;

FileHandler* create_handler(char* file_path) {
    FileHandler* handler = (FileHandler*) malloc(sizeof(FileHandler));
    handler->file_path = file_path;
    handler->buffer = (char*) malloc(BUF_SIZE);
    handler->fd = open(file_path, O_RDONLY);
    handler->depth = 0;
    return handler;
}

void read_file(FileHandler* handler) {
    ssize_t bytes_read;

    if (handler->depth > MAX_DEPTH) {
        perror("Max depth reached");
        close(handler->fd);
        free(handler->buffer);
        free(handler);
        return;
    }

    if ((bytes_read = read(handler->fd, handler->buffer, BUF_SIZE)) < 0) {
        perror("Error reading file");
        close(handler->fd);
        free(handler->buffer);
        free(handler);
        return;
    }

    printf("%s", handler->buffer);

    if (lseek(handler->fd, -bytes_read, SEEK_CUR) < 0) {
        perror("Error moving file pointer");
        close(handler->fd);
        free(handler->buffer);
        free(handler);
        return;
    }

    ++(handler->depth);

    if (bytes_read < BUF_SIZE) {
        handler->buffer[bytes_read] = '\0';
        read_file(handler);
    } else {
        read_file(create_handler(strtok(handler->buffer, "\n")));
    }
}

int main() {
    char* file_path = "./recursive_example.c";
    FileHandler* handler = create_handler(file_path);
    read_file(handler);

    close(handler->fd);
    free(handler->buffer);
    free(handler);

    return 0;
}