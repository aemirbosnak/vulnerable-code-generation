//Falcon-180B DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    FILE* file;
} File;

typedef struct {
    char* line;
    size_t length;
    bool is_allocated;
} Line;

File* open_file(const char* filename) {
    File* file = malloc(sizeof(File));
    file->name[0] = '\0';
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    return file;
}

void close_file(File* file) {
    if (file->file!= NULL) {
        fclose(file->file);
        file->file = NULL;
    }
    free(file);
}

Line* read_line(File* file) {
    Line* line = malloc(sizeof(Line));
    line->line = malloc(MAX_LINE_LENGTH);
    line->length = 0;
    line->is_allocated = false;
    char* buffer = line->line;
    char c;
    while ((c = fgetc(file->file))!= EOF) {
        if (line->length >= MAX_LINE_LENGTH - 1) {
            fprintf(stderr, "Error: line too long\n");
            exit(EXIT_FAILURE);
        }
        if (c == '\n') {
            line->line[line->length] = '\0';
            line->is_allocated = true;
            break;
        }
        line->line[line->length++] = c;
    }
    if (line->length == 0) {
        free(line->line);
        free(line);
        line = NULL;
    }
    return line;
}

void print_file_contents(File* file) {
    Line* line = NULL;
    while ((line = read_line(file))!= NULL) {
        printf("%s", line->line);
    }
    free(line);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    File* file = open_file(argv[1]);
    print_file_contents(file);
    close_file(file);
    return 0;
}