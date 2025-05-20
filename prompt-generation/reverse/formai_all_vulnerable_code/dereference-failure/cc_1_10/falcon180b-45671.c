//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 512

typedef struct {
    char *filename;
    FILE *file;
    int is_open;
} FileHandle;

typedef struct {
    char *data;
    int size;
} DataChunk;

void init_data_chunk(DataChunk *chunk) {
    chunk->data = malloc(CHUNK_SIZE);
    chunk->size = 0;
}

void free_data_chunk(DataChunk *chunk) {
    free(chunk->data);
}

int read_chunk(FileHandle *file, DataChunk *chunk) {
    int bytes_read;

    bytes_read = fread(chunk->data + chunk->size, 1, CHUNK_SIZE - chunk->size, file->file);

    if (bytes_read == 0) {
        return 0;
    }

    chunk->size += bytes_read;

    return 1;
}

int write_chunk(FileHandle *file, DataChunk *chunk) {
    int bytes_written;

    bytes_written = fwrite(chunk->data, 1, chunk->size, file->file);

    if (bytes_written!= chunk->size) {
        return 0;
    }

    return 1;
}

int open_file(FileHandle *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(filename, "rb+");

    if (file->file == NULL) {
        return 0;
    }

    file->is_open = 1;

    return 1;
}

int close_file(FileHandle *file) {
    if (file->is_open) {
        fclose(file->file);
        file->is_open = 0;
    }

    free(file->filename);

    return 1;
}

int main() {
    FileHandle file;
    DataChunk chunk;

    init_data_chunk(&chunk);

    if (!open_file(&file, "test.txt")) {
        printf("Failed to open file.\n");
        exit(1);
    }

    while (read_chunk(&file, &chunk)) {
        printf("%.*s", chunk.size, chunk.data);
    }

    close_file(&file);

    free_data_chunk(&chunk);

    return 0;
}