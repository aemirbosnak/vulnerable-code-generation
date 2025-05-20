//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    FILE *file;
    char *filename;
    int filesize;
    char *buffer;
} FileData;

FileData *open_file(const char *filename) {
    FileData *fd = malloc(sizeof(FileData));
    fd->filename = strdup(filename);
    fd->file = fopen(filename, "rb");
    if (fd->file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    fseek(fd->file, 0, SEEK_END);
    fd->filesize = ftell(fd->file);
    rewind(fd->file);
    fd->buffer = malloc(BUFFER_SIZE);
    return fd;
}

void close_file(FileData *fd) {
    fclose(fd->file);
    free(fd->filename);
    free(fd->buffer);
    free(fd);
}

void recover_data(FileData *fd) {
    int bytes_read;
    char *data = NULL;
    size_t data_size = 0;
    while ((bytes_read = fread(fd->buffer, 1, BUFFER_SIZE, fd->file)) > 0) {
        data_size += bytes_read;
        data = realloc(data, data_size + 1);
        if (data == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }
        memcpy(data + data_size - bytes_read, fd->buffer, bytes_read);
    }
    if (ferror(fd->file)) {
        printf("Error: Could not read file %s\n", fd->filename);
        exit(1);
    }
    fd->buffer = realloc(fd->buffer, data_size);
    memcpy(fd->buffer, data, data_size);
    free(data);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FileData *fd = open_file(argv[1]);
    recover_data(fd);
    close_file(fd);
    return 0;
}