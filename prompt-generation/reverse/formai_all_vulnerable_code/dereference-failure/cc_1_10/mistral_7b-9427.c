//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>

#define MAX_LINE_SIZE 4096
#define MAX_FIELDS 100
#define MAX_FIELD_SIZE 255

typedef struct {
    size_t field_count;
    size_t capacity;
    size_t size;
    char **fields;
} CSVLine;

void csv_line_init(CSVLine *line) {
    line->capacity = 1;
    line->size = 0;
    line->fields = calloc(line->capacity, sizeof(char *));
}

void csv_line_free(CSVLine *line) {
    for (size_t i = 0; i < line->size; ++i) {
        free(line->fields[i]);
    }
    free(line->fields);
}

void csv_line_resize(CSVLine *line) {
    if (line->capacity == line->size) {
        line->capacity *= 2;
        line->fields = realloc(line->fields, line->capacity * sizeof(char *));
    }
}

void csv_line_append(CSVLine *line, const char *field) {
    if (line->size == line->capacity) {
        csv_line_resize(line);
    }

    size_t field_len = strlen(field) + 1;
    line->fields[line->size] = malloc(field_len);
    strcpy(line->fields[line->size], field);
    line->size++;
}

bool csv_line_parse(FILE *file, CSVLine *line) {
    char buffer[MAX_LINE_SIZE];
    size_t len = fgets(buffer, sizeof(buffer), file);
    if (len < 0) {
        return false;
    }

    csv_line_init(line);

    char *token = strtok(buffer, ",");
    size_t i = 0;
    while (token != NULL) {
        csv_line_append(line, token);
        i++;
        token = strtok(NULL, ",");
    }

    return i > 0;
}

int main() {
    FILE *file = fopen("input.csv", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    CSVLine line;
    while (csv_line_parse(file, &line)) {
        printf("Fields count: %zu\n", line.size);
        for (size_t i = 0; i < line.size; ++i) {
            printf("Field %zu: %s\n", i, line.fields[i]);
        }
        csv_line_free(&line);
    }

    fclose(file);
    return 0;
}