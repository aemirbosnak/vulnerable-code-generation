//Falcon-180B DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *filename;
    char **lines;
    int num_lines;
} File;

File *file_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }

    File *f = malloc(sizeof(File));
    f->filename = strdup(filename);
    f->lines = NULL;
    f->num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *copy = strdup(line);
        f->lines = realloc(f->lines, sizeof(char *) * ++f->num_lines);
        f->lines[f->num_lines - 1] = copy;
    }

    fclose(fp);
    return f;
}

void file_print(File *f) {
    for (int i = 0; i < f->num_lines; i++) {
        printf("%s\n", f->lines[i]);
    }
}

void file_close(File *f) {
    for (int i = 0; i < f->num_lines; i++) {
        free(f->lines[i]);
    }
    free(f->lines);
    free(f->filename);
    free(f);
}

int main() {
    File *f = file_open("example.txt");
    file_print(f);
    file_close(f);
    return 0;
}