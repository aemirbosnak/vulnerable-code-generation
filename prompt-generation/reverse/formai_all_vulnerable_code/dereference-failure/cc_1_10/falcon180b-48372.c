//Falcon-180B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *content;
    size_t length;
} Line;

typedef struct {
    Line *lines;
    size_t num_lines;
    size_t total_length;
} File;

File *file_open(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    File *result = malloc(sizeof(File));
    result->lines = NULL;
    result->num_lines = 0;
    result->total_length = 0;

    char line_buffer[MAX_LINE_LENGTH];
    while (fgets(line_buffer, MAX_LINE_LENGTH, file)!= NULL) {
        Line *line = malloc(sizeof(Line));
        line->content = strdup(line_buffer);
        line->length = strlen(line->content);
        result->lines = realloc(result->lines, sizeof(Line) * (result->num_lines + 1));
        result->lines[result->num_lines] = *line;
        result->num_lines++;
        result->total_length += line->length;
    }

    fclose(file);
    return result;
}

void file_close(File *file) {
    for (size_t i = 0; i < file->num_lines; i++) {
        free(file->lines[i].content);
    }
    free(file->lines);
    free(file);
}

void file_print(const File *file) {
    for (size_t i = 0; i < file->num_lines; i++) {
        printf("%zu: %.*s\n", i + 1, file->lines[i].length, file->lines[i].content);
    }
}

int main() {
    File *file = file_open("example.txt");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    file_print(file);

    file_close(file);

    return 0;
}