//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    char* buffer;
} ebook_t;

ebook_t* open_ebook(const char* file_name) {
    ebook_t* ebook = (ebook_t*)malloc(sizeof(ebook_t));
    strcpy(ebook->file_name, file_name);
    ebook->file_size = 0;
    ebook->buffer = NULL;
    return ebook;
}

void close_ebook(ebook_t* ebook) {
    free(ebook->buffer);
    free(ebook);
}

void read_ebook(ebook_t* ebook, int offset, int length) {
    if (offset + length > ebook->file_size) {
        fprintf(stderr, "Invalid offset or length\n");
        return;
    }
    fseek(ebook->buffer, offset, SEEK_SET);
    fread(ebook->buffer + offset, length, 1, ebook->buffer);
}

void write_ebook(ebook_t* ebook, int offset, int length, char* data) {
    if (offset + length > ebook->file_size) {
        fprintf(stderr, "Invalid offset or length\n");
        return;
    }
    fseek(ebook->buffer, offset, SEEK_SET);
    fwrite(data, length, 1, ebook->buffer);
}

int main() {
    ebook_t* ebook = open_ebook("ebook.txt");
    if (ebook == NULL) {
        fprintf(stderr, "Failed to open ebook\n");
        return 1;
    }

    read_ebook(ebook, 0, ebook->file_size);

    char* buffer = malloc(ebook->file_size);
    read_ebook(ebook, 0, ebook->file_size);

    char* transformed_buffer = malloc(ebook->file_size);
    for (int i = 0; i < ebook->file_size; i++) {
        transformed_buffer[i] = buffer[ebook->file_size - i - 1];
    }

    write_ebook(ebook, 0, ebook->file_size, transformed_buffer);

    close_ebook(ebook);

    return 0;
}