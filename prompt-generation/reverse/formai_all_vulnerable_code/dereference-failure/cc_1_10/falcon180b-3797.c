//Falcon-180B DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_LINES 1000

struct Line {
    char line[MAX_LINE_SIZE];
    int length;
};

struct File {
    FILE *fp;
    int num_lines;
    struct Line *lines;
};

void init_file(struct File *file) {
    file->fp = NULL;
    file->num_lines = 0;
    file->lines = NULL;
}

void open_file(struct File *file, const char *filename) {
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
}

void close_file(struct File *file) {
    if (file->fp!= NULL) {
        fclose(file->fp);
        file->fp = NULL;
    }
}

void add_line(struct File *file, const char *line) {
    if (file->num_lines >= MAX_NUM_LINES) {
        printf("Error: maximum number of lines reached\n");
        return;
    }
    struct Line *new_line = malloc(sizeof(struct Line));
    strcpy(new_line->line, line);
    new_line->length = strlen(line);
    file->lines = realloc(file->lines, file->num_lines * sizeof(struct Line));
    file->lines[file->num_lines - 1] = *new_line;
    free(new_line);
    file->num_lines++;
}

void print_file(const struct File *file) {
    for (int i = 0; i < file->num_lines; i++) {
        printf("%d: %s\n", i + 1, file->lines[i].line);
    }
}

int main() {
    struct File file;
    init_file(&file);
    open_file(&file, "example.txt");
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file.fp)!= NULL) {
        int length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') {
            line[--length] = '\0';
        }
        add_line(&file, line);
    }
    close_file(&file);
    print_file(&file);
    return 0;
}