//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *content;
    size_t length;
} Line;

typedef struct {
    Line **lines;
    size_t count;
} File;

File *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    File *result = malloc(sizeof(File));
    result->lines = NULL;
    result->count = 0;

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        Line *line = malloc(sizeof(Line));
        line->content = strdup(buffer);
        line->length = strlen(line->content);
        result->lines = realloc(result->lines, sizeof(Line *) * ++result->count);
        result->lines[result->count - 1] = line;
    }

    fclose(file);
    return result;
}

void free_file(File *file) {
    for (size_t i = 0; i < file->count; ++i) {
        free(file->lines[i]->content);
        free(file->lines[i]);
    }
    free(file->lines);
    free(file);
}

void print_line(Line *line) {
    printf("%s", line->content);
}

void indent(size_t level) {
    for (size_t i = 0; i < level; ++i) {
        printf("  ");
    }
}

void print_file(File *file, size_t level) {
    for (size_t i = 0; i < file->count; ++i) {
        Line *line = file->lines[i];
        if (line->length == 0) {
            printf("\n");
        } else {
            indent(level);
            printf("%s\n", line->content);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    File *file = read_file(argv[1]);
    print_file(file, 0);

    free_file(file);
    return 0;
}