//Falcon-180B DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 10000

typedef struct {
    char *line;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} File;

File *open_file(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    File *file = (File *) malloc(sizeof(File));
    file->lines = (Line *) malloc(sizeof(Line));
    file->num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int length = strlen(line);
        Line *new_line = (Line *) malloc(sizeof(Line));
        new_line->line = (char *) malloc(length + 1);
        strcpy(new_line->line, line);
        new_line->length = length;

        if (file->num_lines == MAX_NUM_LINES) {
            printf("Error: file contains too many lines\n");
            exit(1);
        }

        file->lines = (Line *) realloc(file->lines, sizeof(Line) * (file->num_lines + 1));
        file->lines[file->num_lines++] = *new_line;
    }

    fclose(fp);
    return file;
}

void print_file(File *file)
{
    for (int i = 0; i < file->num_lines; i++) {
        printf("%s\n", file->lines[i].line);
    }
}

void close_file(File *file)
{
    free(file->lines);
    free(file);
}

int main()
{
    File *file = open_file("example.txt");
    print_file(file);
    close_file(file);

    return 0;
}