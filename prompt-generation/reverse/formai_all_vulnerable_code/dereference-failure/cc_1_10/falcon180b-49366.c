//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *data;
    size_t size;
} String;

typedef struct {
    String **lines;
    size_t num_lines;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(*csv));
    csv->lines = NULL;
    csv->num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        size_t line_len = strlen(line);
        if (line_len > 0 && line[line_len - 1] == '\n') {
            line[--line_len] = '\0';
        }

        String *new_line = malloc(sizeof(*new_line));
        new_line->data = strdup(line);
        new_line->size = line_len;

        csv->lines = realloc(csv->lines, sizeof(*csv->lines) * ++csv->num_lines);
        csv->lines[csv->num_lines - 1] = new_line;
    }

    fclose(file);
    return csv;
}

void csv_close(CSV *csv) {
    for (size_t i = 0; i < csv->num_lines; ++i) {
        free(csv->lines[i]->data);
        free(csv->lines[i]);
    }
    free(csv->lines);
    free(csv);
}

size_t csv_get_num_lines(CSV *csv) {
    return csv->num_lines;
}

String *csv_get_line(CSV *csv, size_t index) {
    if (index >= csv->num_lines) {
        return NULL;
    }
    return csv->lines[index];
}

int main() {
    CSV *csv = csv_open("example.csv");

    printf("Number of lines: %zu\n", csv_get_num_lines(csv));

    for (size_t i = 0; i < csv_get_num_lines(csv); ++i) {
        String *line = csv_get_line(csv, i);
        printf("%s\n", line->data);
    }

    csv_close(csv);

    return 0;
}