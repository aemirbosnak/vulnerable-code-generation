//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024)

typedef struct {
    char name[100];
    FILE *fp;
} FileHandler;

FileHandler *create_file_handler(const char *filename) {
    FileHandler *handler = (FileHandler *) malloc(sizeof(FileHandler));
    strcpy(handler->name, filename);
    handler->fp = fopen(filename, "r");
    if (handler->fp == NULL) {
        free(handler);
        return NULL;
    }
    return handler;
}

void read_file(FileHandler *handler, char *buffer, size_t size) {
    size_t bytes_read = fread(buffer, size, 1, handler->fp);
    if (bytes_read == 0) {
        fprintf(stderr, "%s: End of file reached\n", handler->name);
    }
}

void close_file_handler(FileHandler *handler) {
    if (handler != NULL && handler->fp != NULL) {
        fclose(handler->fp);
        free(handler);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FileHandler *handler = create_file_handler(argv[1]);
    if (handler == NULL) {
        fprintf(stderr, "%s: Failed to open file\n", argv[1]);
        return 1;
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, handler->fp)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, stdout);
    }

    if (ferror(handler->fp)) {
        perror("Error reading file");
        close_file_handler(handler);
        return 1;
    }

    close_file_handler(handler);

    return 0;
}