//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct csv_reader {
    FILE *file;
    char *buffer;
    size_t buffer_size;
    size_t buffer_used;
    size_t line_number;
    size_t column_number;
};

struct csv_reader *csv_reader_new(FILE *file) {
    struct csv_reader *reader = malloc(sizeof(struct csv_reader));
    reader->file = file;
    reader->buffer = NULL;
    reader->buffer_size = 0;
    reader->buffer_used = 0;
    reader->line_number = 0;
    reader->column_number = 0;
    return reader;
}

void csv_reader_free(struct csv_reader *reader) {
    free(reader->buffer);
    free(reader);
}

int csv_reader_next_line(struct csv_reader *reader) {
    if (reader->buffer_used == 0) {
        free(reader->buffer);
        reader->buffer = NULL;
        reader->buffer_size = 0;
        reader->buffer_used = 0;
    }

    char *line = NULL;
    size_t line_size = 0;
    ssize_t line_length = getline(&line, &line_size, reader->file);
    if (line_length == -1) {
        free(line);
        return 0;
    }

    reader->buffer = line;
    reader->buffer_size = line_size;
    reader->buffer_used = line_length;
    reader->line_number++;
    reader->column_number = 0;

    return 1;
}

int csv_reader_next_column(struct csv_reader *reader) {
    if (reader->column_number >= reader->buffer_used) {
        return 0;
    }

    char *column = reader->buffer + reader->column_number;
    size_t column_length = strcspn(column, ",\n");

    reader->column_number += column_length + 1;

    return column_length;
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    struct csv_reader *reader = csv_reader_new(file);

    while (csv_reader_next_line(reader)) {
        while (csv_reader_next_column(reader)) {
            char *column = reader->buffer + reader->column_number - 1;
            size_t column_length = strcspn(column, ",\n");

            printf("%.*s\n", column_length, column);
        }
    }

    csv_reader_free(reader);
    fclose(file);

    return 0;
}