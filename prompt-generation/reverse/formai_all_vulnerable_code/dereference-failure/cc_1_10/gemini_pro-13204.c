//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CSVReader {
    FILE *file;
    char *buffer;
    size_t buffer_size;
    size_t buffer_pos;
    size_t buffer_end;
    char delimiter;
} CSVReader;

CSVReader* CSVReader_new(FILE *file, char delimiter) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->file = file;
    reader->buffer = NULL;
    reader->buffer_size = 0;
    reader->buffer_pos = 0;
    reader->buffer_end = 0;
    reader->delimiter = delimiter;
    return reader;
}

void CSVReader_free(CSVReader *reader) {
    free(reader->buffer);
    free(reader);
}

char* CSVReader_read_line(CSVReader *reader) {
    char *line = NULL;
    size_t line_size = 0;
    size_t line_pos = 0;

    while (1) {
        if (reader->buffer_pos >= reader->buffer_end) {
            if (getline(&reader->buffer, &reader->buffer_size, reader->file) == -1) {
                break;
            }
            reader->buffer_pos = 0;
            reader->buffer_end = strlen(reader->buffer);
        }

        if (reader->buffer[reader->buffer_pos] == reader->delimiter) {
            if (line_size == 0) {
                line = malloc(1);
                line[0] = '\0';
            } else {
                line = realloc(line, line_size + 1);
                line[line_size] = '\0';
            }

            reader->buffer_pos++;
            break;
        } else {
            if (line_size == 0) {
                line = malloc(2);
                line[0] = reader->buffer[reader->buffer_pos];
                line[1] = '\0';
            } else {
                line = realloc(line, line_size + 2);
                line[line_size] = reader->buffer[reader->buffer_pos];
                line[line_size + 1] = '\0';
            }

            line_size++;
            reader->buffer_pos++;
        }
    }

    return line;
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    CSVReader *reader = CSVReader_new(file, ',');

    char *line;
    while ((line = CSVReader_read_line(reader)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    CSVReader_free(reader);
    fclose(file);

    return EXIT_SUCCESS;
}