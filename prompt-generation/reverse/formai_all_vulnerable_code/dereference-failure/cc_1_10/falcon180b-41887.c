//Falcon-180B DATASET v1.0 Category: File handling ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char *filename;
    int filesize;
} file_t;

file_t *file_create(char *filename) {
    file_t *file = (file_t*) malloc(sizeof(file_t));
    file->filename = filename;
    file->filesize = 0;
    return file;
}

void file_destroy(file_t *file) {
    free(file);
}

int file_size(file_t *file) {
    return file->filesize;
}

void file_write(file_t *file, char *data) {
    int datasize = strlen(data);
    if (file->filesize + datasize > MAX_FILE_SIZE) {
        printf("Error: File size limit reached\n");
        return;
    }
    strcat(file->filename, data);
    file->filesize += datasize;
}

void file_read(file_t *file, int offset, int size, char *buffer) {
    int datasize = strlen(file->filename);
    if (offset >= datasize) {
        printf("Error: Invalid offset\n");
        return;
    }
    if (offset + size > datasize) {
        size = datasize - offset;
    }
    strncpy(buffer, file->filename + offset, size);
}

int main() {
    file_t *file = file_create("test.txt");
    char buffer[MAX_LINE_SIZE];
    while (1) {
        printf("Enter a line of text (press enter to save):\n");
        fgets(buffer, MAX_LINE_SIZE, stdin);
        if (feof(stdin)) {
            break;
        }
        file_write(file, buffer);
    }
    file_destroy(file);
    return 0;
}