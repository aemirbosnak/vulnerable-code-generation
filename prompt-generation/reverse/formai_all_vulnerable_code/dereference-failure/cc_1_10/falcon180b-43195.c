//Falcon-180B DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *fp;
    char *line;
    int line_num;
} File;

File *open_file(char *filename) {
    File *file = malloc(sizeof(File));
    file->filename = filename;
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    file->line = malloc(MAX_LINE_LENGTH);
    file->line_num = 0;
    return file;
}

char *read_line(File *file) {
    char *line = fgets(file->line, MAX_LINE_LENGTH, file->fp);
    if (line == NULL) {
        printf("Error: Could not read line from file %s\n", file->filename);
        exit(1);
    }
    file->line_num++;
    return line;
}

void close_file(File *file) {
    fclose(file->fp);
    free(file->line);
    free(file);
}

int main() {
    char *filename;
    printf("Enter filename: ");
    scanf("%s", filename);

    File *file = open_file(filename);

    char *line = read_line(file);
    while (line!= NULL) {
        printf("%d: %s", file->line_num, line);
        line = read_line(file);
    }

    close_file(file);

    return 0;
}