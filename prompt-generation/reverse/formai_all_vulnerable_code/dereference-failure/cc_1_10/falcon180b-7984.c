//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define MAX_LINE_SIZE 1000

typedef struct {
    char *filename;
    int linenumber;
    char *line;
} Line;

typedef struct {
    Line *lines;
    int numlines;
} File;

File *open_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }
    File *file = malloc(sizeof(File));
    file->lines = NULL;
    file->numlines = 0;
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        Line *line_data = malloc(sizeof(Line));
        line_data->filename = strdup(filename);
        line_data->linenumber = file->numlines;
        line_data->line = strdup(line);
        file->lines = realloc(file->lines, sizeof(Line) * (file->numlines + 1));
        file->lines[file->numlines] = *line_data;
        file->numlines++;
    }
    fclose(fp);
    return file;
}

void print_file(File *file) {
    for (int i = 0; i < file->numlines; i++) {
        printf("%s:%d:%s\n", file->lines[i].filename, file->lines[i].linenumber, file->lines[i].line);
    }
}

int main() {
    char filename[MAX_FILE_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);
    File *file = open_file(filename);
    print_file(file);
    free(file->lines);
    free(file);
    return 0;
}