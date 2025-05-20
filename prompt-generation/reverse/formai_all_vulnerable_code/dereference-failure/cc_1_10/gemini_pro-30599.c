//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char *filename;
    size_t size;
    char *data;
} File;

File *open_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    char *data = malloc(size);
    if (data == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(data, 1, size, fp);
    fclose(fp);

    File *file = malloc(sizeof(File));
    if (file == NULL) {
        free(data);
        return NULL;
    }

    file->filename = strdup(filename);
    if (file->filename == NULL) {
        free(file);
        free(data);
        return NULL;
    }

    file->size = size;
    file->data = data;

    return file;
}

void close_file(File *file) {
    free(file->filename);
    free(file->data);
    free(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    File *file = open_file(argv[1]);
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    printf("File: %s\n", file->filename);
    printf("Size: %zu\n", file->size);
    printf("Data:\n%s\n", file->data);

    close_file(file);

    return 0;
}