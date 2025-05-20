//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 1024

typedef struct {
    char *name;
    uint32_t size;
    uint8_t *data;
} File;

File *open_file(const char *name) {
    File *file = malloc(sizeof(File));
    if (file == NULL) {
        return NULL;
    }

    file->name = strdup(name);
    if (file->name == NULL) {
        free(file);
        return NULL;
    }

    FILE *fp = fopen(name, "rb");
    if (fp == NULL) {
        free(file->name);
        free(file);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    file->data = malloc(file->size);
    if (file->data == NULL) {
        fclose(fp);
        free(file->name);
        free(file);
        return NULL;
    }

    fread(file->data, 1, file->size, fp);
    fclose(fp);

    return file;
}

void close_file(File *file) {
    if (file == NULL) {
        return;
    }

    if (file->name != NULL) {
        free(file->name);
    }

    if (file->data != NULL) {
        free(file->data);
    }

    free(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    File *file = open_file(argv[1]);
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Do something with the file

    close_file(file);

    return EXIT_SUCCESS;
}