//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CSVReader {
    FILE *file;
    char *line;
    size_t line_size;
    char *field;
    size_t field_size;
    int field_count;
} CSVReader;

CSVReader *CSVReader_new(FILE *file) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->file = file;
    reader->line = NULL;
    reader->line_size = 0;
    reader->field = NULL;
    reader->field_size = 0;
    reader->field_count = 0;
    return reader;
}

void CSVReader_free(CSVReader *reader) {
    if (reader->line) {
        free(reader->line);
    }
    if (reader->field) {
        free(reader->field);
    }
    free(reader);
}

int CSVReader_next_line(CSVReader *reader) {
    if (getline(&reader->line, &reader->line_size, reader->file) == -1) {
        return 0;
    }
    reader->field_count = 0;
    reader->field = strtok(reader->line, ",");
    return 1;
}

int CSVReader_next_field(CSVReader *reader) {
    if (reader->field_count == 0 && !CSVReader_next_line(reader)) {
        return 0;
    }
    reader->field = strtok(NULL, ",");
    reader->field_count++;
    return 1;
}

char *CSVReader_get_field(CSVReader *reader) {
    return reader->field;
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    CSVReader *reader = CSVReader_new(file);

    while (CSVReader_next_line(reader)) {
        while (CSVReader_next_field(reader)) {
            printf("%s ", CSVReader_get_field(reader));
        }
        printf("\n");
    }

    CSVReader_free(reader);
    fclose(file);

    return EXIT_SUCCESS;
}