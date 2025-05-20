//Falcon-180B DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char *filename;
    FILE *file;
    int line_number;
    char line[MAX_LINE_SIZE];
} File;

File *open_file(char *filename) {
    File *file = malloc(sizeof(File));
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    file->line_number = 0;
    return file;
}

void close_file(File *file) {
    fclose(file->file);
    free(file->filename);
    free(file);
}

char *read_line(File *file) {
    char c;
    int i = 0;
    while ((c = fgetc(file->file))!= EOF && i < MAX_LINE_SIZE - 1) {
        if (c == '\n') {
            file->line_number++;
        }
        file->line[i++] = c;
    }
    file->line[i] = '\0';
    return file->line;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    File *file = open_file(argv[1]);

    char *line = read_line(file);
    while (line!= NULL) {
        printf("%d: %s", file->line_number, line);
        line = read_line(file);
    }

    close_file(file);

    return 0;
}