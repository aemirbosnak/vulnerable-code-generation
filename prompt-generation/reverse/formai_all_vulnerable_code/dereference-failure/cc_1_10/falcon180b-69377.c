//Falcon-180B DATASET v1.0 Category: File handling ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 10000

typedef struct {
    char *filename;
    char *content;
    size_t size;
} File;

File *file_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    File *file = malloc(sizeof(File));
    file->filename = strdup(filename);
    file->content = NULL;
    file->size = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        file->size += strlen(line);
        file->content = realloc(file->content, file->size + 1);
        strcat(file->content, line);
    }

    file->content[file->size] = '\0';
    fclose(fp);

    return file;
}

void file_print(const File *file) {
    printf("Filename: %s\n", file->filename);
    printf("Content:\n%s\n", file->content);
}

void file_free(File *file) {
    free(file->filename);
    free(file->content);
    free(file);
}

int main() {
    File *file = file_open("example.txt");
    file_print(file);
    file_free(file);

    return 0;
}