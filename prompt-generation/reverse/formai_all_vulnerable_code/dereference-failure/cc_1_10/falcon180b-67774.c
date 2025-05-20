//Falcon-180B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
    int line_number;
    char *line;
} File;

void init_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");
    file->line_number = 0;
    file->line = malloc(MAX_LINE_LENGTH);
}

char *read_line(File *file) {
    char c;
    int len = 0;
    while ((c = fgetc(file->file))!= EOF && c!= '\n') {
        if (len >= MAX_LINE_LENGTH - 1) {
            printf("Error: Line too long.\n");
            exit(1);
        }
        file->line[len++] = c;
    }
    if (c!= EOF) {
        file->line[len] = '\0';
        file->line_number++;
    } else {
        file->line[len] = '\0';
    }
    return file->line;
}

int main() {
    File file;
    init_file(&file, "example.txt");
    while ((file.line = read_line(&file))!= NULL) {
        printf("Line %d: %s\n", file.line_number, file.line);
    }
    free(file.line);
    fclose(file.file);
    free(file.filename);
    return 0;
}