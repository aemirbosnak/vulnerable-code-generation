//Falcon-180B DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *filename;
    FILE *fp;
    int num_lines;
    char *lines[MAX_NUM_LINES];
} File;

File *open_file(char *filename) {
    File *f = malloc(sizeof(File));
    f->filename = filename;
    f->fp = fopen(filename, "r");
    if (f->fp == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }
    f->num_lines = 0;
    return f;
}

void close_file(File *f) {
    if (f->fp!= NULL) {
        fclose(f->fp);
    }
    free(f);
}

int read_file(File *f) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, f->fp)!= NULL) {
        if (f->num_lines >= MAX_NUM_LINES) {
            printf("Error: too many lines in file\n");
            exit(1);
        }
        f->lines[f->num_lines++] = strdup(line);
    }
    return f->num_lines;
}

void print_file(File *f) {
    for (int i = 0; i < f->num_lines; i++) {
        printf("%s\n", f->lines[i]);
    }
}

int main() {
    File *f = open_file("example.txt");
    int num_lines = read_file(f);
    print_file(f);
    close_file(f);
    return 0;
}