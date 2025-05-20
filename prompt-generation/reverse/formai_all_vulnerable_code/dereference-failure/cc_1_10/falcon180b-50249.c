//Falcon-180B DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *filename;
    FILE *fp;
    char **lines;
    int num_lines;
} File;

File *open_file(char *filename) {
    File *file = (File *) malloc(sizeof(File));
    file->filename = strdup(filename);
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    file->lines = NULL;
    file->num_lines = 0;
    return file;
}

void close_file(File *file) {
    if (file->fp!= NULL) {
        fclose(file->fp);
    }
    free(file->filename);
    for (int i = 0; i < file->num_lines; i++) {
        free(file->lines[i]);
    }
    free(file->lines);
    free(file);
}

void read_file(File *file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file->fp)!= NULL) {
        file->lines = (char **) realloc(file->lines, sizeof(char *) * ++file->num_lines);
        file->lines[file->num_lines - 1] = strdup(line);
    }
}

void print_file(File *file) {
    for (int i = 0; i < file->num_lines; i++) {
        printf("%s\n", file->lines[i]);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    File *file = open_file(filename);
    read_file(file);
    print_file(file);

    close_file(file);
    return 0;
}