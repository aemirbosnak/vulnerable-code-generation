//Gemma-7B DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FileHandle {
    FILE *fp;
    char *buffer;
    int bufferSize;
    int position;
} FileHandle;

void fileHandle_init(FileHandle *fh) {
    fh->fp = NULL;
    fh->buffer = NULL;
    fh->bufferSize = MAX_BUFFER_SIZE;
    fh->position = 0;
}

void fileHandle_open(FileHandle *fh, char *filename) {
    fh->fp = fopen(filename, "r");
    if (fh->fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fh->buffer = malloc(fh->bufferSize);
    if (fh->buffer == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    fh->position = 0;
}

void fileHandle_read(FileHandle *fh, char *data, int size) {
    int remaining = size;
    while (remaining > 0) {
        int readSize = fread(data, 1, remaining, fh->fp);
        if (readSize == 0) {
            break;
        }
        data += readSize;
        remaining -= readSize;
    }

    fh->position += size;
}

void fileHandle_close(FileHandle *fh) {
    fclose(fh->fp);
    free(fh->buffer);
    fh->fp = NULL;
    fh->buffer = NULL;
    fh->position = 0;
}

int main() {
    FileHandle handle;
    fileHandle_init(&handle);
    fileHandle_open(&handle, "example.txt");
    char data[1024];
    fileHandle_read(&handle, data, 512);
    fileHandle_close(&handle);

    printf("%s", data);

    return 0;
}