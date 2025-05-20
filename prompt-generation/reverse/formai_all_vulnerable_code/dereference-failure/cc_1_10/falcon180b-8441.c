//Falcon-180B DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *filename;
    FILE *file;
    int line_count;
    char *line;
} File;

int open_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    file->line_count = 0;
    file->line = malloc(MAX_LINE_LENGTH);
    return 0;
}

void close_file(File *file) {
    free(file->filename);
    fclose(file->file);
    free(file->line);
}

int read_line(File *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    char *token = strtok(file->line, " \n\t");
    while (token!= NULL) {
        strcat(line, token);
        strcat(line, " ");
        token = strtok(NULL, " \n\t");
    }
    strcat(line, "\n");
    file->line_count++;
    return 0;
}

void print_file_contents(File *file) {
    printf("File: %s\n", file->filename);
    printf("Line Count: %d\n", file->line_count);
    printf("Contents:\n");
    while (read_line(file) == 0) {
        printf("%s", file->line);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    File file;
    open_file(&file, argv[1]);
    print_file_contents(&file);
    close_file(&file);
    return 0;
}