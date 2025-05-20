//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct {
    char filename[100];
    int fd;
    char buffer[1024];
} file_handler_t;

void init(file_handler_t *handler, const char *filename) {
    memset(handler, 0, sizeof(file_handler_t));
    strcpy(handler->filename, filename);

    if ((handler->fd = open(filename, O_RDONLY)) < 0) {
        perror("Error opening file");
        printf("Unable to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

void process(file_handler_t *handler) {
    ssize_t bytes_read;

    while ((bytes_read = read(handler->fd, handler->buffer, sizeof(handler->buffer))) > 0) {
        printf("%s", handler->buffer);
        memset(handler->buffer, 0, sizeof(handler->buffer));
    }

    if (bytes_read < 0) {
        perror("Error reading from file");
        printf("Error reading from file: %s\n", handler->filename);
        close(handler->fd);
        exit(EXIT_FAILURE);
    }
}

void cleanup(file_handler_t *handler) {
    if (handler->fd > 0) {
        close(handler->fd);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file_handler_t handler;
    init(&handler, argv[1]);
    process(&handler);
    cleanup(&handler);

    printf("\nProcessing completed successfully!\n");
    return EXIT_SUCCESS;
}